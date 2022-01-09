//---------------------------------------------------------------------------

#ifndef Unit14H
#define Unit14H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sEdit.hpp"
#include "sLabel.hpp"
#include "sBitBtn.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TRSA_ : public TForm
{
__published:	// IDE-managed Components
        TsEdit *sEdit1;
        TsLabel *sLabel1;
        TsEdit *sEdit2;
        TsLabel *sLabel2;
        TsEdit *sEdit3;
        TsLabel *sLabel3;
        TsEdit *sEdit4;
        TsLabel *sLabel4;
        TsEdit *sEdit5;
        TsLabel *sLabel5;
        TsLabel *Yordam;
        TsBitBtn *sBitBtn1;
        TMemo *Memo1;
        TLabel *Label1;
        TLabel *Label2;
        TsEdit *sEdit6;
        TsLabel *sLabel6;
        TsBitBtn *sBitBtn2;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sEdit1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall sEdit2Change(TObject *Sender);
        void __fastcall sEdit3Change(TObject *Sender);
        void __fastcall sEdit4Change(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TRSA_(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRSA_ *RSA_;
//---------------------------------------------------------------------------
#endif
