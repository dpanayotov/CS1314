/*
 * main.cpp
 *
 *  Created on: Mar 26, 2014
 *      Author: Dimitar
 */


#include <MoneyStream.h>
#include <Player.h>
#include <iostream>
#include <iomanip>

//if a cell's value is 0 then it has been visited already
double choice(int index, MoneyStream& str)
{
	return str.getValue(index);
}

int main()
{
	MoneyStream newStream(5);
	Player player1("player1"), player2("player2");
	double playerChoice;
	int i=0, cell;
	while(newStream.hasAvailable())
	{
		i++;
		if(i%2!=0)
		{
			cout<<"Player 1, enter cell: ";
			cin>>cell;
			playerChoice = choice(cell,newStream);
			player1.addScore(playerChoice);
		}
		else
		{
			cout<<"Player 2, enter cell: ";
			cin>>cell;
			playerChoice = choice(cell,newStream);
			player2.addScore(playerChoice);
		}
	}

	if(player1.getScore() > player2.getScore())
	{
		cout<<"Player One Wins!"<<endl;
	}
	else
	{
		cout<<"Player Two Wins"<<endl;
	}

	cout<<player1.getInfo()<<endl<<player2.getInfo()<<endl;
	return 0;
}

