//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "sPanel.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class Tsezar_affin_form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TEdit *Edit1;
        TEdit *Edit3;
        TButton *Button1;
        TEdit *Edit2;
        TLabel *Label4;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TLabel *Label6;
        TLabel *Label7;
        TMemo *Memo1;
        TLabel *Label5;
        TStringGrid *StringGrid1;
        TEdit *Edit4;
        TLabel *Label8;
        TsPanel *sPanel1;
        TsPanel *sPanel2;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tsezar_affin_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsezar_affin_form *sezar_affin_form;
//---------------------------------------------------------------------------
#endif
