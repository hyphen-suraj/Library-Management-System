#include "book_remove.h"
#include "menu_display.h"
#include<iostream>
#include <cstring>
#include<fstream>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include <windows.h>
using namespace std;

	void book_remove::enter_name(){
			cout<<"ENTER BOOK NAME"<<endl;
		cin>>book;
		remove_book();
		}
		
		void book_remove::remove_book(){
			
				char temp[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
		char temp1[10] =".txt";
	
	strcat(temp,book);
		strcat(temp,temp1);
		 
		 int tempo;
		 tempo=remove(temp);
		 if(tempo==0){
		 	cout<<"FILE DELETED SUCCESSFULY"<<endl;
		 }
			else {
				cout<<"UNABLE TO DELETE FILE"<<endl;
			}
			 
			
			remove_menu();
		
		}
	
	
	
		
			void book_remove::remove_menu(){
			
			cout<<"PRESS"<<endl;
			cout<<"1.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"TO DELETE ANOTHER BOOK"<<endl;
	
	
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
	
	
	int local;
	cin>>local;
	if(local==1)
	{
		enter_name();
		remove_book();
	}
	else if(local==2) {
			system ("CLS");
			menu_display ob;
			ob.show();
	}
		else if(local==0) {
			exit(0);
	}
	
	
		}
