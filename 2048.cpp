#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

class Game
{
	public:
		int row;
		int column;		
		void random(int board[4][4])
		{
			int count=0;
			while(1)
			{
				row=rand()%4;
				column=rand()%4;
				
				if(board[row][column]==0)
				{			
					board[row][column]=2;
					break;
				}
				if(count==100)
				{
					system("cls");
					cout<<"\n\n\n\n\n\n\n\t\t\t\tGame Over!"<<endl;
					system("pause");
					exit(1);	
				}
					count++;				
			}
		}
		void display(int board[4][4])
		{
			for(int i=0;i<4;i++)
			{
				
				for(int j=0;j<4;j++)
				{
					if(board[i][j]==0)
					cout<<"\t\t";
					else
					cout<<"\t"<<board[i][j]<<"\t";
				}
				cout<<endl<<endl<<endl;
			}
		}
		void up(int board[4][4])
		{		
			for(int j=0;j<4;j++)
			{
				row=0;
				column=j;
				for(int i=1;i<4;i++)
				{
					if(board[i][j]!=0)
					{
						if(board[i-1][j]==0 || board[i-1][j]==board[i][j])
						{
							if(board[row][column]==board[i][j])
							{
								board[row][column]=board[row][column]+board[row][column];
								board[i][j]=0;
							}
							else
							{
								if(board[row][column]==0)
								{
									board[row][column]=board[i][j];
									board[i][j]=0;
								}
								else
								{									
									board[++row][column]=board[i][j];
									board[i][j]=0;									
								}
							}
						}
						else
						{
							row++;
						}	
					}
				}
			}
		}
		void down(int board[4][4])
		{			
			for(int j=0;j<4;j++)
			{
				row=3;
				column=j;
				for(int i=2;i>=0;i--)
				{
					if(board[i][j]!=0)
					{
						if(board[i+1][j]==0 || board[i+1][j]==board[i][j])
						{
							if(board[row][column]==board[i][j])
							{
								board[row][column]=board[row][column]+board[row][column];
								board[i][j]=0;								
							}
							else
							{
								if(board[row][column]==0)
								{
									board[row][column]=board[i][j];
									board[i][j]=0;
								}
								else
								{
									board[--row][column]=board[i][j];
									board[i][j]=0;
								}
							}
						}
						else
						{
							row--;
						}	
					}
				}
			}
		}
		void left(int board[4][4])
		{			
			for(int i=0;i<4;i++)
			{
				row=i;
				column=0;
				for(int j=1;j<4;j++)
				{
					if(board[i][j]!=0)
					{
						if(board[i][j-1]==0 || board[i][j-1]==board[i][j])
						{
							if(board[row][column]==board[i][j])
							{
								board[row][column]=board[row][column]+board[row][column];
								board[i][j]=0;
							}
							else
							{
								if(board[row][column]==0)
								{
									board[row][column]=board[i][j];
									board[i][j]=0;
								}
								else
								{
									board[row][++column]=board[i][j];
									board[i][j]=0;
								}
							}
						}
						else
						{
							column++;
						}	
					}
				}
			}
		}
		void right(int board[4][4])
		{			
			for(int i=0;i<4;i++)
			{
				row=i;
				column=3;
				for(int j=2;j>=0;j--)
				{
					if(board[i][j]!=0)
					{
						if(board[i][j+1]==0 || board[i][j+1]==board[i][j])
						{
							if(board[row][column]==board[i][j])
							{
								board[row][column]=board[row][column]+board[row][column];
								board[i][j]=0;
							}
							else
							{
								if(board[row][column]==0)
								{
									board[row][column]=board[i][j];
									board[i][j]=0;
								}
								else
								{
									board[row][--column]=board[i][j];
									board[i][j]=0;
								}
							}
						}
						else 
						{
							column--;
						}			
					}
				}
			}
		}		
};

int main()
{
	Game game;
	int Board[4][4]={0};
	srand(time(0));
	game.display(Board);
	game.random(Board);
	game.random(Board);
	system("pause");
	system("cls");
	game.display(Board);	
	while(1)
	{	
        switch((getch())) 
		{
        	case UP:
			  	game.up(Board);
				game.random(Board); 
				system("cls");
				game.display(Board);
				break;
			case DOWN:			
				game.down(Board);
				game.random(Board); 
				system("cls");
				game.display(Board);
				break;
			case LEFT:			
				game.left(Board);
				game.random(Board);
				system("cls"); 
				game.display(Board);
				break;
			case RIGHT:			
				game.right(Board);
				game.random(Board); 
				system("cls");
				game.display(Board);
				break; 
		}
	}		
}
