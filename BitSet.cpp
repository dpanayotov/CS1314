#include <iostream>
#include <cassert>
using namespace std;
class BitSet
{
    long* arr;
    int n;
    const static int longBits = sizeof(long)*8;
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
    n=1;
    arr = new long[n];
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
    arr = new long[n];
    assert(arr != NULL);
    for(int i=0; i<n; i++)
    {
        arr[i] = other.arr[i];
    }
}

BitSet::BitSet(int maxN)
{
    cout<<"overload"<<endl;
    n = maxN/longBits + 1;
    arr = new long[n];
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
	//check if numBits >= amount of bits in array
	//if so => number/(size) + 1
	//(e.g. 250/32 +1 = 7+1=8 => we'll have 8*32=256 bits which are enough
	if(numBit >= longBits*n)
	{
		int tempSize = numBit/longBits + 1;
		long* temp = new long[tempSize];
		assert(temp != NULL);
		for(int i=0; i<n; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		n = tempSize;
		arr = new long[n];
		for(int i=0; i<n; i++)
		{
			arr[i] = temp[i];
		}
		assert(arr != NULL);
		delete[] temp;
	}
    int arrNum = numBit / longBits;
    int bitNum = numBit % longBits;
    long mask = 1 << bitNum;
    arr[arrNum] |= mask;
}

bool BitSet::member(int numBit)
{
    int arrNum = numBit / longBits;
    int bitNum = numBit % longBits;
    long mask = 1 << bitNum;
    return (arr[arrNum] & mask) != 0;
}

void BitSet::print()
{
    for(int i=0; i<longBits*n; i++)
    {
        if(member(i))
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    BitSet bit, bit1(3);
    bit.add(365);
    bit.add(253);
    bit.print();
    return 0;
}
