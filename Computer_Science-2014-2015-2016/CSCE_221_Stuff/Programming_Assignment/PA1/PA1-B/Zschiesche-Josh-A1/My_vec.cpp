//Josh Zschiesche
//CSCE 221-505
//Due: Feb/2/2016
//Instructor: Leyk

#include "My_vec.h"
#include <stdexcept>
#include<iostream>
using namespace std;
//the constructor
My_vec::My_vec()
{
	size = 0,capacity = 16,ptr = new char[capacity];
}
//the destructor
My_vec::~My_vec()
{
	delete [] ptr;
}
//the copy construct
My_vec::My_vec(const My_vec& vec)
{	
	size = vec.size;
	capacity = vec.capacity;
	ptr = new char[capacity];
	for(int i = 0;i<vec.size;++i){ptr[i] = vec.ptr[i];}
}
//overloading the assignment operator
My_vec& My_vec::operator=(const My_vec& vec)
{ //from my_vec.h
	size = vec.size;
	capacity = vec.capacity;
	ptr = new char[capacity];
	for(int i = 0;i<vec.size;++i){ptr[i] = vec.ptr[i];}
}
//return size and capacity
int My_vec::get_size() const{return size;}

int My_vec::get_capacity() const{return capacity;}

char& My_vec::operator[](int i) const
{
	return ptr[i];
}

char& My_vec::operator[](int i)
{
	return ptr[i];
}
//checks to see if My_vec is empty
bool My_vec::is_empty() const
{
	if(size == 0)
	{
		return true;
	}
	return false;
}
//returns the element at rank r	
char& My_vec::elem_at_rank(int r) const
{
	if(r < 0 || r > size)
	{
		cout<<"Error:out of range!"<<endl;
	}
	else
	{
		return ptr[r];
	}
}
//inserts the element at rank r and pushes from that rank on back one
void My_vec::insert_at_rank(int r, const char& elem)
{
	if(r < 0 || r > size)
	{
		cout<<"Error:out of range!"<<endl;
		return;
	}
	if(size == capacity)
	resize();
	if(ptr[r] != 0)
	{
		for(int i = size;i>r;--i)
		{
			ptr[i]=ptr[i-1];
		}
	}
	ptr[r]=elem;
	++size;
}
	//replaces the element at that rank only
void My_vec::replace_at_rank(int r, const char& elem)
{
	if(r < 0 || r > size)
	{
		throw out_of_range("Element is out of range!");
		return;
	}
	if(r == size)
	{
		ptr[r]=elem;
		++size;
		return;
	}
	if(r == size && size == capacity)
	{
		resize();
		ptr[r]=elem;
		++size;
		return;
	}
	ptr[r]=elem;
}
//removes the element at rank r
void My_vec::remove_at_rank(int r)
{
	if(r < 0 || r+1 > size)
	{
		cout<<"Error:No element to remove at rank " << r << endl;
		return;
	}
	for(int i = r;i<size;++i)
	{
		ptr[i] = ptr[i+1];
	}
	ptr[size]=0;
	--size;
}
//A resize memeber function that i 
void My_vec::resize()
{
	capacity = capacity*2;
	char *array = new char[capacity];
		for(int i =0;i<size;++i)
		{
			array[i]=ptr[i];
		}
	delete [] ptr;
	ptr = array;
}
	
//overloading the << operator for My_vec
ostream& operator<<(ostream& out, const My_vec& vec)
{
	for(int i=0;i<vec.get_size();++i)
	{
		if(vec.ptr[i]!=0){out<<vec.ptr[i];}
		else{++i;}
	}
}	 
//finds the max index and returns it
int find_max_index(const My_vec& v,int s)
{
	int j = 0;
	for(int i = 1;i<s;++i)
	{
		if(v[i]>v[j])
		{
			j=i;
		}
	}
return j;
		
	
}
//sort function that uses the max index function to sort  My_vec
void sort_max(My_vec& vec)
{
	int j;
	char k;
	for(int i=0;i<vec.get_size();++i)
	{
		j = find_max_index(vec,vec.get_size()-1-i);
		k = vec[j];
		vec.replace_at_rank(j,vec[vec.get_size()-1-i]);
		vec[vec.get_size()-1-i] = k;
	}
}


