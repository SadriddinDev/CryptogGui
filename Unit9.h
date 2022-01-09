//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "sComboBox.hpp"
#include "sPanel.hpp"
#include "sBitBtn.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class Tuinston_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TStringGrid *SA;
        TLabel *Label3;
        TStringGrid *SB;
        TLabel *Label4;
        TMemo *Memo1;
        TLabel *Label5;
        TEdit *Edit3;
        TLabel *Label6;
        TEdit *Edit4;
        TLabel *Label7;
        TStringGrid *alifbo;
        TLabel *Label8;
        TLabel *Label9;
        TsPanel *sPanel1;
        TsPanel *sPanel2;
        TsComboBox *ComboBox1;
        TsComboBox *ComboBox2;
        TsBitBtn *BitBtn1;
        TsBitBtn *BitBtn2;
        TsLabel *sLabel12;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Label9Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sComboBox1Change(TObject *Sender);
        void __fastcall sComboBox2Change(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tuinston_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tuinston_form *uinston_form;
//---------------------------------------------------------------------------
#endif
