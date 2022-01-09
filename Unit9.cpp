//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sComboBox"
#pragma link "sPanel"
#pragma link "sBitBtn"
#pragma link "sLabel"
#pragma resource "*.dfm"
Tuinston_form *uinston_form;
//---------------------------------------------------------------------------
__fastcall Tuinston_form::Tuinston_form(TComponent* Owner)
        : TForm(Owner)
{
}
bool tekshir()
{
for(int i=1;i<uinston_form->alifbo->RowCount;i++)
for(int j=1;j<uinston_form->alifbo->ColCount;j++)
if(uinston_form->alifbo->Cells[j][i]=="")return false;
return true;
}
bool matn_tekshir(String s)
{
int p=1,p1=0;
for(int k=1;k<=s.Length();k++)
{for(int i=1;i<uinston_form->alifbo->RowCount;i++)
for(int j=1;j<uinston_form->alifbo->ColCount;j++)
if(uinston_form->alifbo->Cells[j][i]==s[k])p1=1;
p*=p1;p1=0;
}
if(p==1)return true;
return false;
}
void a_joylashtir_kalit(String kalit_1)
{
int i,j,k,i1,j1,sa,us,j__; bool bor = false;k=1;
sa=us=1;
for(i=1;i<=kalit_1.Length();i++)
{       bosh:
        for(i1=1;i1<uinston_form->SA->RowCount;i1++)
        for(j1=1;j1<uinston_form->SA->ColCount;j1++)
        if(uinston_form->SA->Cells[j1][i1]==kalit_1[k])bor=true;
        if(!bor) {uinston_form->SA->Cells[us][sa]=kalit_1[k];}
        else {k++;i++;if(i>kalit_1.Length())goto tashqari;bor = false; goto bosh;}
        k++;
        us++;
        if(us==uinston_form->SA->ColCount){us=1; sa++;}
}
tashqari:
}
void a_joylashtir_qolgani()
{     int i,j,j__,i__,i1,j1;
for(i=1;i<uinston_form->SA->RowCount;i++)
for(j=1;j<uinston_form->SA->ColCount;j++)
        if(uinston_form->SA->Cells[j][i]=="")goto tashq;
        tashq:
          bool bor = false;
        j__=j;  i__=i;

for(i=1;i<uinston_form->alifbo->RowCount;i++)
for(j=1;j<uinston_form->alifbo->ColCount;j++)
    {
     for(i1=1;i1<uinston_form->SA->RowCount;i1++)
        for(j1=1;j1<uinston_form->SA->ColCount;j1++)
        if(uinston_form->alifbo->Cells[j][i]==uinston_form->SA->Cells[j1][i1])  bor=true;

        if(!bor)uinston_form->SA->Cells[j__++][i__]=uinston_form->alifbo->Cells[j][i];
          if(j__>=uinston_form->SA->ColCount){j__=1; i__++;}
          bor = false;
     }
}

void b_joylashtir_kalit(String kalit_2)
{
int i,j,k,i1,j1,sa,us,j__; bool bor = false;k=1;
sa=us=1;
for(i=1;i<=kalit_2.Length();i++)
{       boshB:
        for(i1=1;i1<uinston_form->SB->RowCount;i1++)
        for(j1=1;j1<uinston_form->SB->ColCount;j1++)
        if(uinston_form->SB->Cells[j1][i1]==kalit_2[k])bor=true;
        if(!bor) {uinston_form->SB->Cells[us][sa]=kalit_2[k];}
        else {k++;i++;if(i>kalit_2.Length())goto tashqariB;bor = false; goto boshB;}
        k++;
        us++;
        if(us==uinston_form->SB->ColCount){us=1; sa++;}
}
tashqariB:
}
void B_joylashtir_qolgani()
{     int i,j,j__,i__,i1,j1;
for(i=1;i<uinston_form->SB->RowCount;i++)
for(j=1;j<uinston_form->SB->ColCount;j++)
        if(uinston_form->SB->Cells[j][i]=="")goto tashqB;
        tashqB:
          bool bor = false;
        j__=j;  i__=i;

for(i=1;i<uinston_form->alifbo->RowCount;i++)
for(j=1;j<uinston_form->alifbo->ColCount;j++)
    {
     for(i1=1;i1<uinston_form->SB->RowCount;i1++)
        for(j1=1;j1<uinston_form->SB->ColCount;j1++)
        if(uinston_form->alifbo->Cells[j][i]==uinston_form->SB->Cells[j1][i1])  bor=true;

        if(!bor)uinston_form->SB->Cells[j__++][i__]=uinston_form->alifbo->Cells[j][i];
          if(j__>=uinston_form->SB->ColCount){j__=1; i__++;}
          bor = false;
     }
}

void a_tozala()
{
for(int i=1;i<uinston_form->SA->RowCount;i++)
for(int j=1;j<uinston_form->SA->ColCount;j++)
uinston_form->SA->Cells[j][i]="";
}
void b_tozala()
{
for(int i=1;i<uinston_form->SB->RowCount;i++)
for(int j=1;j<uinston_form->SB->ColCount;j++)
uinston_form->SB->Cells[j][i]="";
}

//---------------------------------------------------------------------------
void __fastcall Tuinston_form::FormCreate(TObject *Sender)
{

for(int i=1;i<SA->ColCount;i++)
SA->Cells[i][0]=i;
for(int i=1;i<SB->ColCount;i++)
SB->Cells[i][0]=i;
for(int i=1;i<SA->RowCount;i++)
SA->Cells[0][i]=i;
for(int i=1;i<SB->RowCount;i++)
SB->Cells[0][i]=i;
for(int i=1;i<alifbo->ColCount;i++)
alifbo->Cells[i][0]=i;
for(int i=1;i<alifbo->RowCount;i++)
alifbo->Cells[0][i]=i;
int k=65;
for(int i=1;i<alifbo->RowCount;i++)
for(int j=1;j<alifbo->ColCount;j++)
alifbo->Cells[j][i]=(char)k++;

}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::Label9Click(TObject *Sender)
{
Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::ComboBox1Change(TObject *Sender)
{
alifbo->RowCount=StrToInt(ComboBox1->Text)+1;
SA->RowCount=StrToInt(ComboBox1->Text)+1;
SB->RowCount=StrToInt(ComboBox1->Text)+1;
FormCreate(Sender);
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::ComboBox2Change(TObject *Sender)
{
alifbo->ColCount=StrToInt(ComboBox2->Text)+1;
SA->ColCount=StrToInt(ComboBox2->Text)+1;
SB->ColCount=StrToInt(ComboBox2->Text)+1;
FormCreate(Sender);

}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
uinston_form=NULL;
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::sComboBox1Change(TObject *Sender)
{
alifbo->RowCount=StrToInt(ComboBox1->Text)+1;
SA->RowCount=StrToInt(ComboBox1->Text)+1;
SB->RowCount=StrToInt(ComboBox1->Text)+1;
FormCreate(Sender);
        
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::sComboBox2Change(TObject *Sender)
{
alifbo->ColCount=StrToInt(ComboBox2->Text)+1;
SA->ColCount=StrToInt(ComboBox2->Text)+1;
SB->ColCount=StrToInt(ComboBox2->Text)+1;
FormCreate(Sender);
        
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::sBitBtn1Click(TObject *Sender)
{
if(Edit3->Text==""){ShowMessage("1- kalit yoq"); return;}
if(Edit4->Text==""){ShowMessage("2- kalit yoq"); return;}
if(Edit1->Text==""){ShowMessage("Matn  yoq"); return;}
if(!matn_tekshir(Edit1->Text)){ShowMessage("Matnda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!matn_tekshir(Edit3->Text)){ShowMessage("1-kalitda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!matn_tekshir(Edit4->Text)){ShowMessage("2-kalitda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!(Edit1->Text.Length()%2==0)){ShowMessage("Matnni juft kiriting");return;}
a_tozala();
 a_joylashtir_kalit(Edit3->Text);
 a_joylashtir_qolgani();
b_tozala();
 b_joylashtir_kalit(Edit4->Text);
 B_joylashtir_qolgani();
 String natija,matn,ishlanish;
 matn=Edit1->Text;
 ishlanish="Matn="+matn;
 Memo1->Lines->Add(ishlanish);
 Memo1->Lines->Add("1-Kalit="+Edit3->Text);
 Memo1->Lines->Add("2-Kalit="+Edit4->Text);

 int i,j,l,indeks_i1,indeks_i2,indeks_j1,indeks_j2;

        for(l=2;l<=matn.Length();l+=2)
         {
         for(i=1;i<SA->RowCount;i++)
         for(j=1;j<SA->ColCount;j++)
         if((String)matn[l-1]==SA->Cells[j][i])
          {indeks_i1=i;indeks_j1=j;break;}

        for(i=1;i<SB->RowCount;i++)
         for(j=1;j<SB->ColCount;j++)
         if((String)matn[l]==SB->Cells[j][i])
          {indeks_i2=i;indeks_j2=j;break;}
          if(indeks_i1==indeks_i2)
             {natija+=SB->Cells[indeks_j1][indeks_i1]+SA->Cells[indeks_j2][indeks_i2];
             ishlanish=(String)matn[l-1]+(String)matn[l]+"->A["+(String)indeks_i1+"]["+(String)indeks_j1+"] B["+(String)indeks_i2+"]["+(String)indeks_j2+"] --->> ";
             ishlanish+="B["+(String)indeks_i1+"]["+(String)indeks_j1+"] A["+(String)indeks_i2+"]["+(String)indeks_j2+"] = ";
             ishlanish+=SB->Cells[indeks_j1][indeks_i1]+SA->Cells[indeks_j2][indeks_i2];
              }
           else
           {natija+=SB->Cells[indeks_j2][indeks_i1]+SA->Cells[indeks_j1][indeks_i2];
             ishlanish=(String)matn[l-1]+(String)matn[l]+"->A["+(String)indeks_i1+"]["+(String)indeks_j1+"] B["+(String)indeks_i2+"]["+(String)indeks_j2+"] --->> ";
             ishlanish+="B["+(String)indeks_i1+"]["+(String)indeks_j2+"] A["+(String)indeks_i2+"]["+(String)indeks_j1+"] = ";
             ishlanish+=SB->Cells[indeks_j2][indeks_i1]+SA->Cells[indeks_j1][indeks_i2];
            }
            Memo1->Lines->Add(ishlanish);
           }

      Edit2->Text=natija;
      Memo1->Lines->Add("Shifrlangan matn="+natija);
        
}
//---------------------------------------------------------------------------

void __fastcall Tuinston_form::sBitBtn2Click(TObject *Sender)
{
if(Edit3->Text==""){ShowMessage("1- kalit yoq"); return;}
if(Edit4->Text==""){ShowMessage("2- kalit yoq"); return;}
if(Edit1->Text==""){ShowMessage("Matn  yoq"); return;}
if(!matn_tekshir(Edit1->Text)){ShowMessage("Matnda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!matn_tekshir(Edit3->Text)){ShowMessage("1-kalitda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!matn_tekshir(Edit4->Text)){ShowMessage("2-kalitda alifboda mavjud bo'lmagan belgilar bor"); return;}
if(!(Edit1->Text.Length()%2==0)){ShowMessage("Matnni juft kiriting");return;}
a_tozala();
 a_joylashtir_kalit(Edit3->Text);
 a_joylashtir_qolgani();
b_tozala();
 b_joylashtir_kalit(Edit4->Text);
 B_joylashtir_qolgani();
 String natija,matn,ishlanish;
 matn=Edit1->Text;
 ishlanish="Shifr="+matn;
 Memo1->Lines->Add(ishlanish);
 Memo1->Lines->Add("1-Kalit="+Edit3->Text);
 Memo1->Lines->Add("2-Kalit="+Edit4->Text);

 int i,j,l,indeks_i1,indeks_i2,indeks_j1,indeks_j2;

        for(l=2;l<=matn.Length();l+=2)
         {
         for(i=1;i<SB->RowCount;i++)
         for(j=1;j<SB->ColCount;j++)
         if((String)matn[l-1]==SB->Cells[j][i])
          {indeks_i1=i;indeks_j1=j;break;}

        for(i=1;i<SA->RowCount;i++)
         for(j=1;j<SA->ColCount;j++)
         if((String)matn[l]==SA->Cells[j][i])
          {indeks_i2=i;indeks_j2=j;break;}
          if(indeks_i1==indeks_i2)
             {natija+=SA->Cells[indeks_j1][indeks_i1]+SB->Cells[indeks_j2][indeks_i2];
             ishlanish=(String)matn[l-1]+(String)matn[l]+"->B["+(String)indeks_i1+"]["+(String)indeks_j1+"] A["+(String)indeks_i2+"]["+(String)indeks_j2+"] --->> ";
             ishlanish+="A["+(String)indeks_i1+"]["+(String)indeks_j1+"] B["+(String)indeks_i2+"]["+(String)indeks_j2+"] = ";
             ishlanish+=SA->Cells[indeks_j1][indeks_i1]+SB->Cells[indeks_j2][indeks_i2];
              }
           else
           {natija+=SA->Cells[indeks_j2][indeks_i1]+SB->Cells[indeks_j1][indeks_i2];
             ishlanish=(String)matn[l-1]+(String)matn[l]+"->B["+(String)indeks_i1+"]["+(String)indeks_j1+"] A["+(String)indeks_i2+"]["+(String)indeks_j2+"] --->> ";
             ishlanish+="A["+(String)indeks_i1+"]["+(String)indeks_j2+"] B["+(String)indeks_i2+"]["+(String)indeks_j1+"] = ";
             ishlanish+=SA->Cells[indeks_j2][indeks_i1]+SB->Cells[indeks_j1][indeks_i2];
            }
            Memo1->Lines->Add(ishlanish);
           }

      Edit2->Text=natija;
      Memo1->Lines->Add("Deshifrlangan matn="+natija);

        
}
//---------------------------------------------------------------------------

