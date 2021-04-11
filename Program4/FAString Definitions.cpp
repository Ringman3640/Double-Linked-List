#include "FAString.h"

int FAString::currentCount = 0;
int FAString::createCount = 0;

FAString::FAString() : str(new char[20]) {
	currentCount++;
	createCount++;
	str[0] = '\0';
	cap = 20;
	end = 0;
}

FAString::FAString(const FAString& cpyStr) : str(new char[cpyStr.capacity()]) {
	currentCount++;
	createCount++;
	for (int i = 0; i <= cpyStr.length(); i++) {
		str[i] = cpyStr[i];
	}
	cap = cpyStr.capacity();
	end = cpyStr.length();
}

FAString::FAString(const char* userIn) {
	currentCount++;
	createCount++;
	int length = 0;
	for (length; userIn[length]; length++);
	cap = (length + 20) / 20 * 20;
	end = length;
	str = new char[cap];
	for (int i = 0; i < length; i++) {
		str[i] = userIn[i];
	}
	str[length] = '\0';
}

FAString::~FAString() {
	delete[] str;
	currentCount--;
}

FAString& FAString::operator = (const FAString& argStr) {
	if (this != &argStr) {
		delete[] str;
		cap = argStr.capacity();
		end = argStr.length();
		str = new char[cap];
		for (int i = 0; argStr[i]; i++) {
			str[i] = argStr[i];
		}
		str[end] = '\0';
	}
	return *this;
}

FAString& FAString::operator = (const char argStr[]) {
	int count = 0;
	for (count; argStr[count]; count++);
	count++;
	cap = (count + 20) / 20 * 20;
	end = count - 1;
	delete[] str;
	str = new char[cap];
	for (int i = 0; argStr[i]; i++) {
		str[i] = argStr[i];
	}
	str[end] = '\0';
	return *this;
}

char FAString::operator [] (int index) const {
	return str[index];
}

std::istream& operator >> (std::istream& istrm, FAString& inStr) {
	char temp[100];
	int tempLength = 0;
	if (istrm >> temp) {
		for (tempLength; temp[tempLength]; tempLength++); //get size of temp
		inStr.cap = (tempLength + 20) / 20 * 20;
		inStr.end = tempLength;
		delete[] inStr.str; 
		inStr.str = new char[inStr.cap];
		for (int i = 0; temp[i]; i++) {
			inStr.str[i] = temp[i];
		}
		inStr.str[tempLength] = '\0';
		if (inStr.end != 0 && ispunct(inStr.str[inStr.end - 1])) { //remove trailing punctuation
			inStr.str[--inStr.end] = '\0';
		}
	}
	return istrm;
}

std::ostream& operator << (std::ostream& ostrm, const FAString& outStr) {
	ostrm << outStr.c_str();
	return ostrm;
}

bool FAString::operator < (const FAString& argStr) const {
	if (str == argStr.c_str()) return false;
	if (compareTo(argStr)) return false;
	return true;
}

bool FAString::operator > (const FAString& argStr) const {
	if (str == argStr.c_str()) return false;
	if (compareTo(argStr)) return true;
	return false;
}

bool FAString::operator == (const FAString& argStr) const {
	return this->isEqual(argStr);
}

bool FAString::operator != (const FAString& argStr) const {
	return !this->isEqual(argStr);
}

FAString FAString::operator + (const FAString& argStr) const {
	FAString returnStr;
	char* wordComb = new char[end + argStr.length() + 1];
	for (int i = 0; i < end; i++) {
		wordComb[i] = str[i];
	}
	for (int i = 0; i  <= argStr.length(); i++) {
		wordComb[i + end] = argStr[i];
	}
	returnStr = wordComb;
	delete[] wordComb;
	return returnStr;
}

int FAString::length() const {
	return end;
}

int FAString::capacity() const {
	return cap;
}

char FAString::at(int index) const {
	if (index >= 0 && index <= end) {
		return str[index];
	}
	return '\0';
}

int FAString::compareTo(const FAString& argStr) const {
	int compIdx = 0;
	for (compIdx; tolower(str[compIdx]) == tolower(argStr.at(compIdx)); compIdx++);
	if (tolower(str[compIdx]) > tolower(argStr.at(compIdx))) return 1;
	return 0;
}

bool FAString::isEqual(const FAString& argStr) const {
	int index = 0;
	for (index; str[index]; index++) {
		if (tolower(str[index]) != tolower(argStr.at(index))) return false;
	}
	if (argStr.at(index) != '\0') return false;
	return true;
}

const char* FAString::c_str() const {
	return str;
}

int FAString::getCurrentCount() {
	return FAString::currentCount;
}

int FAString::getCreatedCount() {
	return FAString::createCount;
}