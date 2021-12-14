#pragma once
#include <iostream>
#include <cassert>

using namespace std;
namespace Graph
{
	template <class T>
	class Vector
	{
	private:
		T coords[3];

	public:
		Vector(T x = 0.0, T y = 0.0, T z = 0.0);
		Vector(const Vector&) = delete;
		//delete to stop using the method also declare our own constructor to prevent the default one
		//to prevent using passage par valeur or retour par valeur  as said in the exrcice 
		//since we will always use copy constructor to do so by deleting it we re good
		Vector& operator=(const Vector&) = delete;//if its static declaration it will copy the object 

		void print() const;
		T at(unsigned int) const;
		bool operator==(const Vector&) const;
		bool operator!=(const Vector&) const;
		T& operator[](unsigned int);
		friend void display1(Vector& V);
	};


}

template <class T>
Graph::Vector<T>::Vector(T x, T y, T z)
{
	this->coords[0] = x;
	this->coords[1] = y;
	this->coords[2] = z;
}

template <class T>
void Graph::Vector<T>::print() const
{
	for (int i = 0; i < 3; i++)
		cout << "vect: " << i << this->at(i) << endl;
}

template <class T>
bool Graph::Vector<T>::operator==(const Vector& v) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
		res = res && (this->at(i) == v.at(i));
	return res;
}

template <class T>
bool Graph::Vector<T>::operator!=(const Vector& v) const
{
	bool res = !(*this == v);
	return res;
}

template <class T>
T& Graph::Vector<T>::operator[](unsigned int i)
{
	assert(i >= 0 && i < 3);
	try
	{
		if (i < 0 || i >= 3) throw "Range Error";
		return this->coords[i];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}

template <class T>
T Graph::Vector<T>::at(unsigned int i) const
{
	assert(i >= 0 && i < 3);
	try
	{
		if (i < 0 || i >= 3) throw "Range Error";
		return this->coords[i];
	}
	catch (char* e)
	{
		cout << e << endl;
	}
}

