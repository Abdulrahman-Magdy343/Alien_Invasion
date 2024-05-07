#pragma once
#include "DLnode.h"
#include <iterator>
using namespace std;

template <typename T>
class Deque
{
private:
	DLnode<T>* front;
	DLnode<T>* back;
	int count;
public:
	Deque() 
	{
		front = back = nullptr;
	}
	bool isEmpty() const { return (front == NULL && back == NULL); }

	int getCount() { return count; }

	bool includePairOrMore() { return count >= 2; }

	bool insertFront(const T& item)
	{
		DLnode<T>* newNode = new DLnode<T>(item);
		if (isEmpty())
		{
			front = back = newNode;
		}
		else
		{
			newNode->setNext(front);
			front->setPrev(newNode);
			front = newNode;
		}
		count++;
		return true;	
	}
	bool insertBack(const T& item)
	{
		DLnode<T>* newNode = new DLnode<T>(item);
		if (isEmpty())
		{
			front = newNode;
		}
		else
		{
			back->setNext(newNode);
			newNode->setPrev(back);
			back = newNode;
		}
		count++;
		return true;
	}
	void print() const {
		if (isEmpty()) cout << "the queue is empty" << endl;
		else
		{
			DLnode<T>* temp = front;
			while (temp) {
				cout << temp->getItem()->getID() << "\t";
				temp = temp->getNext();
			}
			
		}

	}

	bool removeBack(T &holder)
	{
		if (!isEmpty()) 
		{
			DLnode<T>* temp = back;
			holder = temp->getItem();
			if (back == front)
				front = back = nullptr;
			else
			{
				back = back->getPrev();
				back->setNext(nullptr);
			}
			delete temp;
			temp = nullptr;
			count--;
			return true;
		}
		else
			return false;
	}
	bool removeFront(T& holder)
	{
		if (!isEmpty())
		{
			DLnode<T>* temp = front;
			holder = temp->getItem();
			if (back == front)
				front = back = nullptr;
			else
			{
				front = front->getNext();
				front->setPrev(nullptr);
			}
			delete temp;
			temp = nullptr;
			count--;
			return true;
		}
		else
			return false;
	}

	bool peekFront(T& holder) const
	{
		if (isEmpty())
			return false;
		holder = front->getItem();
		return true;
	}
	bool peekBack(T& holder) const
	{
		if (isEmpty())
			return false;
		holder = back->getItem();
		return true;
	}

	//void display()
	//{
	//	while (!isEmpty())
	//	{
	//		T ent;
	//		removeFront(ent);
	//		cout << ent << " ";
	//	}
	//}

	void display()
	{
		for (auto it = begin(); it != end(); it++)
		{
			cout << *it << " ";
		}
	}

	virtual ~Deque()
	{
		cout << "\nFreeing all nodes in the Deque...";

		//Free all nodes in the queue
		T temp;
		while (removeFront(temp));

		cout << "\n Is Deque Empty now?? ==> " << boolalpha << isEmpty();
	}

	class iterator {
		DLnode<T>* current;
	public:
		iterator(DLnode<T>* node) : current(node) {}

		T operator*() const {
			return current->getItem();
		}

		iterator& operator++()
		{
			current = current->getNext();
			return *this;
		}

		iterator operator++(int) {
			iterator temp = *this;
			current = current->getNext();
			return temp;
		}

		bool operator==(const iterator &other) const
		{
			return (current == other.current);
		}

		bool operator!=(const iterator& other) const
		{
			return !(*this == other);

		}
	};

	iterator begin() {
		return iterator(front);
	}
	iterator end() {
		return iterator(nullptr);
	}
};