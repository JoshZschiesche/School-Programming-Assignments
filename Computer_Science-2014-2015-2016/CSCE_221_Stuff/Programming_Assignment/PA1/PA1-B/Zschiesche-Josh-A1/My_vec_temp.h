//Josh Zschiesche
//CSCE 221-505
//Due: Feb/2/2016
//Instructor: Leyk

#include <iostream>

using namespace std;
template<class T>
class My_vec {
//friend ostream& operator<<(ostream& out, const My_vec<T>& vec);

	//member variables
	int size, capacity;
	T *ptr;
	
public:	
	//member functions
	My_vec();
	~My_vec();
	My_vec(const My_vec& vec);
	My_vec& operator=(const My_vec& vec);
	int get_size() const;
	int get_capacity() const;
	T& operator[](int i) const;
	T& operator[](int i);
	bool is_empty() const;
	T& elem_at_rank(int r) const;
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	void resize();
};
	
template<class T>
My_vec<T>::My_vec(){size = 0,capacity = 16,ptr = new T[capacity];}

template<class T>
My_vec<T>::~My_vec(){delete [] ptr;}

template<class T>
My_vec<T>::My_vec(const My_vec& vec){	
		size = vec.size;
		capacity = vec.capacity;
		ptr = new T[capacity];
		for(int i = 0;i<vec.size;++i){ptr[i] = vec.ptr[i];}
}

template<class T>
My_vec<T>& My_vec<T>::operator=(const My_vec<T>& vec){
		size = vec.size;
		capacity = vec.capacity;
		ptr = new T[capacity];
		for(int i = 0;i<vec.size;++i){ptr[i] = vec.ptr[i];}
}

template<class T>
int My_vec<T>::get_size() const{return size;}

template<class T>
int My_vec<T>::get_capacity() const{return capacity;}

template<class T>
T& My_vec<T>::operator[](int i) const{
	return ptr[i];}
	
template<class T>
T& My_vec<T>::operator[](int i){
	return ptr[i];
}
template<class T>
bool My_vec<T>::is_empty() const{
	if(size == 0){return true;}
	return false;}
	
template<class T>	
T& My_vec<T>::elem_at_rank(int r) const{
	if(r<0 || r>size){
		cout<<"Error:out of range!"<<endl;
		}
	else{
		return ptr[r];
		}
		}
	
template<class T>
void My_vec<T>::insert_at_rank(int r, const T& elem){
	if(r<0 || r>size){
		cout<<"Error:out of range!"<<endl;
		return;
		}
		if(size == capacity)
			resize();
		if(ptr[r] != 0){
			for(int i = size;i>r;--i){
				ptr[i]=ptr[i-1];
			}
		}
		ptr[r]=elem;
		++size;
		}
		
template<class T>	
void My_vec<T>::replace_at_rank(int r, const T& elem){
	if(r<0 || r>size){
		cout<<"Error:out of range!"<<endl;
		return;
		}
	if(r == size){
		ptr[r]=elem;
		++size;
		return;}
	if(r == size && size == capacity){
		resize();
		ptr[r]=elem;
		++size;
		return;
	}
	remove_at_rank(r);
	insert_at_rank(r,elem);
	}

template<class T>
void My_vec<T>::remove_at_rank(int r){
	if(r<0 || r+1>size){
		cout<<"Error:No element to romove at rank "<<r<<endl;
		return;
		}
	for(int i = r;i<size;++i){
		ptr[i] = ptr[i+1];
	}
	ptr[size]=0;
	--size;
	}

template<class T>	
void My_vec<T>::resize(){
	capacity = capacity*2;
	T *array = new T[capacity];
		for(int i =0;i<size;++i){
			array[i]=ptr[i];
		}
	delete [] ptr;
	ptr = array;
}	

template<typename T>	
ostream& operator<<(ostream& out, const My_vec<T>& vec){
for(int i=0;i<vec.get_size();++i){
		out<<vec[i];
}
}	 

template<class T>
int find_max_index(const My_vec<T>& v,int s){
	int j = 0;
	for(int i = 0;i<s;++i){
		if(v[i]>v[j]){
		j=i;}
	}

		return j;
	
}
	
template<class T>
void sort_max(My_vec<T>& vec){
	int j;
	T k;
	for(int i=0;i<vec.get_size();++i){
		j = find_max_index(vec,vec.get_size()-1-i);
		k = vec[j];
		vec.replace_at_rank(j,vec[vec.get_size()-1-i]);
		vec[vec.get_size()-1-i] = k;
	}

}


