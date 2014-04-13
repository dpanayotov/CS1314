#include <iostream>
#include <cassert>

using namespace std;

class Pixel
{
    int red, green, blue; //range 0-255
public:
    Pixel();
    Pixel(int, int, int);
    Pixel(const Pixel&);
    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    void print() const;
    int getValue();
    void setValue(int, int, int);
    bool inRange(int, int, int);
    bool operator<(const Pixel&);
    bool operator>(const Pixel&);
    bool operator==(const Pixel&);
    bool operator!=(const Pixel&);
};

Pixel::Pixel()
{
    red = 0;
    green = 0;
    blue = 0;
}

Pixel::Pixel(int newRed, int newGreen, int newBlue)
{
    setValue(newRed, newGreen, newBlue);
}

Pixel::Pixel(const Pixel& other)
{
    setValue(other.red, other.green, other.blue);
}

void Pixel::setRed(int newRed)
{
    red = newRed;
}

void Pixel::setGreen(int newGreen)
{
    green = newGreen;
}

void Pixel::setBlue(int newBlue)
{
    blue = newBlue;
}

int Pixel::getRed() const
{
    return red;
}

int Pixel::getGreen() const
{
    return green;
}

int Pixel::getBlue() const
{
    return blue;
}

void Pixel::print() const
{
    cout<<'['<<red<<','<<green<<','<<blue<<']';
}

int Pixel::getValue()
{
    return (255*255*red + 255*green + blue);
}

void Pixel::setValue(int newRed, int newGreen, int newBlue)
{
    if(inRange(newRed, newGreen, newBlue))
    {
        setRed(newRed);
        setGreen(newGreen);
        setBlue(newBlue);
    }
    else
    {
        cout<<"Must be between [0,255]"<<endl;
    }
}

bool Pixel::inRange(int newRed, int newGreen, int newBlue)
{
    if(newRed>=0 && newRed<=255 && newGreen>=0 && newGreen<=255 && newBlue>=0 && newBlue<=255)
    {
        return true;
    }
    return false;
}

bool Pixel::operator>(const Pixel& other)
{
    if(this != &other)
    {
        if(red>other.red && green>other.green && blue>other.blue)
        {
            return true;
        }
    }
    return false;
}

bool Pixel::operator<(const Pixel& other)
{
    if(this != &other)
    {
        if(red<other.red && green<other.green && blue<other.blue)
        {
            return true;
        }
    }
    return false;
}

bool Pixel::operator==(const Pixel& other)
{
    if(this != &other)
    {
        if(red==other.red && green==other.green && blue==other.blue)
        {
            return true;
        }
    }
    return false;
}

bool Pixel::operator!=(const Pixel& other)
{
    if(this != &other)
    {
        if(red!=other.red && green!=other.green && blue!=other.blue)
        {
            return true;
        }
    }
    return false;
}

class ColorLine
{
    Pixel* arr;
    int size;
public:
    ColorLine();
    ColorLine(int, Pixel*);
    ColorLine(const ColorLine&);
    ColorLine&operator=(const ColorLine&);
    ~ColorLine();
    void setSize(int);
    int getSize() const;
    Pixel getPixel(int);
    int getPixelNum() const;
    void print() const;
    Pixel* sort();
    Pixel& operator[](int);
};

ColorLine::ColorLine()
{
    size = 1;
    arr = new Pixel[size];
    assert(arr != NULL);
    for(int i=0; i<size; i++)
    {
        arr[i] = Pixel();
    }
}

ColorLine::ColorLine(int newSize, Pixel* pixels)
{
    size = newSize;
    arr = new Pixel[size];
    assert(arr != NULL);
    for(int i=0; i<size; i++)
    {
        arr[i] = pixels[i];
    }
}

ColorLine::ColorLine(const ColorLine& other)
{
    size = other.size;
    arr = new Pixel[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = other.arr[i];
    }
}

ColorLine& ColorLine::operator=(const ColorLine& other)
{
    if(this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new Pixel[size];
        assert(arr != NULL);
        for(int i=0; i<size; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

void ColorLine::setSize(int newSize)
{
    size = newSize;
}

int ColorLine::getSize() const
{
    return size;
}

Pixel ColorLine::getPixel(int index)
{
    arr[index].print();
}

void ColorLine::print() const
{
    cout<<'[';
    for(int i=0; i<size; i++)
    {
        arr[i].print();
        if(i>=0 && i<size-1)
        {
            cout<<", ";
        }
    }
    cout<<']'<<endl;
}

Pixel* ColorLine::sort()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(arr[i].getValue() > arr[j].getValue())
            {
                Pixel swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
    return arr;
}

Pixel& ColorLine::operator[](int index)
{
    return arr[index];
}

ColorLine::~ColorLine()
{
    delete[] arr;
}

int main()
{
    Pixel pix(2,1,255), pix1[3];
    pix.print();
    cout<<endl;
    pix1[0].print();
    pix1[0].setValue(0,1,2);
    pix1[1].setValue(3,4,5);
    pix1[2].setValue(2,1,255);
    cout<<endl<<"!= : "<<(pix!=pix1[1])<<endl;
    cout<<"> : "<<(pix>pix1[1])<<endl;
    cout<<"< : "<<(pix<pix1[1])<<endl;
    cout<<"== : "<<(pix==pix1[2])<<endl;
    ColorLine cl, cl2(3,pix1);
    cl = cl2;
    cl.print();
    cl[0].setValue(0,2,3);
    cl.sort(); //196100, 130560, 513
    cl.print();
    return 0;
}
