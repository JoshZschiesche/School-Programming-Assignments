//Josh Zschiesche
//CSCE 221-505

#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DoublyLinkedList; // class declaration
//remove this struct if cant get working and recomment the throws below

template <typename T>
class DListNode 
{
	private: 
		T obj = T();
		DListNode<T> *prev, *next;
		friend class DoublyLinkedList<T>;
		
	public:
		DListNode(T element = T(), DListNode<T> *p = NULL, DListNode<T> *n = NULL)
			: obj(element), prev(p), next(n) {}
		T getElem() const { return obj; }
		DListNode<T> * getNext() const { return next; }
		DListNode<T> * getPrev() const { return prev; }
};

struct EmptyDLinkedListException : range_error 
{
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// doubly linked list
template <typename T>
class DoublyLinkedList
{
	protected: 
		DListNode<T> header, trailer;
		
	public:
		DoublyLinkedList() : header(T()), trailer(T()) // constructor
		{
			header.next = &trailer; trailer.prev = &header;
		}
		DoublyLinkedList(const DoublyLinkedList<T>& dll) // copy constructor
		{
			header = *new DListNode<T>(dll.header.getElem(), NULL, NULL);
			trailer = *new DListNode<T>(dll.trailer.getElem(), NULL, NULL);

			header.next = &trailer; trailer.prev = &header;

			insertFirst(dll.first());
			DListNode<T>* current = dll.getFirst()->getNext();
			
			while (current != dll.getAfterLast())
			{
				insertLast(current->getElem());
				current = current->getNext();
			}
		}
		~DoublyLinkedList() // destructor
		{
			DListNode<T> *prev_node, *node = header.next;
			while (node != &trailer) 
			{
				prev_node = node;
				node = node->next;
				delete prev_node;
			}
			
			header.next = &trailer;
			trailer.prev = &header;
		}

		DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& dll) // assignment operator
		{
			while(!isEmpty())
			{
				removeFirst();
			}
			
			for (DListNode<T> *current_node = dll.getFirst(); current_node != dll.getAfterLast(); current_node = current_node->getNext())
			{
				insertLast(current_node->getElem());
			}
			
			return *this;
		}

		DListNode<T> *getFirst() const { return header.next; } // return the pointer to the trailer
		const DListNode<T> *getAfterLast() const { return &trailer; } // return if the list is empty
		bool isEmpty() const { return header.next == &trailer; }// isEmpty();
		
		T first() const // return the first object
		{
			if (isEmpty())
			{
				throw EmptyDLinkedListException("Empty Doubly Linked List");
			}
			return header.next->obj;
		}

		T last() const // return the last object
		{
			if (isEmpty())
			{
				throw EmptyDLinkedListException("Empty Doubly Linked List");
			}
			return trailer.prev->obj;
		}

		void insertFirst(T newobj) // insert to the first of the list
		{
			DListNode<T> *newNode = new DListNode<T>(newobj, &header, header.next);
			header.next->prev = newNode;
			header.next = newNode;
		}
		
		void insertLast(T newobj) // insert to the last of the list
		{
			DListNode<T> *newNode = new DListNode<T>(newobj, trailer.prev, &trailer);
			trailer.prev->next = newNode;
			trailer.prev = newNode;
		}

		void removeFirst() // remove the first node
		{
			if (isEmpty())
			{
				throw EmptyDLinkedListException("Empty Doubly Linked List");
			}
			DListNode<T> *node = header.next;
			node->next->prev = &header;
			header.next = node->next;
			T obj = node->obj;
			delete node;
		}

		T removeLast() // remove the last node
		{
			if (isEmpty())
			{
				throw EmptyDLinkedListException("Empty Doubly Linked List");
			}
			DListNode<T> *node = trailer.prev;
			node->prev->next = &trailer;
			trailer.prev = node->prev;
			T obj = node->obj;
			delete node;
			return obj;
		}
};// DoublyLinkedList;

template <typename T>
int DoublyLinkedListLength(const DoublyLinkedList<T>& dll) 
{
	int c = 0;
	for (DListNode<T> *current = dll.getFirst(); current != dll.getAfterLast(); current = current->getNext()) {
		c++;
	}
	return c;
}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
	if (dll.isEmpty())
	{
		return out << "empty";
	}
	
	DListNode<T> *node_curr = dll.getFirst();
	
	while (node_curr->getNext() != dll.getAfterLast()) 
	{
		out << node_curr->getElem() << "|";
		node_curr = node_curr->getNext();
	}
	
	out << node_curr->getElem();
	
	return out;
}