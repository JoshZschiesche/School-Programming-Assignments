//Josh Zschiesche
//CSCE 221-505

#include "Record.h"
#include <istream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

	string Record::get_title() const
	{
		return title;
	}
	string Record::get_author() const
	{
		return author;
	}
	string Record::get_isbn() const
	{
		return isbn;
	}
	string Record::get_year() const
	{
		return year;
	}
	string Record::get_edition() const
	{
		return edition;
	}
		
	//Set Functions
		
	void Record::set_title(string a)
	{
		a = title;
	}
	void Record::set_author(string b)
	{
		b = author;
	}
	void Record::set_isbn(string c)
	{
		c = isbn;
	}
	void Record::set_year(string d)
	{
		d = year;
	}
	void Record::set_edition(string f)
	{
		f = edition;
	}
		
	string Record::get_title()
	{
		return title;
	}
	string Record::get_author()
	{
		return author;
	}
	string Record::get_isbn()
	{
		return isbn;
	}
	string Record::get_year()
	{
		return year;
	}
	string Record::get_edition()
	{
		return edition;
	}

istream& operator>> (istream& input, Record& r)
{
	string in_title;
	string in_author;
	string in_isbn;
	string in_year;
	string in_edition;
	
	getline(input,in_title);
	if(in_title == " ")
	{
		getline(input,in_title);
	}
	
	getline(input,in_author);
	if(in_author == " ")
	{
		getline(input,in_author);
	}
	
	getline(input,in_isbn);
	if(in_isbn == " ")
	{
		getline(input,in_isbn);
	}
	
	getline(input,in_year);
	if(in_year == " ")
	{
		getline(input,in_isbn);
	}
	
	getline(input,in_edition);
	if(in_edition == " ")
	{
		getline(input,in_edition);
	}
	
	r.set_title(in_title);
	r.set_author(in_author);
	r.set_isbn(in_isbn);
	r.set_year(in_year);
	r.set_edition(in_edition);
}

ostream& operator<< (ostream& output, const Record& o)
{	
	output << "The title is " << o.get_title();
	output << "The author is: " << o.get_author();
	output << "The ISBN is: " << o.get_isbn();
	output << "The year is: " << o.get_year();
	output << "The edition is: " << o.get_edition();
}

bool operator< (const Record& r1, const Record& r2) 
{
	if (r1.get_title() == r2.get_title())
	{
		if (r1.get_author() == r2.get_author())
		{
			if (r1.get_isbn() == r2.get_isbn())
			{
				return false;
			}
			else if (r1.get_isbn() > r2.get_isbn())
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if (r1.get_author() > r2.get_author())
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (r1.get_title() > r2.get_title())
	{
		return false;
	}
	else
	{
		return true;
	}
}