/*
 * main.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: Dimitar Panayotov
 */

#include <iostream>

using namespace std;
const int NUMBER_OF_PLAYERS = 2;

class Player {
private:
	char name[51];
	int number;
	double coefficient;
public:
	//no need to make a validation for the name
	void setName(char *nameP) {
		for (int i = 0; nameP[i]; i++) {
			name[i] = nameP[i];
		}
	}

	bool setNumber(int num) {
		if (num >= 1 && num <= 99) {
			number = num;
			return true;
		} else {
			cout << "Player number must be between 1 and 99!" << endl;
			return false;
		}
	}

	bool setCoefficient(double coef) {
		if (coef >= 1.0 && coef <= 10.0) {
			coefficient = coef;
			return true;
		} else {
			cout << "Player coefficient must be between 1 and 10!" << endl;
			return false;
		}
	}

	char* getName() {
		return name;
	}

	int getNumber() {
		return number;
	}

	double getCoefficient() {
		return coefficient;
	}
};

class Team {
private:
	Player player[12];
	int wins, losses;
public:
	typedef bool (*SortPlayers)(Player*, Player*);

	void setWins(int win) {
		wins = win;
	}

	int getWins() {
		return wins;
	}

	void setLosses(int loss) {
		losses = loss;
	}

	int getLosss() {
		return losses;
	}

	bool readPlayers(int i) {
		char pName[51];
		int num;
		double coef;
		cout << "Enter player's name: ";
		cin>>pName;
		player[i].setName(pName);
		cout << "Enter player's number: ";
		cin >> num;
		if(!player[i].setNumber(num))
		{
			return false;
		}
		cout << "Enter player's coefficient: ";
		cin >> coef;
		if(!player[i].setCoefficient(coef))
		{
			return false;
		}
		cout << "######################" << endl;
		return true;
	}

	void printPlayers(int i)
	{
		cout<<"Player name: "<<player[i].getName()<<endl;
		cout<<"Player number: "<<player[i].getNumber()<<endl;
		cout<<"Player coefficient: "<<player[i].getCoefficient()<<endl;
		cout << "######################" << endl;
	}

	void upCoefficient(int upNumber) {
		for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
			if (player[i].getNumber() == upNumber
					&& player[i].getCoefficient() != 10) {
				player[i].setCoefficient(player[i].getCoefficient() + 1);
			}
		}
	}

	double teamCoefficient() {
		double sum;
		for (int i = 0; i < NUMBER_OF_PLAYERS; i++) {
			sum += player[i].getCoefficient();
		}
		return sum / NUMBER_OF_PLAYERS;
	}

	void sort(Player* p[], SortPlayers playerSort) {
		Player* swap;
		for (int i = 0; i < NUMBER_OF_PLAYERS - 1; i++) {
			int k = i;
			for (int j = i + 1; j < NUMBER_OF_PLAYERS; j++) {
				if (playerSort(p[j], p[k])) {
					k = j;
				}
			}
			if (k != i) {
				swap = p[i];
				p[i] = p[k];
				p[k] = swap;
			}
		}
	}

	bool sortByNumber(Player* p1, Player* p2) {
		return p1->getNumber() < p2->getNumber();
	}

	bool sortByCoefficient(Player* p1, Player* p2) {
		return p1->getCoefficient() < p2->getCoefficient();
	}
};

void game(Team* t1, Team* t2) {
	for (int i = 0; i < NUMBER_OF_PLAYERS - 1; i++) {
		if (t1->teamCoefficient() > t2->teamCoefficient()) {
			cout << "Team one is the winner!";
			t1->setWins(t1->getWins() + 1);
			t2->setLosses(t2->getLosss() + 1);
		} else {
			cout << "Team two is the winner!";
			t1->setLosses(t1->getLosss() + 1);
			t2->setWins(t2->getWins() + 1);
		}
	}
}

int main() {
	const int NUMBER_OF_TEAMS = 2;
	Team teams[NUMBER_OF_TEAMS];
	Player player[NUMBER_OF_PLAYERS];

	//input information about players
	for(int i=0; i<NUMBER_OF_TEAMS; i++)
	{
		cout<<"Enter players for Team "<<i+1<<endl;
		for(int j=0; j<NUMBER_OF_PLAYERS; j++)
		{
			if(!teams[i].readPlayers(j))
			{
				cout<<"Invalid information input!";
				return 0;
			}
		}
	}

	//print player's information
	for(int i=0; i<NUMBER_OF_TEAMS; i++)
	{
		cout<<"Players from Team "<<i+1<<endl;
		for(int j=0; j<NUMBER_OF_PLAYERS; j++)
		{
			teams[i].printPlayers(j);
		}
	}

	return 0;
}

