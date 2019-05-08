#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		int length = 0;
		
		for (const char* start = s; (*start) != '\0'; start++)
		{
			length++;
		}

		mString = new char[length + 1];

		for (int i = 0; (*s) != '\0'; i++,s++)
		{
			mString[i] = (*s);
		}

		mString[length] = '\0';
		mLength = length + 1;
	}

	MyString::MyString(const MyString& other)
		:mLength(other.mLength)
	{
		mString = new char[mLength + 1];
		
		int i = 0;
		const char* s = other.mString;
		for (; (*s) != '\0'; s++, i++)
		{
			this->mString[i] = (*s);
		}

		mString[i] = '\0';
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
}