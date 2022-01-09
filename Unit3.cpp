//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit14.h"
#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sEdit"
#pragma link "sBitBtn"
#pragma link "sLabel"
#pragma resource "*.dfm"
TRyukzak_form *Ryukzak_form;
//---------------------------------------------------------------------------
__fastcall TRyukzak_form::TRyukzak_form(TComponent* Owner)
        : TForm(Owner)
{
}

int ikkilikdan_onlikka_otkaz(String s)
{      int n=0;
for(int i=1;i<=s.Length();i++)
 n=n+((int)s[i]-48)*pow(2,s.Length()-i);
 return n;
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

bool ketma_ketlik_qoidasi_tekshir()
{
int s=0,i;
s=StrToInt(Ryukzak_form->StringGrid1->Cells[0][0]);
if(s<2)return false;
for(i=1;i<Ryukzak_form->StringGrid1->ColCount;i++)
        {
        if(s<StrToInt(Ryukzak_form->StringGrid1->Cells[i][0]))
        s+=StrToInt(Ryukzak_form->StringGrid1->Cells[i][0]);
        else return false;
        }
return true;
}
bool ozaro_tub(int n,int m)
{
for(int i=2;i<=m && i<=n ;i++)
if(m%i==0 && n%i==0)return false;
return true;
}

bool tub(int n)
{
for(int i=2;i<=n;i++)
if(n%i==0)return false;
return true;
}
String ortiqcha_n_ta_boshidan_olib_tashla(int n,String m)
{
int i;
String natija;
for(i=n+1;i<=m.Length();i++)
natija+=m[i];
return natija;
}
int eylorr(int m)
{
 int n,i;
 n=m;
 for(i=2;i<=m;i++)
 if(m%i==0 && tub(i)){n=n/i;n=n*(i-1);}
  return n;
}
String matnni_teskarilat(String m)
{
String n;
for(int i=m.Length();i>0;i--)
n+=m[i];
return n;
}

//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Ryukzak_form=NULL;
Assimmetrik_form->Show();

}
//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::Label10Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::sBitBtn1Click(TObject *Sender)
{
if(StringGrid1->ColCount==1)return;
StringGrid1->ColCount--;
Label2->Caption=IntToStr(StrToInt(Label2->Caption)-1);
}
//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::sBitBtn2Click(TObject *Sender)
{
StringGrid1->ColCount++;
Label2->Caption=IntToStr(StrToInt(Label2->Caption)+1);

}
//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::sBitBtn3Click(TObject *Sender)
{
if(!ketma_ketlik_qoidasi_tekshir())
{
ShowMessage("Ketma ketlik xato");
return;
}
int s=0,i,j;
String ketma_ketlik;
for(i=0;i<StringGrid1->ColCount;i++)
{
s+=StrToInt(StringGrid1->Cells[i][0]);
ketma_ketlik+=StringGrid1->Cells[i][0]+" ";
}
int q,r;
q=StrToInt(Edit1->Text);
r=StrToInt(Edit2->Text);
if(q<=s)
{
ShowMessage("q qiymatini "+(String)s+" dan katta oling");
return;
}
if(!ozaro_tub(q,r))
{
ShowMessage((String)q+" va "+(String)r+" lar o'zaro tub emas");
return;
}
Memo1->Lines->Add("-------------Shifrlash boshlandi-------------");
Memo1->Lines->Add("");
Memo1->Lines->Add("Bizga berilgan qiymatlar:");
Memo1->Lines->Add("");

Memo1->Lines->Add("O'suvchi ketma-ketlik "+ketma_ketlik);
Memo1->Lines->Add("q="+(String)q);
Memo1->Lines->Add("r="+(String)r);
String matn,bitlar;
matn=Edit3->Text;
Memo1->Lines->Add("Matn="+matn);
int l,*b;
l=StringGrid1->ColCount;
int qoshimcha=0;
aql:
if((matn.Length()*8+qoshimcha)%l!=0){qoshimcha++;goto aql;}
if(qoshimcha!=0)
{
Memo1->Lines->Add("Diqqat! Bit uzunligi "+(String)(matn.Length()*8)+" ta uni "+(String)(StringGrid1->ColCount)+" tadan bo'lsam "+(String)qoshimcha+" ta bit yetmay qoladi.");
Memo1->Lines->Add("Shuning uchun men "+(String)qoshimcha+" ta 0 ni bitlar boshiga qo'shib olyabman");
}
for(i=0;i<qoshimcha;i++)
bitlar+="0";

Memo1->Lines->Add("");
for(i=1;i<=matn.Length();i++)
bitlar+=ikkilik_sanoq_sistemaga_otkaz(matn[i]);
Memo1->Lines->Add("Matnni bit ko'rinishi = "+bitlar);

Memo1->Lines->Add("");
Memo1->Lines->Add("Normal ketma ketlik hosil qilinish jarayoni:");
Memo1->Lines->Add("");

b=new int [l];
for(i=0;i<l;i++)
        {
        b[i]=(StrToInt(StringGrid1->Cells[i][0])*r)%q;
        Memo1->Lines->Add("b["+(String)(i+1)+"]=("+StringGrid1->Cells[i][0]+"*"+(String)r+")mod"+(String)q+"="+(String)b[i]);
        }

int *c,k=0,sh_soni;
sh_soni=bitlar.Length()/l;
c=new int [sh_soni];
String ishlanish,natija;
Memo1->Lines->Add("");
Memo1->Lines->Add("Matnni bloklarga ajratish jarayoni:");
Memo1->Lines->Add("");

for(i=0;i<sh_soni;i++)
{
ishlanish="";
for(j=0;j<l;j++)
ishlanish+=bitlar[++k];
Memo1->Lines->Add("M["+(String)(i+1)+"]="+ishlanish);

}
Memo1->Lines->Add("");
Memo1->Lines->Add("Shifr raqamlarni topish jarayoni:");
Memo1->Lines->Add("");
k=0;
for(i=0;i<sh_soni;i++)
{       s=0;
         ishlanish="c["+(String)(i+1)+"]=(";
        for(j=0;j<l;j++){
        s+=StrToInt(bitlar[++k])*b[j];
        ishlanish+=(String)b[j]+"*"+bitlar[k];
        if(j!=l-1)
        ishlanish+="+";
        }
        s=s%q;
        ishlanish+=")mod"+(String)q+"="+(String)s;
        Memo1->Lines->Add(ishlanish);
        c[i]=s;
        natija+=(String)c[i];
        if(i!=sh_soni-1)
        natija+=",";
}

        Edit4->Text=natija;
        Memo1->Lines->Add("Shifr matn="+natija);
Memo1->Lines->Add("");
Memo1->Lines->Add("-------------Shifrlash yakunlandi-------------");
Memo1->Lines->Add("");
}
//---------------------------------------------------------------------------
void __fastcall TRyukzak_form::sBitBtn4Click(TObject *Sender)
{
if(Edit4->Text=="")
{
ShowMessage("Shifr matnni kiriting");
return;
}
if(!ketma_ketlik_qoidasi_tekshir())
{
ShowMessage("Ketma ketlik xato");
return;
}
int s=0,i,j;
String ketma_ketlik;
for(i=0;i<StringGrid1->ColCount;i++)
{
s+=StrToInt(StringGrid1->Cells[i][0]);
ketma_ketlik+=StringGrid1->Cells[i][0]+" ";
}
int q,r;
q=StrToInt(Edit1->Text);
r=StrToInt(Edit2->Text);
if(q<=s)
{
ShowMessage("q qiymatini "+(String)s+" dan katta oling");
return;
}
if(!ozaro_tub(q,r))
{
ShowMessage((String)q+" va "+(String)r+" lar o'zaro tub emas");
return;
}
Memo1->Lines->Add("-------------Deshifrlash boshlandi-------------");
Memo1->Lines->Add("");
Memo1->Lines->Add("Bizga berilgan qiymatlar:");
Memo1->Lines->Add("");

Memo1->Lines->Add("O'suvchi ketma-ketlik "+ketma_ketlik);
Memo1->Lines->Add("q="+(String)q);
Memo1->Lines->Add("r="+(String)r);
int r_teskari=1,teskari_daraja;
teskari_daraja=eylorr(q);
teskari_daraja--;
for(i=0;i<teskari_daraja;i++)
r_teskari=(r_teskari*r)%q;
Memo1->Lines->Add((String)r+" sonini "+(String)q+" ga teskarisi = "+(String)r_teskari);
        String shifr=Edit4->Text,ishlanishi;
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
        ishlanishi+=(String)C[k-1]+" ";
        son=0;
        }
   }
   son=son*10+(int)shifr[i]-48;
   C[k]=son;
   ishlanishi+=(String)C[k];
   Memo1->Lines->Add("Shifr matn = "+ishlanishi);
   Memo1->Lines->Add("");
   Memo1->Lines->Add(" 0 va 1 larni aniqlanish jarayoni:");
   Memo1->Lines->Add("");

   String bit_01,umumiy_bit;
   int *m=new int [vergul_soni+1];

    for(i=0;i<=vergul_soni;i++)
   {
      m[i]=(r_teskari*C[i])%q;
      son=m[i];
      bit_01="";
        for(j=StringGrid1->ColCount-1;j>=0;j--)
        {
        if(son>=StrToInt(StringGrid1->Cells[j][0]))
                {
                bit_01+="1";
                son-=StrToInt(StringGrid1->Cells[j][0]);
                }
        else
        bit_01+="0";
        }
      bit_01=matnni_teskarilat(bit_01);
      umumiy_bit+=bit_01;
      k=1;
     ishlanishi="M["+(String)(i+1)+"]=("+(String)r_teskari+"*"+(String)C[i]+")mod "+(String)q+"="+(String)m[i]+"=";
      for(j=0;j<StringGrid1->ColCount;j++)
        {ishlanishi+=StringGrid1->Cells[j][0]+"*"+bit_01[k++];
         if(j!=StringGrid1->ColCount-1)
         ishlanishi+="+";
         }
      Memo1->Lines->Add(ishlanishi+" M["+(String)(i+1)+"]="+bit_01);
   }

   Memo1->Lines->Add("Barcha M lar jamlanmasi="+umumiy_bit);
   int l,ortiqcha=0;
   l=umumiy_bit.Length();
   ortiqcha_top:
   if((l-ortiqcha)%8!=0){ortiqcha++; goto ortiqcha_top;}
   if(ortiqcha!=0)
   {
   Memo1->Lines->Add("Diqqat! Umumiya bitda ortiqcha "+(String)ortiqcha+" ta 0 qo'shilgan.Ularni olib tashlayman.");
   Memo1->Lines->Add(umumiy_bit);
   umumiy_bit=ortiqcha_n_ta_boshidan_olib_tashla(ortiqcha,umumiy_bit);
   Memo1->Lines->Add(umumiy_bit);
   }
Memo1->Lines->Add("");
Memo1->Lines->Add("Bitlarni harflarga aylantirish jarayoni:");
Memo1->Lines->Add("");
   k=0;
   String matn;
   for(i=0;i<(l-ortiqcha)/8;i++)
   {
     ishlanishi="";
     for(j=0;j<8;j++)
     ishlanishi+=umumiy_bit[++k];
     son=ikkilikdan_onlikka_otkaz(ishlanishi);
     Memo1->Lines->Add(ishlanishi+"="+(String)son+"="+(char)son);
     matn+=(char)son;
   }
    Memo1->Lines->Add("Matn="+matn);
    Edit3->Text=matn;
    Memo1->Lines->Add("-------------Deshifrlash yakunlandi-------------");
}
//---------------------------------------------------------------------------




