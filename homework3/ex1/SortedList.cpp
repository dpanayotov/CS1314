/*
* @Author: dpanayotov
* @Date:   2014-05-04 10:14:04
* @Last Modified by:   dpanayotov
* @Last Modified time: 2014-05-04 23:12:21
*/

#include "SortedList.h"
#include <iostream>

template <typename K, typename V>
struct SortedList<K, V>::Node
{
    K key; //key to which the nodes are going to be sorted
    V value;
    Node *next;
};

template <typename K, typename V>
SortedList<K, V>::SortedList() : capacity(1), start(NULL), end(NULL), size(0)
{}

template <typename K, typename V>
SortedList<K, V>::SortedList(const SortedList<K, V> &other)
{
    size = other.size;
    if (other.start == 0)
    {
        start = 0;
        return;
    }

    start = new Node(other.start->data);
    end = new Node(other.end->data);

    Node *forThis = start;
    Node *forOther = other.start->data;

    while (forOther != 0)
    {
        Node *newNode = new Node(forOther->data);
        forThis->next = newNode;
        forOther = forOther->next;
    }

}

template <typename K, typename V>
void SortedList<K, V>::removeAt(unsigned index)
{
    if (index >= size)
    {
        std::cout << "No such element" << std::endl;
        return;
    }

    Node *toRemove;
    if (index == 0)
    {
        toRemove = start;
        start = start->next;
    }
    else
    {
        unsigned newIndex = index - 1;
        Node *newNode = start;
        while (newNode != NULL && newIndex > 0)
        {
            newNode = newNode->next;
            --newIndex;
        }
        toRemove = newNode->next;
        newNode->next = toRemove->next;
    }
    --size;
}

template <typename K, typename V>
SortedList<K, V>::~SortedList()
{
    Node *previous;

    while (start != NULL)
    {
        previous = start;
        start = start->next;

        delete previous;
    }
}

template <typename K, typename V>
int SortedList<K, V>::getSize() const
{
    return size;
}

template <typename K, typename V>
bool SortedList<K, V>::isEmpty() const
{
    return size == 0;
}