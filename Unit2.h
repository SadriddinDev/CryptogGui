//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sBitBtn.hpp"
#include "sEdit.hpp"
#include "sLabel.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TRabin_form : public TForm
{
__published:	// IDE-managed Components
        TsEdit *sEdit1;
        TsLabel *sLabel1;
        TsEdit *sEdit2;
        TsLabel *sLabel2;
        TsEdit *sEdit3;
        TsLabel *sLabel3;
        TsBitBtn *sBitBtn1;
        TMemo *Memo1;
        TsLabel *sLabel4;
        TsLabel *sLabel5;
        TsEdit *sEdit4;
        TsLabel *sLabel6;
        TsEdit *sEdit6;
        TsLabel *sLabel8;
        TsBitBtn *sBitBtn2;
        TMemo *Memo2;
        TsLabel *sLabel9;
        TsLabel *sLabel10;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sLabel5Click(TObject *Sender);
        void __fastcall sLabel10Click(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRabin_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRabin_form *Rabin_form;
//---------------------------------------------------------------------------
#endif
