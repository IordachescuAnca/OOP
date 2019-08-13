#pragma once
#include "node.h"


template<class U>
class Stack
{
private:
	Node<U>* head;
	int dimension;
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();
	void push(U);
	void pop();
	void clear();
	U top();
	bool empty();
	int size();
	bool operator==(const Stack&) const;
	bool operator>(const Stack&) const;
	bool operator>=(const Stack&) const;
	bool operator<(const Stack&) const;
	bool operator<=(const Stack&) const;
	bool operator!=(const Stack&) const;
	template<class t>
	friend std::istream& operator>>(std::istream&, Stack<t>&);
	template<class t>
	friend std::ostream& operator<<(std::ostream&, Stack<t>&);
};

//IMPLEMENTATION


//--constructor
template<class T>
Stack<T>::Stack()
{
	this->head = NULL;
	this->dimension = 0;
}

//--specific methods of stack

template<class T>
void Stack<T>::push(T value)
{
	Node<T> *temp = new Node<T>(value);
	++dimension;

	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->set_next(head);
		head = temp;
	}
}

template<class T>
void Stack<T>::pop()
{
	if(head == NULL)
	{
		std::cout << "\nStack is empty already.\n";
		return;
	}

	Node<T> *temp = head;
	if(head->next == NULL)
	{
		head = NULL;
	}
	else
	{
		head = head->next;
	}
	delete temp;
	--dimension;
}

template<class T>
T Stack<T>::top()
{
	if(head == NULL)
	{
		std::cout << "\nStack is empty.\n";
		return -1;
	}
	return head->data;
}

template<class T>
bool Stack<T>::empty()
{
	return !(this->dimension);
}

template<class T>
int Stack<T>::size()
{
	return this->dimension;
}

template<class T>
void Stack<T>::clear()
{
	while(this->dimension)
	{
		pop();
	}
}

//--copy-constructor
template<class T>
Stack<T>::Stack(const Stack& S)
{
	this->head = NULL;
	this->dimension = 0;

	Stack temp;
	Node<T>* begin = S.head;
	for(int i = 0; i < S.dimension; ++i)
	{
		temp.push(begin->data);
		begin = begin->next;
	}

	while(!temp.empty())
	{
		push(temp.top());
		temp.pop();
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& S)
{
	if(this != &S)
	{
		while(this->dimension)
		{
			pop();
		}
		this->head = NULL;
		this->dimension = 0;

		Stack temp;
		Node<T>* begin = S.head;
		for(int i = 0; i < S.dimension; ++i)
		{
			temp.push(begin->data);
			begin = begin->next;
		}

		while(!temp.empty())
		{
			push(temp.top());
			temp.pop();
		}
	}
	return *this;
}

//--destructor
template<class T>
Stack<T>::~Stack()
{
	clear();
}

template<class T>
std::istream& operator>>(std::istream& i, Stack<T> &S)
{
	if(S.dimension)
	{
		S.clear();
	}
	int no;
	i >> no;
	for(int it = 0; it < no; ++it)
	{
		T value;
		i >> value;
		S.push(value);
	}
	return i;
}
template<class T>
std::ostream& operator<<(std::ostream& o, Stack<T> &S)
{
	while(S.dimension)
	{
		o << S.top() << " ";
		S.pop();
	}
	o << "\n";
	return o;
}

//based on size of stacks
template<class T>
bool Stack<T>::operator==(const Stack &S) const
{
	return (this->dimension == S.dimension);
}
template<class T>
bool Stack<T>::operator>(const Stack &S) const
{
	return (this->dimension > S.dimension);
}
template<class T>
bool Stack<T>::operator>=(const Stack &S) const
{
	return (*this == S) || (*this > S);
}
template<class T>
bool Stack<T>::operator<(const Stack &S) const
{
	return !(*this > S);
}
template<class T>
bool Stack<T>::operator<=(const Stack &S) const
{
	return !(*this >= S);
}
template<class T>
bool Stack<T>::operator!=(const Stack &S) const
{
	return ~(*this == S);
}