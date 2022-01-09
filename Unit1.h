//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <MPlayer.hpp>
#include "acPNG.hpp"
#include "sPanel.hpp"
#include "sSkinManager.hpp"
#include "sLabel.hpp"
#include "sBitBtn.hpp"
#include "sEdit.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label7;
        TLabel *Label22;
        TImage *Image1;
        TLabel *Hotira;
        TLabel *Label2;
        TsSkinManager *sSkinManager1;
        TsPanel *sPanel1;
        TsLabel *sLabel1;
        TsPanel *sPanel2;
        TsEdit *sEdit1;
        TsLabel *sLabel2;
        TsBitBtn *sBitBtn1;
        TMainMenu *MainMenu1;
        TMenuItem *Dasturhaqidamalumot1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Label7Click(TObject *Sender);
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall Dasturhaqidamalumot1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
