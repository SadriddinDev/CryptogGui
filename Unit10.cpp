//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sPanel"
#pragma link "sLabel"
#pragma resource "*.dfm"
TVijener_form *Vijener_form;
//---------------------------------------------------------------------------
__fastcall TVijener_form::TVijener_form(TComponent* Owner)
        : TForm(Owner)
{
}
bool mavjud(String s)
{   bool bor=true,bor1;
for(int i=1;i<=s.Length();i++)
        {   bor1=false;
        for(int j=0;j<Vijener_form->StringGrid1->ColCount;j++)
        if((String)s[i]==Vijener_form->StringGrid1->Cells[j][1])
        bor1=true;
        bor*=bor1;
        }
  return bor;
}
int turgan_orni(char c)
{
for(int i=0;i<Vijener_form->StringGrid1->ColCount;i++)
if((String)c==Vijener_form->StringGrid1->Cells[i][1])return i+1;
}
bool boshliq()
{
for(int i=0;i<Vijener_form->StringGrid1->ColCount;i++)
if(Vijener_form->StringGrid1->Cells[i][1]=="")return false;
return true;
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::FormCreate(TObject *Sender)
{
for(int i=0;i<StringGrid1->ColCount;i++)
{StringGrid1->Cells[i][0]=i+1;
StringGrid1->Cells[i][1]=(char)(i+65);
}
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::Button1Click(TObject *Sender)
{
if(Edit1->Text=="" || Edit2->Text=="")
{
ShowMessage("Qiymatlarni to'diring");
return;
}
if(!boshliq())
{
ShowMessage("Alifboni to'ldiring.Bo'sh joylari bor");
return;
}

String matn,kalit;
matn=Edit1->Text;
kalit=Edit2->Text;
if(!mavjud(matn))
{
ShowMessage("Matnda alifboda mavjud bo'lmagan belgi bor!!! Alifboga shu belgini qo'shing yoki boshqa belgidan foydalaning.");
return;
}
if(!mavjud(kalit))
{
ShowMessage("Kalitda alifboda mavjud bo'lmagan belgi bor!!! Alifboga shu belgini qo'shing yoki boshqa belgidan foydalaning.");
return;
}
String natija,ishlanish;
int i,j,k,orin,n,m;
k=1;
m=StringGrid1->ColCount;
ishlanish="Matn  = ";
n=matn.Length();
    for(j=1;j<=n;j++ )
        ishlanish+=(String)matn[j]+" ";
    Memo1->Lines->Add(ishlanish);
    ishlanish="Kalit = ";
    for(j=1;j<=n;j++)
    {
    ishlanish+=(String)kalit[k++]+" ";
    if(k>kalit.Length())k=1;
    }  k=1;
    Memo1->Lines->Add(ishlanish);
        for(i=1;i<=n;i++)
        {
          j=turgan_orni(matn[i])+turgan_orni(kalit[k]);
          j=j%m;
          if(j==0)j=m;
          ishlanish="C["+(String)i+"]="+"("+(String)matn[i]+" + "+(String)kalit[k]+") mod m=";
          ishlanish+="("+(String)turgan_orni(matn[i])+ "+" + (String)turgan_orni(kalit[k])+") mod "+(String)m + "=";
          ishlanish+=(String)j+"--> "+StringGrid1->Cells[j-1][1];
          natija+=StringGrid1->Cells[j-1][1];
          k++;
          if(k>kalit.Length())k=1;
          Memo1->Lines->Add(ishlanish);
        }
        Memo1->Lines->Add("Natija="+natija);
        Edit3->Text=natija;
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::Button2Click(TObject *Sender)
{
if(Edit1->Text=="" || Edit2->Text=="")
{
ShowMessage("Qiymatlarni to'diring");
return;
}

if(!boshliq())
{
ShowMessage("Alifboni to'ldiring.Bo'sh joylari bor");
return;
}
String matn,kalit;
matn=Edit1->Text;
kalit=Edit2->Text;
if(!mavjud(matn))
{
ShowMessage("Matnda alifboda mavjud bo'lmagan belgi bor!!! Alifboga shu belgini qo'shing yoki boshqa belgidan foydalaning.");
return;
}
if(!mavjud(kalit))
{
ShowMessage("Kalitda alifboda mavjud bo'lmagan belgi bor!!! Alifboga shu belgini qo'shing yoki boshqa belgidan foydalaning.");
return;
}
String natija,ishlanish;
int i,j,k,orin,n,m;
k=1;
m=StringGrid1->ColCount;
ishlanish="Shifr = ";
n=matn.Length();
    for(j=1;j<=n;j++ )
        ishlanish+=(String)matn[j]+" ";
    Memo1->Lines->Add(ishlanish);
    ishlanish="Kalit = ";
    for(j=1;j<=n;j++)
    {
    ishlanish+=(String)kalit[k++]+" ";
    if(k>kalit.Length())k=1;
    }  k=1;
    Memo1->Lines->Add(ishlanish);
        for(i=1;i<=n;i++)
        {
          j=m+turgan_orni(matn[i])-turgan_orni(kalit[k]);
          j=j%m;
          if(j==0)j=m;
          ishlanish="C["+(String)i+"]="+"("+(String)m+" + "+(String)matn[i]+" - "+(String)kalit[k]+") mod m=";
          ishlanish+="("+(String)m+" + "+(String)turgan_orni(matn[i])+ "-" + (String)turgan_orni(kalit[k])+") mod "+(String)m + "=";
          ishlanish+=(String)j+"--> "+StringGrid1->Cells[j-1][1];
          natija+=StringGrid1->Cells[j-1][1];
          k++;
          if(k>kalit.Length())k=1;
          Memo1->Lines->Add(ishlanish);
        }
        Memo1->Lines->Add("Natija="+natija);
        Edit3->Text=natija;

}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::Label11Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::Label2Click(TObject *Sender)
{
StringGrid1->ColCount=StringGrid1->ColCount+1;
Label8->Caption=(String)(StrToInt(Label8->Caption)+1);
StringGrid1->Cells[StringGrid1->ColCount-1][0]=StringGrid1->ColCount;
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::Label3Click(TObject *Sender)
{
StringGrid1->ColCount=StringGrid1->ColCount-1;
Label8->Caption=(String)(StrToInt(Label8->Caption)-1);
}
//---------------------------------------------------------------------------
void __fastcall TVijener_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
   Action=caFree;
   Vijener_form=NULL;        
}
//---------------------------------------------------------------------------


