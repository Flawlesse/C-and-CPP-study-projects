//---------------------------------------------------------------------------

#ifndef UnitMainH
#define UnitMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *AwaitedOutput;
	TRichEdit *InStockOutput;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *NameEdit;
	TLabel *Label3;
	TEdit *AmountEdit;
	TLabel *Label4;
	TEdit *CostEdit;
	TLabel *Label5;
	TDateTimePicker *DateTimePicker;
	TLabel *Label6;
	TButton *AddButton;
	TButton *ExitButton;
	TRichEdit *REInfoBoard;
	TEdit *ToFindEdit;
	TButton *FindByName;
	TButton *FindByAmount;
	TButton *FindByCost;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall FindByNameClick(TObject *Sender);
	void __fastcall FindByAmountClick(TObject *Sender);
	void __fastcall FindByCostClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
