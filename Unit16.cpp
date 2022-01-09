//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#pragma hdrstop

#include "Unit16.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "sEdit"
#pragma link "sLabel"
#pragma link "sBitBtn"
#pragma resource "*.dfm"
TAnaliktik_form *Analiktik_form;
//---------------------------------------------------------------------------

__fastcall TAnaliktik_form::TAnaliktik_form(TComponent* Owner)
        : TForm(Owner)
{
}

int scanf(float a[100][100]){
	int i,j,n;
        n=StrToInt(Analiktik_form->sEdit1->Text);
     	for(i=0;i<n;i++)
	for(j=0;j<n;j++){
	    a[i][j]= StrToFloat(Analiktik_form->StringGrid1->Cells[j][i]);
	}
return n;
}
void printf(float a[100][100],int n)
{       int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	 Analiktik_form->StringGrid2->Cells[j][i]=FloatToStr(a[i][j]);
}
void minor(float b[100][100],float a[100][100],int i,int n){
	int j,l,h=0,k=0;
	for(l=1;l<n;l++)
		for( j=0;j<n;j++){
			if(j == i)
				continue;
			b[h][k] = a[l][j];
			k++;
			if(k == (n-1)){
				h++;
				k=0;
			}
		}

}
float det(float a[100][100],int n){
	int i;
	float b[100][100],sum=0;
	if (n == 1)
return a[0][0];
	else if(n == 2)
return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	else
		for(i=0;i<n;i++){
			minor(b,a,i,n);
			sum = (float) (sum+a[0][i]*pow(-1,i)*det(b,(n-1)));
		}
return sum;
}
void transpose(float c[100][100],float d[100][100],int n){
	int i,j;
	float b[100][100];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			b[i][j] = c[j][i];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			d[i][j] = b[i][j];
}
void cofactor(float a[100][100],float d[100][100],int n,float determinte){
	float b[100][100],c[100][100];
	int l,h,m,k,i,j;
	for (h=0;h<n;h++)
		for (l=0;l<n;l++){
		 m=0;
		 k=0;
		 for (i=0;i<n;i++)
		 	for (j=0;j<n;j++)
		 		if (i != h && j != l){
		 			b[m][k]=a[i][j];
		 			if (k<(n-2))
		 				k++;
		 			else{
		 				k=0;
		 				m++;
		 			}
		 		}
		c[h][l] = (float) pow(-1,(h+l))*det(b,(n-1));
	     }
	transpose(c,d,n);
}
void inverse(float a[100][100],float d[100][100],int n,float det){
	if(det == 0)
	       ShowMessage("Teskari matritsa hosil qilib bo'lmaydi");
	else if(n == 1)
		d[0][0] = 1;
	else
		cofactor(a,d,n,det);
}


bool tekshirish_martitsa()
{
int s,n;
s=Analiktik_form->StringGrid1->ColCount;
        for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
        {
                try{
                n=StrToInt(Analiktik_form->StringGrid1->Cells[j][i]);
                }
                catch(EConvertError &)
                {
                return false;
                }
        }
return true;
}

void teskari_matritsa()
{
    int i,j,n;
	float a[100][100],d[100][100],deter;
	n = scanf(a);
	deter =(float)det(a,n);
        Analiktik_form->Edit1->Text=FloatToStr(deter);
	inverse(a,d,n,deter);
	printf(d,n);

}

//---------------------------------------------------------------------------
void __fastcall TAnaliktik_form::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
Analiktik_form=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TAnaliktik_form::sEdit1Change(TObject *Sender)
{
int n;
try{
n=StrToInt(sEdit1->Text);
}
catch(EConvertError &){return;}
if(n<11 && n>0)
   {
       StringGrid1->RowCount=n;StringGrid1->ColCount=n;
       StringGrid1->Height=n*32+20;
       StringGrid1->Width=n*32+20;
       StringGrid3->RowCount=n;StringGrid3->ColCount=n;
       StringGrid3->Height=n*28+20;
       StringGrid3->Width=n*64+20;
   }
}
//---------------------------------------------------------------------------
void __fastcall TAnaliktik_form::sBitBtn1Click(TObject *Sender)
{
if(sEdit2->Text=="")
        {
        ShowMessage("Matnni kiriting");return;
        }
        if(!tekshirish_martitsa())
        {
        ShowMessage("Matritsa elementlarida xatolik bor");
        return;
        }
        String s;
        s=sEdit2->Text;
        int l,l1,marta,n;
        l=s.Length();
        l1=StringGrid1->ColCount;
        if(l%l1==0)marta=l/l1;
        else
        {
        ShowMessage("Jadval va matn uzunligi mos emas");
        return;
        }
        n=l/marta;
        String orin;
        int *B=new int[n],**A,*M=new int[l];
        for(int i=0;i<l;i++)
        {
        M[i]=(int)s[i+1];
        orin+=(String)M[i];
        if(i!=l-1)orin+=",";
        }
        sEdit3->Text=orin;
        int k;
        A=new int*[l1];
        for(int i=0;i<l1;i++)A[i]=new int [l1];
        for(int i=0;i<l1;i++)
        for(int j=0;j<l1;j++)
        A[i][j]=StrToInt(StringGrid1->Cells[j][i]);
        k=0;
        int son=0;
        String natija;
        for(int i=1;i<=marta;i++)
                {
                  for(int j=0;j<n;j++)
                  B[j]=M[k++];
                  for(int i1=0;i1<l1;i1++)
                  {   son=0;
                    for(int j=0;j<l1;j++)
                    son+=A[i1][j]*B[j];
                    natija+=(String)son;
                    if(i1!=l1-1 || i!=marta)natija+=",";
                  }
                 }
                sEdit4->Text=natija;
}
//---------------------------------------------------------------------------
void __fastcall TAnaliktik_form::sBitBtn2Click(TObject *Sender)
{
if(sEdit4->Text=="")
        {
        ShowMessage("Shifrni kiriting");return;
        }
        if(!tekshirish_martitsa())
        {
        ShowMessage("Matritsa elementlarida xatolik bor");
        return;
        }
        int v_soni=0,determinanat;
         String s;
        s=sEdit4->Text;
        int i,k,j;
        for(i=1;i<=s.Length();i++)
        if(s[i]==',')v_soni++;
        int *Shifr=new int[v_soni+1];
        int l;
        l=v_soni+1;
        if(l%StringGrid1->ColCount!=0)
        {
        ShowMessage("Shifr uzunligi jadvalga mos emas!!!");
        return;
        }

        if(!tekshirish_martitsa())
        {
        ShowMessage("Matritsa elementlarida xatolik bor");
        return;
        }
        int son=0;k=0;
        bool manfiy=false;
        for(i=1;i<=s.Length();i++)
        {
        if(s[i]=='-')manfiy=true;
        else if(s[i]!=',')son=son*10+(int)s[i]-48;
        else
                {
                if(manfiy)son=son*(-1);
                manfiy=false;
                Shifr[k++]=son;
                son=0;
                }
        }
        Shifr[k]=son;
        teskari_matritsa();
        determinanat=StrToInt(Edit1->Text);
        k=0;
        int marta;
        marta=l/StringGrid1->ColCount;
        int n;
        n=l/marta;
        int l1=StringGrid1->ColCount;
        int *B=new int[n];
        String natija;
        for(int i=1;i<=marta;i++)
                {
                  for(int j=0;j<n;j++)
                  B[j]=Shifr[k++];
                  for(int i1=0;i1<l1;i1++)
                  {   son=0;
                    for(int j=0;j<l1;j++)
                    {son+=StrToFloat(StringGrid2->Cells[j][i1])*B[j];
                    StringGrid3->Cells[j][i1]=StringGrid2->Cells[j][i1]+"/"+(String)determinanat;
                    }
                  son/=determinanat;
                    natija+=(char)son;
                    }
                 }
                sEdit2->Text=natija;
}
//---------------------------------------------------------------------------







