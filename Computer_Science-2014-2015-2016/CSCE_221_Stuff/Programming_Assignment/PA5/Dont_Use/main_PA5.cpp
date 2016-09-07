#include <regex>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include "TemplateDoublyLinkedList.h"


struct HashObject //was class and had public:
{ 
	int key;
	int value;
};

/*ostream& operator<<(ostream& out, const HashObject ho);
void readFile(regex uin, regex scores, vector<string> &keys, vector<string> &grades);
void createTable(vector<string> keys, vector<string> grades, vector<DoublyLinkedList<HashObject>> &hash_table);
void updateRoster(vector<DoublyLinkedList<HashObject>> hash_table);*/

/*ostream& operator<<(ostream& out, const HashObject ho){
	out << ho.value;
	return out;
}*/ //Didn't use

//reads the input file and stores the uins and grades into vectors
void readFile(regex uin, regex score, vector<string> &keys, vector<string> &grades)
{
	ifstream inputfstream1;
	int i = 0;
	smatch matches;
	inputfstream1.open("input.csv");
	for(string line; getline(inputfstream1,line);)
	{
		if(regex_search(line,matches,uin))
		{		//finds and stores the uin
			keys.push_back(matches[0]);
		}
		if(regex_search(line,matches,score))
		{	//finds and stores the grade
			grades.push_back(matches[0]);
			grades[i] = grades[i].substr(2,2);
		}
		i++;
	}
	inputfstream1.close();
}

//creates a hash table from the vectors
void createTable(vector<string> keys, vector<string> grades, vector<DoublyLinkedList<HashObject>> &hash_table)
{
	for(int j = 0; j < keys.size(); j++)
	{
		int temp = atoi(keys[j]);
		int index = temp%hash_table.size();
		HashObject storage;
		storage.key = temp;
		storage.value = stoi(grades[j]);
		hash_table[index].insertLast(storage);
	}
}

//updates the roster by adding the grades and then outputs them to output.csv
void updateRoster(vector<DoublyLinkedList<HashObject>> hash_table)
{
	ifstream inputfstream2;
	regex uin ("\\d{9}");
	smatch matches;
	vector<string> students;
	vector<string> keys;
	inputfstream2.open("roster.csv");
	
	for(string line; getline(inputfstream2,line);)
	{		//reads roster.csv and stores the entire line
		students.push_back(line);				//along with the uin
		if(regex_search(line,matches,uin))
		{
			keys.push_back(matches[0]);
		}
	}
	
	inputfstream2.close();
	ofstream ofs;
	ofs.open("output.csv");
	for(int i = 0; i < keys.size(); i++){
			int temp = stoi(keys[i]);
			int index = temp%hash_table.size();	//evaluate the key to create an index to be searched in the hash table
			DListNode<HashObject> *temp_node;
			temp_node = hash_table[index].getFirst();
				
			while(temp_node != NULL){					//compares the current key value in the hash table with
				if(temp_node->getElem().key == temp){	//the key value of the current line
					if(!students[i].empty()){
						students[i].pop_back();
						students[i] = students[i] + to_string(temp_node->getElem().value);
					}
					break;
				}
				else{
					temp_node = temp_node->getNext();
				}
			}
			if(!students[i].empty()){
				ofs << students[i] << endl;
			}
	}
	ofs.close();
}

using namespace std;

int main()
{
	//try{
		vector<string> keys, grades;
		regex uin ("\\d{9}");
		regex score ("\\d,\\d{2,3}");
		readFile(uin, score, keys, grades);
		vector<DoublyLinkedList<HashObject>> hash_table (keys.size()); //change keys.size to a number or some toher variable
		createTable(keys,grades,hash_table);
		updateRoster(hash_table);
	//}
	/*catch(exception& error){
		cerr << "Error: " << error.what() << endl;
		return 1;
	}
	catch(...){
		cerr << "Oops. Unknown Error!" << endl;
		return 2;
	}*/
	return 0;
}