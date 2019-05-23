#include "add_book.h"
#include "menu_display.h"
#include<iostream>
#include <cstring>
#include<fstream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include <windows.h>
using namespace std;


	
		void add_book::enter_name(){
			cin.ignore();
			cout<<"ENTER BOOK NAME"<<endl;
		scanf("%[^\n]%*c",book);
		
		}
		
		
		
		
		
	void add_book::addbook(){
		ofstream obj;
	
		
		char temp[200] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
		char temp1[10] =".txt";
	
		
		strcat(temp,book);
		strcat(temp,temp1);
		
			obj.open(temp,ios::app);
	
		
	
			
		
		obj<<"NAME OF BOOK: ";
		
		
		
		obj<<book;
		obj<<"\n";
		
		
		
		char publi[100];
		cout<<"ENTER PUBLICATION"<<endl;
		cin.ignore();
		scanf("%[^\n]%*c",publi);
		obj<<"PUBLICATION NAME: ";
	
		obj<<publi;
		obj<<"\n";
		
		
		char author[100];
		cout<<"ENTER AUTHOR"<<endl;
		scanf("%[^\n]%*c",author);
		obj<<"AUTHOR NAME: ";
		
		obj<<author;
		obj<<"\n";
		
			
		char edition[100];
		cout<<"ENTER EDITION"<<endl;
		scanf("%[^\n]%*c",edition);
		obj<<"EDITION: ";
		
		obj<<edition;
		obj<<"\n";
		
				
		char price[10];
		cout<<"ENTER PRICE"<<endl;
		scanf("%[^\n]%*c",price);
		obj<<"PRICE: ";
		
		obj<<price;
		obj<<"\n";
		
		char quantity[10];
		cout<<"ENTER QUANTITY"<<endl;
		scanf("%[^\n]%*c",quantity);
		obj<<"QUANTITY: ";
		
		obj<<quantity;
		
		
		
		if(!obj) 
   { 
       cout<<"Error in saving!!!"<<endl; 
       
	   
	    
   } 
  else
   cout<<"File saved successfully."<<endl;


		 
		 		obj.close();

		add_menu();	
	
		}





	void add_book::add_menu(){
			
			cout<<"PRESS"<<endl;
			cout<<"1.";
			for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"TO ADD ANOTHER BOOK"<<endl;
	
	
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
	
	cin>>loc_add;
	cout<<loc_add;
	
	
	
	if(loc_add=='1')
	{
		system ("CLS");
		
		 enter_name();
	 addbook();
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
