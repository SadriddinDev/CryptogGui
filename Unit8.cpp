//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sPanel"
#pragma link "sLabel"
#pragma resource "*.dfm"
Tsezar_affin_form *sezar_affin_form;
//---------------------------------------------------------------------------
__fastcall Tsezar_affin_form::Tsezar_affin_form(TComponent* Owner)
        : TForm(Owner)
{
}
int turgan_orni(String s)
{
for(int i=0;i<sezar_affin_form->StringGrid1->ColCount;i++)
if(s==sezar_affin_form->StringGrid1->Cells[i][1])return i+1;
return 0;
}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
sezar_affin_form=NULL;
}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::FormCreate(TObject *Sender)
{
Label7->Caption="26";
for(int i=0;i<StringGrid1->ColCount;i++)
StringGrid1->Cells[i][0]=i+1;
for(int i=0;i<26;i++)
StringGrid1->Cells[i][1]=(char)(i+65);

}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::SpeedButton1Click(TObject *Sender)
{
Label7->Caption=IntToStr(StrToInt(Label7->Caption)+1);
StringGrid1->ColCount+=1;
StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount;
}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::SpeedButton2Click(TObject *Sender)
{
Label7->Caption=IntToStr(StrToInt(Label7->Caption)-1);
StringGrid1->ColCount-=1;
}
bool ozaro_tub(int a,int b)
{
for(int i=2;i<=a;i++)
if(a%i==0 && b%i==0)return false;
return true;
}
bool tub(int n)
{
for(int i=2;i<n;i++)
if(n%i==0)return false;
return true;
}
int eylor(int m)
{
 int n,i;
 n=m;
 for(i=2;i<m;i++)
 if(m%i==0 && tub(i)){n=n/i;n=n*(i-1);}
 return n;

}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::Button1Click(TObject *Sender)
{
String matn,s,natija;
int a,b,i,j,n,a_1;
matn=Edit1->Text;
try{
a=StrToInt(Edit2->Text);
b=StrToInt(Edit4->Text);
}
catch(EConvertError &)
{
ShowMessage("a va b larga faqat raqam kiriting"); return;
}
if(!ozaro_tub(a,StringGrid1->ColCount))
{
ShowMessage("a va m lar ozaro tub emas"); return;
}
n=StringGrid1->ColCount;
if(b>=n)
{
ShowMessage("b m dan kichik bo'lishi kerak");
return;
}
if(RadioButton1->Checked)s="Matn="+matn;
else s="Shifr="+matn;
Memo1->Lines->Add(s);
s="";
a_1=1;
for(j=1;j<=eylor(n)-1;j++)a_1=(a*a_1)%n;
if(a_1==0)a_1=n;
for(i=1;i<=matn.Length();i++)
        {
            if(RadioButton1->Checked)
            {s="C["+IntToStr(i)+"]=("+(String)a+"*"+turgan_orni(matn[i])+"+"+(String)b+")mod"+IntToStr(n)+"=";
            j=(a*turgan_orni(matn[i])+b)%n; }
            else
            {
             s="M["+IntToStr(i)+"]=(("+turgan_orni(matn[i])+"-"+b+")*"+a_1+")mod"+n+"=";
             j=((turgan_orni(matn[i])-b)*a_1)%n;
             hhhh:if(j<0){j+=n; goto hhhh;}
             }
            if(j==0)j=n;
            s+=(String)j;
            s+="--->>\t";
            natija+=StringGrid1->Cells[j-1][1];
            s+=StringGrid1->Cells[j-1][1];
            Memo1->Lines->Add(s);
          }
Edit3->Text=natija;
Memo1->Lines->Add("Natija = "+natija);
}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::RadioButton1Click(TObject *Sender)
{
Label1->Caption="M=";
Label2->Caption="C=";

}
//---------------------------------------------------------------------------
void __fastcall Tsezar_affin_form::RadioButton2Click(TObject *Sender)
{
Label2->Caption="M=";
Label1->Caption="C=";

}
//---------------------------------------------------------------------------
