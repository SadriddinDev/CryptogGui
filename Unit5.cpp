//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sBitBtn"
#pragma link "sPanel"
#pragma link "sLabel"
#pragma resource "*.dfm"
TSezar_form *Sezar_form;
//---------------------------------------------------------------------------
__fastcall TSezar_form::TSezar_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TSezar_form::FormCreate(TObject *Sender)
{

for(int i=1;i<=StringGrid1->ColCount;i++)
{
StringGrid1->Cells[i-1][0]=(String)i;
StringGrid1->Cells[i-1][1]=(char)(i+64);
}
Label7->Caption="26";
}
//---------------------------------------------------------------------------
void __fastcall TSezar_form::Button1Click(TObject *Sender)
{
String s,n,matn;
s=Edit1->Text;
int mi,i,j,l,k;
try{
k=StrToInt(Edit2->Text);
}catch(EConvertError &)
{
ShowMessage("Kalit xato kiritildi");return;
}
if(RadioButton1->Checked)
matn="Matn="+s;
else
matn="Shifr="+s;
Memo1->Lines->Add(matn);  l=StringGrid1->ColCount;
for(i=1;i<=s.Length();i++)
{
for(j=0;j<StringGrid1->ColCount;j++)
if((String)s[i]==StringGrid1->Cells[j][1]){mi=j;break;}
mi++; matn=IntToStr(i)+")"+s[i]+"-o'rni="+mi;
if(RadioButton1->Checked){mi=(mi+k)%l;if(mi==0)mi=l;}
else{mi=(l+mi-k)%l;if(mi==0)mi=l;}
Memo1->Lines->Add(matn);
}
for(i=1;i<=s.Length();i++)
{for(j=0;j<StringGrid1->ColCount;j++)
if((String)s[i]==StringGrid1->Cells[j][1]){mi=j;break;}
mi++;
if(RadioButton1->Checked){
matn="C["+(String)i+"]=("+IntToStr(mi) + "+" +(String)k+")mod"+l+"=";
mi=(mi+k)%l;
}
else {matn="M["+(String)i+"]=("+IntToStr(l)+"+"+IntToStr(mi) + "-" +(String)k+")mod"+l+"=";
mi=(l+mi-k)%l;
jjj:if(mi<0){mi+=l;goto jjj;}
}
if(mi==0)mi=l;
matn+=(String)mi+" ->\t " + StringGrid1->Cells[mi-1][1];
n+=StringGrid1->Cells[mi-1][1];
Memo1->Lines->Add(matn);
}
Edit3->Text=n;
Memo1->Lines->Add("Natija="+n);


}
//---------------------------------------------------------------------------
void __fastcall TSezar_form::RadioButton1Click(TObject *Sender)
{
Label1->Caption="M";
Label2->Caption="C";
}
//---------------------------------------------------------------------------
void __fastcall TSezar_form::RadioButton2Click(TObject *Sender)
{
Label1->Caption="C";
Label2->Caption="M";
}
//---------------------------------------------------------------------------
void __fastcall TSezar_form::sBitBtn1Click(TObject *Sender)
{
StringGrid1->ColCount+=1;
StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount;
Label7->Caption=IntToStr(StrToInt(Label7->Caption)+1);
        
}
//---------------------------------------------------------------------------

void __fastcall TSezar_form::sBitBtn2Click(TObject *Sender)
{
StringGrid1->ColCount-=1;
Label7->Caption=IntToStr(StrToInt(Label7->Caption)-1);
        
}
//---------------------------------------------------------------------------

void __fastcall TSezar_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Sezar_form=NULL;
}
//---------------------------------------------------------------------------

