#pragma once

#include <string>

class StringArray {
private:
	std::string *array;		// The array of string
	int array_capacity;		// Current capacity of the array
	int array_size;			// Current number of used elements
	void expand_capacity();
public:
	StringArray();
	StringArray(const StringArray& other_stringarray);
	~StringArray();
	void append(const std::string& s);
	std::string get(int index) const;
	void set(int index, const std::string& s);
	int size() const { return array_size; }
};
