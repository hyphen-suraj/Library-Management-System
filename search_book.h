#ifndef SEARCH_BOOK_H
#define SEARCH_BOOK_H
#include<string>
class search_book
{

	private:
		char book[100];
	public:
			void enter_name();
			void find_book();
			bool exist(char name[100]);
			void exist_menu(char book[100]);
			void search_menu();
			
};

#endif
