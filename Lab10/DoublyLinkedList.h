#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mRoot;
	};

	template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
		: mRoot(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> nodePtr = std::make_shared<Node<T>>(Node<T>(std::move(data)));
		if (mRoot == nullptr)
		{
			mRoot = nodePtr;
			return;
		}
		std::shared_ptr<Node<T>> curNode = mRoot;
		while (curNode->Next != nullptr)
		{
			curNode = curNode->Next;
		}

		curNode->Next = nodePtr;
		nodePtr->Previous = curNode;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index > GetLength() - 1)
		{
			Insert(std::move(data));
			return;
		}
		if (index < 0)
		{
			return;
		}
		std::shared_ptr<Node<T>> nodePtr = std::make_shared<Node<T>>(Node<T>(std::move(data)));

		if (index == 0)
		{
			mRoot->Previous = nodePtr;
			nodePtr->Next = mRoot;
			mRoot = nodePtr;
			return;
		}
		std::shared_ptr<Node<T>> curNode = mRoot;
		unsigned int count = 0;

		while (count < index)
		{
			curNode = curNode->Next;
			count++;
		}

		curNode->Previous.lock()->Next = nodePtr;
		nodePtr->Previous = curNode->Previous.lock();

		curNode->Previous = nodePtr;
		nodePtr->Next = curNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> iter = mRoot;

		while (iter != nullptr)
		{
			if (*(iter->Data) == data)
			{
				break;
			}
			iter = iter->Next;
		}

		if (iter == nullptr)
		{
			return false;
		}

		if (iter == mRoot)
		{
			iter->Next->Previous.lock() = nullptr;
			mRoot = iter->Next;
			iter->Next = nullptr;
			return true;
		}

		// before
		iter->Previous.lock()->Next = iter->Next;
		// deleting iter
		iter->Previous.lock() = nullptr;

		// after
		if (iter->Next != nullptr)
		{
			iter->Next->Previous = iter->Previous.lock();
			iter->Next = nullptr;
		}

		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> iter = mRoot;

		while (iter != nullptr)
		{
			if (*(iter->Data) == data)
			{
				return true;
			}
			iter = iter->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index > GetLength() - 1)
		{
			return nullptr;
		}
		std::shared_ptr<Node<T>> iter = mRoot;
		unsigned int start = 0;
		while (start < index)
		{
			start++;
			iter = iter->Next;
		}

		return iter;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		if (mRoot == nullptr)
		{
			return 0;
		}

		unsigned int length = 0;
		std::shared_ptr<Node<T>> iter = mRoot;

		while (iter->Next != nullptr)
		{
			length++;
			iter = iter->Next;
		}
		return length + 1;
	}
}