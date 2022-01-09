//---------------------------------------------------------------------------
#include <vcl.h>
#include <Registry.hpp>
#pragma hdrstop
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit12.h"
#include "Unit4.h"
#include "Unit_maalumot.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "acPNG"
#pragma link "sPanel"
#pragma link "sSkinManager"
#pragma link "sLabel"
#pragma link "sBitBtn"
#pragma link "sEdit"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
sSkinManager1->SkinDirectory=ExtractFilePath(Application->ExeName)+"Dizayn";
sSkinManager1->SkinName="Deep";
try{
Image1->Picture->LoadFromFile
(ExtractFilePath(Application->ExeName)+"Rasmlar\\Title.jpg");
}
catch(Exception &)
{
return;
}
TRegistry *reg = new TRegistry;
    reg->RootKey = HKEY_CURRENT_USER;
    String g;
    if(reg->KeyExists("Wind.key.id"))
    {
            reg->OpenKey("Wind.key.id",true);
            g=reg->ReadString("Cur");
            if(g=="ishla"){
            sLabel2->Visible=false;
            sBitBtn1->Visible=false;
            sEdit1->Visible=false;
    }
    }
    reg->CloseKey();
    delete reg;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label7Click(TObject *Sender)
{
if(sBitBtn1->Visible)
return;
if(Simmetrik_form==NULL)
Simmetrik_form=new TSimmetrik_form (this);
Simmetrik_form->Show();
Form1->Hide();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2Click(TObject *Sender)
{

if(sBitBtn1->Visible)
return;
if(Assimmetrik_form==NULL)
Assimmetrik_form=new TAssimmetrik_form(this);
Assimmetrik_form->Show();
Form1->Hide();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::sBitBtn1Click(TObject *Sender)
{


    TRegistry *reg=new TRegistry;
    try{
        reg->RootKey=HKEY_CURRENT_USER;
    if(sEdit1->Text=="ishla"){
        if(reg->OpenKey("Wind.key.id",true)){
            reg->WriteString("Cur",sEdit1->Text);
            sLabel2->Visible=false;
            sBitBtn1->Visible=false;
            sEdit1->Visible=false;
            ShowMessage("Kalit olindi");
            reg->CloseKey();
        }
        else ShowMessage("Xatolik sodir bo'ldi");
    }
    else ShowMessage("Parol xatolik");

    }
    __finally{
        delete reg;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Dasturhaqidamalumot1Click(TObject *Sender)
{
if(malumot==NULL)
malumot=new Tmalumot(this);
malumot->Show();
}
//---------------------------------------------------------------------------


