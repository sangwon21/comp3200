#include "MyString.h"
#include <cassert>

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		assert(s != nullptr);
		mLength = CountLength(s);
		
		mString = new char[mLength];

		Strcpy(s, mString, mLength);
	}

	MyString::MyString(const MyString& other)
		:mLength(other.mLength)
	{
		mString = new char[mLength + 1];
		
		int i = 0;
		Strcpy(other.mString, mString, mLength);

	}

	MyString::~MyString()
	{
		if (mString != nullptr)
		{
			delete[] mString;
		}
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
	}

	MyString MyString::operator+(const MyString& other) const
	{
		return MyString("temporary");
	}

	int MyString::IndexOf(const char* s)
	{
		return 0;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
	int MyString::CountLength(const char* s)
	{
		assert(s != nullptr);
		int length = 0;
		for (const char* start = s; (*start) != '\0'; start++)
		{
			length++;
		}

		return length + 1;
	}
	void MyString::Strcpy(const char* src, char*& dest, int size)
	{
		for (int i = 0; (*src) != '\0' && i < size - 1; i++, src++)
		{
			dest[i] = (*src);
		}

		dest[size - 1] = '\0';
	}
}