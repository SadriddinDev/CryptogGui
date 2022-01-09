//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "sBitBtn.hpp"
#include "sPanel.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class TSezar_form : public TForm
{
__published:	// IDE-managed Components
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TEdit *Edit1;
        TLabel *Label1;
        TEdit *Edit3;
        TLabel *Label2;
        TButton *Button1;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TStringGrid *StringGrid1;
        TLabel *Label5;
        TMemo *Memo1;
        TLabel *Label6;
        TLabel *Label7;
        TsPanel *sPanel1;
        TsPanel *sPanel2;
        TsBitBtn *sBitBtn1;
        TsBitBtn *sBitBtn2;
        TsLabel *sLabel12;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall sBitBtn1Click(TObject *Sender);
        void __fastcall sBitBtn2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TSezar_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSezar_form *Sezar_form;
//---------------------------------------------------------------------------
#endif
