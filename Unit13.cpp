//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit13.h"
#include "Unit6.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sComboBox"
#pragma link "sEdit"
#pragma link "sLabel"
#pragma resource "*.dfm"
TOrin_form *Orin_form;
//---------------------------------------------------------------------------
__fastcall TOrin_form::TOrin_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TOrin_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Orin_form=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TOrin_form::sEdit1Change(TObject *Sender)
{
     sComboBox1->Items->Clear();
        String s;
        int n,i,j,k;
        s=sEdit1->Text;
        n=s.Length();
        k=0;
        for(i=2;i<n;i++)if(n%i==0)
        sComboBox1->Items->Add(IntToStr(n/i)+" / "+IntToStr(i));
        s=NULL;
        n=i=NULL;
        k=j=NULL;

}
//---------------------------------------------------------------------------
void __fastcall TOrin_form::sComboBox1Change(TObject *Sender)
{
if(sComboBox1->Items->Strings[sComboBox1->ItemIndex]=="")
 return;
 String s,mm;
 mm=sEdit1->Text;
 int l,i,j,satr,ustun;
 s=sComboBox1->Items->Strings[sComboBox1->ItemIndex];
 l=s.Length();
 l=sEdit1->Text.Length();
 satr=0;   i=1;
 while(s[i]!=' ')
 {
 satr*=10;
 satr+=StrToInt((String)s[i]); i++;
 }
 ustun=sEdit1->Text.Length()/satr;
 jadval->ColCount=ustun+1;
 jadval->RowCount=satr+1;
 jadval->Width=ustun*36+56;
 jadval->Height=satr*32+56;
 for(i=1;i<=ustun;i++) jadval->Cells[i][0]=IntToStr(i);
 for(i=1;i<=satr;i++)  jadval->Cells[0][i]=IntToStr(i);
  l=1;
  for(j=1;j<=ustun;j++) for(i=1;i<=satr;i++)
     jadval->Cells[j][i]=mm[l++];
      s="";
     for(i=1;i<=satr;i++)for(j=1;j<=ustun;j++)
     s+=jadval->Cells[j][i];
     sEdit2->Text=s;
 }
//---------------------------------------------------------------------------


