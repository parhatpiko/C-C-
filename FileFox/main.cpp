#include <iostream>
#include"Filesch.h"
#include"Encrypt.h" 
#include"stdio.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	int serial;
	string path;
	char * _path;
	bool flag;
	printf("********************************************************************************\n");
    printf("                       ");
    printf("Welcome to use FileFox \n");
    printf("                             \n");
    printf("*****************************************************************************author@H.T\n");
	cout<<"Please Enter the mode : Encrypt->1######Decryption->2"<<endl;
	cin>>serial;
	 if((serial==0)||(serial==1))
	 {
	 	flag = true;
	 }
	 else
	 {
	 	flag = false;
	 }
	while(!flag)
	{
		cout<<"Input Error----Encrypt->1######Decryption->2 "<<endl;
		cin>>serial;
		if((serial==0)||(serial==1))
	 {
	 	flag = true;
	 }
	 else
	 {
	 	flag = false;
	 }
	}
	Filesch file(serial);
	Encrypt enc;
	cout<<"Please Enter the full path"<<endl;
	cin>>_path;
	_path = (char *)path.c_str();
	file.filesch(_path);
	file.Work();
	cout<<file.counter<<endl; 
	return 0;
}
