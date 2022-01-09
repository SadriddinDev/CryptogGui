//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit12.h"
#include "Unit1.h"
#include "Unit10.h"
#include "Unit13.h"
#include "Unit3.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sBitBtn"
#pragma link "sEdit"
#pragma link "sLabel"
#pragma link "sPanel"
#pragma resource "*.dfm"
TEl_Gamal *El_Gamal;
//---------------------------------------------------------------------------
__fastcall TEl_Gamal::TEl_Gamal(TComponent* Owner)
        : TForm(Owner)
{
}
 String ikkilikka_n_xona_10likdan_otkaz(int n,int M)
 {
 String s,natija;
 for(int i=1;i<=n;i++)
 {s+=(String)(M%2);
 M=M/2;}
 for(int i=1;i<=n;i++)
 natija+=(String)s[n-i+1];
 return natija;
 }

 int orqtub(int n)
 {int i,j;  bool bor;
 for(i=n;i>1;i--){bor=true;for(j=2;j<i;j++)if(i%j==0)bor=false;
 if(bor)return i;
 }  return 0;
 }
int oldtub(int n)
 {int i,j;  bool bor;
 for(i=n;i<10000;i++){bor=true;for(j=2;j<i;j++)if(i%j==0)bor=false;
 if(bor)return i;
 } return 0;
 }

bool tup(int son)
{
int i;
for(i=2;i<son/2;i++)
if(son%i==0)return false;
return true;
}
String ikkilik_sanoq_sistemaga_otkaz(char c)
{
int i,n,k;
String s="12345678";
k=(int)c;
for(i=1;i<=8;i++)
{
n=k%2;
k=k/2;
if(n==0)
s[9-i]='0';
else s[9-i]='1';
}
return s;
}
int ikkilikdan_onlikka_otkaz(String s)
{      int n=0;
for(int i=1;i<=s.Length();i++)
 n=n+((int)s[i]-48)*pow(2,s.Length()-i);

 return n;
}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
El_Gamal=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::sLabel9Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::sBitBtn1Click(TObject *Sender)
{
sPanel1->Visible=true;
sPanel2->Visible=false;
sBitBtn1->Enabled=false;
sBitBtn2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::sBitBtn2Click(TObject *Sender)
{
sPanel1->Visible=false;
sPanel2->Visible=true;
sBitBtn2->Enabled=false;
sBitBtn1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::sBitBtn3Click(TObject *Sender)
{

sLabel6->Caption="";

 if((sEdit1->Text=="") || (sEdit2->Text=="") || (sEdit3->Text=="") ||(sEdit4->Text=="") || (sEdit5->Text==""))
  {ShowMessage("Qiymatlarni kiriting!"); return;}
  int p,g,x,k;
  p=StrToInt(sEdit2->Text);
  g=StrToInt(sEdit3->Text);
  x=StrToInt(sEdit4->Text);
  k=StrToInt(sEdit5->Text);
  if(!tup(p))
  {  sLabel6->Caption= IntToStr(oldtub(p))+","+ IntToStr(orqtub(p));
  return;
  }if(!(x<p-1)|| !(g<p))
  {
  ShowMessage("G va X da xatolik bor"); return;}
  String s,ishlanishi,ikkilikda_korinish,jamlangan="";
  s=sEdit1->Text;
  Memo1->Lines->Add("Matn = "+s);

  int i , j , l , matn_uzunlik , hlog , z=0;

  matn_uzunlik=s.Length();
  for(i=1;i<=matn_uzunlik;i++)
        {
        ikkilikda_korinish+=ikkilik_sanoq_sistemaga_otkaz(s[i]);
        Memo1->Lines->Add((String)i+") "+(String)s[i]+" -> "+(String)((int)s[i])+" -> " + ikkilik_sanoq_sistemaga_otkaz(s[i]));
        }
  hlog=log(p)/(log(2));
  l=0;

  ii: if((l+8*s.Length())%hlog!=0){l++;goto ii;}
  for(i=1;i<=l;i++)jamlangan+='0';
  jamlangan+=ikkilikda_korinish;
  int *M=new int [jamlangan.Length()/hlog],n;
  if(l>0)
  Memo1->Lines->Add("Diqqat!!! Matnning uzunligi "+(String)(jamlangan.Length()-l)+" ta uni "+(String)hlog+" tadan qilib ajratib olsak bizga "+(String)l +" ta hona yetishmaydi.Shuning uchun men "+(String)l +" ta 0 ni matn boshiga qo'shib olmoqdaman.");
   Memo1->Lines->Add("Umumiy jamlanmasi");
  Memo1->Lines->Add(jamlangan);
  String vaqtincha,natija;
  n=jamlangan.Length()/hlog;
  Memo1->Lines->Add("Matnni "+(String)hlog + " tadan qilib ajratib M[i] larga o'zlashtiramiz");
  for(i=0;i<n;i++)
  {     vaqtincha="";
        for(j=0;j<hlog;j++)
        vaqtincha+=jamlangan[i*hlog+j+1];
        M[i]=ikkilikdan_onlikka_otkaz(vaqtincha);
        Memo1->Lines->Add("M["+(String)(i+1)+"]= "+vaqtincha+ "(2) = "+M[i]+" (10)");
  }
  int y=1,a=1;
  for(i=1;i<=x;i++) y=(y*g)%p;   if(y==0)y=p;
  Memo1->Lines->Add("y=(g^x) mod p =("+(String)g+"^"+(String)x+") mod "+(String)p+"="+(String)y);
  for(i=1;i<=k;i++) a=(a*g)%p;   if(a==0)a=p;
  Memo1->Lines->Add("a=(g^k) mod p =("+(String)g+"^"+(String)k+") mod "+(String)p+"="+(String)a);
  natija=(String)a;
  int *b=new int [n];
  for(i=0;i<n;i++)
  {
  natija+=",";
   b[i]=M[i];
         for(j=0;j<k;j++)
             b[i]=(b[i]*y)%p;
                 if(b[i]==0)b[i]=p;
   natija+=(String)b[i];
    Memo1->Lines->Add("b["+(String)(i+1)+"]=(y^k * M["+(String)(i+1)+"]) mod p =("+(String)y+"^"+(String)k+" * "+(String)M[i]+") mod "+(String)p+"="+(String)b[i]);
   }
   sEdit6->Text=natija;
   Memo1->Lines->Add("Shifr matn="+natija);
   Memo1->Lines->Add("---------------------------------------------------------");

}
//---------------------------------------------------------------------------
void __fastcall TEl_Gamal::sBitBtn4Click(TObject *Sender)
{
  sLabel15->Caption="";
  String ishlanish;
  if((sEdit7->Text=="") || (sEdit8->Text=="") || (sEdit10->Text==""))
  {ShowMessage("Qiymatlarni kiriting!"); return;}
  int p,x;
  p=StrToInt(sEdit8->Text);
  x=StrToInt(sEdit10->Text);
  if(!tup(p))
  {  sLabel15->Caption= IntToStr(oldtub(p))+","+ IntToStr(orqtub(p));
  return;
  }
  int i , vergul_soni=0 , a =-1;
  String s;
  s=sEdit7->Text;
  Memo1->Lines->Add("Shifr="+s);
  s+=".";
  for(i=1;i<=s.Length();i++)
  if(s[i]==',')vergul_soni++;
   int *b=new int [vergul_soni],son=0,l=0;

          for(i=0;i<s.Length()-1;i++)
             { son=son*10+(int)s[i+1]-48;
               if(s[i+2]==','||i==s.Length()-1){
               if(a==-1){a=son;Memo1->Lines->Add("a="+(String)a);}
                  else {b[l++]=son;Memo1->Lines->Add("b["+(String)l+"]="+(String)b[l-1]);} son=0;i++;
                                              }
               }
               b[l]=son;Memo1->Lines->Add("b["+(String)l+"]="+(String)b[l]);
               int *M=new int [vergul_soni];
     int j , nat=1,a_1,honalar_soni=log(p)/log(2);
     for(j=1;j<=(p-2)*x;j++)nat=(nat*a)%p;if(nat==0)nat=p;
                a_1=nat;
     Memo1->Lines->Add("((a^-1)^x)mod p = "+(String)a_1);
      String jamlanma;
     for(i=0;i<vergul_soni;i++) {M[i]=(b[i]*a_1)%p;if(M[i]==0)M[i]=p;

    jamlanma+=ikkilikka_n_xona_10likdan_otkaz(honalar_soni,M[i]);

     Memo1->Lines->Add("M["+(String)(i+1)+"]=(b["+(String)(i+1)+"] * (a^-1)^x )mod p=("+(String)b[i]+" * "+(String)a_1 +")mod "+(String)p+"="+(String)M[i]+" --> "+ikkilikka_n_xona_10likdan_otkaz(honalar_soni,M[i]));
             }
     Memo1->Lines->Add(jamlanma);
     l=jamlanma.Length();
     j=l%8;   String bolish_8tadan,natija;
     if(j!=0)
     {Memo1->Lines->Add((String)j+" ta ortiqcha 0 ni boshidan olib tashlaymabman!");
     }
     Memo1->Lines->Add("Bitlarni 8 tadan bo'lib chiqamiz");
     ishlanish="";
     for(int i1=j+1;i1<=jamlanma.Length();i1++)
     {
     if((i1-j-1)%8==0 && i1!=j+1)ishlanish+=",";
     ishlanish+=(String)jamlanma[i1];
     }
     Memo1->Lines->Add(ishlanish);
     for(i=j+1;i<=jamlanma.Length()+1;i++)
     {
     if(bolish_8tadan.Length()==8)
     {
       Memo1->Lines->Add(bolish_8tadan+" -->"+(String)ikkilikdan_onlikka_otkaz(bolish_8tadan)+" -->"+(char)(ikkilikdan_onlikka_otkaz(bolish_8tadan)));
       natija+=(char)(ikkilikdan_onlikka_otkaz(bolish_8tadan));
       if(i==jamlanma.Length()+1)goto tugat;
       bolish_8tadan=(String)jamlanma[i];

     }
     else bolish_8tadan+=(String)jamlanma[i];
     }
     tugat:
     sEdit12->Text=natija;
     Memo1->Lines->Add("Matn="+natija);
     Memo1->Lines->Add("---------------------------------------------------------");

}
//---------------------------------------------------------------------------

