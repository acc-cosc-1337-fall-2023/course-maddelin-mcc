#include"tic_tac_toe.h"
#include"tic_tac_toe_manager.h"
#include<iostream>
#include<string>
#include<memory>

using std::cout; using std::cin; using std::string;
using std::unique_ptr; using std::make_unique;
/*

1) Create a program that will play the TicTacToe game until the user opts to quit (outer loop).
2) Start the game with X or O. Loop here while user doesn’t provide an X or O.
3) Modify (inner loop) that iterates until a winner is determined to display the winner.
4) After a winner is determined prompt user if they want to play another game.

*/
int main() 
{
	TicTacToeManager mgr;
	unique_ptr<TicTacToe> game;
	string first_player;
	char user_choice = 'y';
	int o, x, t;
	int board_size;

	do
	{
		//allow user to choose game size
		cout<<"Choose Tic Tac Toe Game, enter 3 or 4: ";
		cin>>board_size;
		game = make_unique<TicTacToe>(board_size);

		while(first_player != "X" && first_player != "O")
		{
			cout<<"Enter first player: ";
			cin>>first_player;
		}

		(*game).start_game(first_player);

		int position;
		while(!(*game).game_over())
		{
			cout<<"Enter a position: ";
			cin>>position;
			(*game).mark_board(position);
			display_board(*game);
		}
		mgr.save_game(game);
		mgr.get_winner_total(o, x, t);
		cout<<"Game Over. Winner: "<<(*game).get_winner()<<"\n\n";
		cout<<"X Wins: "<<x<<"\nO Wins: "<<o<<"\nTies: "<<t<<"\n\n";
		cout<<"Enter Y or y to play again: ";
		cin>>user_choice;

	}
	while(user_choice == 'y' ||user_choice == 'Y');

	return 0;
}