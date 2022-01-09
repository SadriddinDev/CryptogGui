//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "acPNG.hpp"
#include <ExtCtrls.hpp>
#include "sPanel.hpp"
#include "sBitBtn.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TSimmetrik_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TsPanel *sPanel1;
        TsPanel *sPanel2;
        TPopupMenu *PopupMenu1;
        TMenuItem *Nazariytushuncha1;
        TMenuItem *Dastur1;
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall Label3Click(TObject *Sender);
        void __fastcall Label4Click(TObject *Sender);
        void __fastcall Label5Click(TObject *Sender);
        void __fastcall Label6Click(TObject *Sender);
        void __fastcall Label7Click(TObject *Sender);
        void __fastcall Label8Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Dastur1Click(TObject *Sender);
        void __fastcall Nazariytushuncha1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSimmetrik_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSimmetrik_form *Simmetrik_form;
//---------------------------------------------------------------------------
#endif
