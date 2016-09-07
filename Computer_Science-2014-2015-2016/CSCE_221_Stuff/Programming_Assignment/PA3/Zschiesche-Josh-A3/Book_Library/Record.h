//Josh Zschiesche
//CSCE 221-505

#include <istream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Record
{
	private:
		
	public:
		string title;
		string author;
		string isbn;
		string year;
		string edition;
	
		//Get Functions
		
		string get_title() const;
		string get_author() const;
		string get_isbn() const;
		string get_year() const;
		string get_edition() const;
		//Set Functions
		
		void set_title(string a);
		void set_author(string b);
		void set_isbn(string c);
		void set_year(string d);
		void set_edition(string f);
		
		string get_title();
		string get_author();
		string get_isbn();
		string get_year();
		string get_edition();
};

istream& operator>> (istream& input, Record& r);
ostream& operator<< (ostream& output, const Record& o);
bool operator< (const Record& r1, const Record& r2);