//---------------------------------------------------------------------------

#ifndef Unit_maalumotH
#define Unit_maalumotH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "sLabel.hpp"
#include "acPNG.hpp"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tmalumot : public TForm
{
__published:	// IDE-managed Components
        TsLabel *sLabel1;
        TsLabel *sLabel2;
        TsLabel *sLabel3;
        TsLabel *sLabel4;
        TImage *Image1;
        TsLabel *sLabel5;
        TsLabel *sLabel6;
        TsLabel *sLabel7;
        TsLabel *sLabel8;
        TImage *Image2;
private:	// User declarations
public:		// User declarations
        __fastcall Tmalumot(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tmalumot *malumot;
//---------------------------------------------------------------------------
#endif
