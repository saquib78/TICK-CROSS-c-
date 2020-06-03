#include<iostream>
using namespace std;
	
	// variable
	char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
	int choice,row,column;
	char turn = 'X';
	bool draw = false;

// display function
void display_board()
{
	cout<<"\n\n\t T i c k   C r o s s   G a m e \n\n";
	cout<<"\tPlayer1 [X]";
	cout<<"\n\tPlayer2 [O]\n\n"<<endl;
	
	
	system("cls");   // for clear the creen
	cout<<"\t\t       |      |      \n";
	cout<<"\t\t   "<<board[0][0]<<"   |  "<<board[0][1]<<"   |  "<<board[0][2]<<"   \n";
	cout<<"\t\t ______|______|______ \n";
	cout<<"\t\t       |      |      \n";
	cout<<"\t\t  "<<board[1][0]<<"    |  "<<board[1][1]<<"   |  "<<board[1][2]<<"   \n";
	cout<<"\t\t ______|______|______ \n";
	cout<<"\t\t       |      |      \n";
	cout<<"\t\t  "<<board[2][0]<<"    |  "<<board[2][1]<<"   |  "<<board[2][2]<<"   \n";
	cout<<"\t\t       |      |      \n";
}

// player turns
void player_turn()
{
	if(turn == 'X')
	{
		cout<<"\n\n\tPlayer1 [X] Turn : ";
	}
	if(turn == 'O')
	{
		cout<<"\n\n\tPlayer2 [O] Turn : ";
	}
	
	cin>>choice;
	switch(choice)
	{
		case 1: row=0; column =0; break;
		case 2: row=0; column =1; break;
		case 3: row=0; column =2; break;
		case 4: row=1; column =0; break;
		case 5: row=1; column =1; break;
		case 6: row=1; column =2; break;
		case 7: row=2; column =0; break;
		case 8: row=2; column =1; break;
		case 9: row=2; column =2; break;
			
		default:
			cout<<"Invalid choice\n";
			break;
	}
	
	
	if(turn == 'X' && board[row][column] !='X' && board[row][column] !='O')
	{
		board[row][column]= 'X';
		turn = 'O';
	}
	
	
	else if(turn == 'O' && board[row][column] !='X' && board[row][column] !='O')
	{
		board[row][column]= 'O';
		turn = 'X';
	}
	
	
	else
	{
		cout<<"Box already filled . try again";
		player_turn();
	}
	
	display_board();  // after one steps print again updated value
	
}


// condintion for game over
bool gameover()
{
	//check for wins
	for(int i=0; i<3;i++)
	{
		if(board[i][0] == board [i][1] && board[i][0] == board [i][2] || board[0][i] == board [1][i] && board[0][i] == board [2][i])
		{
			return false;	
		}
		if(board[0][0] == board[1][1] && board[0][0] == board [2][2]  || board[0][2] == board[1][1] && board[0][2] == board [2][0] )
		{
			return false;	
		}	
	}
	
	
	// check any shell is empty or not
	for(int i =0; i<3; i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j] !='X' && board[i][j] !='Y')
			{
				return true;
			}		
		}	
	}
	
	
	draw = true;
	return false;
}


int main()
{
	while(gameover())
	{
	display_board();
	player_turn();
	gameover();
	}
	
	if(turn =='X' && draw == false)
	{
		cout<<"Congratulations player2 [O] wins !!"<<endl;	
	}	
	else if(turn =='O' && draw == false)
	{
		cout<<"Congratulations player1 [X] wins !!"<<endl;	
	}
	else
	{
		cout<<"MATCH IS DRAW ";
	}
	return 0;	
}
