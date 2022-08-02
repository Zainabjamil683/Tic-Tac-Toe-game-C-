#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void displayboard();
void playerchoice();
void blockreset();
void exit();
struct data
{
	bool draw=false;
	char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	char turn='X';	
	char player1[20],player2[20];
	bool decision = false;
	int reset=0;
};
struct data d;

bool gameover();
	
main()
{
	int choice;
	cout<<"\n\n\t\t**************** WELCOME to C++ GAME *****************\n\n";
	cout<<"\t\t**************** T I C K  T A C  T O E *****************\n\n\n";
	
	fstream game;
	do
	{
	cout<<"\t\t 1. PLAY GAME\n\n";
	cout<<"\t\t 2. SHOW WINNERS LIST\n\n";
	cout<<"\t\t 3. EXIT GAME\n\n\n";
	cout<<"\t\t======================================================="<<endl;
	cout<<"\t\t======================================================="<<endl;
	cout<<"\t\t Enter your choice=";

	cin>>choice;
	system("cls");
	switch(choice)
	{
	case 1:
		cout<<"\n\n\tEnter player [X] name=";
		cin>>d.player1;
		cout<<"\tEnter player [O] name=";
		cin>>d.player2;
		while(gameover())
		{
			displayboard();
			playerchoice();
			gameover();
		}
	
		game.open("D:Winners name.txt",ios::app);
		//filestoring
		if(game.is_open())
		{	
			//gamewin
			if(d.turn=='X'&& d.draw==false )
			{
				displayboard();
				cout<<"\n\t"<<d.player2<<" [O] Wins!!\n\tCongratulations!"<<endl;
				game<<d.player2<<" [O]"<<endl;
				cout<<"\n\t\t\''HOPE YOU ENJOY THE GAME''!!!!";
				cout<<"\n\n\tDO YOU WANT TO PLAY AGAIN\n\n"<<endl;
				game.close();
			
			blockreset();
			}
			else if(d.turn=='O' && d.draw==false)
			{
				displayboard();
				cout<<"\n\t"<<d.player1<<" [X] Wins!!\n\tCongratulations!"<<endl;
				game<<d.player1<<" [X]"<<endl;
				cout<<"\n\t\t\tHOPE YOU ENJOY THE GAME!!!!";
				cout<<"\n\n\tDO YOU WANT TO PLAY AGAIN\n\n"<<endl;
				game.close();
					blockreset();
			}
			//gamedraw
			else if(d.draw==true)
			{	
				displayboard();
				cout<<"\t\tGame Draw"<<endl;
				cout<<"\n\t\t\tHOPE YOU ENJOY THE GAME!!!!";
				cout<<"\n\n\tDO YOU WANT TO PLAY AGAIN\n\n"<<endl;
				game.close();
			d.decision=true;
			}
		}
		else
		{
			cout<<"File not found"<<endl;
		}
		break;
	case 2:	
		game.open("D:Winners name.txt",ios::in);
		if(game.is_open())
		{
			cout<<"\tWINNER NAMES\n"<<endl;
			string ch;
			while(!game.eof())
			{
				getline(game,ch);
				cout<<"\t"<<ch<<endl;
			}	
			cout<<endl;
				cout<<"\t\t======================================================="<<endl;
				cout<<"\t\t=======================================================\n\n"<<endl;
			game.close();
		d.decision=true;
		}
		else
		{
			cout<<"File not exist";
		}
		break;
	case 3:
		exit();
		break;
	default:
		cout<<"\n\tINVALID CHOICE"<<endl;
		}
	}while(choice!=3);
	return 0;
	
}
void displayboard()
{
	system("cls");
	cout<<"\n   T I C K  T A C  T O E\n"<<endl;
	cout<<"\t"<<d.player1<<" [X]\n\t"<<d.player2<<" [0]"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<d.board[0][0]<<"  |  "<<d.board[0][1]<<"  |  "<<d.board[0][2]<<"  "<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<d.board[1][0]<<"  |  "<<d.board[1][1]<<"  |  "<<d.board[1][2]<<"  "<<endl;
	cout<<"\t\t_____|_____|_____"<<endl;
	cout<<"\t\t     |     |     "<<endl;
	cout<<"\t\t  "<<d.board[2][0]<<"  |  "<<d.board[2][1]<<"  |  "<<d.board[2][2]<<"  "<<endl;
	cout<<"\t\t     |     |     "<<endl;

}
void playerchoice()
{
	int choice;
	int row,column;
	if(d.turn == 'X')
		cout<<"\n\t"<<d.player1<<" [X] turn:";
	if(d.turn == 'O')
		cout<<"\n\t"<<d.player2<<" [O] turn:";
	cin>>choice;
	switch(choice)
	{
		case 1:row=0;column=0;break;
	    case 2:row=0;column=1;break;
		case 3:row=0;column=2;break;
		case 4:row=1;column=0;break;
		case 5:row=1;column=1;break;
		case 6:row=1;column=2;break;
		case 7:row=2;column=0;break;
		case 8:row=2;column=1;break;
		case 9:row=2;column=2;break;
		default:
			cout<<"Invald choice";
	}
	
	if(d.turn == 'X')
	{
		d.board[row][column]='X';
		d.turn='O';
	}
	else if(d.turn == 'O')
	{
		d.board[row][column]='O';
		d.turn='X';
	}
}
 void blockreset()
{
		d.board[0][0]='1';
		d.board[0][1]='2';
		d.board[0][2]='3';
		
		d.board[1][0]='4';
		d.board[1][1]='5';
		d.board[1][2]='6';
		
		d.board[2][0]='7';
		d.board[2][1]='8';
		d.board[2][2]='9';
	
		d.decision=true;
		d.reset=1;
}
bool gameover()
{ d.decision=false;
	//gamewin
	for(int i=0;i<3;i++)
	{
		
		if((d.board[i][0]==d.board[i][1])&&(d.board[i][0]==d.board[i][2]))
			{
				return d.decision;
				
			}
		else if((d.board[0][i]==d.board[1][i])&&(d.board[0][i]==d.board[2][i]))
			{
				return d.decision;
			}
		else if((d.board[0][0]==d.board[1][1])&&(d.board[0][0]==d.board[2][2]))
			{
				return d.decision;
			}
		else if((d.board[0][2]==d.board[1][1])&&(d.board[0][2]==d.board[2][0]))
			{
				return d.decision;
			}
	}
	
	//if any box not filed
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if((d.board[i][j]!='X')&&(d.board[i][j]!='O'))
			{
				return true;
			}	
	//game draw
	d.draw=true;
	return d.decision;
}
void exit()
{
	cout<<"\n\t\t*************************************************\n";
	cout<<"\t\t*************************************************\n";
	cout<<"\n\t\t   *********E X I T  F R O M  G A M E**********\n";
	cout<<"\n\t\t    ***********GAME DESIGNED BY***********\n\n\t\t\t"; 
	cout<<" ZAINAB JAMIL  (2021 BSE 034)\n\n";
}

