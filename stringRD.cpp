// stringRD.cpp -- class String methods
#include <cstring>
#include "stringRD.h"

using std::cin;
using std::cout;

// Static member of class initialization
int String::num_strings = 0;

// Static method
int String::HowMany()
{
	return num_strings;
}

// Methods of class
String::String(const char * s)		// Create string from C-string
{
	len = std::strlen(s);			// size install
	str = new char[len + 1];		// memory allocation
	std::strcpy(str, s);			// pointer initialization
	num_strings++;					// adjusting the object counter 
}

String::String()					// default constructor
{
	len = 4;
	str = new char [1];
	str[0] = '\0';					// default string
	num_strings++;	
} 

String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);		// copying a line to a new location
}

String::~String()
{
	--num_strings;
	delete [] str;
}

// Methods of overloaded operations
// Assigning a String object to a String object 
String & String::operator=(const String & st)
{
	if(this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// Assigning a C-string to a String object
String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

// Read and write access to individual characters in a non-constant String object
char & String::operator[](int i)
{
	return str[i];
}

// Read and write access to individual characters in a constant String object
const char & String::operator[] (int i) const
{
	return str[i];
 } 

// Friendly overloaded operations functions
bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2.str < st1.str; 
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// Simple String output
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

// Simple String input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
		st = temp;
	while(is && is.get() != '\n')
		continue;
	
	return is;
}









