#include <iostream>
#include <cassert>

using namespace std;

class vector
{
    int* arr;
    public:
    vector();
    vector(const vector&);
    vector&operator=(const vector&);
    vector&operator[](const vector&);
    ~vector();
    void pushBack(int); //el value
    void popBack();
    void insertAt(int, int); //position
    void removeAt(int); //position
    bool elementExists(int); //element value
    int size;
    void print() const;
};

vector::vector()
{
    size = 1;
    arr = new int[size];
    arr[0] = 0;
}

vector::vector(const vector& newVector)
{
    size = newVector.size;
    arr = new int[size];
    assert(arr != NULL);
    for(int i=0; i<size; ++i)
    {
        arr[i] = newVector.arr[i];
    }
}
vector& vector::operator=(const vector& newVector)
{
    if(this != &newVector)
    {
        size = newVector.size;
        if(arr != NULL)
        {
            delete[] arr;
        }
        arr = new int[size];
        assert(arr != NULL);
        for(int i=0; i<size; ++i)
        {
            arr[i] = newVector.arr[i];
        }
    }
    return *this;
}

void vector::pushBack(int val)
{
    int* temp = new int[size+1];
    for(int i=0; i<size; i++)
    {
        temp[i] = arr[i];
    }
    temp[size] = val;
    delete[] arr;
    size++;
    arr = new int[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}

void vector::popBack()
{
    size--;
}

void vector::insertAt(int index, int val)
{
    int* temp = new int[size+1];
    for(int i=0; i<index; i++)
    {
        temp[i] = arr[i];
    }
    temp[index-1] = val;
    for(int i=index; i<size+1; i++)
    {
        temp[i] = arr[i-1];
    }
    size++;
    delete[] arr;
    arr = new int[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}

void vector::removeAt(int index)
{
    int* temp = new int[size-1];
    for(int i=0; i<index; i++)
    {
        temp[i] = arr[i];
    }
    for(int i=index; i<size-1; i++)
    {
        temp[i] = arr[i+1];
    }
    size--;
    delete[] arr;
    arr = new int[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}

void vector::print() const
{
    for(int i=0; i<size; i++)
    {
        cout<<"Element "<<i<<": "<<arr[i]<<endl;
    }
}

vector::~vector()
{
    delete[] arr;
}

int main()
{
    vector vect;
    vect.pushBack(2);
    vect.pushBack(3);
   // vect.popBack();
    vect.insertAt(2,4);
    vect.removeAt(3);
    vect.print();
    return 0;
}