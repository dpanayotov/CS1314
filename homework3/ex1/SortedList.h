#ifndef SortedList_H_
#define SortedList_H_

template <typename K, typename V>
class SortedList
{
    struct Node;
    Node *start; //pointer to the front of the list
    Node *end; //pointer to the end of the list
    unsigned size; //current number of items in the list
    const int capacity; //maximum number of items in the list
public:
    SortedList();
    SortedList(const SortedList &);
    ~SortedList();
    K getKey(unsigned); //returns key, given the index
    V getValue(unsigned); //returns value, given the index
    bool containsKey(K); //check if such key exists
    bool containsValue(V); //check if such value exists
    void add(K, V); //add element to the list
    void remove(K); //remove element, given the key
    void removeAt(unsigned); //remove element, given the index
    int getSize() const; //returns the number of elements in the list
    bool isEmpty() const; //check if the list is empty
};

#endif