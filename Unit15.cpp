//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit15.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sLabel"
#pragma link "acPNG"
#pragma link "sBitBtn"
#pragma link "sEdit"
#pragma resource "*.dfm"
TEyler_form *Eyler_form;
//---------------------------------------------------------------------------
__fastcall TEyler_form::TEyler_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEyler_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Eyler_form=NULL;
}
//---------------------------------------------------------------------------
bool tub(int n)
{
for(int i=2;i<=n/2;i++)
if(n%i==0)return false;
return true;
}

//---------------------------------------------------------------------------
void __fastcall TEyler_form::sBitBtn1Click(TObject *Sender)
{

try{int m,n,i;
  m=StrToInt(sEdit1->Text);
  n=m;
  String boluvchilari;
 for(i=2;i<=m;i++)
 if(m%i==0 && tub(i)){n=n/i;n=n*(i-1);boluvchilari+=(String)i+"  ";}
 sEdit2->Text=(String)n;
 sEdit3->Text=boluvchilari;
 }
 catch(EConvertError &)
 {
 ShowMessage("Faqat son kiriting");
 return;
 }


}
//---------------------------------------------------------------------------
