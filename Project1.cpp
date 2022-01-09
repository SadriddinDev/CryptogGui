//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit4.cpp", sehrli_kv);
USEFORM("Unit5.cpp", Sezar_form);
USEFORM("Unit6.cpp", Simmetrik_form);
USEFORM("Unit7.cpp", Assimmetrik_form);
USEFORM("Unit8.cpp", sezar_affin_form);
USEFORM("Unit9.cpp", uinston_form);
USEFORM("Unit10.cpp", Vijener_form);
USEFORM("Unit12.cpp", El_Gamal);
USEFORM("Unit13.cpp", Orin_form);
USEFORM("Unit14.cpp", RSA_);
USEFORM("Unit15.cpp", Eyler_form);
USEFORM("Unit2.cpp", Rabin_form);
USEFORM("Unit16.cpp", Analiktik_form);
USEFORM("Unit3.cpp", Ryukzak_form);
USEFORM("Unit_maalumot.cpp", malumot);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
