//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
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
class Tsehrli_kv : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TStringGrid *S;
        TStringGrid *M;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TsPanel *sPanel1;
        TsLabel *sLabel12;
         void __fastcall Edit1Change(TObject *Sender);
        void __fastcall kvadrat_toldir_toq(int olcham);
        void __fastcall maydon_sozlash();
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Edit2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tsehrli_kv(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsehrli_kv *sehrli_kv;
//---------------------------------------------------------------------------
#endif
