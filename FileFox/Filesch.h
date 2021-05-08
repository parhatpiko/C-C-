#ifndef FILESCH_H
#define FILESCH_H 

#include<list>
#include<iostream>
#include<string>
#include<io.h>

using namespace std;

class Filesch
{
	public:
		Filesch(int mode);
		~Filesch();
	
	public:
     std::list<string> directory_list;
     std::list<string> FileName_list;
     std::list<string> En_FileName_list;
    //list<string>::iterator it = str_path.begin();
	
	public:
	 void filesch(char *path);
	
	public:
	void Work();
	
	private:
	 int mode; 
	
	public:
	 int counter = 0; 				
		
};

#endif

