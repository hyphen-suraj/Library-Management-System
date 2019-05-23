#include "display.h"
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
#include<dirent.h>

using namespace std;

void display::menu(){
	cout<<"PRESS"<<endl;
	cout<<"1."<<setw(10);
	cout<<"AVALAIBLE BOOKS"<<endl;
	cout<<"2."<<setw(10);
	cout<<"ISSUED BOOKS"<<endl;
		cout<<"3."<<setw(10);
	cout<<"MAIN MENU"<<endl;
	cout<<"PRESS ANY KEY"<<endl;
	int option;
	cin>>option;
	if(option==1){
		ava_books();
	}
	else if(option==2){
	issued_book();	
		
	}
	else if(option==3){
system ("CLS");
			menu_display ob;
			ob.show();
		
	}
	
	
}


string lib[1000];
void display::ava_books(){
		system("CLS");
	int i=0;
	
	lib[0]="WRONG KEY";
 DIR *dir;
struct dirent *ent;
if ((dir = opendir ("C:\\Users\\Suraj\\Desktop\\book donation system\\Books")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
  	if(i>1){
	  
  	printf("%d        ",i-1);
  	string temp=ent->d_name;
  	lib[i-1]=temp;
  	
  	int pos=temp.find(".");
  	string sub = temp.substr(0,pos); 
    cout<<sub<<endl;
  
}

i++;

  }
  closedir (dir);
} 
  cout<<"0.       ";
    cout<<"GO BACK"<<endl;
    
show_book();
	
}



void display::show_book(){
	cout<<"PRESS ANY KEY"<<endl;
	int opt;
	
	cin>>opt;
	if(opt==0){
		system ("CLS");
		menu();
	}
	else {
	
	string temp=lib[opt];
	 int n = temp.length();
	 char array[n + 1];
	 strcpy(array, temp.c_str()); 
	
	char prc[100] = "C:\\Users\\Suraj\\Desktop\\book donation system\\Books\\";
	strcat(prc,array);
	string x;
	ifstream ob;
		ob.open(prc);
		
		             		while (getline(ob,x)){
					   
					   
cout << x<<endl;
}
sub1_menu();
}
}









string library[1000];


void display::issued_book(){
		system("CLS");
	int i=0;
	
	library[0]="WRONG KEY";
 DIR *dir;
struct dirent *ent;
if ((dir = opendir ("C:\\Users\\Suraj\\Desktop\\book donation system\\issued_book")) != NULL) {
  /* print all the files and directories within directory */
  while ((ent = readdir (dir)) != NULL) {
  	if(i>1){
	  
  	printf("%d        ",i-1);
  	string temp=ent->d_name;
  library[i-1]=temp;
  	
  	int pos=temp.find(".");
  	string sub = temp.substr(0,pos); 
    cout<<sub<<endl;
    
}

i++;

  }
  closedir (dir);
} 
cout<<"0.       ";
    cout<<"GO BACK"<<endl;	
show_issued_book();

}



void display::show_issued_book(){
		cout<<"PRESS ANY KEY"<<endl;
	int op;
	cin>>op;
	if(op==0){
		system ("CLS");
		menu();
	}
	else{
	
	string temp=library[op];
	 int n = temp.length();
	 char array[n + 1];
	 strcpy(array, temp.c_str()); 
	
	char prc[100] = "C:\\Users\\Suraj\\Desktop\\book donation system\\issued_book\\";
	strcat(prc,array);
	string x;
	ifstream ob;
		ob.open(prc);
		
		             		while (getline(ob,x)){
					   
					   
cout << x<<endl;
sub_menu();	
}
}
}


void display::sub_menu(){
	cout<<"PRESS"<<endl;
	cout<<"1.     ";
	cout<<"RETURN TO MAIN MENU"<<endl;
	cout<<"2.     ";
	cout<<"GO BACK"<<endl;
		cout<<"3.     ";
	cout<<"EXIT"<<endl;
	int b;
	cin>>b;
	if(b==1)
	{
		system ("CLS");
			menu_display ob;
			ob.show();
	}
	else if (b==2)
	{
			system ("CLS");
	issued_book();	
	}
	else if (b==3)
	{
	exit(0);
		
	}
}



void display::sub1_menu(){
	cout<<"PRESS"<<endl;
	cout<<"1.     ";
	cout<<"RETURN TO MAIN MENU"<<endl;
	cout<<"2.     ";
	cout<<"GO BACK"<<endl;
	int b;
	cin>>b;
	if(b==1)
	{
		system ("CLS");
			menu_display ob;
			ob.show();
	}
	else if (b==2)
	{
			system ("CLS");
ava_books();	
	}
}
