// stringRD.h -- fixed and extended the declaration of a string class
#ifndef STRINGRD_H_
#define STRINGRD_H_

#include <iostream>
using std::ostream;
using std::istream;

class String
{
	private:
		char * str;						// string pointer
		int len;						// string length
		static int num_strings;			// num of objects
		static const int CINLIM = 80;	// limit of input for cin
	public:
		// Constructions and others methods
		String(const char * s);			// construction
		String();						// default construction 
		String(const String & s);		// copy construction
		~String();						// destructor
		int length () const { return len; }
		
		// Methods of overloaded operations
		String & operator=(const String &);
		String & operator=(const char *);
		char & operator[](int i);
		const char & operator[](int i) const;
		
		// Friendly overloaded operations functions
		friend bool operator<(const String &st, const String &st2);	
		friend bool operator>(const String &st1, const String &st2);
		friend bool operator==(const String &st, const String &st2);
		friend ostream & operator<<(ostream & os, const String & st);
		friend istream & operator>>(istream & is, String & st);
		
		// Static function
		static int HowMany();
};

#endif
