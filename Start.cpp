#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
main()
{
	string message,subject,is,mailto;
	string account,choice,file,filename,filec;
	int accounts;
	cout<<"Email spammer!! \n\n";
	cout<<"How many gmail accounts? "<<endl;
	getline(cin,account);
	stringstream obj;
     	obj<<account;
    	obj>>accounts;
     	obj.clear();
	string gmail[accounts],password[accounts],number,os;
	cout<<"Read from file(Data.txt)? (1 for yes , 0 for no)"<<endl;
	getline(cin,filec);
	     string tp[accounts*2];
	if (filec=="1")
	{
		 fstream newfile;
         newfile.open("Data.txt",ios::in); 
         if (newfile.is_open())
		 {   
          int counter=0;
          for (int f=1;f<=accounts*2;f++)
		  {  
		  getline(newfile, tp[counter]);
		   
               counter++;   
          }
         }
        int number_of_lines = 0;
        string line;
        ifstream myfile("Data.txt");
        while (std::getline(myfile, line))
        ++number_of_lines;
        
        
         int counterb=0;
         for (int r=0;r<accounts*2;r=r+2)
         {
         	gmail[counterb]=tp[r];
         	password[counterb]=tp[r+1];
         	counterb++;
		 }
		 	int x=-1;
		 	for (int s=0;s<accounts;s++)
	    	{
			x++;
			gmail[s]=gmail[x];
			password[s]=password[x];
			if (x==(number_of_lines/2)-1)
			{
				x=-1;
			}
			
	    	}
		 goto label;
	}
	else
{
	for (int z=0;z<accounts;z++)
	{
	cout<<"Enter Your gmail address: (Account : "<<z+1<<")"<<endl;
	getline(cin,gmail[z]);
	gmail[z]=gmail[z].c_str();
	cout<<"Enter the password of your gmail account: (Account : "<<z+1<<")"<<endl;
    getline(cin,password[z]);

	password[z]=password[z].c_str();
	cout<<"Want to auto fill? (Y/N) Capital letters only!"<<endl;
	getline(cin,choice);
	if (choice=="Y")
	{
		int x=-1;
		for (int s=0;s<accounts;s++)
		{
			x++;
			gmail[s]=gmail[x];
			password[s]=password[x];
			if (x==z)
			{
				x=-1;
			}
			
		}
	break;
	}
		
    }
    label:
	cout<<"Enter the mail to spam: "<<endl;
    getline(cin,mailto);
	mailto=mailto.c_str();
	cout<<"Enter the subject for your mails : "<<endl;
	getline(cin,subject);
	subject=subject.c_str();
	cout<<"Enter the message for spam email: "<<endl;
	getline(cin,message);
	message=message.c_str();
	cout<<"Want to send a custom file? (1 for yes, 0 for no)"<<endl;
	getline(cin,file);
	if (file=="1")
	{
		cout<<"Enter file name:"<<endl;
			getline(cin,filename);
			filename=filename.c_str();
	}
	else
	{
		filename="la.txt";
		filename=filename.c_str();
	}
	cout<<"How many messages to spam? (0 for unlimited) "<<endl;
	cin>>number;
	number.c_str();
}
	cout<<"Sending mail...";
	string command;
	for (int o=0;o<accounts;o++)
	{
		stringstream ob;
     	ob<<o;
    	ob>>os;
     	ob.clear();
		 command="start  spammer.exe \""+gmail[o]+"\" \""+password[o]+"\" \""+mailto+"\" \""+subject+"\" \""+message+"\" \""+number+"\" \""+os+"\" \""+filename+"\"";
	     system(command.c_str());

       
    }
 
}
