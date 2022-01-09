//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sEdit.hpp"
#include <Buttons.hpp>
#include <Grids.hpp>
#include "sBitBtn.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class TRyukzak_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TStringGrid *StringGrid1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TsEdit *Edit1;
        TLabel *Label5;
        TsEdit *Edit2;
        TsBitBtn *sBitBtn1;
        TsBitBtn *sBitBtn2;
        TLabel *Label6;
        TsEdit *Edit3;
        TsBitBtn *sBitBtn3;
        TLabel *Label7;
        TsEdit *Edit4;
        TsBitBtn *sBitBtn4;
        TMemo *Memo1;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Label10Click(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
        void __fastcall sBitBtn3Click(TObject *Sender);
        void __fastcall sBitBtn4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRyukzak_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRyukzak_form *Ryukzak_form;
//---------------------------------------------------------------------------
#endif
