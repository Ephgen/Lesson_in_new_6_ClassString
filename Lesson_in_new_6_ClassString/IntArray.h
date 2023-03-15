#pragma once
#include <iostream>
#include <windows.h>
#include <initializer_list>

using namespace std;

template<class T>
class DynamicArray
{
	int length;
	T* data;
public:
	DynamicArray() :length{ 0 }, data{nullptr}{}
	DynamicArray(int l) :length{ l } {	data = new T[l];}
	DynamicArray(const initializer_list<T>& list) : DynamicArray(list.size()) {
		int i = 0;
		for (auto& element : list) {    
			data[i] = element;
			i++;
		}
	}

	~DynamicArray() {
		delete[] data;
	}

	T& operator[](int index) {
		return data[index];
	}

	int getLen() {
		return length;
	}

};

