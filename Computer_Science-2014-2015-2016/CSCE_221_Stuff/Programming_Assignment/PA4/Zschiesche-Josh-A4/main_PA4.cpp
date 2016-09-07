#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

vector<char> conv(const string &string)
{
	return vector<char>(string.begin(), string.end());
}

int main()
{
	double number_of_nodes = 0.0;
	cout << "Please enter the name of a file" << endl << ">> ";
	string file_in;
	cin >> file_in;
	cout << "You entered in " << file_in << endl;
	
	BinarySearchTree tree;
	
	string line;
	ifstream myfile (file_in);
	
	while (myfile>>line)
	{
		cout << "Key: " << line << " Search Cost: ";
		
		int value = atoi(line.c_str());
			
		tree.insert(value);
		cout << s << endl;
		
		totalCostSearch = s + totalCostSearch;
		++number_of_nodes;
		s = 1;
	}
	myfile.close();
	
	if (number_of_nodes < 17)
	{
		cout << "Average Cost Was: " << totalCostSearch/number_of_nodes << endl;
		vector<char> myVec = conv(file_in);
		
		cout << "I Am printing" << endl;
		cout << tree;
		
		cout << endl << "PreOrder" << endl;
		PrintTreeNode pt;
		tree.getRoot()->preOrderTraversal(pt);
		
		cout << endl << "PostOrder" <<endl;
		tree.getRoot()->postOrderTraversal(pt);
		
		cout << endl << "InOrder" << endl;
		tree.getRoot()->inOrderTraversal(pt);
		
		cout << endl << "I Have printed" << endl;
		
		cout << "PLease enter the key of the node to DELETE." << endl;
		cout << "To skip this step enter 0 or a negative number" << endl << ">> ";
		
		int ans = 0;
		cin >> ans;
		if(ans > 0)
		{
			tree.remove(ans);
			PrintTreeNode qt;
			tree.getRoot()->inOrderTraversal(qt);
		}
		else
		{
			cout << "Thank you for using this Program and not removing anything!!" << endl;
		}
		
		cout << "No output file was generated! Must have more than 16 nodes!" << endl;
	}
	else 
	{
		cout << "Average Cost Was: " << totalCostSearch/number_of_nodes << endl;
		
		cout << "The number of nodes was greater than 16!" << endl;
		cout << "Creating ostream" << endl;
		
		ofstream out_stream;
		out_stream.open ("output.txt");
		
		out_stream << "I Am printing to output.txt" << endl;
		
		streambuf* backup = cout.rdbuf();
		streambuf* testbuf = out_stream.rdbuf();
		cout.rdbuf(testbuf);
		
		out_stream << endl << "PreOrder" << endl;
		PrintTreeNode pt;
		tree.getRoot()->preOrderTraversal(pt);
		
		cout << endl << "PostOrder" <<endl;
		tree.getRoot()->postOrderTraversal(pt);
		
		cout << endl << "InOrder" << endl;
		tree.getRoot()->inOrderTraversal(pt);
		
		cout.rdbuf(backup);
		cout << endl << "I Have printed to output.txt" << endl;
		
		out_stream.close();
	}
}