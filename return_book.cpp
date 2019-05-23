#include "return_book.h"
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

void return_book::enter_book(){
	char reg[100];
	char book[100];
	char date[100];
	
	cin.ignore();
	
	
	cout<<"ENTER BOOK NAME ";
	scanf("%[^\n]%*c",book);


	
		ifstream obj;
	
		char temp[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\issued_book\\";
		char temp1[10] =".txt";
	
		
		strcat(temp,book);
		strcat(temp,temp1);
		
			obj.open(temp);
		string x;	
			if(!obj)
			{
				cout<<"THIS BOOK NOT ISSUED"<<endl;
			}
			else {
			cout<<"ENTER REGISTRATION NO.";
	scanf("%[^\n]%*c",reg);
	
	cout<<"BOOK RETURN DATE ";
	scanf("%[^\n]%*c",date);
	
			char ser[]="REGISTRATION NO. : ";
			strcat(ser,reg);
			ofstream ob;
			ob.open("exp.txt",ios::app);
		while (getline(obj,x)){
			ob << x << endl;		   
		if(x==ser){
			getline(obj,x);
			int pos=x.find(":");
         string sub = x.substr(0,pos); 
         cout<<sub<<endl;
         if(sub=="BOOK RETURN DATE ")
         {
         	ob << x << endl;
         
		 }
		 else {
		 
		 
			ob<<"BOOK RETURN DATE :"<<date<<endl;
			ob << x << endl;
			
		}
		}
					   

}
			
obj.close();
ob.close();
cout<<"BOOK RETURN SUCCESSFULLY"<<endl;
remove(temp);

    rename("exp.txt", temp);
add_book(book);
}
list();

}



void return_book::list(){
	
	cout<<"PRESS"<<endl;
	cout<<"1.     "<<"RETURN ANOTHER BOOK"<<endl;
	cout<<"2.     "<<"MAIN MENU"<<endl;
	cout<<"3.     "<<"EXIT"<<endl;
	cout<<"PRESS ANY KEY"<<endl;
	
	int b;
	cin>>b;
	
	if(b==1)
	{
		system ("CLS");
		enter_book();
		
	}
	if(b==2){
			system ("CLS");
			menu_display ob;
			ob.show();
	}
	
	
	if(b==3){
			exit(0);
	}
}




void return_book::add_book(char b[100]){

	char prc[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
		char prc1[10] =".txt";
		strcat(prc,b);
		strcat(prc,prc1);
		ifstream ob;
		ob.open(prc);
	
		
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
   int exp = atoi(sub.c_str());


	ob.open(prc);
   	 string pri="QUANTITY: ";
   	 string line;
   	ofstream temp;
    temp.open("tempo.txt",ios::app);
    
     
    
  
    while (getline(ob,line))
    {
      if (!strstr(line.c_str(),pri.c_str())){
	  
        temp << line << endl;
       
   }
        
    }
    
  
    
    temp<<"QUANTITY: ";
    int c=exp+1;
    temp<<c;
   	 ob.close();
    temp.close();
    remove(prc);
    rename("tempo.txt", prc);
}
