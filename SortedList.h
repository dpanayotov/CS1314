/*
 * SortedList.h
 *
 *  Created on: May 17, 2014
 *      Author: dpanayotov
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include <iostream>
using namespace std;

template<typename K, typename V>
struct Node
{
	K key;
	V value;
	Node* next;
};

template<typename K, typename V>
class SortedList
{
	Node<K, V>* start;
	Node<K, V>* end;
	int size;
	void copy(const SortedList&);
	void del();
public:
	SortedList();
	SortedList(const SortedList&);
	SortedList&operator=(const SortedList&);
	~SortedList();
	K getKey(int);
	V getValue(int);
	bool containsKey(K) const;
	bool containsValue(V) const;
	void add(K, V);
	void remove(K);
	void removeAt(int);
	SortedList& merge(const SortedList&);
	int getSize() const;
	bool empty() const;

};

template<typename K, typename V>
void SortedList<K, V>::copy(const SortedList& other)
{
	size = other.size;

	if (other.start == 0)
	{
		start = end = 0;
		return;
	}

	Node<K, V>* start;
	start->key = other.start->key;
	start->value = other.start->value;

	Node<K, V>* that = start;
	Node<K, V>* ot = other.start;

	while (ot != 0)
	{
		Node<K, V>* newNode;
		newNode->key = ot->key;
		newNode->value = ot->value;
		that->next = newNode;

		that = newNode;
		ot = ot->next;
	}
}

template<typename K, typename V>
void SortedList<K, V>::del()
{
	Node<K, V>* previous;

	while (!empty())
	{
		previous = start;
		start = start->next;

		delete previous;
	}
}

template<typename K, typename V>
SortedList<K, V>::SortedList() :
		start(0), end(0), size(1)
{
}

template<typename K, typename V>
SortedList<K, V>::SortedList(const SortedList& other)
{
	copy(other);
}

template<typename K, typename V>
SortedList<K, V>& SortedList<K, V>::operator=(const SortedList& other)
{
	del();
	copy(other);
}

template<typename K, typename V>
SortedList<K, V>::~SortedList()
{
	del();
}

template<typename K, typename V>
K SortedList<K, V>::getKey(int index)
{
	Node<K, V>* temp = start;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return temp->key;
		}
		temp = temp->next;
	}
	return -1;
}

template<typename K, typename V>
V SortedList<K, V>::getValue(int index)
{
	Node<K, V>* temp = start;
	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			return temp->value;
		}
		temp = temp->next;
	}
	return -1;
}

template<typename K, typename V>
bool SortedList<K, V>::containsKey(K _key) const
{
	Node<K, V>* temp = start;
	for (int i = 0; i < size; i++)
	{
		if (temp->key == _key)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<typename K, typename V>
bool SortedList<K, V>::containsValue(V _value) const
{
	Node<K, V>* temp = start;
	for (int i = 0; i < size; i++)
	{
		if (temp->value == _value)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<typename K, typename V>
void SortedList<K, V>::add(K _key, V _value)
{
	if (start != NULL)
	{
		size++;
		Node<K, V>* temp = new Node<K, V>;
		temp->key = _key;
		temp->value = _value;

		if (start == end)
		{
			temp->next = end;
			start = temp;
		}
		else
		{
			int k = 0;
			Node<K, V>* newNode = start;
			while (newNode != NULL && newNode->key < _key)
			{
				k++;
				newNode = newNode->next;
			}
			newNode = start;

			for (int i = 0; i < k - 1; i++)
			{
				newNode = newNode->next;
			}

			temp->next = newNode->next;
			newNode->next = temp;
			if (end->next != NULL)
			{
				end = temp;
			}
			if (newNode->next == start)
			{
				start = newNode;
			}
		}
	}
	else
	{
		size++;
		start = new Node<K, V>;
		start->key = _key;
		start->value = _value;
		start->next = NULL;
		end = start;
	}
}

template<typename K, typename V>
void SortedList<K, V>::remove(K _key)
{
	Node<K, V>* temp = start;
	for (int i = 0; i < size; i++)
	{
		if (temp->key == _key)
		{
			removeAt(i);
			return;
		}
		temp = temp->next;
	}
}

template<typename K, typename V>
void SortedList<K, V>::removeAt(int index)
{
	if (index >= size)
	{
		return;
	}

	Node<K, V>* temp;

	if (index == 0)
	{
		temp = start;
		start = start->next;
	}
	else
	{
		Node<K, V>* previous;
		Node<K, V>* find = start;

		while (find != 0 && index > 0)
		{
			find = find->next;
			--index;
		}

		previous = find;

		temp = previous->next;
		previous->next = temp->next;
	}

	delete temp;
	--size;
}

template<typename K, typename V>
SortedList<K, V>& SortedList<K, V>::merge(const SortedList<K, V>& other)
{
	Node<K, V>* temp = other.start;
	for (int i = 0; i < other.size; i++)
	{
		add(temp->key, temp->value);
		temp = temp->next;
	}
}

template<typename K, typename V>
int SortedList<K, V>::getSize() const
{
	return size;
}

template<typename K, typename V>
bool SortedList<K, V>::empty() const
{
	return start == 0;
}

#endif /* SORTEDLIST_H_ */
