#pragma once
#include <stdexcept>

template<class T>
class VectorIterator;

template<class type>
class Vector
{
private:
	int Size;
	int Capacity;
	type *array;
public:
	Vector(int = 0);
	Vector(int, type);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

	//capacity
	int size();
	void resize(int, type);
	int capacity();
	bool empty();
	void rezerve(int);
	void shrink_to_fit();

	//element access
	type& operator[](int);
	type& at(int);
	type& front();
	type& back();
	type* data();

	//modifiers
	void push_back(type);
	void pop_back();
	void insert(int, type);
	void erase(int);
	void clear();

	//iterator
	template<class T>class VectorIterator;
	VectorIterator<type> &createIterator() const
	{
		return new VectorIterator<type>(*this);
	}
};

///IMPLEMENTATION

template<class type>
Vector<type>::Vector(int size_p)
{
	if(size_p)
	{
		this->Capacity = this->Size = size_p;
	}
	else
	{
		this->Capacity = 1;
		this->Size = 0;
	}
	array = new type[Capacity];
}

template<class type>
Vector<type>::Vector(int size_p, type value)
{
	if(size_p)
	{
		this->Capacity = this->Size = size_p;
	}
	else
	{
		this->Capacity = 1;
		this->Size = 0;
	}

	array = new type[Capacity];
	for(int i = 0; i < Size; ++i)
	{
		array[i] = value;
	}
}

template<class type>
Vector<type>::Vector(const Vector &V)
{
	this->Capacity = V.Capacity;
	this->Size = V.Size;
	array = new type[Capacity];
	for(int i = 0; i < Size; ++i)
	{
		array[i] = V.array[i];
	}
}

template<class type>
Vector<type>& Vector<type>::operator=(const Vector &V)
{
	if(this == &V)
	{
		return *this;
	}

	if(this->Size)
	{
		delete [] array;
	}
	this->Size = V.Size;
	this->Capacity = V.Capacity;
	array = new type[Capacity];
	for(int i = 0; i < Size; ++i)
	{
		array[i] = V.array[i];
	}
	return *this;
}

template<class type>
Vector<type>::~Vector()
{
	if(this->Size)
	{
		delete[]array;
	}
	this->Size = this->Capacity = 0;
}

//capacity

template<class type>
int Vector<type>::size()
{
	return Size;
}

template<class type>
void Vector<type>::resize(int number, type value)
{
	if(number < Size)
	{
		for(int i = Size-1; i >= number; i--)
		{
			pop_back();
		}
	}

	if(number > Size)
	{
		if(number > Capacity)
		{
			type *temp = new type[Size];
			for(int i = 0; i < Size; ++i)
			{
				temp[i] = array[i];
			}
			delete [] array;
			array = NULL;

			this->Capacity = 2 * number;
			array = new type[Capacity];

			for(int i = 0; i < Size; ++i)
			{
				array[i] = temp[i];
			}
			delete[] temp;
		}
		for(int i = Size; i < number; ++i)
		{
			array[i] = value;
		}
		this->Size = number;
		
	}
}

template<class type>
int Vector<type>::capacity()
{
	return Capacity;
}

template<class type>
bool Vector<type>::empty()
{
	return !(Size);
}

template<class type>
void Vector<type>::rezerve(int capacity_p)
{
	if(capacity_p > this->Capacity)
	{
		type *temp = new type[Size];
		for(int i = 0; i < Size; ++i)
		{
			temp[i] = array[i];
		}
		delete [] array;
		array = NULL;

		this->Capacity = capacity_p;
		array = new type[Capacity];

		for(int i = 0; i < Size; ++i)
		{
			array[i] = temp[i];
		}
		delete []temp;
	}
}

template<class type>
void Vector<type>::shrink_to_fit()
{
	type *temp = new type[Size];
	for(int i = 0; i < Size; ++i)
	{
		temp[i] = array[i];
	}
	delete [] array;
	array = NULL;

	this->Capacity = this->Size;
	array = new type[Capacity];

	for(int i = 0; i < Size; ++i)
	{
		array[i] = temp[i];
	}
	delete []temp;
}


//element access


template<class type>
type& Vector<type>::operator[](int i)
{
	return array[i];
}

template<class type>
type& Vector<type>::at(int i)
{
	if(i < 0 || i > Size-1)
	{
		throw std::out_of_range("Error!");
	}

	return array[i];
}

template<class type>
type& Vector<type>::front()
{
	if(!this->Size)
	{
		throw std::out_of_range("Error!");
	}
	return array[0];
}

template<class type>
type& Vector<type>::back()
{
	if(!this->Size)
	{
		throw std::out_of_range("Error!");
	}
	return array[Size-1];
}

template<class type>
type* Vector<type>::data()
{
	return array;
}


//modifiers


template<class type>
void Vector<type>::push_back(type value)
{
	if(this->Size == this->Capacity)
	{
		int *temp = new int[Size];
		for(int i = 0; i < Size; ++i)
		{
			temp[i] = array[i];
		}
		delete [] array;
		array = NULL;

		this->Capacity *= 2;
		array = new type[Capacity];

		for(int i = 0; i < Size; i++)
		{
			array[i] = temp[i];
		}

		delete[] temp;
	}
	this->Size++;
	array[Size-1] = value;
}

template<class type>
void Vector<type>::pop_back()
{
	if(!this->Size)
	{
		std::out_of_range("Error!");
	}
	Size--;
}

template<class type>
void Vector<type>::insert(int position, type value)
{
	if(0 > position || position >= Size)
	{
		throw std::out_of_range("Error!");
	}

	if(this->Size == this->Capacity)
	{
		type *temp = new type[Size];
		for(int i = 0; i < Size; ++i)
		{
			temp[i] = array[i];
		}
		delete [] array;
		array = NULL;

		this->Capacity *= 2;
		array = new type[Capacity];

		for(int i = 0; i < Size; i++)
		{
			array[i] = temp[i];
		}

		delete[] temp;
	}
	for(int i = Size-1; i >= position; i--)
	{
		array[i+1] = array[i];
	}
	array[position] = value;
	Size++;
}

template<class type>
void Vector<type>::erase(int position)
{
	if(0 > position || position > Size)
	{
		throw std::out_of_range("Error!");
	}

	Size--;
	for(int i = position; i < Size-1; i++)
	{
		array[i] = array[i+1];
	}
}

template<class type>
void Vector<type>::clear()
{
	this->Size = 0;
	delete[] array;
	this->Capacity = 1;
	array = new type[Capacity];
}