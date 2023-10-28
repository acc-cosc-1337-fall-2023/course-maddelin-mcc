#include"tic_tac_toe.h"
#include"tic_tac_toe_manager.h"
#include<iostream>
#include<string>

using std::cout; using std::cin; using std::string;
/*

1) Create a program that will play the TicTacToe game until the user opts to quit (outer loop).
2) Start the game with X or O. Loop here while user doesn’t provide an X or O.
3) Modify (inner loop) that iterates until a winner is determined to display the winner.
4) After a winner is determined prompt user if they want to play another game.

*/
int main() 
{
	TicTacToeManager mgr;
	TicTacToe game;
	string first_player;
	char user_choice = 'y';
	int o, x, t;

	do
	{
		while(first_player != "X" && first_player != "O")
		{
			cout<<"Enter first player: ";
			cin>>first_player;
		}

		game.start_game(first_player);

		int position;
		while(!game.game_over())
		{
			cout<<"Enter a position: ";
			cin>>position;
			game.mark_board(position);
			game.display_board();
		}
		mgr.save_game(game);
		mgr.get_winner_total(o, x, t);
		cout<<"Game Over. Winner: "<<game.get_winner()<<"\n\n";
		cout<<"X Wins: "<<x<<"\nO Wins: "<<o<<"\nTies: "<<t<<"\n\n";
		cout<<"Enter Y or y to play again: ";
		cin>>user_choice;

	}
	while(user_choice == 'y' ||user_choice == 'Y');

	return 0;
}