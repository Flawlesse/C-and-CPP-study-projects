//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "Date.h"
#include "Firm.h"
#include "Candidate.h"
#include "Position.h"
#include "CandidateList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
CandidateList* candList;
int currentIdx = -1;
Firm* FirmList;
int flcount = 10;
typedef unsigned int uint;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    PositionComboBox->Items->Add("Head");
	PositionComboBox->Items->Add("Manager");
	PositionComboBox->Items->Add("Trader");
	PositionComboBox->Items->Add("Accountant");
	PositionComboBox->Items->Add("BranchManager");
	PositionComboBox->Items->Add("OfficeWorker");
	CandidateChoiceComboBox->ItemIndex = 5;

	candList = new CandidateList();
	FirmList = new Firm[10];

	FirmsComboBox->Items->Clear();
	FirmList[0] = Firm("ALMO", "Engineer", 150, 35, 20, 50, true, Manager);
	FirmsComboBox->Items->Add
		("ALMO, Engineer, 150, 35, 20, 50, HENeeded, Manager");
	FirmList[1] = Firm("RoarCycle", "Engineer", 250, 10, 24, 35, false, Head);
	FirmsComboBox->Items->Add
		("RoarCycle, Engineer, 250, 10, 24, 35, HEUnnecessary, Head");
	FirmList[2] = Firm("ALMO", "Worker", 80, 40, 23, 40, false, Accountant);
	FirmsComboBox->Items->Add
		("ALMO, Worker, 80, 40, 23, 40, HEUnnecessary, Accountant");
	FirmList[3] = Firm("MechaWorld", "Worker", 200, 29, 23, 40, true, Manager);
	FirmsComboBox->Items->Add
		("MechaWorld, Worker, 200, 29, 23, 40, HENeeded, Manager");
	FirmList[4] = Firm("RoarCycle", "Worker", 80, 40, 18, 40, false,
		Accountant);
	FirmsComboBox->Items->Add
		("RoarCycle, Worker, 80, 40, 18, 40, HEUnnecessary, Accountant");
	FirmList[5] = Firm("Denti", "Doctor", 250, 40, 25, 40, true, OfficeWorker);
	FirmsComboBox->Items->Add
		("Denti, Doctor, 250, 40, 25, 40, HENeeded, OfficeWorker");
	FirmList[6] = Firm("Denti", "Biologist", 400, 40, 25, 40, true,
		BranchManager);
	FirmsComboBox->Items->Add
		("Denti, Biologist, 400, 40, 25, 40, HENeeded, BranchManager");
	FirmList[7] = Firm("RoarCycle", "IT-specialist", 400, 30, 23, 50, true,
		BranchManager);
	FirmsComboBox->Items->Add
		("RoarCycle, IT-specialist, 400, 30, 23, 50, HENeeded, BranchManager");
	FirmList[8] = Firm("ALMO", "Engineer", 650, 35, 20, 50, true, Head);
	FirmsComboBox->Items->Add
		("ALMO, Engineer, 650, 35, 20, 50, HENeeded, Head");
	FirmList[9] = Firm("Denti", "Worker", 100, 35, 18, 50, false, OfficeWorker);
	FirmsComboBox->Items->Add
		("Denti, Worker, 100, 35, 18, 50, HEUnnecessary, OfficeWorker");
	FirmsComboBox->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowCandidatesButtonClick(TObject *Sender)
{
    if (candList->isEmpty()) {
		ShowMessage("������ ����!");
		return;
	}
	candList->ShowAll(ListBox);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddNewCandidateButtonClick(TObject *Sender)
{
    enum Position pos;
	AnsiString fn;
	AnsiString spec;
	MDate date;
	bool check;
	uint mr;

	fn = FNEdit->Text.Trim();
	spec = SpecEdit->Text.Trim();
	try {
		if (fn.IsEmpty() || spec.IsEmpty())
			throw -1;

		TStringDynArray arr(SplitString((UnicodeString)fn, L" "));
		if (arr.Length != 3) // ������ ���� 3 ������� ����� ������
			throw -1;


		arr = SplitString((UnicodeString)spec, L" ");
		if (arr.Length != 1)
		   	throw -1;

		switch (PositionComboBox->ItemIndex) {
		case 0:
			pos = Head;
			break;
		case 1:
			pos = Manager;
			break;
		case 2:
			pos = Trader;
			break;
		case 3:
			pos = Accountant;
			break;
		case 4:
			pos = BranchManager;
			break;
		default:
			pos = OfficeWorker;
		}

		AnsiString tmpdate = DOBEdit->Text.Trim();
		date = StrToMDate(tmpdate);
		if (!CheckDate(date))
			throw -1;

		check = (HighEdCheckBox->Checked) ? true : false;
		mr = StrToInt(MinRateEdit->Text);
	}
	catch (EConvertError &e) {
		ShowMessage("Bad input.");
		return;
	}
	catch (...) {
		ShowMessage("Bad input.");
		return;
	}
	Candidate cand(fn, spec, pos, date, check, mr);
	candList->AddNew(cand);
	candList->ShowAll(ListBox);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SortByNameButtonClick(TObject *Sender)
{
	if (candList->isEmpty()) {
		ShowMessage("������ ����������� :)");
		return;
	}
	candList->SortByName(ListBox);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PickFirmListButtonClick(TObject *Sender)
{
    if (candList->isEmpty()) {
		ShowMessage("������ ���������� ����!");
		return;
	}
	if (currentIdx == -1) {
		ShowMessage("��� ������ �������� ���������.");
		return;
	}
	MDate currentDate;
	ListBox->Items->Clear();
	int yearsOld = TotalDays((*candList)[currentIdx].GetDateOfBirth(),
		currentDate) / 365;
	ListBox->Items->Add("List of appropriate vacancies:");
	for (int i = 0; i < flcount; i++) {
		if (yearsOld > FirmList[i].GetMaxYears() || yearsOld <
			FirmList[i].GetMinYears())
			continue;
		if ((*candList)[currentIdx].GetSpecialization() != FirmList[i].GetSpec())
			continue;
		if ((*candList)[currentIdx].GetPos() != FirmList[i].GetPos())
			continue;
		if ((*candList)[currentIdx].GetMinRate() > FirmList[i].GetRate())
			continue;
		if (!(*candList)[currentIdx].GetEducation() && FirmList[i].GetEdNeeded())
			continue;
		ListBox->Items->Add(FirmsComboBox->Items->Strings[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CandidateChoiceComboBoxChange(TObject *Sender)
{
    currentIdx = CandidateChoiceComboBox->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScarceVacButtonClick(TObject *Sender)
{
    // ������� Firms ��� ���������� ����������
	if (candList->isEmpty()) {
		ShowMessage("������ ���������� ����!");
		return;
	}
	MDate currentDate;
	bool *difVac = new bool[flcount];
	for (int i = 0; i < flcount; i++)
		difVac[i] = true;
	ListBox->Items->Clear();
	ListBox->Items->Add("List of scarce vacancies:");
	int yearsOld;
	for (int i = 0; i < candList->GetNum(); i++) {
		yearsOld = TotalDays((*candList)[i].GetDateOfBirth(), currentDate) / 365;
		for (int j = 0; j < flcount; j++)
			if ((yearsOld <= FirmList[j].GetMaxYears() && yearsOld >=
				FirmList[j].GetMinYears()) &&
				(*candList)[i].GetSpecialization() == FirmList[j].GetSpec()
				&& (*candList)[i].GetPos() == FirmList[j].GetPos()
				&& (*candList)[i].GetMinRate() <= FirmList[j].GetRate() &&
				((*candList)[i].GetEducation() || (*candList)[i].GetEducation()
				== FirmList[j].GetEdNeeded()) && difVac[j] )
				difVac[j] = false;
	}
	for (int i = 0; i < flcount; i++)
        if(difVac[i])
			ListBox->Items->Add(FirmsComboBox->Items->Strings[i]);

	delete[]difVac;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScarceFirmsButtonClick(TObject *Sender)
{
	if (candList->isEmpty()) {
		ShowMessage("������ ���������� ����!");
		return;
	}
	MDate currentDate;
	bool *difVac = new bool[flcount];
	int yearsOld;
	for (int i = 0; i < flcount; i++)
		difVac[i] = true;
	ListBox->Items->Clear();
	ListBox->Items->Add("List of firms with all the vacancies being scarce:");
	for (int i = 0; i < candList->GetNum(); i++) {
		yearsOld = TotalDays((*candList)[i].GetDateOfBirth(), currentDate) / 365;
		for (int j = 0; j < flcount; j++)
			if ((yearsOld <= FirmList[j].GetMaxYears() && yearsOld >= FirmList[j].GetMinYears())
				&& (*candList)[i].GetSpecialization() == FirmList[j].GetSpec()
				&& (*candList)[i].GetPos() == FirmList[j].GetPos() &&
				(*candList)[i].GetMinRate() <=FirmList[j].GetRate() &&
				((*candList)[i].GetEducation() || (*candList)[i].GetEducation()
				== FirmList[j].GetEdNeeded()) && difVac[j] )
				difVac[j] = false;
	}

	AnsiString name;
	bool flag;
	for (int i = 0; i < flcount; i++)
	{
		name = FirmList[i].GetName();
		flag = true;
		for (int j = i; j < flcount; j++)
			if (name == FirmList[j].GetName())
			{
				if (!difVac[j])
					flag = false;
				difVac[j] = false;
			}
		if (flag)
			ListBox->Items->Add(name);
	}

	delete[]difVac;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteCandidateButtonClick(TObject *Sender)
{
    if (currentIdx == -1) {
		ShowMessage("��� ������ �������� ���������.");
		return;
	}
	if (MessageDlg("�� ������������� ������ ������� ������� ��������� �� ������?",
		mtConfirmation, TMsgDlgButtons() << mbYes << mbCancel, 0) == mrYes)
		candList->Delete();
	else
		ShowMessage("������� �� ��� ����.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveCandidatesButtonClick(TObject *Sender)
{
	candList->Save();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LoadCandidatesButtonClick(TObject *Sender)
{
    candList->Load();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CreateNewCandidateListButtonClick(TObject *Sender)
{
    if (MessageDlg
		("�� ������������� ������ ������� ������� ������ � ������� �����?",
		mtConfirmation, TMsgDlgButtons() << mbYes << mbCancel, 0) == mrYes) {
		candList->Clear();
		ShowMessage("����� ������ ������� ������.");
		candList->ShowAll(ListBox);
	}
	else {
		ShowMessage("������� �� ��� ����.");
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitButtonClick(TObject *Sender)
{
    Form1->DestroyComponents();
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
    if (FirmList)
		delete[]FirmList;
	if (candList)
		delete candList;
}
//---------------------------------------------------------------------------
//*********************************DONE**************************************