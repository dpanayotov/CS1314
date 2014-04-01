/*
 * main.cpp
 *
 *  Created on: Mar 19, 2014
 *      Author: Dimitar Panayotov
 */

#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Label
{
private:
    char* content;
    int barcode;
public:
    Label();
    Label(char*, int);
    Label(const Label&);
    Label&operator=(const Label&);
    ~Label();
    void setContent(char*);
    void setBarcode(int);
    char* getContent() const;
    int getBarcode() const;
    void printLabel() const;
    void readLabel();
};

class Expiration
{
private:
    int day, month, year;
public:
    Expiration();
    Expiration(int, int, int);
    Expiration(const Expiration&);
    Expiration&operator=(const Expiration&);
    ~Expiration();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

class Product
{
private:
    char* name;
    double weight, price;
    Expiration expDate;
    Label label;
public:
    Product();
    Product(char*, double, double, Expiration, Label);
    Product(const Product&other);
    Product&operator=(const Product&);
    ~Product();
    void setName(char*);
    void setWeight(double);
    void setPrice(double);
    void setExpiration(Expiration);
    void setLabel(Label);
    char* getName() const;
    double getWeight() const;
    double getPrice() const;
    Expiration getExpDate() const;
    Label getLabel() const;
};

class Shopper
{
private:
    double cash;
    Product* shoppingList;
    int numberOfProducts;
public:
    Shopper();
    Shopper(double, Product*, int);
    Shopper(const Shopper&);
    Shopper&operator=(const Shopper&);
    ~Shopper();
    void setCash(double);
    void setProducts(Product*);
    void setProductsN(int);
    double getCash() const;
    Product* getProducts() const;
    double productsWeight();
    double productsPrice();
    bool hasMoney();
    void cashIn();
    Product* addProduct(Product);
    Product* removeProduct(char*);
};

//start Label
Label::Label()//ok
{
    content = new char[1];
    assert(content != NULL);
    content[0] = '\0';
    barcode = 0;
}

Label::Label(const Label &other)//ok
{
    content = new char[strlen(other.content) + 1];
    assert(content != NULL);
    strcpy(content, other.content);
    barcode = other.barcode;
}

Label::Label(char* c, int b)//ok
{
    if (c != NULL && strcmp(c, "") > 0)
    {
        content = new char[strlen(c) + 1];
        assert(content != NULL);
        strcpy(content, c);
    }
    else
    {
        content = new char[1];
        assert(content != NULL);
        content[0] = '\0';
    }
    if (b > 0)
    {
        barcode = b;
    }
    else
    {
        barcode = 0;
    }
}

Label& Label::operator=(const Label& other)//ok
{
    if (this != &other)
    {
        if (content != NULL)
        {
            delete[] content;
        }
        content = new char[strlen(other.content) + 1];
        strcpy(content, other.content);
        barcode = other.barcode;
    }
    return *this;
}

Label::~Label()//ok
{
    if (content != NULL)
    {
        delete[] content;
    }
}

void Label::setContent(char *c)
{
    if (c != NULL && strcmp(c, "") > 0)
    {
        delete[] content;
        content = new char[strlen(c) + 1];
        assert(content != NULL);
        strcpy(content, c);
    }
    else
    {
        delete[] content;
        content = new char[1];
        assert(content != NULL);
        content[0] = '\0';
    }

}

void Label::setBarcode(int b)
{
    if (b > 0)
    {
        barcode = b;
    }
    else
    {
        barcode = 0;
    }
}

char* Label::getContent() const
{
    return content;
}

int Label::getBarcode() const
{
    return barcode;
}

void Label::readLabel()
{
    int bar;
    char con[100];
    cout << "Enter barcode: ";
    cin >> bar;
    setBarcode(bar);
    cin.get();
    cout << "Enter content: ";
    cin.getline(con, 100);
    setContent(con);
}

void Label::printLabel() const
{
    cout << "Label:" << endl;
    cout << "Content: " << content << endl;
    cout << "Barcode: " << barcode << endl;
    cout << "End of label" << endl;
}
//end Label
//start Expiration
Expiration::Expiration()
{
    day = 0;
    month = 0;
    year = 0;
}

Expiration::Expiration(int d, int m, int y)
{
    day = d;
    month = m;
    year = m;
}

Expiration& Expiration::operator=(const Expiration& other)
{
    if (this != &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Expiration::Expiration(const Expiration& other)
{
    day = other.day;
    month = other.month;
    year = other.month;
}

Expiration::~Expiration()
{
//do something ?!
}

void Expiration::setDay(int d)
{
    day = d;
}

void Expiration::setMonth(int m)
{
    month = m;
}

void Expiration::setYear(int y)
{
    year = y;
}
int Expiration::getDay() const
{
    return day;
}

int Expiration::getMonth() const
{
    return month;
}

int Expiration::getYear() const
{
    return year;
}
//end Expiration
//start Product
Product::Product() // : label(), expDate()
{
    name = new char[1];
    assert(name != NULL);
    name[0] = '\0';
    weight = 0;
    price = 0;
    expDate = Expiration();
    label = Label();
}

Product::Product(const Product& other)// : label(other.label), expDate(other.expDate)
{
	name = new char[strlen(other.name) + 1];
	assert(name!= NULL);
    strcpy(name, other.name);
    price = other.price;
    weight = other.weight;
	label = other.label;
	expDate = other.expDate;

}

Product& Product::operator=(const Product& other)//ok
{
    if (this != &other)
    {
        if (name != NULL)
        {
            delete[] name;
        }
		name = new char[strlen(other.name) + 1];
		assert(name != NULL);
        strcpy(name, other.name);
        price = other.price;
        weight = other.weight;
        label = other.label;
        expDate = other.expDate;
    }
    return *this;
}

Product::Product(char* prName, double prWeight, double prPrice,/*const Expiration&*/Expiration prExpDate,/*const Label&*/ Label prLabel)//:expDate(prExpDate), label(prLabel)
{
    if (prName != NULL && strcmp(prName, "")>0)
    {
        name = new char[strlen(prName) + 1];
        assert(name != NULL);
        strcpy(name, prName);
    }
    else
    {
        name = new char[1];
        assert(name != NULL);
        name[0] = '\0';
    }
    weight = prWeight;
    price = prPrice;
    expDate = prExpDate;
    label = prLabel;
}

Product::~Product()
{
    delete [] name;
}

void Product::setName(char* prName)//ок
{
    if (prName != NULL && strcmp(prName, "")>0)
    {
        delete[] name;
        name = new char[strlen(prName) + 1];
        assert(name != NULL);
        strcpy(name, prName);
    }
    else
    {
        delete[] name;
        name = new char[1];
        assert(name != NULL);
        name[0] = '\0';
    }
}

void Product::setWeight(double prWeight)//ок
{
    if (prWeight > 0)
    {
        weight = prWeight;
    }
}

void Product::setPrice(double prPrice)//ок
{
    if (prPrice > 0)
    {
        price = prPrice;
    }
}

void Product::setExpiration(Expiration prExp)//ок
{
    expDate = prExp;
}

void Product::setLabel(Label prLabel)//ok
{
    label = prLabel;
}

char* Product::getName() const
{
    return name;
}

double Product::getWeight() const
{
    return weight;
}

double Product::getPrice() const
{
    return price;
}

Expiration Product::getExpDate() const
{
    return expDate;
}

Label Product::getLabel() const
{
    return label;
}
//end Product

//start Shopper
Shopper::Shopper()
{
    cash = 0;
    numberOfProducts = 1;
    Expiration expir;
    Label lab;
    Product pr;
    shoppingList = new Product[numberOfProducts];
    shoppingList[0] = pr;
}

Shopper::Shopper(double shCash, Product* pr, int numPr)
{
    cash = shCash;
    numberOfProducts = numPr;
    if(pr != NULL)
    {
        shoppingList = new Product[numberOfProducts];
        assert(shoppingList != NULL);
        for(int i=0; i<numberOfProducts; i++)
        {
            shoppingList[i] =  pr[i];
        }
    }
    else
    {
        Product pr;
        shoppingList = new Product[numberOfProducts];
        assert(shoppingList != NULL);
        shoppingList[0] = pr;
    }
}
Shopper::Shopper(const Shopper& other)
{
    cash = other.cash;
    numberOfProducts = other.numberOfProducts;
    if(shoppingList != NULL)
    {
        delete[] shoppingList;
    }
    shoppingList = new Product[numberOfProducts];
    assert(shoppingList != NULL);
    for(int i=0; i<numberOfProducts; i++)
    {
        shoppingList[i] = other.shoppingList[i];
    }
}
Shopper& Shopper::operator=(const Shopper& other)
{
    if (this != &other)
    {
        cash = other.cash;
        numberOfProducts = other.numberOfProducts;
        if(shoppingList != NULL)
        {
            delete[] shoppingList;
        }
        assert(shoppingList != NULL);
        shoppingList = new Product[numberOfProducts];
        for(int i=0; i<numberOfProducts; i++)
        {
            shoppingList[i] = other.shoppingList[i];
        }
    }
    return *this;
}
Shopper::~Shopper()
{
    delete[] shoppingList;
}

void Shopper::setCash(double shCash)
{
    cash = shCash;
}

double Shopper::getCash() const
{
    return cash;
}

void Shopper::setProductsN(int prN)
//ако имаш такава функция , която ти променя броя на продуктите е смислено и добре да промениш и самия масив
//от продукти
{
    numberOfProducts = prN;
}

double Shopper::productsWeight()
{
    double allWeight = 0;
    for (int i = 0; numberOfProducts; i++)
    {
        allWeight += shoppingList[i].getWeight();
    }
    return allWeight;
}

double Shopper::productsPrice()
{
    double allPrice = 0;
    for (int i = 0; shoppingList[i].getPrice(); i++)
    {
        allPrice += shoppingList[i].getPrice();
    }
    return allPrice;
}
bool Shopper::hasMoney()
{
    if (productsPrice() > cash)
    {
        return false;
    }
    return true;
}

void Shopper::cashIn()
{
    if (hasMoney())
    {
        for (int i = 0; shoppingList[i].getPrice(); i++)
        {
            cash -= shoppingList[i].getPrice();
        }
    }
}

void Shopper::setProducts(Product* products)
{
    delete[] shoppingList;
    shoppingList = new Product[numberOfProducts];
    for(int i=0; i<numberOfProducts; i++)
    {
        shoppingList[i] = products[i];
    }
}

Product* Shopper::getProducts() const
//тази функция не ти е нужна, защото продктите, които си взел не искаш да ти ги вземат
//по този начин ти правиш копие на продуктите и връщаш копието
//когато функцията ти върне указател, зад който се крие динамично заделена памет
//човекът, който ще използва тази функция, трябва да се погрижи за да я изтрие, което не е добре
//друг начин, е да върнеш и самия указател, но и това не е добре
//трети и според мен най-приемлив начин е да подадеш на функцията ти 2 параметъра
//указател към Product и една int променлива, в която да запазиш размера
//правиш функцията ти да е void и работиш с параметрите й
//в main после се грижиш да си изтриеш паметта
//третото пак не е добре, но в C++ не знам по-добър начин
{
    Product* newProducts = new Product[numberOfProducts];
    for(int i=0; i<numberOfProducts; i++)
    {
        newProducts[i] = shoppingList[i];
    }
    return newProducts;
}

Product* Shopper::addProduct(/*const Product&*/Product newProduct)
//когато добавяш елемент ти трябва да го добавиш в текущия ти масив от обекти
//т.е. функцията най-добре да е void и правиш копие на старите продукти
//изтриваш старите, т.е. delete [] shoppingList;
//после заделяш необходимата памет за shoppingList и прекопираш нещата от newList(копието)
//после изтриваш копието и си готов :)
{
    Product* newList = new Product[numberOfProducts + 1];
    for(int i=0; i<numberOfProducts; i++)
    {
        newList[i] = this->shoppingList[i];//можеш да минеш и без this->
    }
    newList[numberOfProducts+1] = newProduct;
    numberOfProducts++;
    delete[] shoppingList;
    return newList;
}

Product* Shopper::removeProduct(char* prName)
//почти същото като в горната ситуация
{
    Product* newList = new Product[numberOfProducts -1];
    for(int i=0; i<numberOfProducts; i++)
    {
        if(strcmp(this->shoppingList[i].getName(),prName)!=0)
        {
            newList[i] = this->shoppingList[i];
        }
        else
        {
            i++;
        }
    }
    numberOfProducts--;
    delete[] this->shoppingList;
    return newList;
}

//end Shopper

int main()
{
    int productsN;
    double maxWeight, money;
    Label lab1;
    Expiration exp1;
    cout<<"Enter number of products: ";
    cin>>productsN;
    cout<<"How much can you carry: ";
    cin>>maxWeight;
    cout<<"How much money do you have: ";
    cin>>money;

    Product* pr1 = new Product[productsN];
    for(int i=0; i<productsN; i++)
    {
        char prName[50];
        char labC[50];
        int d, m, y, labB;
        double weight, price;
        cout<<"Enter product name: ";
        cin>>prName;
        cout<<"Enter Expiration (d m y): ";
        cin>>d>>m>>y;
        Expiration expir(d,m,y);
        cout<<"Enter label content: ";
        cin>>labC;
        cout<<"Enter barcode: ";
        cin>>labB;
        Label lab(labC,labB);
        cout<<"Enter weight: ";
        cin>>weight;
        cout<<"Enter price: ";
        cin>>price;
        Product pr(prName,weight,price,expir,lab);
        pr1[i] = pr;
    }
    Shopper guy = Shopper(money,pr1,productsN);
    cout<<"Cost: "<<guy.productsPrice()<<endl;
    cout<<"Weight: "<<guy.productsWeight()<<endl;

    if(maxWeight < guy.productsWeight())
    {
    	cout<<"You can't carry this much weight!"<<endl;
    }
    if(money < guy.productsPrice())
    {
        cout<<"You don't have enough money!"<<endl;
    }
    else
    {
        if(money - guy.productsPrice() < 2)
        {
            cout<<"You don't have money to get home!"<<endl;
        }
        else
        {
            cout<<"You may now eat!"<<endl;
        }
    }
    delete[] pr1;
    return 0;
}
