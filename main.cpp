#include <iostream>
#include "windows.h"
#include <MMsystem.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include "time.h"
#include <ctime>
using namespace std;
string * MenuItems();
void gotoxy(int,int);
void MenuFun1();
void MenuFun2();
void MenuFun3();
void ExitOption();
void welcomeScreen();//function declared to display the welcome screen
void gameOver(); //function declared to display the gameover screen
void levelUp();
void cursorStatus();
void playEasy(); //function declared to play the easy level
void playMedium(); //function declared to play the medium level
void printVictoryScreen(); //function declared to display the victory screen
void playDifficultLevel(); //function declared to play the difficult level
 string playersName;

char mapEasy[25][25]=
{
	"!!!!!!!!!!!!!!!!!!!!",
	"!                  !",
	"!                  !",
	"!   @ @ @ @ @ @    !",
	"!    @ @ @ @ @     !",
	"!     @ @ @ @      !",
	"!      @ @ @       !",
	"!       @ @        !",
	"!        @         !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!                  !",
	"!        X         !",
	"!!!!!!!!!!!!!!!!!!!!"

};
char mapMedium[25][50]=
{
	"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!",
    "!                @                  !",
    "!               @ @                 !",
    "!              @ @ @                !",
    "!             @ @ @ @               !",
    "!            @ @ @ @ @              !",
    "!  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  !",
    "!       @    @ @ @ @ @      @       !",
    "!     @ @ @   @ @ @ @     @ @ @     !",
    "!       @      @ @ @        @       !",
    "!               @ @                 !",
    "!                @                  !",
    "!                                   !",
    "!                                   !",
    "!                                   !",
    "!    ###      ###    ###      ###   !",
    "!    ###      ###    ###      ###   !",
    "!                                   !",
    "!                X                  !",
    "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"

};


char area [22][40] =
{
    "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!",
    "!                 @                 !",
    "!                @ @                !",
    "!      @        @ @ @        @      !",
    "!    @ @ @     @ @ @ @     @ @ @    !",
    "!      @      @ @ @ @ @      @      !",
    "!  @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @  !",
    "!   @ @ @ @   @ @ @ @ @   @ @ @ @   !",
    "!    @ @ @     @ @ @ @     @ @ @    !",
    "!     @ @       @ @ @       @ @     !",
    "!      @         @ @         @      !",
    "!                 @                 !",
    "!                 @                 !",
    "!                                   !",
    "!                                   !",
    "!                                   !",
    "!                                   !",
    "!                                   !",
    "!                X                  !",
    "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"

};
bool gameRunning = true;
int randomNumber;
bool endGame =false;
bool endGame2 =false;
int gameSpeed=0; //Speed that the player can move
int randomNum;
int maximumLives=5; //The maximum lives the player can have
int yourLife=maximumLives; //maximumlives is assigned to player's health
int yourScore=0; //score of the player

int main() {

	welcomeScreen();
	cursorStatus();
	gameOver;
	return 0;
}

void welcomeScreen()
{ PlaySound(TEXT("C:\\Users\\User\\Desktop\\GALAXIAN\\sound.wav"),NULL,SND_SYNC); //plays a sound clip in the welcome screen
//before compiling the game change path of the sound file
	ifstream f1("welcome.txt"); //displays an image at the welcome screen

    if (f1.is_open())
        cout << f1.rdbuf();


    cout<<"\n\n\t\t\tWelcome Soldier!   \n\n";
    cout<<"\t\tYour World Depends on You.......   \n\n ";
    cout<<"\n\n\t\t\t  Good Luck!   \n\n";
    cout<<("\n\t\t Press Any key to continue........");
	getch();
	system("cls");
}

void gameOver()
{
	system("color 0c");
	ifstream f2("gameover.txt"); //displays an image at the gameover screen
    if (f2.is_open())
    cout << f2.rdbuf();
   PlaySound(TEXT("C:\\Users\\User\\Desktop\\GALAXIAN\\gameOver.wav"),NULL,SND_SYNC); //plays a sound clip in the gameover screen
//before compiling the game change path of the sound file
}

void levelUp()
{
   system ("color 06");
   ifstream f4("LevelUp.txt"); //displays an image at the levelup screen
   if (f4.is_open())
   cout << f4.rdbuf();
   PlaySound(TEXT("C:\\Users\\User\\Desktop\\GALAXIAN\\tada.wav"),NULL,SND_SYNC); //plays a sound clip in the levelup screen)
   //before compiling the game change path of the sound file
}

void cursorStatus()
{
	typedef void (*TMenuOption)(); // typedef for defining a 'pointer to function' type.

	int ItemCount=4; // This variable holds the number of menu items.
	int MenuChoice=1; // This variable holds the position of the cursor.
	char key; //for entering the key (up arrow,down arrow,etc...);

	TMenuOption *MenuOption=new TMenuOption[ItemCount];//array of pointers to functions (dynamic).
	MenuOption[0]=MenuFun1; //filling the array with the functions.
	MenuOption[1]=MenuFun2;
	MenuOption[2]=MenuFun3;
	MenuOption[3]=ExitOption;


	while(1) //infinite loop. (this loop will not break that's why we need an exit function).
	{
		for (int i=0;i<ItemCount;i++) // Draw the menu.
		{
			gotoxy(25,7+i);
			MenuChoice==i+1 ? cout<<" -> " : cout<<"    "; // if (i+1) == the cursor then
			                                               //    print ' -> ' else print '    '.
			                                               //    by the way i call '->' the cursor
			cout<<MenuItems()[i]<<endl; // print the name of the item.
		} // finish the drawing.

		key=getch(); //get the key.


		switch (key) //check the entered key.
		{
		case '\r': // if the entered key is 'Enter'.
			try
			{
				(*MenuOption[MenuChoice-1])(); // call the function of the index 'cursor-1' in
				                               //     the 'pointer to function' array.
			}
			catch(...)
			{}  // we have to use try and catch coz if we did'nt fill that index with a function.
				//                     a runtime error will appear.

			break;

		case 'P': // if the entered key is the 'up arrow' notice that its equal to 'P' (capital)
			MenuChoice++; //then we will increment the cursor by one.
			if (MenuChoice>ItemCount) // if the cursor value is more than the items count.
				MenuChoice=1;         //    then it will return back to the first item.
			break;

		case 'H': // same but with 'down arrow' and decrement the cursor.
			MenuChoice--;
			if (MenuChoice<1)
				MenuChoice=ItemCount;
			break;

		case 27: // 27 is the asscii to the escape key (Esc)
			try {(*MenuOption[ItemCount-1])();} // useually when the 'Esc' key is pressed the last
			                                    //     item will be called (executed). but you can
			                                    //     change it to whatever you want.
			catch(...){}
			break;
		default:// any another key.
			if (key>='1' && key <=char(ItemCount+'0'))//check if the pressed key is in the range
				                                      //    of (1,2,3,...,#of items) [all char(s)]
			{
				try {(*MenuOption[int(key)-'0'-1])();} //call the function of the pressed number.
				     //  you can make the cursor move to that item instead of calling (executing)
					 //  it by replacing all the code between 'if (bla){' and '}' with this
				     //  statement MenuChooice=int(key)-'0'
				catch(...){}
			}
		}
	}

	delete MenuOption;
}


string * MenuItems() // this function returns a pointer to a string.
{
	string *item=new string[4];
	item[0]="PLAY";
	item[1]="INSTRUCTIONS";
	item[2]="ABOUT";
	item[3]="EXIT.";


	return item;
}
//-----------------------------------------------------------------------------------------------
void gotoxy(int xpos, int ypos) //to change the console output position
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}
//-----------------------------------------------------------------------------------------------
void MenuFun1()
{

	system("cls"); //clear the screen.
	gotoxy(25,10);
	cout<<"Enter Player's Name : ";
	getline(cin,playersName);
	playEasy();


}
//-----------------------------------------------------------------------------------------------
void MenuFun2()
{
	system("cls");
	ifstream f1("game2.txt");
    if (f1.is_open())
        cout << f1.rdbuf();
	getch();
	system("cls");

}
//-----------------------------------------------------------------------------------------------
void MenuFun3()
{
	system("cls");
	gotoxy(25,10);
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<" \t\t\t\t\t\t\t\t\t :ABOUT: \t\t\t\t\t " <<endl<<endl;;
	cout<<" \t\t\t <*>Galaxian is a fixed shooter arcade game which Controlling a small starfighter. The palyer is tasked with wiping out the Galaxian "<<endl;
	cout<<" \t\t\t    who plot to take over Earth and enslave mankind."<<endl<<endl;
	cout<<" \t\t\t <*>Space Ship is Represented by 'X' and the aliens are Represented by '@'."<<endl<<endl;
	cout<<" \t\t\t <*>Space Ship shots Represented by '^' and the bombs deployed by aliens are Represented by '*' Symbols."<<endl<<endl;
	cout<<" \t\t\t <*>Space Ship is controlled by arrow keys.\n\n";
	cout<<" \t\t\t <*>Gamer life can be increased by collecting 'O's.\n\n";
	cout<<" \t\t\t <*>The Game was Developed by,\n";
	cout<<" \t\t\t\t Hansi Karunarathna- 18/ENG/050"<<endl;
	cout<<" \t\t\t\t Isora Dolage      - 18/ENG/014"<<endl;
	cout<<" \t\t\t\t Kavish Rajakaruna - 18/ENG/085"<<endl;
	cout<<" \t\t\t\t Rashmika Silva    - 18/ENG/105"<<endl;
	cout<<"\n\n\n\n\n";
	getch();
	system("cls");

}
//-----------
void ExitOption()
{
	system("cls");
    exit(0);
}
//-----------------------------------------------------------------------------------------------

void playEasy()
{
	system("cls");
	system("color 0b");
	for(int x=0;x<25;x++)
		{
			cout<<mapEasy[x]<<endl; //Prints the map before starting to play the game
		}

	cout<<"\nGood Luck "<<playersName<<endl;
	cout<<"GAME WILL START IN..."<<endl;
		for(int i=3;i>=1;i--) //countdown to begin the game
		{

			cout<<i<<"....";
			Sleep(1500); //wait till the game starts
		}

	while(endGame==false)
	{
		srand(time(0));
		system("cls");
		for(int x=0;x<25;x++)
		{
			cout<<mapEasy[x]<<endl; //Prints the map to play the game
		}
		cout<<playersName<<" is playing!!!\n\n";
		cout<<"Health "<<yourLife<<"/"<<maximumLives<<endl;//Update the lives of the player
		cout<<"Score: "<<yourScore<<endl;//Updates the score of the Player
		for (int y=0;y<25;y++)
		{
			for(int x=0;x<25;x++)
			{
				switch (mapEasy[y][x])
				{

					case 'X':
						{
							if (GetAsyncKeyState(VK_LEFT) !=0) //moves the player to the left
							{
								int newX =x-1;
								switch (mapEasy[y][newX])
								{
									system("color 0y");
									case ' ':
								    mapEasy[y][x]=' '; //replace the old position of the player
									x--;
									mapEasy[y][newX]='X'; //new position of the player
									mapEasy[y-1][newX] = '^'; //auto generating bullets
		    						break;

								}
							}
							if (GetAsyncKeyState(VK_RIGHT) !=0) //moves the player to the right
							{
								int newX=x+1;
								switch (mapEasy[y][newX])
								{
									case ' ':
									mapEasy[y][x]=' ';  //replace the old position of the player
									x++;
									mapEasy[y][newX]='X'; //new position of the player
									mapEasy[y-1][newX] = '^'; //auto generating bullets
									break;
								}
							}

							break;
						}
						case '^':
							{

								mapEasy[y][x]=' ';
								y--;

								if (mapEasy[y][x] !='!' && mapEasy[y][x] !='@' )
								{
									mapEasy[y][x]='^';
								}
								else if (mapEasy[y][x]=='@')
								{
									mapEasy[y][x]=' ';
									yourScore+=50; //if a bullet hits the player increase the score of the player by 50
								}
								break;
							}
						case '@':
						    {
						    	randomNum=rand() %20+1; //Alien bombs landing in random places by aliens
						    	if (randomNum==1)
						    	{
						    		y++;
						    		mapEasy[y][x]='*'; //symbol to represent the alien bombs
								}

								break;
							}
						case '*':
				    		{
				    			mapEasy[y][x]=' ';
				    			y++;
				    			if (mapEasy[y][x]!='!' && mapEasy[y][x] != 'X' && mapEasy[y][x]!='@') //if the bomb hits the board nothing is deleted
				    			{
				    				mapEasy[y][x]='*';
								}
								else if (mapEasy[y][x]=='X')
								{
									Beep(500,500);
									yourLife-=1; //reduce a life of the player when an alien bomb hits into the player
									if (yourLife<=0) //when all the 3 lives are over player lose the game
	                            	{
		                            	endGame=true;
		                            	system("cls");
		                            	gameOver();
		                            	cout<<"\n\nYour Score: "<<yourScore<<endl;
		                            	system("pause");
		                            	exit(0);
	                            	}

								}

				    			break;
					    	}

				}
				int count=0; //algorithm to verify the player has won the easy level
						for(int row=3;row<=8;row++)
						{
							for (int col=1;col<=18;col++)
							{
								if (mapEasy[row][col]==' ')
								count++; //checks whether the game area is free of all the enemies and count is incremented by 1.
							}
						}
						if (count==108)
						{
							endGame=true; //if the count is equal to 108 easy level ends
							system("cls");
							levelUp();
							gotoxy(25,10); //moves the cout text to (25,10) coordinate
							cout<<"Congratulations You have Won the Easy Level!!!"<<endl;
							gotoxy(25,12);
							cout<<"Your Score was: "<<yourScore;
							gotoxy(25,14);
							cout<<"You saved the planet Soldier!!!"<<endl; //displays a message including the score
							gotoxy(25,16);
							system("pause");
							system("cls");
							gotoxy(25,10);
							cout<<"Welcome to LVL 2!......."<<endl;
							Sleep(1000); //Delays the screen
							gotoxy(25,12);
							system("pause");
							playMedium(); //calling the function declared to medium level
							break;
						}

			}
		}


	}


}

void playMedium()
{
	system("cls");
	system("color 0e"); //setting a color to the content
	for(int x=0;x<25;x++)
		{
			cout<<mapMedium[x]<<endl;
		}
    cout<<"\nGood Luck "<<playersName<<endl;
	cout<<"GAME WILL START IN..."<<endl;
		for(int i=3;i>=1;i--)
		{

			cout<<i<<"....";
			Sleep(1500);
		}


	while(endGame2==false)
	{
		srand(time(0));
		system("cls");
		for(int x=0;x<25;x++)
		{
			cout<<mapMedium[x]<<endl;
		}
		cout<<playersName<<" is playing!!!\n\n";
		cout<<"Health "<<yourLife<<"/"<<maximumLives<<endl;
		cout<<"Score: "<<yourScore<<endl;
		for (int y=0;y<25;y++)
		{
			for(int x=0;x<50;x++)
			{
				switch (mapMedium[y][x])
				{

					case 'X':
						{
							if (GetAsyncKeyState(VK_LEFT) !=0)
							{
								int newX =x-1;
								switch (mapMedium[y][newX])
								{
									case ' ':
								    mapMedium[y][x]=' ';
									x--;
									mapMedium[y][newX]='X';
									mapMedium[y-1][newX]='^';
		    						break;

								}
							}
							if (GetAsyncKeyState(VK_RIGHT) !=0)
							{
								int newX=x+1;
								switch (mapMedium[y][newX])
								{
									case ' ':
									mapMedium[y][x]=' ';
									x++;
									mapMedium[y][newX]='X';
									mapMedium[y-1][newX]='^';
									break;
								}
							}


							break;

						}

						case '^':
							{

								mapMedium[y][x]=' ';
								y--;

								if (mapMedium[y][x] !='!' && mapMedium[y][x] !='@')
								{
									mapMedium[y][x]='^';
								}
								else if (mapMedium[y][x]=='@' )
								{
									mapMedium[y][x]=' ';
									yourScore+=50;
								}
								break;
							}
						case '@':
						    {
						    	randomNum=rand() %20+1; //Alien bombs landing in random places
						    	if (randomNum==1 && mapMedium[y+1][x] != '@')
						    	{
						    		y++;
						    		mapMedium[y][x]='*';
								}

								break;
							}



						case '*':
				    		{
				    			mapMedium[y][x]=' ';
				    			y++;
				    			if (mapMedium[y][x]!='!' && mapMedium[y][x] != 'X' && mapMedium[y][x]!='@' && mapMedium[y][x]!='#' )
				    			{
				    				mapMedium[y][x]='*';
								}
								else if (mapMedium[y][x]=='X')
								{
								    Beep(500,500);
									yourLife-=1;
									if (yourLife<=0) //when all the 5 lives are over player loses the game
	                            	{
		                            	endGame=true;
		                            	system("cls");
		                            	gameOver();
		                            	cout<<"\n\nYour Score: "<<yourScore<<endl;
		                            	system("pause");
		                            	exit(0);
	                            	}
								}
				    			break;

					    	}
				}
				int count=0;
						for(int row=1;row<=16;row++)
						{
							for (int col=1;col<=35;col++)
							{
								if (mapMedium[row][col]==' ')
								count++;
							}
						}
						if (count==560)
						{
							endGame2=true;
							system("cls");
							levelUp();
							gotoxy(25,10);
							cout<<"Congratulations You have Won the Medium Level!!!"<<endl;
							gotoxy(25,12);
							cout<<"Your Score was: "<<yourScore;
							gotoxy(25,14);
							cout<<"You Saved the planet Soldier!!!"<<endl; //displays player's score after winning the level
                            gotoxy(25,16);
                            system("pause");
							system("cls");
							gotoxy(25,10);
							cout<<"Welcome to LVL 3!......."<<endl;
							Sleep(1000);
							gotoxy(25,12);
							system("pause");


							 playDifficultLevel(); //calling the function declared to hard level

							break;
						}
			}
		}
		if (yourLife<=0)
		{
			endGame2=true; //when all the lives are over game is over
		}

	}
}

//-------------
void printVictoryScreen() //Function to display the victory screen
{
  system("color 06");
  ifstream f3("victory.txt");
  if (f3.is_open())
    cout << f3.rdbuf();
PlaySound(TEXT("C:\\Users\\User\\Desktop\\GALAXIAN\\victory.wav"),NULL,SND_SYNC);
//before compiling the game change path of the sound file
}
void playDifficultLevel ()
{
system("cls");
system("color 0e");
for (int y=0; y<22; y++)
             {cout << area[y] << endl;}
             cout<<"\nGood Luck "<<playersName<<endl;
             cout<<"GAME WILL START IN..."<<endl;

for(int i=3;i>=1;i--)
{
	cout<<i<<"....";
	Sleep(1500);
		}
while (gameRunning== true)
{system("cls");
srand(time(0));


      for (int y=0; y<22; y++)
             {cout << area[y] << endl;}

              cout<<playersName<<" is playing!!!\n\n";
              cout<<"Health "<<yourLife<<"/"<<maximumLives<<endl;
		      cout<<"Score: "<<yourScore<<endl;
            for (int y = 0 ; y<22;y++)
             {for (int x = 0 ; x< 40 ; x++)
              {
			 int rand1 = rand()%2000;
							if (rand1==79)
                             { int z=rand()%30+2;
                               area[1][z]='O';
                            }
             switch(area[y][x])
                 {case 'X': {if (GetAsyncKeyState(VK_LEFT)!= 0)
                                  {int x_new = x-1;
                                   if(area[y][x_new] == ' ')
                                     {area[y][x] = ' ';
                                     x--;
                                     area[y][x]= 'X';
                                     area[y-1][x] ='^'; //bullets are automatically generated
                                     }
                                   }
                                else if (GetAsyncKeyState(VK_RIGHT)!=0)
                                   {int x_new = x+1;
                                    if(area[y][x_new] == ' ')
                                      {area[y][x] =' ';
                                      x++;
                                      area[y][x]= 'X';
                                      area[y-1][x] ='^';
                                      }
                                   }; break;
                                }
                     case '^': { area[y][x]=' ';
                                 y--;
                                 if (area[y][x]!= '!' && area[y][x]!= '@')
                                 {area[y][x] = '^';}
                                 else if (area[y][x]== '@')
                                    {area[y][x]=' ';
                                    yourScore+=50; //when a bullet hits the enemy player's score is increased by 50
                                    }

                                ; break;
                                }
                    case '@': { randomNumber = rand()%15;
                               if (randomNumber== 1 && area[y+1][x] !='@' )
                                {area[y+1][x] ='*';}
                               if (randomNumber < 5)
                               {if(y%2==0)
                                  {if (area [y][x-1] != '!' && area [y][x-1] !='@' && y<=17)
                                      {
                                       area[y][x]=' ';
                                       area [y][x-1]= '@';
                                      }
                                 else if (area [y][x-1] =='!' || y<=17 )
                                 {area [y][x]=' ';
                                  area [y+1][x+1]='@';
                                 }
                     if ( y==17)
                     {
                       gameRunning= false;
                     }
                                  }
                    else
                    {if (area [y][x+1] != '!' && area [y][x+1] !='@' && y<=17)
                     {
                         area[y][x]=' ';
                         area [y][x+1]= '@';
                     }
                     else if (area [y][x+1] =='!' || y<=17 )
                     {area [y][x]=' ';
                         area[y+1][x-1]='@';
                     }
                     if (y==17)
                     {
                       gameRunning= false;
                       system("cls");
                       gameOver();
                       cout<<"\n\nYour Score: "<<yourScore<<endl;
                       cout<<"Try Again..."<<endl;
                       system("pause>null");
                       exit(0); //once the player lost the hard level game will be exit
                     }
                    }

                    } ;break;}
                 case '*': { area[y][x]=' ';
                                 y++;
                                 if (area[y][x]!= '!' && area[y][x]!= 'X' && area[y][x]!='@' ||area[y][x]== '^' )
                                 {area[y][x] = '*';}
                                 else if (area[y][x]== 'X')
                                    {Beep(500,500);yourLife-=1;}
                                 ;

								 break;
                            }
                case 'O': {area[y][x]=' ';
                                 y++;
                                 if (area[y][x]!= '!' && area[y][x]!= 'X' && area[y][x]!='@' )
                                 {area[y][x] = 'O';}
                                 else if (area[y][x]== 'X')
                                    {yourLife+=1;}
				            	break;
				          }

             }
              int count=0;
						for(int row=1;row<=17;row++)
						{
							for (int col=1;col<=35;col++)
							{
								if (area[row][col]==' ' || area[row][col]=='O')
								count++;
							}
						}
						if (count==595)
						{
							gameRunning=false;
							system("cls");
							printVictoryScreen();
                            cout<<"Your Score was: "<<yourScore<<"\nYou Saved the planet Soldier!!!"<<endl;
                            system("pause>null");
                            exit(0);
                        }
                       if (yourLife == 0)
                        {
                            gameRunning=false;
                            system("cls");
                            gameOver();
                            cout<<"\n\nYour Score: "<<yourScore<<"\nTry again"<<endl;
                            system("pause>null"); //press any key to continue message is omitted
                            exit(0);
                        }


}
}
Sleep(gameSpeed);
}
}







