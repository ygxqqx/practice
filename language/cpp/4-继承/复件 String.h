#include "iostream"
using namespace std;

#ifndef _STRING_H_
#define _STRING_H_

class String
{
public :
	String();
	String(const char*str);
	String(String& s1);
	~String();
public:

	char* getString();
	void  setString(String s1);
	int length();

	String& operator=(String &s1); ////c3 = c1  = c2
	String& operator=(const char *str);// c3 = "abcde";
	String operator+(String &s1); //c3 = c1 +c2

	bool operator==(String &s);
	bool operator!=(String &s);

public:
	friend ostream& operator<<(ostream &out, String &s1);

private:

	char *p;
	int len;

};
#endif

