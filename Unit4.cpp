//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sPanel"
#pragma link "sLabel"
#pragma resource "*.dfm"
Tsehrli_kv *sehrli_kv;
//---------------------------------------------------------------------------
__fastcall Tsehrli_kv::Tsehrli_kv(TComponent* Owner)
        : TForm(Owner)
{
}
String kv_4[16]={"8","11","14","1","13","2","7","12","3","16","9","6","10","5","4","15"};
String kv_6[36]={"35","1","6","26","19","24","3","32","7","21","23","25","31","9","2","22","27","20","8","28","33","17","10","15","30","5","34","12","14","16","4","36","29","13","18","11"};
String kv_8[64]={"8","58","59","5","4","62","63","1","49","15","14","52","53","11","10","56","41","23","22","44","45","19","18","48","32","34","35","29","28","38","39","25","40","26","27","37","36","30","31","33","17","47","46","20","21","43","42","24","9","55","54","12","13","51","50","16","64","2","3","61","60","6","7","57"};

void __fastcall Tsehrli_kv::kvadrat_toldir_toq(int olcham)
{
   Label5->Font->Color=clBlue;   Label5->Caption="Mos keldi";
   int c=1,i,j,sa,us,sa1,us1;
    String s;        s=Edit1->Text;
    M->ColCount=olcham; M->RowCount=olcham;
    sa=0;   us=olcham/2;   S->ColCount=olcham; S->RowCount=olcham;
    for(i=1;i<=olcham*olcham;i++)
  {
   S->Cells[us][sa]=(String)c;
   M->Cells[us][sa]=s[c];
   c++;
   sa1=sa;us1=us;
   sa--;
   if(sa<0)sa=olcham-1;
   us--;
   if(us<0)us=olcham-1;
   if(S->Cells[us][sa]!="")
        {
        sa=sa1+1;us=us1;
        }
   }
}

void __fastcall Tsehrli_kv::maydon_sozlash()
   {
    int w;
   w=S->ColCount;
   if(w<10)
   {
    S->Height=w*30+20;
    S->Width=w*30+20;
    M->Height=w*30+20;
    M->Width=w*30+20;
   }
   else
   {
    S->Height=320;
    S->Width=320;
    M->Height=320;
    M->Width=320;

   }
}
//---------------------------------------------------------------------------
void __fastcall Tsehrli_kv::Edit1Change(TObject *Sender)
{
 int u,i1; float t;
   u=Edit1->Text.Length();
   t=sqrt(u);
   String s;
   s=Edit1->Text;
   i1=t;bool juft=false;
   String nat;
   Label3->Caption=IntToStr(Edit1->Text.Length());
         if(u==16){u=4;juft=true;}
         if(u==36){u=6;juft=true;}
         if(u==64){u=8;juft=true;}
         if(juft){
             S->ColCount=u;
             S->RowCount=u;
             M->ColCount=u; M->RowCount=u;
             int i,j,k;k=0;
             for(i=1;i<=u;i++)for(j=1;j<=u;j++)
             {if(u==4){S->Cells[j-1][i-1]=kv_4[k]; M->Cells[j-1][i-1]=s[StrToInt(kv_4[k])];}
              if(u==6){S->Cells[j-1][i-1]=kv_6[k]; M->Cells[j-1][i-1]=s[StrToInt(kv_6[k])];}
              if(u==8){S->Cells[j-1][i-1]=kv_8[k]; M->Cells[j-1][i-1]=s[StrToInt(kv_8[k])];}
              k++;}
             Label5->Font->Color=clBlue;   Label5->Caption="Mos keldi";
             for(int i=0;i<u;i++)for(int j=0;j<u;j++)
             nat+=s[StrToInt(S->Cells[j][i])];
             Edit2->Text=nat;
             maydon_sozlash();
             return;
              }
   if(u!=1 && u%2==1 && t==i1)
   {
   u=sqrt(u);
   kvadrat_toldir_toq(u);
     for(int i=0;i<u;i++)
     for(int j=0;j<u;j++)
   nat+=s[StrToInt(S->Cells[j][i])];
   Edit2->Text=nat;
   }
   else
   {Label5->Font->Color=clRed;Label5->Caption="Mos kelmadi";
   int y,m;
   for(y=0;y< S->ColCount;y++)for(m=0;m< S->RowCount;m++)
   {S->Cells[y][m]="";
    M->Cells[y][m]="";
   }
   Edit2->Text="";
   }
   maydon_sozlash();
}
//---------------------------------------------------------------------------
void __fastcall Tsehrli_kv::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
sehrli_kv=NULL;
}
//---------------------------------------------------------------------------


void __fastcall Tsehrli_kv::Edit2Change(TObject *Sender)
{
/* int d_u,d_i1; float d_t;
   d_u=Edit2->Text.Length();
   d_t=sqrt(d_u);
   String d_s;
   d_s=Edit2->Text;
   d_i1=d_t;bool d_juft=false;
   String d_nat;
   Label3->Caption=IntToStr(Edit2->Text.Length());
         if(d_u==16){d_u=4;d_juft=true;}
         if(d_u==36){d_u=6;d_juft=true;}
         if(d_u==64){d_u=8;d_juft=true;}
         if(d_juft){
             S->ColCount=d_u;S->RowCount=d_u;
             M->ColCount=d_u;M->RowCount=d_u;
             int d_i,d_j,d_k,d_i_,d_j_,d_zi,d_zj;d_k=0;
            if(d_u==4) for(d_i=0;d_i<d_u;d_i++)for(d_j=0;d_j<d_u;d_j++){S->Cells[d_j][d_i]=kv_4[d_k++];M->Cells[d_j][d_i]=d_s[d_k];}
            if(d_u==6) for(d_i=0;d_i<d_u;d_i++)for(d_j=0;d_j<d_u;d_j++){S->Cells[d_j][d_i]=kv_6[d_k++];M->Cells[d_j][d_i]=d_s[d_k];}
            if(d_u==8) for(d_i=0;d_i<d_u;d_i++)for(d_j=0;d_j<d_u;d_j++){S->Cells[d_j][d_i]=kv_8[d_k++];M->Cells[d_j][d_i]=d_s[d_k];}

             Label5->Font->Color=clBlue;   Label5->Caption="Mos keldi";
             d_k=1;
             for(d_i=0;d_i<d_u;d_i++)for(d_j=0;d_j<d_u;d_j++)
             {
             for(d_i_=0;d_i_<d_u;d_i_++)
             for(d_j_=0;d_j_<d_u;d_j_++)
             if((String)d_k==S->Cells[d_j_][d_i_]){d_zi=d_i_;d_zj=d_j_;}
             d_nat+=M->Cells[d_zj][d_zi];
             d_k++;
             }
             Edit1->Text=d_nat;
             goto kk2;
              }
   if(d_u!=1 && d_u%2==1 && d_t==d_i1)
   {
   d_u=sqrt(d_u);
   kvadrat_toldir_toq(d_u);
     for(int i=0;i<d_u;i++)
     for(int j=0;j<d_u;j++)
   d_nat+=d_s[StrToInt(S->Cells[j][i])];
   Edit2->Text=d_nat;
   }
   else
   {Label5->Font->Color=clRed;Label5->Caption="Mos kelmadi";
   int y,m;
   for(y=0;y< S->ColCount;y++)for(m=0;m< S->RowCount;m++)
   {S->Cells[y][m]="";
    M->Cells[y][m]="";
   }
   Edit1->Text="";
   }
kk2:
   maydon_sozlash();
*/
}
//---------------------------------------------------------------------------


