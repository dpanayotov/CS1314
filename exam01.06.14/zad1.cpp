#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T>* next;
};

template <typename T>
class CyclicList
{
    Node<T>* end;
    void copy(const CyclicList&);
    void del();
public:
    CyclicList();
    CyclicList(const CyclicList&);
    CyclicList& operator=(const CyclicList&);
    ~CyclicList();
    void addElement(const T&);
    bool removeElement(T&);
    void print() const;
};

template <typename T>
void CyclicList<T>::copy(const CyclicList& other)
{
    Node<T>* temp = new Node<T>;
    end = other.end;
    temp = other.end->next;
    while(temp->next != other.end)
    {
        addElement(temp->data);
        temp = temp->next;
        end->next = temp;
    }
}

template <typename T>
CyclicList<T>& CyclicList<T>::operator=(const CyclicList& other)
{
    del();
    copy(other);
    return *this;
}

template <typename T>
void CyclicList<T>::del()
{
    T data;
    while(removeElement(data))
    {
        cout<<"data deleted: "<<data<<endl;
    }
}

template <typename T>
CyclicList<T>::CyclicList()
{
    end = NULL;
}

template <typename T>
CyclicList<T>::CyclicList(const CyclicList& other)
{
    end = new Node<T>;
    copy(other);
}

template <typename T>
void CyclicList<T>::addElement(const T& _data)
{
    if(end == NULL)
    {
		end = new Node<T>;
        end->data = _data;
        end->next = end;
    }
    else
    {
        Node<T>* temp = new Node<T>;
        temp->data = _data;
        temp->next = end->next;
        end->next = temp;
    }
}

template <typename T>
bool CyclicList<T>::removeElement(T& _data)
{
    if(end != NULL)
    {
        Node<T>* temp = new Node<T>;
        temp = end->next;

        end->next = temp->next;
        _data = temp->data;
        if(end == temp)
        {
            end = NULL;
            return 1;
        }
        delete[] temp;
        return 1;
    }
    return 0;
}

template <typename T>
void CyclicList<T>::print() const
{
    Node<T>* temp = new Node<T>;
    temp = end->next;
    while(temp != end)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
    cout<<end->data; //
}

template <typename T>
CyclicList<T>::~CyclicList()
{
    del();
}

int main()
{
    CyclicList<int> a;
    a.addElement(1);
    a.addElement(2);
    a.addElement(3);
    int asd = 1;
    a.removeElement(asd);
    cout<<asd<<endl;
	a.print();
    CyclicList<int> b(a);
    cout<<endl<<"CyclicList(&): ";
    b.print();
    CyclicList<int> c;
    cout<<endl<<"operator=(a): ";
    c = a;
    b.print();
    cout<<endl;
}
