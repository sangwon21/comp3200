#include "MyString.h"
#include <cassert>

namespace assignment1
{
	MyString::MyString(const char* s)
		:mCapacity(NULL_LENGTH)
	{
		mLength = CountLength(s);
		SetCapacity(mLength);

		mString = new char[mCapacity];
		if (mLength == NULL_LENGTH)
		{
			mString[NULL_LENGTH - 1] = '\0';
		}

		Strcpy(s, mString, mLength);
	}

	MyString::MyString(const MyString& other)
		:mLength(other.mLength),
		mCapacity(other.mCapacity)
	{
		mString = new char[mLength];

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
		assert(mString != nullptr && s != nullptr);
		
		int length = CountLength(s);
		if (length == NULL_LENGTH)
		{
			return;
		}

		mLength = mLength + length;
		
		if (mLength > mCapacity)
		{
			SetCapacity(mLength);

			char* result = new char[mCapacity];
			result[0] = '\0';

			Strcat(mString, result);
			Strcat(s, result);

			delete[] mString;
			mString = result;
		}
		else
		{
			Strcat(s, mString);
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		if (other.GetLength() == NULL_LENGTH)
		{
			return *this;
		}

		MyString result(*this);
		result.Append(other.mString);
		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int length = CountLength(s);
		// 빈 칸일 때 생각하기

		if (length > mLength)
		{
			return -1;
		}

		if (length == NULL_LENGTH)
		{
			return 0;
		}

		length = length - NULL_LENGTH;


		for (unsigned int index = 0; index < mLength - length; index++)
		{
			bool judge = Strcmp(mString + index, s, length);
			if (judge == true)
			{
				return index;
			}
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		unsigned int length = CountLength(s);
		
		if (length > mLength)
		{
			return -1;
		}

		if (length == NULL_LENGTH)
		{
			return mLength - 1;
		}
		
		length = length -NULL_LENGTH;
		// 빈 칸일 때 생각하기

		// s의 길이가 mLength보다 길떄 생각하기

		int maxIndex = -1;

		for (int index = mLength - length; index >= length; index--)
		{
			bool judge = Strcmp(mString + index, s, length);
			if (judge == true && maxIndex < index)
			{
				 maxIndex = index;
			}
		}

		return maxIndex;
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
	unsigned int MyString::CountLength(const char* s)
	{
		int length = NULL_LENGTH;

		if (s == nullptr)
		{
			return length;
		}
		for (const char* start = s; (*start) != '\0'; start++)
		{
			length++;
		}

		return length;
	}
	void MyString::Strcpy(const char* src, char*& dest, unsigned int size)
	{
		if (src != nullptr)
		{
			for (unsigned int i = 0; (*src) != '\0' && i < size - 1; i++, src++)
			{
				dest[i] = (*src);
			}
		}
		dest[size - 1] = '\0';
	}
	void MyString::Strcat(const char* src, char*& dest)
	{
		const char* start = dest;
		unsigned int index = 0;

		for (; (*start) != '\0'; start++)
		{
			index++;
		}

		for (; (*src) != '\0'; index++, src++)
		{
			dest[index] = (*src);
		}

		dest[index] = '\0';
	}
	bool MyString::Strcmp(const char* from, const char* to, unsigned int size)
	{
		for (unsigned int i = 0; i < size; i++)
		{
			if (from[i] != to[i])
			{
				return false;
			}
		}

		return true;
	}
	void MyString::SetCapacity(unsigned int length)
	{
		while (length >= mCapacity)
		{
			mCapacity = mCapacity * 2;
		}
	}
}