#include <iostream>
#include <cassert>

using namespace std;
template <typename T>
class Vector
{
    T* arr;
    int capacity;
    int size;
public:
    Vector();
    Vector(int);
    Vector(const T*, int);
    Vector(const Vector&);
    Vector&operator=(const Vector&);
    int&operator[](const int);
    ~Vector();
    void pushBack(int); //el value
    void popBack();
    void insertAt(int, int); //position
    void removeAt(int); //position
    bool elementExists(int); //element value
    void getSize() const;
    void print() const;
};
template <typename T>
Vector<T>::Vector()
{
    size = 1;
    capacity = 16;
    arr = new T[capacity];
    arr[0] = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& newVector)
{
    size = newVector.size;
    capacity = newVector.capacity;
    arr = new T[capacity];
    assert(arr != NULL);
    for(int i=0; i<size; ++i)
    {
        arr[i] = newVector.arr[i];
    }
}

template <typename T>
Vector<T>::Vector(const T* arr, int cap)
{

}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& newVector)
{
    if(this != &newVector)
    {
        size = newVector.size;
        capacity = newVector.capacity;
        if(arr != NULL)
        {
            delete[] arr;
        }
        arr = new T[capacity];
        assert(arr != NULL);
        for(int i=0; i<size; ++i)
        {
            arr[i] = newVector.arr[i];
        }
    }
    return *this;
}
template <typename T>
int& Vector<T>::operator [](const int index)
{
	return arr[index];
}

template <typename T>
void Vector<T>::pushBack(int val)
{
    T* temp = new T[size+1];
    for(int i=0; i<size; i++)
    {
        temp[i] = arr[i];
    }
    temp[size] = val;
    delete[] arr;
    size++;
    arr = new T[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}
template <typename T>
void Vector<T>::popBack()
{
    size--;
}
template <typename T>
void Vector<T>::insertAt(int index, int val)
{
    T* temp = new T[size+1];
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
    arr = new T[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}
template <typename T>
void Vector<T>::removeAt(int index)
{
    T* temp = new T[size-1];
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
    arr = new T[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }
}
template <typename T>
void Vector<T>::print() const
{
    for(int i=0; i<size; i++)
    {
        cout<<"Element "<<i<<": "<<arr[i]<<endl;
    }
}
template <typename T>
bool Vector<T>::elementExists(int element)
{
	for(int i=0; i<size; i++)
	{
		if(arr[i] == element)
		{
			return true;
		}
	}
	return false;
}
template <typename T>
void Vector<T>::getSize() const
{
	cout<<"Array size is "<<size<<endl;
}
template <typename T>
Vector<T>::~Vector()
{
    delete[] arr;
}

int main()
{
    Vector<int> vect;
    vect.pushBack(2);
    vect.pushBack(3);
    vect.popBack();
    vect.insertAt(2,4);
    vect.removeAt(3);
    vect.print();
    vect[0] = 4;
    cout<<vect[1]<<endl;
    return 0;
}
