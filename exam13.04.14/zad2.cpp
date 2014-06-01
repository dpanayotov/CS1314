#include <iostream>
#include <cassert>
#include <climits> //INT_MIN

using namespace std;

//if value = INT_MIN => the element is not in use
struct Item
{
    int index;
    int value;
};

class SparseArray
{
    Item* arr;
    int size;
    const static int free = INT_MIN;
public:
    SparseArray();
    ~SparseArray();
    bool addItem(int, int);
    int getValue(int);
    bool removeItem(int, int&);
};

SparseArray::SparseArray()
{
    cout<<"cosntructor"<<endl;
    size = 1;
    arr = new Item[size];
    assert(arr != NULL);
    for(int i=0; i<size; i++)
    {
        arr[i].index = i;
        arr[i].value = free;
    }
}

SparseArray::~SparseArray()
{
    cout<<"destructor"<<endl;
    delete[] arr;
}

bool SparseArray::addItem(int index, int value)
{
    if(index > size && index>0)
    {
        Item* temp = new Item[index+1];
        for(int i=0; i<size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        size = index+1;
        arr = new Item[size];
        assert(arr != NULL);
    }
    for(int i=0; i<size; i++)
    {
        if(arr[i].index == index)
        {
            return false;
        }
        else
        {
            arr[i].index = index;
            arr[i].value = value;
        }
    }
    return true;
}

int SparseArray::getValue(int index)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i].index == index)
        {
            return arr[i].value;
        }
    }
    return -1;
}

bool SparseArray::removeItem(int index, int& value)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i].index == index && arr[i].value != free)
        {
            value = arr[i].index;
            arr[i].value = free;
            return true;
        }
        else
        {
            value = arr[i].index;
            return false;
        }
    }
    return false;
}

int main()
{
    SparseArray newArr;
    int ix = 2, val = 3;
    cout<<"Add result: "<<newArr.addItem(ix, val);
    cout<<endl;
    cout<<"Value: "<<newArr.getValue(ix);
    cout<<endl;
    cout<<"Remove result: "<<newArr.removeItem(ix,val);
    cout<<endl;
    cout<<"Add result: "<<newArr.addItem(ix+1, val);
    cout<<endl;
    cout<<"Value: "<<newArr.getValue(ix+1);
    cout<<endl;

    return 0;
}
