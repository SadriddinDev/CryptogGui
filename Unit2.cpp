//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sBitBtn"
#pragma link "sEdit"
#pragma link "sLabel"
#pragma resource "*.dfm"
TRabin_form *Rabin_form;
//---------------------------------------------------------------------------
__fastcall TRabin_form::TRabin_form(TComponent* Owner)
        : TForm(Owner)
{
}
bool tub(int n)
{
for(int i=2;i<n;i++)
if(n%i==0)return false;
return true;
}
 bool tup_3(int son)
{
int i;
for(i=2;i<son/2;i++)
if(son%i==0)return false;
if(son%4==3)return true;
else return false;
}

//---------------------------------------------------------------------------
void __fastcall TRabin_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Rabin_form=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TRabin_form::sLabel5Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TRabin_form::sLabel10Click(TObject *Sender)
{
Memo2->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TRabin_form::sBitBtn1Click(TObject *Sender)
{
if(sEdit1->Text=="" || sEdit2->Text=="" || sEdit3->Text=="")
{
ShowMessage("Qiymatlar to'liq emas");
return;
}

int p,q;
p=StrToInt(sEdit1->Text);
q=StrToInt(sEdit2->Text);
if(!(tup_3(p)&&tup_3(q)))
{
ShowMessage("P va Q xato kiritildi");
return;
}
String m=sEdit3->Text,natija;
Memo1->Lines->Add("p="+(String)p);
Memo1->Lines->Add("q="+(String)q);
Memo1->Lines->Add("Matn="+m);
Memo1->Lines->Add("n="+(String)(p*q));

int n, son;
n=p*q;
for(int i=1;i<=m.Length();i++)
{
son=1;
son=((int)m[i]*(int)m[i])%n;
if(son==0)son=n;
Memo1->Lines->Add("C["+(String)i+"]=("+(String)((int)m[i])+"*"+(String)((int)m[i])+")mod"+(String)n+"="+(String)son);
natija+=(String)son;
if(i!=m.Length())natija+=",";
}
Memo1->Lines->Add("Shifr matn="+natija);
}
//---------------------------------------------------------------------------
void __fastcall TRabin_form::sBitBtn2Click(TObject *Sender)
{
int n,i,p=0,q,a,b;
n=StrToInt(sEdit4->Text);
 for(i=3;i<=n/3;i+=4)

   if((n/i)%4==3 && tub(n/i) && tub(i)&& n%i==0)
   { p=i; q=n/i;}
   if(p==0)
   {
   ShowMessage("N xato kiritildi");
   return;
   }
   Memo2->Lines->Add("p="+(String)p);
   Memo2->Lines->Add("q="+(String)q);
   String shifr,natija;
   shifr=sEdit6->Text;
   Memo2->Lines->Add("Shifr="+shifr);
   int vergul_soni=0;
   for(i=1;i<=shifr.Length();i++)
   if(shifr[i]==',')vergul_soni++;

   int *C=new int [vergul_soni+1];
   int son=0,k=0;
   for(i=1;i<shifr.Length();i++)
   {
   son=son*10+(int)shifr[i]-48;
   if(shifr[i+1]==',')
        {
        C[k++]=son;i++;
        Memo2->Lines->Add((String)k+"->>"+(String)C[k-1]);
        son=0;

        }
   } son=son*10+(int)shifr[i]-48;
   C[k]=son;
    Memo2->Lines->Add((String)(k+1)+"->>"+(String)C[k]);
    int j,m1,m2,m3,m4,M1,M2,M3,M4;
    a=1;
    for(j=1;j<=q-2;j++)
    a=(a*p)%q;
     if(a==0)a=q;
     a=a*p;
   b=1;
    for(j=1;j<=p-2;j++)
    b=(b*q)%p;
     if(b==0)b=p;
     b=b*q;
     Memo2->Lines->Add("a="+(String)a);
     Memo2->Lines->Add("b="+(String)b);
    for(i=0;i<vergul_soni+1;i++)
    {
      m1=1;
      for(j=1;j<=(p+1)/4;j++)m1=(m1*C[i])%p;
      if(m1==0)m1=p;

      Memo2->Lines->Add("m1="+(String)m1);

      m2=(p-m1)%p;
      if(m2==0)m2=p;

      Memo2->Lines->Add("m2="+(String)m2);

      m3=1;
      for(j=1;j<=(q+1)/4;j++)m3=(m3*C[i])%q;
      if(m3==0)m3=q;

      Memo2->Lines->Add("m3="+(String)m3);

      m4=(q-m3)%q;
      if(m4==0)m4=q;

      Memo2->Lines->Add("m4="+(String)m4);
      M1=(a*m3+b*m1)%n;
      if(M1==0)M1=n;
      if(M1<127)natija+=(char)M1;
      Memo2->Lines->Add((String)(i+1)+"-->> M1="+(String)M1);

      M2=(a*m4+b*m1)%n;
      if(M2==0)M2=n;
      if(M2<127 && M2!=M1)natija+=(char)M2;
      Memo2->Lines->Add((String)(i+1)+"-->> M2="+(String)M2);

      M3=(a*m3+b*m2)%n;
      if(M3==0)M3=n;
      if(M3<127 && M3!=M2 && M3!=M1)natija+=(char)M3;
      Memo2->Lines->Add((String)(i+1)+"-->> M3="+(String)M3);

      M4=(a*m4+b*m2)%n;
      if(M4==0)M4=n;
      if(M4<127 && M4!=M3 &&M4!=M2 && M4!= M1)natija+=(char)M4;
      Memo2->Lines->Add((String)(i+1)+"-->> M4="+(String)M4);
    }
    Memo2->Lines->Add("Natija="+natija);

}
//---------------------------------------------------------------------------
