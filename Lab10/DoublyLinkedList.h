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
		std::shared_ptr<Node<T>> root;
		unsigned int GetLength() const;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: root(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> nodePtr = std::make_shared<Node<T>>(Node<T>(std::move(data)));
		if (root == nullptr)
		{
			root = nodePtr;
			return;
		}
		std::shared_ptr<Node<T>> curNode = root;
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
			root->Previous.lock() = nodePtr;
			nodePtr->Next = root;
			root = nodePtr;
			return;
		}
		std::shared_ptr<Node<T>> curNode = root;
		unsigned int count = 0;
		
		while (count < index)
		{
			curNode = curNode->Next;
			count++;
		}

		curNode->Previous.lock()->Next = nodePtr;
		nodePtr->Previous.lock() = curNode->Previous.lock();

		curNode->Previous.lock() = nodePtr;
		nodePtr->Next = curNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> iter = root;

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
		
		if (iter == root)
		{
			iter->Next->Previous.lock() = nullptr;
			root = iter->Next;
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
		std::shared_ptr<Node<T>> iter = root;

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
		std::shared_ptr<Node<T>> iter = root;
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
		if (root == nullptr)
		{
			return 0;
		}

		unsigned int length = 0;
		std::shared_ptr<Node<T>> iter = root;
		
		while (iter->Next != nullptr)
		{
			length++;
			iter = iter->Next;
		}
		return length + 1;
	}
}