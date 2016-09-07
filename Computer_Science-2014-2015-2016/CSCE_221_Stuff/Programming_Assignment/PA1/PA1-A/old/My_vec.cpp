//Josh Zschiesche
//CSCE 221-505
//My_vec.cpp
//Due: Feb/2/2016

#include <ostream>
#include "My_vec.h"
My_vec::My_vec()
{
	size = 0; //Give size an initial value
	capacity = 4; //Give capacity an initial value
	ptr = new char[capacity]; //create pointer to new array of char's
}
My_vec::~My_vec()
{
	delete[] ptr; //when getting rid of the vector delete the pointer
}
My_vec::get_size()
{
	return size; //return the size
}
My_vec::get_capacity()
{
	return capacity; //return the capacity
}
My_vec& My_vec::operator=(const My_vec& vec) //assign the operator =
{
	size = vec.get_size();
	capacity = vec.get_capacity();
	delete[] ptr;
	ptr = new char[capacity];
	for(int y=0; y<size; y++)
	{
		ptr[y] = vec[y];
	}
}
char& My_vec::operator[](int i) const
{
	return ptr[i];
}
char& My_vec::operator[](int i)
{
	return ptr[i];
}
bool My_vec::is_empty() const
{
	return size == 0;
}
char& My_vec::elem_at_rank(int r) const
{
	if(r <= get_size && r >= 0)
	{
		return ptr[r];
	}
	else
	{
		cerr << "Out of Range"
	}
}
void My_vec::insert_at_rank(int r, const char& elem)
{
	if (r < 0)
	{
		cerr << "Your index was less than 0, this is bad"
	}
	else if (r < size-1)
	{
		if size == capacity;
		{
			capapcity = 2*capacity;
			ptrtemp = new char[capacity];
			
			for (int i = 0; i <= r; ++i)
			{
				ptrtemp[i] = ptr[i];
			}
			
			delete[] ptr;
			ptr=ptrtemp;
		}
	}
	else if (r == size)
	{
	}
}



