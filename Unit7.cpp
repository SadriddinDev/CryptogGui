//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit15.h"
#include "Unit10.h"
#include "Unit12.h"
#include "Unit13.h"
#include "Unit4.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit14.h"
#include "Unit2.h"
#include "Unit16.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sPanel"
#pragma resource "*.dfm"
TAssimmetrik_form *Assimmetrik_form;
//---------------------------------------------------------------------------
__fastcall TAssimmetrik_form::TAssimmetrik_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAssimmetrik_form::Label2Click(TObject *Sender)
{
Form1->Hotira->Caption="8";
int x,y;
x=Assimmetrik_form->Left+Label2->Left+Label2->Width+15;
y=Assimmetrik_form->Top+Label2->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TAssimmetrik_form::Label6Click(TObject *Sender)
{
Form1->Hotira->Caption="9";
int x,y;
x=Assimmetrik_form->Left+Label6->Left+Label6->Width+15;
y=Assimmetrik_form->Top+Label6->Top+40;
PopupMenu1->Popup(x,y);


}
//---------------------------------------------------------------------------
void __fastcall TAssimmetrik_form::Label3Click(TObject *Sender)
{
Form1->Hotira->Caption="a";
int x,y;
x=Assimmetrik_form->Left+Label3->Left+Label3->Width+15;
y=Assimmetrik_form->Top+Label3->Top+40;
PopupMenu1->Popup(x,y);

}
//---------------------------------------------------------------------------
void __fastcall TAssimmetrik_form::Label4Click(TObject *Sender)
{
Form1->Hotira->Caption="b";
int x,y;
x=Assimmetrik_form->Left+Label4->Left+Label4->Width+15;
y=Assimmetrik_form->Top+Label4->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TAssimmetrik_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Form1->Show();
Action=caFree;
Assimmetrik_form=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TAssimmetrik_form::Label5Click(TObject *Sender)
{
if(Eyler_form==NULL)
Eyler_form=new TEyler_form(this);
Eyler_form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TAssimmetrik_form::Dastur1Click(TObject *Sender)
{
AnsiString s;
s=Form1->Hotira->Caption;
char c;
c=s[1];
switch(c)
{
case '8':  { if(Ryukzak_form==NULL)
                Ryukzak_form=new TRyukzak_form(this);
                Ryukzak_form->ShowModal();
             }break;
case '9':  { if(RSA_==NULL)
                RSA_=new TRSA_(this);
                RSA_->ShowModal();
             }break;
case 'b':  { if(El_Gamal==NULL)
                El_Gamal=new TEl_Gamal(this);
                El_Gamal->ShowModal();
             }break;
case 'a':  { if(Rabin_form==NULL)
                Rabin_form=new TRabin_form(this);
                Rabin_form->ShowModal();
             }break;
}
}
//---------------------------------------------------------------------------




void __fastcall TAssimmetrik_form::Nazariymalumot1Click(TObject *Sender)
{
if(!DirectoryExists("Nazariy"))
{
ShowMessage("Kerakli katalog topilmadi");
return;
}
ShellExecute(NULL, "open", "Nazariy\\", NULL, NULL, SW_RESTORE);
        
}
//---------------------------------------------------------------------------

