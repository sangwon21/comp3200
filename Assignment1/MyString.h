#pragma once
namespace assignment1
{
	class MyString
	{
	public:
		MyString(const char* s);
		MyString(const MyString& other);
		~MyString();

		unsigned int GetLength() const;
		const char* GetCString() const;
		void Append(const char* s);
		MyString operator+(const MyString& other) const;
		int IndexOf(const char* s);
		int LastIndexOf(const char* s);
		void Interleave(const char* s);
		bool RemoveAt(unsigned int i);
		void PadLeft(unsigned int totalLength);
		void PadLeft(unsigned int totalLength, const char c);
		void PadRight(unsigned int totalLength);
		void PadRight(unsigned int totalLength, const char c);
		void Reverse();
		bool operator==(const MyString& rhs) const;
		MyString& operator=(const MyString& rhs);
		void ToLower();
		void ToUpper();
		unsigned int CountLength(const char* s);
		void Strcpy(const char* src, char*& dest, unsigned int size);
		void Strcat(const char* src, char*& dest);
		bool Strcmp(const char* from, const char* to, unsigned int size);
		void Merge(const char* src, const char* obj, char*& dest);
		void SetCapacity(unsigned int length);
	private:
		const unsigned int NULL_LENGTH = 1;
		char* mString = nullptr;
		unsigned int mLength;
		unsigned int mCapacity;
	};
}