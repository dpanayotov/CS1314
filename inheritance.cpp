#include <iostream>
#include <cstring>

using namespace std;

class Film
{
    char* title;
    int year;
    public:
    Film();
    virtual ~Film();
    virtual void print();
    void printAll();
};



class Animation : virtual public Film
{
    char* heroName;
    public:
    Animation();
    ~Animation();
    void print();
};

class Comedy: virtual public Film
{
    int actorCnt;
    char** actorNames;
    public:
    Comedy();
    ~Comedy();
    void print();
};

class Drama : virtual public Film
{
    char* maleLead;
    char* femaleLead;
    public:
    Drama();
    ~Drama();
    void print();
};

class History : public Comedy, public Animation, public Drama
{
    int historicPersonCnt;
    public:
    History();
    ~History();
    void print();
    void printAll();
};

void History::printAll()
{
	Film::print();
	Animation::print();
	Comedy::print();
	Drama::print();
	print();
}

Film::Film()
{
	cout<<"Film()"<<endl;
    title = new char[5];
    strcpy(title, "asd");
    year = 1999;
}

Film::~Film()
{
	cout<<"~Film()"<<endl;
    delete[] title;
}

void Film::print()
{
    cout<<title<<' '<<year<<endl;
}

Animation::Animation() : Film()
{
	cout<<"Animation()"<<endl;
    heroName = new char[10];
    strcpy(heroName, "snoopy");
}

Animation::~Animation()
{
	cout<<"~Animation()"<<endl;
    delete[] heroName;
}

void Animation::print()
{
    cout<<heroName<<endl;
}

Comedy::Comedy() : Film()
{
	cout<<"Comedy()"<<endl;
    actorCnt = 2;
    actorNames = new char*[actorCnt];
    for(int i=0; i<actorCnt; i++)
    {
        actorNames[i] = new char[10];
    }
    strcpy(actorNames[0], "johny");
    strcpy(actorNames[1], "bravo");
}

Comedy::~Comedy()
{
	cout<<"~Comedy()"<<endl;
    for(int i=0; i<actorCnt; i++)
    {
        delete[] actorNames[i];
    }
    delete[] actorNames;
}

void Comedy::print()
{
    for(int i=0; i<actorCnt; i++)
    {
        cout<<actorNames[i]<<' ';
    }
    cout<<endl;
}

Drama::Drama() : Film()
{
	cout<<"Drama()"<<endl;
    maleLead = new char[10];
    femaleLead = new char[10];
    strcpy(maleLead, "ivanka");
    strcpy(femaleLead, "pencho");
}

Drama::~Drama()
{
	cout<<"~Drama()"<<endl;
    delete[] maleLead;
    delete[] femaleLead;
}

void Drama::print()
{
    cout<<maleLead<<' '<<femaleLead<<endl;
}

History::History() : Comedy(), Animation(), Drama()
{
	cout<<"History()"<<endl;
    historicPersonCnt = 10;
}

History::~History()
{
	cout<<"~History()"<<endl;
}

void History::print()
{
    cout<<historicPersonCnt<<endl;
}

int main()
{

    History e;

/*    cout<<"Film: ";
    a.print();

    cout<<"Comedy: ";
    b.print();

    cout<<"Animation: ";
    c.print();

    cout<<"Drama: ";
    d.print();

    cout<<"History: ";
    e.print();

    cout<<endl;
    Film* ptr = &a;
    ptr->print();
    ptr = &b;
    cout<<endl;
    ptr->print();
    ptr=&c;
    cout<<endl;
    ptr->print();
    ptr=&e;
    cout<<endl;
    ptr->print();*/

    e.printAll();
    return 0;
}
