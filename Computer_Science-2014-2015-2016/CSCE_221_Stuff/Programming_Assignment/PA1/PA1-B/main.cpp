//Josh Zschiesche
//CSCE 221-505
//Due: Feb/2/2016
//Instructor: Leyk

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){
try{
    // define an object v of My_vec type
    // insert 'B' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
    // display the vector v size
	My_vec v;
	v.insert_at_rank(0,'B');
	cout << v;
	cout << v.get_size()<<endl;
	// insert 'A' at the rank 0 into the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	v.insert_at_rank(0,'A');
	cout << v;
	cout << v.get_size()<<endl;
	// insert 'D' at the rank 10 into the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	v.insert_at_rank(10,'D');
	cout << v;
	cout << v.get_size()<<endl;
	// remove a character at the rank 2 from the vector v
	// use the overloaded operator << to display vector elements
	// display the vector v size
	v.remove_at_rank(2);
	cout << v;
	cout << v.get_size() << endl;
	// replace a character at the rank 2 by the character 'E' 
	// use the overloaded operator << to display vector elements
	// display the vector v size
	v.replace_at_rank(2,'E');
	cout << v;
	cout << v.get_size() << endl;
	// create a copy v1 of the vector v using a copy constructor
	// use the overloaded operator << to display the vector v1
    // replace a character at the rank 2 of the vector v1 with the character 'Y'
	// use the overloaded operator << to display vector v1 elements	My_vec v1(v);
	v1.insert_at_rank(0,'K');
	cout<<v1;
	cout<<v1.get_size()<<endl;
	// define an object v2 of My_vec type
	// insert 'K' at the rank 0 into the vector v2
	// use the overloaded operator << to display vector elements
    // display the vector v2 size
	My_vec v2;
	v2.insert_at_rank(0,'K');

	cout << v2;
	cout << v2.get_size()<<endl;
    // test the assignment operator and copy the vector v1 to v2 
    // use the overloaded operator << to display vector v2
    // display the vector v2 size
	v2 = v1;
	v2.insert_at_rank(1,'R');
	cout << v2;

	cout << v1.get_size()<<endl;
    // test the function find_max_index using v2
	// test the function sort_max using v2
	// replace in the vector v2 a character at the rank 14 with 'S'
	find_max_index(v2,v2.get_size());
	sort_max(v2);
	cout << v2;
	cout << endl;
	v2.replace_at_rank(14,'k');

	}

	catch(exception &error){
		cerr << "Error: " << error.what() << endl;
	}
}
