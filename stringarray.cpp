#include "stringarray.h"
using namespace std;

StringArray::StringArray() {
	// Create empty array with capacity 10
	array_capacity = 10;
	array_size = 0;
	array = new string[array_capacity];
}

StringArray::StringArray(const StringArray& other_stringarray) {
	// Create StringArray as a copy of another stringarray
	array_capacity = other_stringarray.array_capacity;
	array_size = other_stringarray.array_size;
	array = new string[array_capacity];
	for (int i = 0; i < array_size; i++)
		array[i] = other_stringarray.array[i];
}

StringArray::~StringArray() {
	delete [] array;
}

void StringArray::append(const string& s) {
	// Check for capacity to add element, expand if necessary
	if (array_size == array_capacity) {
		expand_capacity();
	}
	array[array_size++] = s;
}

string StringArray::get(int index) const {
	if (index < 0 || index >= array_size)
		throw "Array index out of range";
	return array[index];
}

void StringArray::expand_capacity() {
	// Double the current capacity
	array_capacity *= 2;
	// Allocate a new array
	string *p = new string[array_capacity];
	// Copy all string from the old array to the new array
	for (int i = 0; i < array_size; i++)
		p[i] = array[i];
	// Return old array to the system
	delete [] array;
	// Keep track of the new array (in member variable)
	array = p;
}

void StringArray::set(int index, const string& s) {
	if (index < 0 || index >= array_size)
		throw "Array index out of range";
	array[index] = s;
}
