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
		// ºó Ä­ÀÏ ¶§ »ý°¢ÇÏ±â

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

		
		for (int index = mLength - length - 1; index >= 0; index--)
		{
			bool judge = Strcmp(mString + index, s, length);
			if (judge == true)
			{
				return index;
			}
		}

		return -1;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int length = CountLength(s);

		if (length == NULL_LENGTH)
		{
			return;
		}

		if (mLength + length - NULL_LENGTH > mCapacity)
		{
			SetCapacity(mLength + length - NULL_LENGTH);
		}
		
		char* result = new char[mCapacity];

		unsigned int index = 0;

		mLength = mLength + length - NULL_LENGTH;
		
		Merge(mString, s, result);
		delete[] mString;
		mString = result;
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (mLength == NULL_LENGTH)
		{
			return false;
		}

		if (index >= mLength - NULL_LENGTH)
		{
			return false;
		}
		
		mLength = mLength - 1;

		for (unsigned int i = index; i < mLength; i++)
		{
			mString[i] = mString[i + 1];
		}

		mString[mLength] = '\0';
		
		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}

		if (totalLength > mCapacity)
		{
			SetCapacity(totalLength);
		}

		unsigned int length = totalLength - mLength + NULL_LENGTH;
		char* result = new char[mCapacity];

		for (unsigned int i = 0; i < length; i++)
		{
			result[i] = c;
		}
		result[length] = '\0';

		Strcat(mString, result);

		mLength = totalLength + NULL_LENGTH;
		
		result[mLength] = '\0';
		delete[] mString;
		mString = result;
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
	void MyString::Merge(const char* src, const char* obj, char*& dest)
	{
		int indexSrc = 0;
		int indexObj = 0;
		int indexDest = 0;

		for (;src[indexSrc] != '\0' && obj[indexObj] != '\0'; indexDest++)
		{
			if (indexDest % 2 == 0)
			{
				dest[indexDest] = src[indexSrc];
				indexSrc++;
			}
			else
			{
				dest[indexDest] = obj[indexObj];
				indexObj++;
			}
		}

		while (src[indexSrc] != '\0')
		{
			dest[indexDest] = src[indexSrc];
			indexDest++;
			indexSrc++;
		}

		while (obj[indexObj] != '\0')
		{
			dest[indexDest] = obj[indexObj];
			indexDest++;
			indexObj++;
		}

		dest[indexDest] = '\0';
	}
	void MyString::SetCapacity(unsigned int length)
	{
		while (length >= mCapacity)
		{
			mCapacity = mCapacity * 2;
		}
	}
}