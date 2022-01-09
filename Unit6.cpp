//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit12.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit10.h"
#include "Unit13.h"
#include "Unit3.h"
#include "Unit16.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "acPNG"
#pragma link "sPanel"
#pragma link "sBitBtn"
#pragma resource "*.dfm"
TSimmetrik_form *Simmetrik_form;
//---------------------------------------------------------------------------
__fastcall TSimmetrik_form::TSimmetrik_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label2Click(TObject *Sender)
{
Form1->Hotira->Caption="1";
int x,y;
x=Simmetrik_form->Left+Label2->Left+Label2->Width+15;
y=Simmetrik_form->Top+Label2->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label3Click(TObject *Sender)
{
Form1->Hotira->Caption="2";
int x,y;
x=Simmetrik_form->Left+Label3->Left+Label3->Width+15;
y=Simmetrik_form->Top+Label3->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label4Click(TObject *Sender)
{
Form1->Hotira->Caption="3";
int x,y;
x=Simmetrik_form->Left+Label4->Left+Label4->Width+15;
y=Simmetrik_form->Top+Label4->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label5Click(TObject *Sender)
{
Form1->Hotira->Caption="4";
int x,y;
x=Simmetrik_form->Left+Label5->Left+Label5->Width+15;
y=Simmetrik_form->Top+Label5->Top+40;
PopupMenu1->Popup(x,y);

}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label6Click(TObject *Sender)
{
Form1->Hotira->Caption="5";
int x,y;
x=Simmetrik_form->Left+Label6->Left+Label6->Width+15;
y=Simmetrik_form->Top+Label6->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label7Click(TObject *Sender)
{
Form1->Hotira->Caption="6";
int x,y;
x=Simmetrik_form->Left+Label7->Left+Label7->Width+15;
y=Simmetrik_form->Top+Label7->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::Label8Click(TObject *Sender)
{
Form1->Hotira->Caption="7";
int x,y;
x=Simmetrik_form->Left+Label8->Left+Label8->Width+15;
y=Simmetrik_form->Top+Label8->Top+40;
PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TSimmetrik_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Form1->Show();
Action=caFree;
Simmetrik_form=NULL;
}
//---------------------------------------------------------------------------



void __fastcall TSimmetrik_form::Dastur1Click(TObject *Sender)
{
AnsiString s;
s=Form1->Hotira->Caption;
char c;
c=s[1];
switch(c)
{
 case '1':  { if(sehrli_kv==NULL)
                sehrli_kv=new Tsehrli_kv(this);
                sehrli_kv->ShowModal();
             }break;
 case '2':  { if(Sezar_form==NULL)
                Sezar_form=new TSezar_form(this);
                Sezar_form->Show();
             }break;
case '3':  { if(sezar_affin_form==NULL)
                sezar_affin_form=new Tsezar_affin_form(this);
                sezar_affin_form->Show();
             }break;
case '4':  { if(uinston_form==NULL)
                uinston_form=new Tuinston_form(this);
                uinston_form->Show();
             }break;
case '5':  { if(Vijener_form==NULL)
                Vijener_form=new TVijener_form(this);
                Vijener_form->Show();
             }break;
case '6':  { if(Analiktik_form==NULL)
                Analiktik_form=new TAnaliktik_form(this);
                Analiktik_form->Show();
             }break;
case '7':  { if(Orin_form==NULL)
                Orin_form=new TOrin_form(this);
                Orin_form->Show();
             }break;


}

}
//---------------------------------------------------------------------------

void __fastcall TSimmetrik_form::Nazariytushuncha1Click(TObject *Sender)
{
if(!DirectoryExists("Nazariy"))
{
ShowMessage("Kerakli katalog topilmadi");
return;
}
ShellExecute(NULL, "open", "Nazariy\\", NULL, NULL, SW_RESTORE);
}
//---------------------------------------------------------------------------


