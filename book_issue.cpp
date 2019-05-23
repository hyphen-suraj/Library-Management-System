#include "book_issue.h"

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

void book_issue::enter_book(){
		cin.ignore();
	cout<<"ENTER BOOK NAME :"<<endl;
	scanf("%[^\n]%*c",book);
	char amount;
	char prc[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
		char prc1[10] =".txt";
		strcat(prc,book);
		strcat(prc,prc1);
		ifstream ob;
		ob.open(prc);
		if(!ob){
			cout<<"BOOK IS CURRENTLY UNAVAILAIBLE"<<endl;
			issue_menu();
		}
		else {
		
		ob.seekg(-1,ios::end);
		bool keepLooping = true;
        while(keepLooping) {
            char ch;
            ob.get(ch);                            // Get current byte's data

            if((int)ob.tellg() <= 1) {             // If the data was at or before the 0th byte
                ob.seekg(0);                       // The first line is the last line
                keepLooping = false;                // So stop there
            }
            else if(ch == '\n') {                   // If the data was a newline
                keepLooping = false;                // Stop at the current position.
            }
            else {                                  // If the data was neither a newline nor at the 0 byte
                ob.seekg(-2,ios::cur);        // Move to the front of that data, then to the front of the data before it
            }
        }

        	string lastLine;            
        getline(ob,lastLine);                      // Read the current line
        int pos=lastLine.find(":");
         string sub = lastLine.substr(pos + 2); 
        
       ob.close();  
   int b = atoi(sub.c_str());
   if(b>0){
   	create_record();
   	ob.open(prc);
   	 string pri="QUANTITY: ";
   	 string line;
   	ofstream temp;
    temp.open("temp.txt",ios::app);
    
     
    
  
    while (getline(ob,line))
    {
      if (!strstr(line.c_str(),pri.c_str())){
	  
        temp << line << endl;
       
   }
        
    }
    
  
    
    temp<<"QUANTITY: ";
    int c=b-1;
    temp<<c;
   	 ob.close();
    temp.close();
    remove(prc);
    rename("temp.txt", prc);
   }
   else {
   	cout<<"BOOK IS CURRENTLY UNAVAILAIBLE"<<endl;
   }




	issue_menu();


}
	
}
 
void book_issue::create_record(){
	ofstream obj;
	
		char temp[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\issued_book\\";
		char temp1[10] =".txt";
	
		
		strcat(temp,book);
		strcat(temp,temp1);
		
			obj.open(temp,ios::app);
			obj<<"NAME OF BOOK: ";
		
		
		
		obj<<book;
		obj<<"\n";
		
		
		
		char student[100];
		cout<<endl;
		cout<<"ENTER STUDENT NAME"<<endl;
		cin.ignore();
		scanf("%[^\n]%*c",student);
		obj<<"STUDENT NAME: ";
	
		obj<<student;
		obj<<"\n";
		
		
		
		char regis[100];
		cout<<"ENTER REGISTRATION NO."<<endl;
		scanf("%[^\n]%*c",regis);
		obj<<"REGISTRATION NO. : ";
		
		obj<<regis;
		obj<<"\n";
		
		
		char issue[100];
		cout<<"ENTER DATE OF ISSUE"<<endl;
		scanf("%[^\n]%*c",issue);
		obj<<"DATE OF ISSUE: ";
		
		obj<<issue;
		obj<<"\n";
		
			
		obj<<"*****************************";
		obj<<"\n";
				
		
		if(!obj) 
   { 
       cout<<"Error in saving!!!"<<endl; 
       
	   
	    
   } 
  else
   cout<<"BOOK ISSUED successfully."<<endl;


		 
		 		obj.close();
		 		
	
		
}




void book_issue::issue_menu(){
			cout<<"PRESS"<<endl;
			cout<<"1.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"TO ISSUE ANOTHER BOOK"<<endl;
	
	
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
char
 loc_add;
	cin>>loc_add;
	cout<<loc_add;
	
	
	
	if(loc_add=='1')
	{
		system ("CLS");
		
		 enter_book();
	 create_record();
	}
	else if(loc_add=='2') {
			system ("CLS");
			menu_display ob;
			ob.show();
	}
	
	
	else if(loc_add=='0') {
			exit(0);
	}
	

}
