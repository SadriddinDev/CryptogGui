//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "sPanel.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TAssimmetrik_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TsPanel *sPanel1;
        TsPanel *sPanel2;
        TPopupMenu *PopupMenu1;
        TMenuItem *Nazariymalumot1;
        TMenuItem *Dastur1;
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall Label6Click(TObject *Sender);
        void __fastcall Label3Click(TObject *Sender);
        void __fastcall Label4Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Label5Click(TObject *Sender);
        void __fastcall Dastur1Click(TObject *Sender);
        void __fastcall Nazariymalumot1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAssimmetrik_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAssimmetrik_form *Assimmetrik_form;
//---------------------------------------------------------------------------
#endif
