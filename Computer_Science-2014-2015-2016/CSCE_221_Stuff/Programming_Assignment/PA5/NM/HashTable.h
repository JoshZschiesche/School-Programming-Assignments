//HashTable.h
//Joseph Gunter
//josephg24
//section: 505
//josephg24

#include <iostream>
#include <fstream>
#include <regex>
#include <stdexcept>
#include <string>
#include "TemplateDoublyLinkedList.h"

using namespace std;

class HashObject{ //Object that holds the 
	public:
		int key, value;
};

ostream& operator<<(ostream& out, const HashObject ho);
void readFile(regex uin, regex scores, vector<string> &keys, vector<string> &grades);
void createTable(vector<string> keys, vector<string> grades, vector<DoublyLinkedList<HashObject>> &hash_table);
void updateRoster(vector<DoublyLinkedList<HashObject>> hash_table);

/*ostream& operator<<(ostream& out, const HashObject ho){
	out << ho.value;
	return out;
}*/ //Didn't use

//reads the input file and stores the uins and grades into vectors
void readFile(regex uin, regex score, vector<string> &keys, vector<string> &grades){
	ifstream ifs;
	int i = 0;
	smatch matches;
	ifs.open("input.csv");
	for(string line; getline(ifs,line);){
		if(regex_search(line,matches,uin)){		//finds and stores the uin
			keys.push_back(matches[0]);
		}
		if(regex_search(line,matches,score)){	//finds and stores the grade
			grades.push_back(matches[0]);
			grades[i] = grades[i].substr(2,2);
		}
		i++;
	}
	ifs.close();
}

//creates a hash table from the vectors
void createTable(vector<string> keys, vector<string> grades, vector<DoublyLinkedList<HashObject>> &hash_table){
	for(int j = 0; j < keys.size(); j++){
			int temp = stoi(keys[j]);
			int index = temp%hash_table.size();
			HashObject storage;
			storage.key = temp;
			storage.value = stoi(grades[j]);
			hash_table[index].insertLast(storage);
		}
}

//updates the roster by adding the grades and then outputs them to output.csv
void updateRoster(vector<DoublyLinkedList<HashObject>> hash_table){
	ifstream ifs;
	regex uin ("\\d{9}");
	smatch matches;
	vector<string> students, keys;
	ifs.open("roster.csv");
	for(string line; getline(ifs,line);){		//reads roster.csv and stores the entire line
		students.push_back(line);				//along with the uin
		if(regex_search(line,matches,uin)){
			keys.push_back(matches[0]);
		}
	}
	ifs.close();
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