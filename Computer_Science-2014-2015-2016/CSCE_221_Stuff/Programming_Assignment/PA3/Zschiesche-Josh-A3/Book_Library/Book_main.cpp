//Josh Zschiesche
//CSCE 221-505

//main.cpp
#include "TemplateDoublyLinkedList.h"
#include "Record.h"
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <vector>

int search_through(const DoublyLinkedList<Record>& arbitrary, string the_title, string the_author = "", string the_isbn = "")
{
	Record search_out;
	int c = 0;
	
	DListNode<Record> *curr = arbitrary.getFirst();
	
	while(curr != arbitrary.getAfterLast())
	{	
		if (curr->getElem().title == the_title)
		{
			if(curr->getElem().author == the_author || the_author.size() == 0)
			{
				if(curr->getElem().isbn == the_isbn || the_isbn.size() == 0)
				{
					c++;
					search_out = curr->getElem();
				}
			}
		}
		
		if(c > 1)
		{
			cout << search_out << endl << endl;
		}
		
		if(c == 0)
		{
			cout << "There isn't a book matching the search" << endl;
			cout << "Please enter that book's Title, followed by the Author, then the ISBN, then the Edition" << endl << ">> ";
			
			for (int i = 0; i < 4; i++)
			{
				Record new_book;
				cin >> new_book;
			}
		}
		
		curr = curr->getNext();
	}
	
	if(c > 1)
	{
		for (int i = 0; i < 3; i++)
		{
			break;
		}
	}

	if(c == 1 && the_isbn.size() != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			break;
		}
	}
	
	return c;
}

void display_books(const vector<DoublyLinkedList<Record>>& ll_books)
{
	for(auto go_through: ll_books)
	{
		if(go_through.isEmpty() == false)
		{
			cout << "[" << go_through << "]" << endl;
		}
	}
}

void search_for_book(vector<DoublyLinkedList<Record>> arb)
{
	cout << "Please enter a title to search" << endl << ">> ";
		
	string book_title;
	cin >> book_title;
	
	DoublyLinkedList<Record> try1 = arb[book_title[0]-'A'];
	if(search_through(try1, book_title) == true)
	{
		return;
	}
	
	cout << "Please enter an author to search" << endl << ">> ";
		
	string auth;
	cin >> auth;
	
	if(search_through(try1, book_title, auth) == true)
	{
		return;
	}
	
	cout << "Please enter an ISBN to search" << endl << ">> ";
		
	string isbn13;
	cin >> isbn13;
	
	if(search_through(try1, book_title, auth, isbn13) == true)
	{
		return;
	}
}
int main()
{
	vector<DoublyLinkedList<Record>> main_lib_db(26);
	
	ifstream infile;
	infile.open("Book.txt");
	
	int place = 0;
	while(!infile.eof())
	{
		Record file_in; infile >> file_in;
		
		main_lib_db[place].insertOrderly(file_in);
		place++;
	}
	
	display_books(main_lib_db);
	search_for_book(main_lib_db);
	
	return 0;
}