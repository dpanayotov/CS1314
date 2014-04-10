#include <iostream>
#include <cassert>
using namespace std;
class BitSet
{
    long* arr;
    int n;
    const static int s = sizeof(long)*8;
public:
    BitSet();
    BitSet(const BitSet&);
    BitSet(int maxN);
    ~BitSet();
    BitSet&operator=(const BitSet&);
    bool operator==(const BitSet&);
    int& operator[](int);
    void add(int);
    bool member(int);
    void remove();
    void print();
};

BitSet::BitSet()
{
    cout<<"default"<<endl;
    n=2;
    arr = new long[s*n];
    assert(arr != NULL);
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
}

BitSet::BitSet(const BitSet& other)
{
    cout<<"copy"<<endl;
    n = other.n;
    arr = new long[n*s*s];
    assert(arr != NULL);
    for(int i=0; i<n; i++)
    {
        arr[i] = other.arr[i];
    }
}

BitSet::BitSet(int maxN)
{
    cout<<"overload"<<endl;
    n = s/maxN + 1;
    arr = new long[s*maxN];
    assert(arr != NULL);
    for(int i=0; i<n; i++)
    {
        arr[i] = 0;
    }
}

BitSet::~BitSet()
{
    cout<<"destrcutor"<<endl;
    delete[] arr;
}

void BitSet::add(int numBit)
{
    int arrNum = numBit / s; //get arr number
    int bitNum = numBit % s;
    long mask = 1 << bitNum;
    arr[arrNum] |= mask;
}

bool BitSet::member(int numBit)
{
    int arrNum = numBit / s;
    int bitNum = numBit % s;
    long mask = 1;
    mask = 1 << bitNum;
    return (arr[arrNum] & mask) != 0;
}

void BitSet::print()
{
    for(int i=0; i<s*n; i++)
    {
        if(member(i))
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    BitSet bit, bit1(2);
    bit.add(128);
    bit.add(30);
    bit.add(50);
    //cout<<bit.member(128)<<endl;
    bit.print();
    return 0;
}