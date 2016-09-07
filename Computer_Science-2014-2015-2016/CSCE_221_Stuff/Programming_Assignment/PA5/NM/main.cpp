/*
Joseph Gunter
josephg24
section: 505
josephg24@tamu.edu
*/

#include "HashTable.h"

using namespace std;

int main(){
	try{
		vector<string> keys, grades;
		regex uin ("\\d{9}");
		regex score ("\\d,\\d{2,3}");
		readFile(uin, score, keys, grades);
		vector<DoublyLinkedList<HashObject>> hash_table (keys.size()); //change keys.size to a number or some toher variable
		createTable(keys,grades,hash_table);
		updateRoster(hash_table);
	}
	catch(exception& error){
		cerr << "Error: " << error.what() << endl;
		return 1;
	}
	catch(...){
		cerr << "Oops. Unknown Error!" << endl;
		return 2;
	}
	return 0;
}