//---------------------------------------------------------------------------

#ifndef Unit10H
#define Unit10H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "sPanel.hpp"
#include "sLabel.hpp"
//---------------------------------------------------------------------------
class TVijener_form : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label9;
        TEdit *Edit3;
        TMemo *Memo1;
        TLabel *Label5;
        TLabel *Label10;
        TLabel *Label11;
        TsPanel *sPanel1;
        TsLabel *sLabel12;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Label11Click(TObject *Sender);
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall Label3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TVijener_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVijener_form *Vijener_form;
//---------------------------------------------------------------------------
#endif
