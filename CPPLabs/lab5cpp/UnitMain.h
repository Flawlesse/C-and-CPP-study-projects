//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Gauges.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGauge *GaugeQ;
	TLabel *Label1;
	TListBox *QueueLB;
	TButton *AddQButton;
	TButton *LetGoButton;
	TLabel *Label2;
	TEdit *TopQEdit;
	TLabel *Label3;
	TListBox *RingLB;
	TGauge *GaugeR;
	TLabel *Label4;
	TButton *AddRButton;
	TButton *DeleteRButton;
	TButton *NextButton;
	TButton *PrevButton;
	TLabel *Label5;
	TLabel *RElemLabel;
	TButton *ExitButton;
	TEdit *QAddEdit;
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall AddQButtonClick(TObject *Sender);
	void __fastcall LetGoButtonClick(TObject *Sender);
	void __fastcall AddRButtonClick(TObject *Sender);
	void __fastcall DeleteRButtonClick(TObject *Sender);
	void __fastcall NextButtonClick(TObject *Sender);
	void __fastcall PrevButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
