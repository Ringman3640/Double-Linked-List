////
// Name: Franz Alarcon
// Section: A
// Program Name: P3 FAString v2
//
//Class Description: This class is an updated version of FAString
//  v1, which now includes the use of operator overloading in order
//  to improve the string's use and simplicity. 
//
//List of functions and their descriptions:
//	length() - Returns the length of the string (end value)
//	capacity() - Returns the cap value
//	at(int) - Returns the character at a given index. If out of
//		bounds, will return the character '\0'
//	c_str() - Returns str as a constant cString pointer. Allows 
//		for access to str and for more output abilities.
//	getCurrentCount() - returns the static currentCount variable
//	getCreatedCount() - returns the static createdCount variable
//
//New overloaded operators:
//	= operator: replaces the setEqualTo() function, allows for a
//		FAString to be set equal to another FAString
//	[] operator: similar to the at() function but with no error
//		checking
//	>> operator: replaces the read() function, allows for text to
//		be read from a file or from cin into a FAString. Now 
//		removes trailing puntuation
//	<< operator: replaces the write() function, allows for a 
//		FAString to be outputted to a ostream
//	<, >, !=, and == operator: replaces the compareTo() function, 
//		compares two FAStrings together and returns a boolean
//		expression 
//	+ operator: combines two FAStrings into one FAString which
//      is returned
////

#ifndef FASTRING_H
#define FASTRING_H
#include <istream>

class FAString {
public: 
	FAString();
	FAString(const FAString& mstr);
	FAString(const char* userIn);
	~FAString();

	FAString& operator = (const FAString& argStr);
	FAString& operator = (const char argStr[]);
	friend std::istream& operator >> (std::istream& istrm, FAString& inStr);
	friend std::ostream& operator << (std::ostream& ostrm, const FAString& outStr);
	char operator [] (int index) const;
	bool operator < (const FAString& argStr) const;
	bool operator > (const FAString& argStr) const;
	bool operator == (const FAString& argStr) const;
	bool operator != (const FAString& argStr) const;
	FAString operator + (const FAString& argStr) const;

	int length() const;
	int capacity() const;
	char at(int index) const;
	const char* c_str() const;

	static int getCurrentCount();
	static int getCreatedCount();

private:
	char* str;
	int cap, end;
	static int currentCount, createCount;
	int compareTo(const FAString& argStr) const;
	bool isEqual(const FAString& argStr) const;
};

#endif