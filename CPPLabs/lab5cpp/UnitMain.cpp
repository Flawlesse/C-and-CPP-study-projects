//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Ring.h"
#include <time.h>
#include <stdlib.h>

TForm1 *Form1;
DLList<int> *dllist;
Queue<int> *queue;
Ring<int> *ring;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	dllist = new DLList<int>();
	queue = new Queue<int>();
	ring = new Ring<int>();
	TopQEdit->Text = "NULL";
    srand(time(0));
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
	if (dllist)
		delete dllist;
	if (queue)
		delete queue;
	if (ring)
		delete ring;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddQButtonClick(TObject *Sender)
{
	try
	{
		int a = StrToInt(QAddEdit->Text);
		if (queue->Size() < GaugeQ->MaxValue)
		{
			queue->Push(a);
            GaugeQ->Progress = queue->Size();
		}
		else
		{
			ShowMessage("������� �����������!");
            return;
		}
		TopQEdit->Text = IntToStr(queue->Top());
	}
	catch(EConvertError &e)
	{
		ShowMessage("Bad input.");
		return;
	}
    queue->Show(QueueLB);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LetGoButtonClick(TObject *Sender)
{
	queue->Pop();
    GaugeQ->Progress = queue->Size();
	if (queue->Size())
		TopQEdit->Text = IntToStr(queue->Top());
	else
		TopQEdit->Text = "NULL";
    queue->Show(QueueLB);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::AddRButtonClick(TObject *Sender)
{
	ring->PushBack(1 + rand() % 384);
	if (ring->Size() == 1)
        ring->Move(1);
	ring->ShowAll(RingLB);
	ring->ShowCurrent(RElemLabel);
	GaugeR->MaxValue = (ring->Size()) ? ring->Size()- 1 : ring->Size();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteRButtonClick(TObject *Sender)
{
	ring->DeleteCurrent();
    ring->ShowCurrent(Form1->RElemLabel);
	ring->ShowAll(RingLB);
    GaugeR->MaxValue = (ring->Size()) ? ring->Size()- 1 : ring->Size();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::NextButtonClick(TObject *Sender)
{
	if (!ring->Size())
        return;
	ring->Move(1);
	ring->ShowCurrent(RElemLabel);
	int tmp = GaugeR->Progress;
	tmp++;
	GaugeR->Progress = tmp % ring->Size();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrevButtonClick(TObject *Sender)
{
	if (!ring->Size())
        return;
	ring->Move(-1);
	ring->ShowCurrent(RElemLabel);
    int tmp = GaugeR->Progress;
	tmp--;
	if (tmp  == -1)
		GaugeR->Progress = GaugeR->MaxValue;
	else
        GaugeR->Progress = tmp;
}
//---------------------------------------------------------------------------
//********************************DONE!**************************************
