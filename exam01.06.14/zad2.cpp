#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>

using namespace std;

class CelestialBody
{
    char* name;
    double xCoord, yCoord;
    double radius;
public:
    CelestialBody();
    CelestialBody(char*, double, double, double);
    CelestialBody(const CelestialBody&);
    CelestialBody& operator=(const CelestialBody&);
    ~CelestialBody();
    double calculateDistance(const CelestialBody&);
    double getRadius() const;
    void setRadius(double r)
    {
        radius = r;
    }
    void setCoord(double _xCoord, double _yCoord)
    {
        xCoord = _xCoord;
        yCoord = _yCoord;
    }

    double getX() const
    {
        return xCoord;
    }

    double getY() const
    {
        return yCoord;
    }
};

CelestialBody::CelestialBody()
{
    name = new char[1];
    assert(name != NULL);
    name[0]='\0';
    xCoord=yCoord=radius=1;
}

CelestialBody::CelestialBody(char* _name, double _xCoord, double _yCoord, double _radius)
{
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    xCoord = _xCoord;
    yCoord = _yCoord;
    radius = _radius;
}

CelestialBody::CelestialBody(const CelestialBody& other)
{
    name = new char[strlen(other.name)+1];
    assert(name!=NULL);
    strcpy(name, other.name);
    xCoord = other.xCoord;
    yCoord = other.yCoord;
    radius = other.radius;
}

CelestialBody& CelestialBody::operator=(const CelestialBody& other)
{
    if(this != &other)
    {
        delete[] name;
        name = new char[strlen(other.name)+1];
        assert(name != NULL);
        strcpy(name, other.name);
        xCoord = other.xCoord;
        yCoord = other.yCoord;
        radius = other.radius;
    }
    return *this;
}

CelestialBody::~CelestialBody()
{
    delete[] name;
}

double CelestialBody::calculateDistance(const CelestialBody& other)
{
    return sqrt((other.xCoord - xCoord)*(other.xCoord-xCoord) + (other.yCoord - yCoord)*(other.yCoord - yCoord));
}

double CelestialBody::getRadius() const
{
    return radius;
}

class Planet : public CelestialBody
{
    bool habitable;
    double density;
public:
    Planet();
    Planet(const Planet&);
    Planet& operator=(const Planet&);
    ~Planet();
    int getNumHabitants();
};

Planet::Planet() : CelestialBody()
{
    habitable = true;
    density = 2;
}

Planet::Planet(const Planet& other) : CelestialBody(other)
{
    habitable = other.habitable;
    density = other.density;
}

Planet& Planet::operator=(const Planet& other)
{
    if(this != &other)
    {
        CelestialBody::operator=(other);
        habitable = other.habitable;
        density = other.density;
    }
    return *this;
}

Planet::~Planet()
{

}

int Planet::getNumHabitants()
{
    if(habitable)
    {
        return density*4*3.14*getRadius()*getRadius();
    }
    return 0;
}

class Sun : public CelestialBody
{
    Planet* planets;
    int size;
public:
    Sun();
    Sun(const Sun&);
    Sun(Planet*, int);
    Sun& operator=(const Sun&);
    ~Sun();
    int habitantsBrightestPlanet();
    double getDistance(int);
    double getArea(int);
};

Sun::Sun() : CelestialBody()
{
    size = 1;
    planets = new Planet[size];
    assert(planets != NULL);
}

Sun::Sun(Planet* _planets, int _size) : CelestialBody()
{
    size = _size;
    planets = new Planet[size];
    assert(planets != NULL);
    for(int i =0; i<size; i++)
    {
        planets[i] = _planets[i];
    }
}

Sun::Sun(const Sun& other) : CelestialBody(other)
{
    size = other.size;
    planets = new Planet[size];
    assert(planets != NULL);
    for(int i=0; i<size; i++)
    {
        planets[i] = other.planets[i];
    }
}

Sun& Sun::operator=(const Sun& other)
{
    if(this != &other)
    {
        size = other.size;
        delete[] planets;
        planets = new Planet[size];
        assert(planets != NULL);
        for(int i=0; i<size; i++)
        {
            planets[i] = other.planets[i];
        }
        CelestialBody::operator=(other);
    }
}

Sun::~Sun(){}

double Sun::getDistance(int i)
{
    return sqrt((this->getX() - planets[i].getX())*(this->getX() - planets[i].getX()) + (this->getY() - planets[i].getY())*(this->getY() - planets[i].getY()));
}

double Sun::getArea(int i)
{
    return 4 * 3.14 * planets[i].getRadius() * planets[i].getRadius();
}

int Sun::habitantsBrightestPlanet()
{
    int max=0;
    double area;
    double distance;
    for(int i=0; i<size-1; i++)
    {
        if(getArea(i)/getDistance(i) > getArea(i+1)/getDistance(i+1))
        {
            max = i;
        }
    }

    return (getArea(max)/getDistance(max) > getArea(size-1) / getDistance(size-1)) ? planets[max].getNumHabitants() : planets[size-1].getNumHabitants();
}

int main()
{
    CelestialBody a;
    Planet b, c;
    c.setCoord(0,0);
    c.setRadius(3.5);
    Planet* planets = new Planet[2];
    planets[0] = c;
    planets[1] = b;
    cout<<c.getNumHabitants()<<endl;
    Sun s(planets, 2);
    s.setCoord(1,1);
    cout<<s.habitantsBrightestPlanet()<<endl;
    return 0;
}
