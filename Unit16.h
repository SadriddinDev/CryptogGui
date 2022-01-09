//---------------------------------------------------------------------------

#ifndef Unit16H
#define Unit16H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sEdit.hpp"
#include "sLabel.hpp"
#include <Grids.hpp>
#include "sBitBtn.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAnaliktik_form : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TsLabel *sLabel1;
        TsEdit *sEdit1;
        TsLabel *sLabel2;
        TsEdit *sEdit2;
        TsLabel *sLabel3;
        TsEdit *sEdit3;
        TsLabel *sLabel4;
        TsEdit *sEdit4;
        TsBitBtn *sBitBtn1;
        TsBitBtn *sBitBtn2;
        TStringGrid *StringGrid2;
        TsLabel *sLabel5;
        TEdit *Edit1;
        TsLabel *sLabel6;
        TStringGrid *StringGrid3;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sEdit1Change(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAnaliktik_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAnaliktik_form *Analiktik_form;
//---------------------------------------------------------------------------
#endif
