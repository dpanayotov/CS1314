#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Set
{
public:
    int* el;
    int size;
    Set()
    {
        size=0;
        el = NULL;
    }

    Set(int a[], int s)
    {
        size=s;
        el = new int[size];
        for(int i=0; i<size; i++)
        {
            el[i] = a[i];
        }
    }

    Set(int a)
    {
        size = 1;
        el = new int[size];
        el[0] = a;
    }

    Set(char* a)
    {
        size=strlen(a);
        el = new int[strlen(a)];
        for(int i=0; i<size; i++)
        {
            el[i] = (int)a[i];
        }
    }

    Set(const Set& other)
    {
        size = other.size;
        el = new int[size];
        for(int i=0; i<size; i++)
        {
            el[i] = other.el[i];
        }
    }

    ~Set()
    {
        delete[] el;
    }

    void readSet(char* fname)
    {
        ifstream f(fname);
        f>>size;
        for(int i=0; i<size; i++)
        {
            f>>el[i];
        }
    }

    void printSet()
    {
        cout<<"\n:"<<size<<endl;
        for(int i=0; i<size; i++)
        {
            cout<<el[i]<<' ';
        }
        cout<<endl;
    }

    void add(int x)
    {
        if(!member(x))
        {
            int* el2 = new int[size+1];
            for(int i=0; i<size; i++)
            {
                el2[i] = el[i];
            }
            delete[] el;
            el2[size] = x;
            size++;
            el = el2;
        }
    }

    void del(int x)
    {
        if(member(x))
        {
            int* el2 = new int[size-1];
            int j=0;
            for(int i=0; i<size; i++)
            {
                if(el[i] != x)
                {
                    el2[j] = el[i];
                    j++;
                }
            }
            delete[] el;
            size--;
            el = el2;
        }
    }


    bool member(int x)
    {
        for(int i=0; i<size; i++)
        {
            if(el[i]==x)
                return true;
        }
        return false;
    }

    bool operator<(Set& s)
    {
        for(int i=0; i<this->size; i++)
        {
            if(!s.member(this->el[i]))
            {
                return false;
            }
        }
        return true;
    }

    Set operator+(const Set& s)
    {
        Set newSet;
        for(int j=0; j<this->size; j++)
        {
            newSet.el[j] = this->el[j];
        }
        for(int k=0; k<s.size; k++)
        {
            newSet.el[k+this->size] = s.el[k];
        }

        newSet.size = this->size + s.size;
        return newSet;
    }

    Set intersection(Set s)
    {
        Set newSet;
        for(int i=0; i<s.size; i++)
        {
            if(this->member(s.el[i]) && !newSet.member(s.el[i]))
            {
                newSet.size++;
                newSet.add(s.el[i]);
            }
        }
        return newSet;
    }

    Set difference(Set s)
    {
        Set newSet;
        int p=0;
        for(int i=0; i<s.size; i++)
        {
            if(!this->member(s.el[i]) && !newSet.member(s.el[i]))
            {
                newSet.size++;
                newSet.el[p] = s.el[i];
                p++;
            }
        }
        for(int j =0; j<this->size; j++)
        {
            if(!s.member(this->el[j]) && !newSet.member(this->el[j]))
            {
                newSet.size++;
                newSet.el[p] = this->el[j];
                p++;
            }
        }
        return newSet;
    }

    Set& operator=(const Set& s)
    {
        if(this != &s)
        {
            size = s.size;
            if(el != NULL)
            {
                delete[] el;
            }
            el = new int[size];
            for(int i=0; i<size; i++)
            {
                el[i] = s.el[i];
            }
            return *this;
        }
    }

    Set& operator+=(const Set& s)
    {
        *this = *this + s;
        return *this;
    }

    bool operator==(Set& s)
    {
        for(int i=0; i<s.size; i++)
        {
            if(!(s.member(this->el[i])))
            {
                return false;
            }
        }
        return true;
    }

    bool operator<=(Set& s)
    {
        if(*this < s || *this==s)
        {
            return true;
        }
        return false;
    }
};

ostream& operator<<(ostream& out, Set s)
{
    for(int i=0; i<s.size; i++)
    {
        out<<s.el[i];
    }
    return out;
}

class AllSets
{
public:
    Set newSet[2];

    Set unionAllSets()
    {
        Set merged;
        int newSize = newSet[0].size;
        for(int i=0; i<2; i++)
        {
            merged.operator+(newSet[i]);
            newSize += newSet[i].size;
        }
        merged.size = newSize;
        return merged;
    }
};

int main()
{
    int a[] = {'e', 'a', 't'};
    Set s1('e'), s2("hello"), s3(), s4(a,3);
    s4.add(123);
    s4.del(101);
    s4.printSet();

    s4.printSet();
    s4 = s1;
    cout<<(s1<=s4);
    cout<<endl;
    cout<<s4;
    return 0;
}