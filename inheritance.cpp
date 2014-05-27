#include <iostream>
#include <cstring>

using namespace std;

class Robot
{
    char* program;
public:
    Robot()
    {
        program = new char[1];
        program[0] = '\0';
    }

    Robot(char* prog)
    {
        program = new char[strlen(prog)+1];
        strcpy(program, prog);
    }

    void changeProgram()
    {
        cout<<"Enter program: ";
        delete[] program;
        char prog[50];
        cin.getline(prog, 50);
        program = new char[strlen(prog)+1];
        strcpy(program, prog);
    }

    ~Robot()
    {
        delete[] program;
    }

};

class Terminator : public Robot
{
    char** peopleKilled;
    int peopleKilledCnt;
public:
    Terminator() : Robot()
    {
        peopleKilledCnt = 1;
        peopleKilled = new char*[peopleKilledCnt];
        for(int i=0; i<peopleKilledCnt; i++)
        {
            peopleKilled[i] = new char[50];
            strcpy(peopleKilled[i], "misho");
        }
    }

    void del()
    {

        for(int i=0; i<peopleKilledCnt; i++)
        {
            delete[] peopleKilled[i];
        }
        delete[] peopleKilled;
    }

    Terminator(int cnt, char** ppl, char* pr) : Robot(pr)
    {
        char killed[10][50];
        for(int i=0; i<strlen(*ppl); i++)
        {
            strcpy(killed[i], ppl[i]);
        }
        peopleKilledCnt = cnt;
        peopleKilled = new char*[peopleKilledCnt];
        for(int i=0; i<peopleKilledCnt; i++)
        {
            peopleKilled[i] = new char[strlen(killed[i])+1];
        }
    }

    void killPerson()
    {
        char buffer[100];
        cout<<"Who would you like me to kill, master? ";
        cin.getline(buffer, 100);
        char* name = new char[strlen(buffer)+1];
        strcpy(name, buffer);

        int tempCnt = peopleKilledCnt+1;
        char** killPpl = new char*[tempCnt];
        for(int i=0; i<tempCnt; i++)
        {
            killPpl[i] = new char[strlen(peopleKilled[i])+1];
            strcpy(killPpl[i], peopleKilled[i]);
        }

        strcpy(killPpl[tempCnt-1], name);

        del();

        peopleKilledCnt = tempCnt;

        peopleKilled = new char*[peopleKilledCnt];
        for(int i=0; i<peopleKilledCnt; i++)
        {
            peopleKilled[i] = new char[strlen(killPpl[i])+1];
            strcpy(peopleKilled[i], killPpl[i]);
        }
        delete[] name;
    }

    void print()
    {
        for(int i=0; i<peopleKilledCnt; i++)
        {
            cout<<peopleKilled[i]<<' ';
        }
    }

    ~Terminator()
    {
        del();
    }
};

class KitchenRobot : public Robot
{
    char* brand;
public :
    KitchenRobot() : Robot()
    {
        brand = new char[1];
        brand[0] = '\0';
    }

    KitchenRobot(char* br, char* pr) : Robot(pr)
    {
        brand = new char[strlen(br)+1];
        strcpy(brand, br);
    }

    ~KitchenRobot()
    {
        delete[] brand;
    }
};

class SmartToster : public KitchenRobot
{
    int toastsMade;
public:
    SmartToster() : KitchenRobot()
    {
        toastsMade = 1;
    }

    SmartToster(int cnt, char* br, char* pr) : KitchenRobot (br, pr)
    {
        toastsMade = cnt;
    }

    void makeToast()
    {
        toastsMade++;
    }
};

class SmartOven : public KitchenRobot
{
    char** recipes;
    int recipeCnt;
public:
    SmartOven() : KitchenRobot()
    {
        recipeCnt = 3;
        recipes = new char*[recipeCnt];
        for(int i=0; i<recipeCnt; i++)
        {
            recipes[i] = new char[20];
            strcpy(recipes[i], "aassdqwertyuiopkhgf");
        }
    }

    SmartOven(int cnt, char** rec, char* br, char* pr) : KitchenRobot(br, pr)
    {
        recipeCnt = cnt;
        recipes = new char*[recipeCnt];
        {
            for(int i=0; i<recipeCnt; i++)
            {
                recipes[i] = new char[strlen(*rec) + 1];
                strcpy(recipes[i], rec[i]);
            }
        }
    }



    ~SmartOven()
    {
        for(int i=0; i<recipeCnt; i++)
        {
            delete[] recipes[i];
        }
        delete[] recipes;
    }

    bool cook(char** meal, int cnt)
    {
        bool is = false;
        for(int i=0; i<recipeCnt; i++)
        {
           for(int j=0; j<cnt; j++)
           {
               if(strcmp(meal[j], recipes[i])!=0)
               {
                   return false;
               }
           }
        }
        return true;
    }
};

int main()
{
    Robot r;
    r.changeProgram();
    Terminator t;
    t.killPerson();
    t.print();
    char** asd = new char*[3];
    for(int i=0; i<3; i++)
    {
        asd[i] = new char[20];
        strcpy(asd[i], "aassdqwertyuiopkhgf");
    }

    SmartOven so;
    cout<<so.cook(asd, 3);
    delete[] asd;
    return 0;
}

