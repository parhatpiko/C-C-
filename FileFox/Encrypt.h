#ifndef ENCRYPT_H
#define ENCRYPT_H
#include"list"
#include<iostream>

using namespace std;

class Encrypt
{
	public:
		Encrypt();
	    ~Encrypt();
		
    public:
	 void Enfactor(char * in_fname,char * out_fname,int password);	
	 void del(char * del_path);
	
	public:
	void FileAttri(char *path,int mode);
	
	
	
	 	 
	
	protected:
};

#endif
