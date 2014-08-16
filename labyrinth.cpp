
//#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int globalLevel = 1; //start level
int playerCurrentPosition[2] = {0,0}; // 1st element - row, 2nd element column
bool completed = false;

char level1[6][6]=
{
	{'@','#',' ',' ',' ',' '},
	{' ','#','>','#',' ','#'},
	{' ','#','#','#',' ','#'},
	{' ','#',' ',' ',' ',' '},
	{' ',' ',' ','#','#',' '},
	{' ','#','#','#',' ',' '}
};

char level2[6][6]=
{
	{'#',' ','<',' ','#',' '},
	{'#','#',' ',' ','#',' '},
	{' ','#',' ',' ',' ',' '},
	{'#',' ',' ','#',' ','#'},
	{' ',' ','#','#',' ',' '},
	{' ','#',' ',' ','#','>'}
};

char level3[6][6]=
{
	{'#',' ',' ',' ','#','#'},
	{'#',' ','#',' ',' ','#'},
	{' ',' ',' ','#','$','#'},
	{' ','#',' ','#','#','#'},
	{' ',' ','#','<',' ',' '},
	{' ',' ',' ',' ',' ','#'}
};

bool inRange(int row, int col)
{
	bool rowInRange = row>=0 && row < 6;
	bool colInRange = col>=0 && col < 6;
	return rowInRange && colInRange;
}

void gameOver()
{
	system("CLS");
	cout<<"You have completed the task!\nPress any key to continue..."<<endl;
	_getch();
}

void printLabyrinth(char keyPressed, char (*level)[6], int addRow, int addColumn)
{
	if(inRange(playerCurrentPosition[0]+addRow,playerCurrentPosition[1]+addColumn))
	{
		if(level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn] != '#')
		{
			system("CLS"); //clear screen to keep it simple
			cout<<"Press Q to quit"<<endl;
			//if nextPosition == '>' go to next level and set level +=1
			if(level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn] == '>')
			{
				level[playerCurrentPosition[0]][playerCurrentPosition[1]]=' '; //clear position in current level
				globalLevel+=1;
				if(globalLevel == 2)
				{
					//set fixed spawn position for player and call function
					playerCurrentPosition[0] = 1;
					playerCurrentPosition[1] = 2;
					printLabyrinth(keyPressed, level2, 0, 0);
				}
				else if(globalLevel == 3)
				{
					playerCurrentPosition[0] = 5;
					playerCurrentPosition[1] = 2;
					printLabyrinth(keyPressed, level3, 0, 0);
				}
				return;
			}
			//if nextPosition == '<' go to previous level and set level-=1
			else if(level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn] == '<')
			{
				level[playerCurrentPosition[0]][playerCurrentPosition[1]]=' '; //clear position in current level
				globalLevel-=1;
				if(globalLevel == 1)
				{
					playerCurrentPosition[0] = 0;
					playerCurrentPosition[1] = 2;
					printLabyrinth(keyPressed, level1, 0, 0);
				}
				else if(globalLevel == 2)
				{
					playerCurrentPosition[0] = 1;
					playerCurrentPosition[1] = 2;
					printLabyrinth(keyPressed, level2, 0, 0);
				}
				else if(globalLevel == 3)
				{
					playerCurrentPosition[0] = 5;
					playerCurrentPosition[1] = 2;
					printLabyrinth(keyPressed, level3, 0, 0);
				}
				return;
			}
			//if nextPosition == '$' end
			else if(level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn] == '$')
			{
				completed=true;
			}
			//if nextPosition == ' ' clear current position and write @ at it
			else if(level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn] == ' ')
			{
				level[playerCurrentPosition[0]][playerCurrentPosition[1]]=' ';
				level[playerCurrentPosition[0]+addRow][playerCurrentPosition[1]+addColumn]='@';
			}
			//set player at next position
			playerCurrentPosition[0]+=addRow;
			playerCurrentPosition[1]+=addColumn;
			//print the labyrinth
			for(int i=0; i<6; i++)
			{
				for(int j=0; j<6; j++)
				{
					cout<<level[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"Out of bounds!\n";
	}
}


int main()
{
	cout<<"Press Q to quit"<<endl;
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			cout<<level1[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	while(!completed)
	{
		if(kbhit()) //if key is pressed
		{
			char keyPressed = _getch();
			if(keyPressed=='q')
			{
				return 0;
			}
			if(keyPressed=='a')
				{
					//print player at same row, -1 column
					if(globalLevel==1)
					{
						printLabyrinth(keyPressed,level1, 0, -1);
					}
					else if(globalLevel==2)
					{
						printLabyrinth(keyPressed,level2, 0, -1);
					}
					else if(globalLevel==3)
					{
						printLabyrinth(keyPressed,level3, 0, -1);
					}
				}
				else if(keyPressed == 'd')
				{
					//print player at same row, +1 column
					if(globalLevel==1)
					{
						printLabyrinth(keyPressed,level1, 0, 1);
					}
					else if(globalLevel==2)
					{
						printLabyrinth(keyPressed,level2, 0, 1);
					}
					else if(globalLevel==3)
					{
						printLabyrinth(keyPressed,level3, 0, 1);
					}

				}
				else if(keyPressed == 's')
				{
					//print player at +1 row, same column
					if(globalLevel==1)
					{
						printLabyrinth(keyPressed,level1, 1, 0);
					}
					else if(globalLevel==2)
					{
						printLabyrinth(keyPressed,level2, 1, 0);
					}
					else if(globalLevel==3)
					{
						printLabyrinth(keyPressed,level3, 1, 0);
					}

				}
				else if(keyPressed == 'w')
				{
					//print player at -1 row, same column
					if(globalLevel==1)
					{
						printLabyrinth(keyPressed,level1, -1, 0);
					}
					else if(globalLevel==2)
					{
						printLabyrinth(keyPressed,level2, -1, 0);
					}
					else if(globalLevel==3)
					{
						printLabyrinth(keyPressed,level3, -1, 0);
					}
			}
		}
		if(completed)
			gameOver();
	}
	return 0;
}
