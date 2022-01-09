//---------------------------------------------------------------------------

#ifndef Unit12H
#define Unit12H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sBitBtn.hpp"
#include "sEdit.hpp"
#include "sLabel.hpp"
#include "sPanel.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TEl_Gamal : public TForm
{
__published:	// IDE-managed Components
        TsBitBtn *sBitBtn1;
        TsBitBtn *sBitBtn2;
        TsPanel *sPanel1;
        TsEdit *sEdit1;
        TsLabel *sLabel1;
        TsBitBtn *sBitBtn3;
        TsEdit *sEdit2;
        TsEdit *sEdit3;
        TsEdit *sEdit4;
        TsEdit *sEdit5;
        TsLabel *sLabel2;
        TsLabel *sLabel3;
        TsLabel *sLabel4;
        TsLabel *sLabel5;
        TsLabel *sLabel6;
        TsEdit *sEdit6;
        TsLabel *sLabel7;
        TMemo *Memo1;
        TsLabel *sLabel8;
        TsLabel *sLabel9;
        TsPanel *sPanel2;
        TsLabel *sLabel11;
        TsLabel *sLabel13;
        TsLabel *sLabel15;
        TsLabel *sLabel16;
        TsEdit *sEdit7;
        TsBitBtn *sBitBtn4;
        TsEdit *sEdit8;
        TsEdit *sEdit10;
        TsEdit *sEdit12;
        TsLabel *sLabel10;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sLabel9Click(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
        void __fastcall sBitBtn3Click(TObject *Sender);
        void __fastcall sBitBtn4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEl_Gamal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEl_Gamal *El_Gamal;
//---------------------------------------------------------------------------
#endif
