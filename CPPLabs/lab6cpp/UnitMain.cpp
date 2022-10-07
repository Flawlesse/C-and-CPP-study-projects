//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "TreeRB.h"
#include "Node.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree* rbTree;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	rbTree = new Tree();

	SG->Cells[0][1] = "�.�.�.";
	SG->Cells[0][2] = "����";

	SG->Cells[1][1] = "Lavrenovich A E";
	SG->Cells[1][2] = "2899152";
	SG->Cells[2][1] = "Kondrashov I D";
	SG->Cells[2][2] = "1890557";
	SG->Cells[3][1] = "Koleshko A S";
	SG->Cells[3][2] = "4881507";
	SG->Cells[4][1] = "Romanovski M S";
	SG->Cells[4][2] = "7800155";
	SG->Cells[5][1] = "Lavrenovich A E";
	SG->Cells[5][2] = "3555480";
	SG->Cells[6][1] = "Twardovsky I I";
	SG->Cells[6][2] = "1554700";
	SG->Cells[7][1] = "Malinovskiy M V";
	SG->Cells[7][2] = "1557088";
	SG->Cells[8][1] = "Randall J J";
	SG->Cells[8][2] = "1566780";
	SG->Cells[9][1] = "Alba K A";
	SG->Cells[9][2] = "1877051";
	SG->Cells[10][1] = "Slizh M V";
	SG->Cells[10][2] = "1844780";

	//inputing info
	for (int i = 1; i <= 10; i++)
		rbTree->InsertNode(SG->Cells[i][1], StrToInt(SG->Cells[i][2]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PreorderButtonClick(TObject *Sender)
{
    Memo->Lines->Clear();
    rbTree->Preorder(Memo, rbTree->GetRoot());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PostorderButtonClick(TObject *Sender)
{
	Memo->Lines->Clear();
	rbTree->Postorder(Memo, rbTree->GetRoot());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CenteredButtonClick(TObject *Sender)
{
    Memo->Lines->Clear();
	rbTree->Centered(Memo, rbTree->GetRoot());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	try
	{
		AnsiString data = FIOEdit->Text;
		if (data.IsEmpty())
			throw -1;
		int key = StrToInt(PassNumEdit->Text);
        rbTree->InsertNode(data, key);
	}
	catch(EConvertError &e)
	{
		ShowMessage("������ �����������. ���� ������ ���� ������ 0.");
		return;
	}
	catch(...)
	{
		ShowMessage("���-�� ����� �� ���. ��������, ���� � �����.");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DelButtonClick(TObject *Sender)
{
	try
	{
		int key = StrToInt(KeyEdit->Text);
		rbTree->DeleteNode(rbTree->FindNode(key));
	}
	catch(EConvertError &e)
	{
		ShowMessage("������ �����������. ���� ������ ���� ������ 0.");
		return;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReflectButtonClick(TObject *Sender)
{
    try
	{
		int key = StrToInt(KeyEdit->Text);
		Node* tmp = rbTree->FindNode(key);
		if (tmp)
			ReflectLabel->Caption = tmp->data;
		else
            ShowMessage("���� �� ������.");
	}
	catch(EConvertError &e)
	{
		ShowMessage("������ �����������. ���� ������ ���� ������ 0.");
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
	if (rbTree)
        delete rbTree;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LSButtonClick(TObject *Sender)
{
    LSLabel->Caption = IntToStr(rbTree->LeftSubtreeVal());
}
//---------------------------------------------------------------------------
//****************************DONE*******************************************
