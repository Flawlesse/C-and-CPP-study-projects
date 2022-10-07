//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
#include "HashTable.h"
#include "ExtHT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HashTable* ht;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ht = new HashTable();
    Memo->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	try
	{
		AnsiString tmp = ADFEdit->Text.Trim();
		if (tmp.IsEmpty())
			throw -1;
		ht->Add(tmp);
	}
	catch(...)
	{
		ShowMessage("������� ���� ���-��.");
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
	if (ht)
        delete ht;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DelButtonClick(TObject *Sender)
{
	try
	{
		AnsiString tmp = ADFEdit->Text.Trim();
		if (tmp.IsEmpty())
			throw -1;
		ht->Delete(tmp);
	}
	catch(...)
	{
		ShowMessage("������� ���� ���-��.");
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindButtonClick(TObject *Sender)
{
	try
	{
		AnsiString tmp = ADFEdit->Text.Trim();
		if (tmp.IsEmpty())
			throw -1;
		if (ht->Has(tmp))
		{
			HasLabel->Font->Color = clLime;
			HasLabel->Caption = "����!";
		}
		else
		{
            HasLabel->Font->Color = clRed;
			HasLabel->Caption = "����...";
		}

	}
	catch(...)
	{
		ShowMessage("������� ���� ���-��.");
		return;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrintButtonClick(TObject *Sender)
{
    ht->Print(Memo);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MostRepeatedButtonClick(TObject *Sender)
{
    ((ExtHT*)ht)->ShowMostRepKeys(MRKeyLabel);
}
//---------------------------------------------------------------------------
//******************************DONE*****************************************