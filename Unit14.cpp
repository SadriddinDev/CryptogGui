//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit14.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sEdit"
#pragma link "sLabel"
#pragma link "sBitBtn"
#pragma resource "*.dfm"
TRSA_ *RSA_;
//---------------------------------------------------------------------------
__fastcall TRSA_::TRSA_(TComponent* Owner)
        : TForm(Owner)
{
}
bool tayyor;
int p,q,e,L;
 int orqtub(int n)
 {int i,j;  bool bor;
 for(i=n;i>1;i--){bor=true;for(j=2;j<i;j++)if(i%j==0)bor=false;
 if(bor)return i;
 }  return 0;
 }
int oldtub(int n)
 {int i,j;  bool bor;
 for(i=n;i<50000;i++){bor=true;for(j=2;j<i;j++)if(i%j==0)bor=false;
 if(bor)return i;
 } return 0;
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
String ikkilik_sanoq_sistemaga_otkaz_L_xonali(int son,int L)
{
int i,n;
String s;
for(i=0;i<L;i++)
s+="0";
for(i=0;i<L;i++)
{
n=son%2;
son=son/2;
if(n==0)
s[L-i]='0';
else s[L-i]='1';
}
return s;
}
int ikkilikdan_onlikka_otkaz(String s)
{      int n=0;
for(int i=1;i<=s.Length();i++)
 n=n+((int)s[i]-48)*pow(2,s.Length()-i);

 return n;
}

bool tub(int n)
{
for(int i=2;i<=n/2;i++)
if(n%i==0)return false;
return true;
}
bool ozaro_tub(int n,int m)
{
for(int i=2;i<=m && i<=n ;i++)
if(m%i==0 && n%i==0)return false;
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
void __fastcall TRSA_::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
RSA_=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sEdit1Change(TObject *Sender)
{
 try{
 p=StrToInt(sEdit1->Text);
 if(p>50000 || p<=0)return;
 if(tub(p))
 { sEdit2->Enabled=true;
 Yordam->Caption="";
 }else
 { tayyor=false;
 Yordam->Caption="Yordam:"+IntToStr(oldtub(p))+","+ IntToStr(orqtub(p));
 sEdit2->Enabled=false;
 sEdit3->Enabled=false;
 sEdit4->Enabled=false;
 }
  }
 catch(EConvertError &)
 { tayyor=false;
 Yordam->Caption="Faqat son";
 tayyor=false;
 sEdit2->Enabled=false;
 sEdit3->Enabled=false;
 sEdit4->Enabled=false;
 return;
 }
}
//---------------------------------------------------------------------------
void __fastcall TRSA_::FormCreate(TObject *Sender)
{
tayyor=false;
}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sEdit2Change(TObject *Sender)
{
 try{
 q=StrToInt(sEdit2->Text);
 if(q>50000 || q<=0)return;
 if(tub(q))
 { sEdit3->Enabled=true;
 Yordam->Caption="";
 }else
 { tayyor=false;
 Yordam->Caption="Yordam:"+IntToStr(oldtub(q))+","+ IntToStr(orqtub(q));
 sEdit3->Enabled=false;
 sEdit4->Enabled=false;
 }

 }
 catch(EConvertError &)
 {  tayyor=false;
 Yordam->Caption="Faqat son";
 tayyor=false;
 sEdit3->Enabled=false;
 sEdit4->Enabled=false;
 return;
 }

}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sEdit3Change(TObject *Sender)
{
 try{
 e=StrToInt(sEdit3->Text);
 if(e>50000 || e<=0)return;
 if(ozaro_tub(e,(p-1)*(q-1)))
 { sEdit4->Enabled=true;
 Yordam->Caption="";
 }else
 { int i;  tayyor=false;
 for(i=e+1;i<i+1;i++)
 if(ozaro_tub(i,(p-1)*(q-1)))
 break;
 Yordam->Caption="Yordam:"+IntToStr(i);
  sEdit4->Enabled=false;
 }
  }
 catch(EConvertError &)
 {  tayyor=false;
 Yordam->Caption="Faqat son";
 tayyor=false;
 sEdit4->Enabled=false;
 return;
 }


}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sEdit4Change(TObject *Sender)
{
try{
L=StrToInt(sEdit4->Text);
        if(L<=5 || L>20)
        {
        sEdit5->Enabled=false;
        sEdit6->Enabled=false;
         Yordam->Caption="Xato";tayyor=false;
         return;
        }
sEdit5->Enabled=true;
sEdit6->Enabled=true;

tayyor=true;
}
catch(EConvertError &)
{
Yordam->Caption="Faqat son";
tayyor=false;
sEdit5->Enabled=false;
sEdit6->Enabled=false;
return;
}

}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sBitBtn1Click(TObject *Sender)
{
if(!tayyor)
{
ShowMessage("Qiymatlar to'liq emas.Avval ularni to'ldiring");
return;
}
int n=p*q;
String ff;
for(int i=1;i<=L;i++)
ff+="1";
if(ikkilikdan_onlikka_otkaz(ff)>=n)
{
ShowMessage("L bitni uzunligi katta.Hisoblashda hatolik sodir bo'lishi mumkin.\nL ni kichikriq oling");
return;
}

Memo1->Lines->Add("p="+(String)p);
Memo1->Lines->Add("q="+(String)q);
Memo1->Lines->Add("e="+(String)e);
Memo1->Lines->Add("Bit uzunligi="+(String)L);
Memo1->Lines->Add("n="+(String)n);

String matn=sEdit5->Text,ikkilik_jamlanma;
Memo1->Lines->Add("Matn="+matn);
int i,j,l=0;
qaytish: if((8*matn.Length()+l)%L!=0){l++;goto qaytish;}
if(l!=0)
Memo1->Lines->Add("Diqqat! Bit matnni uzunligi = "+(String)(matn.Length()*8)+" uni "+(String)L+" tadan bo'lsam "+(String)l+" ta hona yetmay qoladi.Shuning uchun men shuncha 0 ni bit matn boshiga qo'shib olyabman");
for(i=0;i<l;i++)
ikkilik_jamlanma+="0";

for(i=1;i<=matn.Length();i++)
{
ikkilik_jamlanma+=ikkilik_sanoq_sistemaga_otkaz(matn[i]);
Memo1->Lines->Add((String)i+"-harf ="+(String)matn[i]+"="+ikkilik_sanoq_sistemaga_otkaz(matn[i]));
}

Memo1->Lines->Add("Jami="+ikkilik_jamlanma);

Memo1->Lines->Add("Endi bit matnni "+(String)L+" tadan ajratib chiqamiz");

int soni,*M,k=1,c,i1;
String vaqtincha;
soni=(8*matn.Length()+l)/L;
 M=new int [soni];
 for(i=0;i<soni;i++)
 {   vaqtincha="";
        for(j=1;j<=L;j++)
                vaqtincha+=(String)ikkilik_jamlanma[k++];

       M[i]=ikkilikdan_onlikka_otkaz(vaqtincha);
       Memo1->Lines->Add("M["+(String)(i+1)+"]="+vaqtincha+" = "+M[i]);
       c=1;
       for(i1=1;i1<=e;i1++)
       c=(c*M[i])%n;
       if(c==0)c=n;
       M[i]=c;
 }   String s;
 for(i=1;i<=soni;i++)
  {   if(i!=1)s+=",";
 Memo1->Lines->Add("C["+(String)i+"]=M["+(String)i+"]^"+(String)e+"mod"+(String)n+"="+(String)M[i-1]);
 s+=(String)M[i-1];
  }
  sEdit6->Text=s;
  Memo1->Lines->Add("C="+s);
  Memo1->Lines->Add("--------------------------------------------------------------------------");

}
//---------------------------------------------------------------------------
void __fastcall TRSA_::Label2Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TRSA_::sBitBtn2Click(TObject *Sender)
{
if(!tayyor)
{
ShowMessage("Qiymatlar to'liq emas.Avval ularni to'ldiring");
return;
}
int n=p*q;
String ff;
for(int i=1;i<=L;i++)
ff+="1";
if(ikkilikdan_onlikka_otkaz(ff)>=n)
{
ShowMessage("L bitni uzunligi katta.Hisoblashda hatolik sodir bo'lishi mumkin.\nL ni kichikriq oling");
return;
}

Memo1->Lines->Add("p="+(String)p);
Memo1->Lines->Add("q="+(String)q);
Memo1->Lines->Add("e="+(String)e);
Memo1->Lines->Add("Bit uzunligi="+(String)L);
Memo1->Lines->Add("n="+(String)n);
String shifr;
int d,i,j,k,vergul_soni=0;
k=eylor((p-1)*(q-1));
--k; d=1;
for(i=1;i<=k;i++)
d=(d*e)%((p-1)*(q-1));
if(d==0)d=(p-1)*(q-1);
shifr=sEdit6->Text;
Memo1->Lines->Add("Shifr matn="+shifr);
Memo1->Lines->Add("d=(e^-1)mod((p-1)*(q-1))="+(String)d);

for(i=1;i<=shifr.Length();i++)
if(shifr[i]==',')vergul_soni++;
vergul_soni++;
int *C,*M;
C=new int [vergul_soni];
M=new int [vergul_soni];
int son=0; k=0;
for(i=1;i<=shifr.Length();i++)
{
if(shifr[i]==',')
{C[k++]=son;
son=0;}
        else
        {
        son=son*10+(int)shifr[i]-48;
        }
}
  C[k]=son;
   String jamlanma;
  for(i=0;i<vergul_soni;i++)
  {  son=1;
  for(j=0;j<d;j++)
  son=(son*C[i])%n;
  if(son==0)son=n;
  M[i]=son;
  Memo1->Lines->Add("M["+(String)(i+1)+"]=C^d mod n="+(String)M[i]);
  jamlanma+=ikkilik_sanoq_sistemaga_otkaz_L_xonali(M[i],L);
 Memo1->Lines->Add((String)M[i]+"="+ikkilik_sanoq_sistemaga_otkaz_L_xonali(M[i],L));
  }
 Memo1->Lines->Add("Jami="+jamlanma);
 int l=0;
 boshhh: if((jamlanma.Length()-l)%8!=0){l++;goto boshhh;}
 if(l!=0)
 Memo1->Lines->Add("Ortiqcha 0 larni olib tashlamoqdaman");
  String natija,idish;   k=0;
  for(i=l+1;i<=jamlanma.Length();i++)
  {
  idish+=jamlanma[i];
  k++;
  if(k==8)
  {
  k=0;
  Memo1->Lines->Add(idish+"="+ikkilikdan_onlikka_otkaz(idish)+"="+(char)ikkilikdan_onlikka_otkaz(idish));
  natija+=(char)ikkilikdan_onlikka_otkaz(idish);
  idish="";
  }
  }
   Memo1->Lines->Add("Matn="+natija);
   sEdit5->Text=natija;

}
//---------------------------------------------------------------------------
