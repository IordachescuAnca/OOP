#pragma once
#include<iostream>

template<class T>
class Node
{
private:
	T data;
	Node<T> *next;
public:
	Node();
	Node(T);
	Node(const Node &);
	Node& operator=(const Node&);
	~Node();
	T get_data();
	Node* get_next();
	void set_data(T);
	void set_next(Node*);
	bool operator==(const Node&) const;
	bool operator>(const Node&) const;
	bool operator>=(const Node&) const;
	bool operator<(const Node&) const;
	bool operator<=(const Node&) const;
	bool operator!=(const Node&) const;
	template<class t>
	friend std::istream& operator >>(std::istream&, Node<t>&);
	template<class t>
	friend std::ostream& operator <<(std::ostream&, const Node<t>&);
	template<class U>friend class Stack;
};

//IMPLEMENTATION



//--constructors 

template<class T>
Node<T>::Node()
{
	this->next = NULL;
}

template<class T>
Node<T>::Node(T value)
{
	this->data = value;
	this->next = NULL;
}

//--copy-constructor
template<class T>
Node<T>::Node(const Node& N)
{
	this->data = N.data;
	this->next = N.next;
}


template<class T>
Node<T>& Node<T>::operator=(const Node&N)
{
	if(this != &N)
	{
		this->data = N.data;
		this->next = N.next;
	}
	return *this;
}

//--destructor
template<class T>
Node<T>::~Node()
{
	this->next = NULL;
}



template<class T>
T Node<T>::get_data()
{
	return this->data;
}

template<class T>
Node<T>* Node<T>::get_next()
{
	return this->next;
}

template<class T>
void Node<T>::set_data(T value)
{
	this->data = value;
}

template<class T>
void Node<T>::set_next(Node* n)
{
	this->next = n;
}



template<class T>
bool Node<T>::operator==(const Node& N) const
{
	return (this->data == N.data);
}

template<class T>
bool Node<T>::operator>(const Node& N) const
{
	return (this->data > N.data);
}

template<class T>
bool Node<T>::operator>=(const Node& N) const
{
	return (*this > N) || (*this == N);
}

template<class T>
bool Node<T>::operator<(const Node& N) const
{
	return !(*this >= N);
}

template<class T>
bool Node<T>::operator<=(const Node& N) const
{
	return !(*this > N);
}

template<class T>
bool Node<T>::operator!=(const Node& N) const
{
	return !(*this == N);
}

template<class T>
std::istream& operator>>(std::istream& i, Node<T>& N)
{
	i >> N.data;
	N.next = NULL;
	return i;
}

template<class T>
std::ostream& operator<<(std::ostream& o, const Node<T>& N)
{
	o << N.data;
	return o;
}