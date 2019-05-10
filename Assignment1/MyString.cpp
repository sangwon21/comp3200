#include "MyString.h"
#include <cassert>

namespace assignment1
{
	MyString::MyString(const char* s)
		: mCapacity(NULL_LETTER)
	{
		mLength = CountLength(s);
		SetCapacity(mLength);

		mString = new char[mCapacity];
		if (mLength == NULL_LENGTH)
		{
			mString[NULL_LENGTH] = '\0';
		}

		Strcpy(s, mString, mLength);
	}

	MyString::MyString(const MyString& other)
		: mLength(other.mLength),
		 mCapacity(other.mCapacity)
	{
		mString = new char[mCapacity];

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
		int length = CountLength(s);
		if (length == NULL_LENGTH)
		{
			return;
		}

		mLength = mLength + length;
		
		if (mLength >= mCapacity)
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

		if (s == nullptr || length > mLength)
		{
			return -1;
		}

		if (length == NULL_LENGTH)
		{
			return 0;
		}


		for (unsigned int index = 0; index <= mLength - length; index++)
		{
			bool bJudge = Strcmp(mString + index, s, length);
			if (bJudge == true)
			{
				return index;
			}
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		unsigned int length = CountLength(s);
		
		if (s == nullptr || length > mLength)
		{
			return -1;
		}

		if (length == NULL_LENGTH)
		{
			return mLength;
		}
			
		for (int index = mLength - length; index >= 0; index--)
		{
			bool bJudge = Strcmp(mString + index, s, length);
			if (bJudge == true)
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

		if (mLength + length >= mCapacity)
		{
			SetCapacity(mLength + length);
		}
		
		char* result = new char[mCapacity];

		unsigned int index = 0;

		mLength = mLength + length;
		
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

		if (index >= mLength)
		{
			return false;
		}
		
		for (unsigned int i = index; i < mLength; i++)
		{
			mString[i] = mString[i + 1];
		}

		mString[mLength] = '\0';
		mLength--;

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

		if (totalLength >= mCapacity)
		{
			SetCapacity(totalLength);
		}

		unsigned int length = totalLength - mLength;
		char* result = new char[mCapacity];

		for (unsigned int i = 0; i < length; i++)
		{
			result[i] = c;
		}
		result[length] = '\0';

		Strcat(mString, result);

		mLength = totalLength;
		result[mLength] = '\0';
		delete[] mString;
		mString = result;
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength <= mLength)
		{
			return;
		}

		if (totalLength >= mCapacity)
		{
			SetCapacity(totalLength);
		}

		char* result = new char[mCapacity];

		Strcpy(mString, result, mLength);

		for (unsigned int i = mLength; i < totalLength; i++)
		{
			result[i] = c;
		}
		result[totalLength] = '\0';

		mLength = totalLength;
		delete[] mString;
		mString = result;
	}

	void MyString::Reverse()
	{
		if (mLength == NULL_LENGTH)
		{
			return;
		}

		char* start = mString;
		char* end = mString + mLength - NULL_LETTER;

		while (start < end)
		{
			char tmp = *start;
			*start = *end;
			*end = tmp;
			start++;
			end--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (rhs.mLength != this->mLength)
		{
			return false;
		}
		bool bJudge = Strcmp(this->mString, rhs.mString, this->mLength);

		return bJudge;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		this->mLength = rhs.mLength;
		this->mCapacity = rhs.mCapacity;

		char* result = new char[mCapacity];
		Strcpy(rhs.mString, result, rhs.mLength);

		delete[] mString;
		mString = result;

		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mString[i] >= 'A' && mString[i] <= 'Z')
			{
				mString[i] = 'a' + (mString[i] - 'A');
			}
		}
	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mString[i] >= 'a' && mString[i] <= 'z')
			{
				mString[i] = 'A' + (mString[i] - 'a');
			}
		}
	}
	unsigned int MyString::CountLength(const char* s)
	{
		int length = 0;

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
			for (unsigned int i = 0; (*src) != '\0' && i < size; i++, src++)
			{
				dest[i] = (*src);
			}
		}
		dest[size] = '\0';
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
	bool MyString::Strcmp(const char* from, const char* to, unsigned int size) const
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

		for (; src[indexSrc] != '\0' && obj[indexObj] != '\0'; indexDest++)
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