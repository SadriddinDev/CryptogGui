//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sComboBox.hpp"
#include "sEdit.hpp"
#include "sLabel.hpp"
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TOrin_form : public TForm
{
__published:	// IDE-managed Components
        TsLabel *sLabel1;
        TsEdit *sEdit1;
        TsLabel *sLabel2;
        TsEdit *sEdit2;
        TsComboBox *sComboBox1;
        TsLabel *sLabel3;
        TStringGrid *jadval;
        TsLabel *sLabel12;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall sEdit1Change(TObject *Sender);
        void __fastcall sComboBox1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TOrin_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOrin_form *Orin_form;
//---------------------------------------------------------------------------
#endif
