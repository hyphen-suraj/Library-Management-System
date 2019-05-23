#include "log.h"
#include "menu_display.h"
#include<iostream>
#include <cstring>
#include<fstream>
#include<string>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include <windows.h>
#include <iomanip>

using namespace std;

void log::password(){
	
		string s="BOOK MANAGEMENT SYSTEM";
	cout<<setw(75)<<s<<endl;
	cout<<setw(54);

	for(int i=0;i<s.length();i++)
	{
		cout<<"=";
	}
	cout<<endl;
	cout<<"PRESS"<<endl;
	cout<<"1.              "<<"LOG IN"<<endl;
	cout<<"2.              "<<"ADD MEMBER"<<endl;
		cout<<"3.              "<<"EXIT"<<endl;
	cout<<"PRESS ANY KEY"<<endl;
	int b;
	cin>>b;
	if(b==1)
{
	log_in();
	
	}
	else if(b==2)	
	{
		add_member();
	}
	else if(b==3)	
	{
		exit(0);
	}
	else {
		cout<<"ENTER INVALID KEY"<<endl;
		
	}
	
}



void log::log_in(){
	cin.ignore();
	cout<<"ENTER USER NAME:"<<endl;
	char user[100];
	
	scanf("%[^\n]%*c",user);
	cout<<"ENTER PASSWORD :"<<endl;
	char pass[100];
	scanf("%[^\n]%*c",pass);
	char prc[500] = "C:\\Users\\Suraj\\Desktop\\book donation system\\members\\";
		char prc1[10] =".txt";
		strcat(prc,user);
		strcat(prc,prc1);
		ifstream ob;
		ob.open(prc);
		if(!ob){
			cout<<"INVALID USER NAME"<<endl;
		}
		else {
			
		ob.seekg(-1,ios::end);
	
		bool keepLooping = true;
        while(keepLooping) {
            char ch;
            ob.get(ch);                            
 
            if((int)ob.tellg() <= 1) {  
			           
                ob.seekg(0);                       
                keepLooping = false;                
            }
            else if(ch == '\n') { 
			                   
                keepLooping = false;                
            }
            else {  
			                                
                ob.seekg(-2,ios::cur);   
				 	  
            }
        }

        	string lastLine;            
        getline(ob,lastLine); 
		                    
        int pos=lastLine.find(":");
          string sub = lastLine.substr(pos + 2); 
          cout<<sub<<endl;
          
        if(sub==pass){
        	system("CLS");
        		menu_display ob;
	ob.show();
		}
        
	else {
		cout<<"INVALID PASSWORD"<<endl;
	}
	
	
	
}


}


void log::add_member(){
		cin.ignore();
	cout<<"ENTER MEMBER NAME :"<<endl;
	char name[100];
scanf("%[^\n]%*c",name);
char prc[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\members\\";
		char prc1[10] =".txt";
		strcat(prc,name);
		strcat(prc,prc1);
	ofstream obj;
	obj.open(prc,ios::app);
	
	
	
	
		obj<<"NAME: ";
		
		
		
		obj<<name;
		obj<<"\n";
		
		
		
		char father[100];
		cout<<"ENTRE FATHER NAME: "<<endl;
		cin.ignore();
		scanf("%[^\n]%*c",father);
		obj<<"FATHERS NAME: ";
	
		obj<<father;
		obj<<"\n";
		
		
		char email[100];
		cout<<"ENTER EMAIL ID"<<endl;
		scanf("%[^\n]%*c",email);
		obj<<"EMAIL ID: ";
		
		obj<<email;
		obj<<"\n";
		
			
	
		
				
	
		
		char age[10];
		cout<<"ENTER AGE :"<<endl;
		scanf("%[^\n]%*c",age);
		obj<<"AGE : ";
		
		obj<<age;
		
		obj<<"\n";
			char pass[100];
		cout<<"ENTER PASSWORD"<<endl;
		scanf("%[^\n]%*c",pass);
		obj<<"PASSWORD : ";
		
		obj<<pass;
	
		
			
		if(!obj) 
   { 
       cout<<"Error in member adding!!!"<<endl; 
       
	   
	    
   } 
  else
   cout<<"Member added successfully."<<endl;


		 
		 		obj.close();

		
	
	add_menu();
}








	void log::add_menu(){
			
			cout<<"PRESS"<<endl;
			cout<<"1.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"TO ADD ANOTHER MEMBER"<<endl;
	
	
		cout<<"2.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"RETURN TO MAIN MENU"<<endl;
	
	
		cout<<"0.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"EXIT"<<endl;
	int loc_add;

	cin>>loc_add;
	cout<<loc_add;
	
	
	
	if(loc_add==1)
	{
		system ("CLS");
		
		add_member();
	}
	else if(loc_add==2) {
			system ("CLS");
			password();
	
	
}


	else if(loc_add==0) {
		exit(0);
	
	
}
}
		
