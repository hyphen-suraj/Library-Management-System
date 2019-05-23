#include "menu_display.h"
#include<iostream>
#include <iomanip>
#include<string>
#include <dir.h>
#include "add_book.h"
#include "book_remove.h"
#include "search_book.h"
#include "book_issue.h"
#include "display.h"
#include "return_book.h"
using namespace std;

	void menu_display::show(){
	
	string s="BOOK MANAGEMENT SYSTEM";
	cout<<setw(75)<<s<<endl;
	cout<<setw(54);

	for(int i=0;i<s.length();i++)
	{
		cout<<"=";
	}
	cout<<endl;
	cout<<"MAIN MENU"<<endl;
	cout<<"Press"<<endl;
	cout<<"1.";
	for(int i=0;i<20;i++){
		cout<<" ";
	}
	cout<<"ADD BOOK"<<endl;
cout<<"2.";
	for(int i=0;i<20;i++){
		cout<<" ";
	}
	
		cout<<"DELETE BOOK"<<endl;
	cout<<"3.";	
	for(int i=0;i<20;i++){
		cout<<" ";
	}
		cout<<"SEARCH"<<endl;
			cout<<"4.";	
				for(int i=0;i<20;i++){
		cout<<" ";
	}
		cout<<"DISPLAY"<<endl;
			cout<<"5.";	
						for(int i=0;i<20;i++){
		cout<<" ";
	}
		cout<<"ISSUE BOOK"<<endl;
		
		
				cout<<"6.";	
						for(int i=0;i<20;i++){
		cout<<" ";
	}
		cout<<"RETURN BOOK"<<endl;
				cout<<"7.";	
						for(int i=0;i<20;i++){
		cout<<" ";
	}
		cout<<"EXIT"<<endl;
	
	cout<<"PRESS ANY KEY "<<endl;
	int key;
	cin>>key;
	
	mkdir("Books");
	
	
	
	if(key==1){
		
		
		add_book ob;
		ob.enter_name();
		ob.addbook();
		
	}
	
	
	else if(key==2){
		
		
	book_remove ob;
		ob.enter_name();
		ob.remove_book();
	
		
	}
	
	
	
	else if(key==3){
		
		
	search_book ob;
		ob.enter_name();
		ob.find_book();
	
		
	}
	
	
		else if(key==4){
		display obj;
		obj.menu();
	
	}
	else if(key==5){
		book_issue ob;
		ob.enter_book();
	
	}
	
	else if(key==6){
		return_book ob;
		ob.enter_book();
	
	}
	else if(key==7){
		exit(0);
	
	}
}





