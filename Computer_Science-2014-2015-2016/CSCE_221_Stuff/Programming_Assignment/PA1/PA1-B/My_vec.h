//Josh Zschiesche
//CSCE 221-505
//Due: Feb/2/2016
//Instructor: Leyk
#include <ostream>

using namespace std;

class My_vec {
friend ostream& operator<<(ostream& out, const My_vec& vec);

	//member variables
	int size, capacity;
	char *ptr;
	
public:	
	//member functions
	My_vec();
	~My_vec();
	My_vec(const My_vec& vec);
	My_vec& operator=(const My_vec& vec);
	int get_size() const;
	int get_capacity() const;
	char& operator[](int i) const;
	char& operator[](int i);
	bool is_empty() const;
	char& elem_at_rank(int r) const;
	void insert_at_rank(int r, const char& elem);
	void replace_at_rank(int r, const char& elem);
	void remove_at_rank(int r);
	void resize();
};
	
	ostream& operator<<(ostream& out, const My_vec& vec);
	int find_max_index(const My_vec& v,int s);
	void sort_max(My_vec& vec);