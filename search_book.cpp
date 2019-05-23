#include "search_book.h"
#include "menu_display.h"
#include<iostream>
#include <cstring>
#include<fstream>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include <windows.h>
#include <iomanip>

using namespace std;

string x;

	void search_book::enter_name(){
			cout<<"ENTER BOOK NAME"<<endl;
		cin>>book;
		}
		
		 void search_book::find_book(){
		 	
		 	
		 	
		 	
		 	
		 			char temp[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
		char temp1[10] =".txt";
	
	strcat(temp,book);
		strcat(temp,temp1);
		 	
		 	
		 	
		 	
		exist(temp);	
		 	 
		 	
		 }
		 
		 
		 bool search_book::exist(char name[100])
             {
                  ifstream file(name);
                    if(!file) {
					         
                   cout<<"BOOK NOT FOUND"<<endl;
                   search_menu();
               }
                     else  {
                     	 cout<<"BOOK FOUND"<<endl;
                     	 exist_menu(name);
                     	
					 }               
                      
               }
               
               
               void search_book::exist_menu(char book[100]){
			   
               	cout<<"1."<<setw(31)<<"DISPLAY BOOK DETAILS"<<endl;
               	cout<<"2."<<setw(20)<<"MAIN MENU"<<endl;
               	cout<<"PRESS"<<endl;
               	int key;
               	cin>>key;
               	if(key==1){
               		ifstream obj;
               		obj.open(book);
               		
               		while (getline(obj,x)){
					   
					   
cout << x<<endl;
}
search_menu();

				   }
               }
			   
      void search_book::search_menu(){
      	
      	
cout<<"1."<<setw(30)<<"SEARCH ANOTHER BOOK"<<endl;
cout<<"2."<<setw(20)<<"MAIN MENU"<<endl;
cout<<"3."<<setw(20)<<"EXIT"<<endl;
cout<<"PRESS"<<endl;
int key;
cin>>key;
if(key==1){
	system("CLS");
	 	 enter_name();
			 find_book();
			
  
}
else if(key==2){
	  		system ("CLS");
			menu_display ob;
			ob.show();
	
}

else if(key==3){
	  		exit(0);
	
}

}
               
