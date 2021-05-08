#include"Encrypt.h"
#include"Filesch.h"
#include<list>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<iostream>

using namespace std;

Encrypt::Encrypt()
{
	
}

void Encrypt::Enfactor(char * in_fname,char * out_fname,int password)
{
	 char ch;
	 FILE *f1=0,*f2=0;
    if((f1=fopen(in_fname,"rb"))==0 )

    {
      printf("open f1 error");
    }
    if((f2=fopen(out_fname,"wb+"))==0 )
  {
    printf("open f2 error");
  }
    while(!feof(f1))
  {
      ch=fgetc(f1);
     if((fputc(ch^password,f2))==-1)
      {
          printf("write error");
      }
  }
  fclose(f1);
  fclose(f2);
		
}

void Encrypt::del(char * del_path)
{
	if(DeleteFile(del_path)==0)
	{
		cout<<"cannot delete primitive file..."<<endl;
	}
}

void Encrypt::FileAttri(char * path,int mode )
{
        if(mode==1)
		{
		 SetFileAttributes(path,FILE_ATTRIBUTE_READONLY);
		 SetFileAttributes(path,FILE_ATTRIBUTE_SYSTEM);	
		}
		else
		{
			SetFileAttributes(path,FILE_ATTRIBUTE_NORMAL);
		} 
			
	 	
	
	
}



Encrypt::~Encrypt()
{
}
