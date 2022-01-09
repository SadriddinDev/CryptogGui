//---------------------------------------------------------------------------

#ifndef Unit15H
#define Unit15H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sLabel.hpp"
#include "acPNG.hpp"
#include <ExtCtrls.hpp>
#include "sBitBtn.hpp"
#include "sEdit.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TEyler_form : public TForm
{
__published:	// IDE-managed Components
        TsLabel *sLabel1;
        TsLabel *sLabel2;
        TsLabel *sLabel3;
        TsLabel *sLabel4;
        TImage *Image1;
        TsLabel *sLabel5;
        TsEdit *sEdit1;
        TsLabel *sLabel6;
        TsBitBtn *sBitBtn1;
        TsEdit *sEdit2;
        TsLabel *sLabel7;
        TsEdit *sEdit3;
        TsLabel *sLabel8;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sBitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEyler_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEyler_form *Eyler_form;
//---------------------------------------------------------------------------
#endif
