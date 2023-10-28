#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include"tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test if there is a tie"){
	TicTacToe game;

	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test First Player = X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player()=="X");
}

TEST_CASE("Test First Player = O")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player()=="O");
}

TEST_CASE("Test Win by First Column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(9);
	game.mark_board(7);
	REQUIRE(game.game_over()==true);
}

TEST_CASE("Test Win by Second Column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(8);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by Third Column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(2);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by First Row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(2);
	game.mark_board(9);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by Second Row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(6);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by Third Row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(6);
	game.mark_board(8);
	game.mark_board(3);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by Top Left Diagonal")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(6);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test Win by Bottom Left Diagonal")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(6);
	game.mark_board(5);
	game.mark_board(9);
	game.mark_board(3);
	REQUIRE(game.game_over()==true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager.get_winner_total")
{
	TicTacToeManager games;

	//game 1, x will win
	TicTacToe game1;
	game1.start_game("X");
	game1.mark_board(7);
	game1.mark_board(6);
	game1.mark_board(5);
	game1.mark_board(9);
	game1.mark_board(3);
	REQUIRE(game1.game_over()==true);
	REQUIRE(game1.get_winner() == "X");
	games.save_game(game1);

	//game2, will be a tie
	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(1);
	game2.mark_board(2);
	game2.mark_board(3);
	game2.mark_board(4);
	game2.mark_board(5);
	game2.mark_board(7);
	game2.mark_board(6);
	game2.mark_board(9);
	game2.mark_board(8);
	REQUIRE(game2.game_over() == true);
	REQUIRE(game2.get_winner() == "C");
	games.save_game(game2);

	//game3, winner will be X
	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(2);
	game3.mark_board(1);
	game3.mark_board(5);
	game3.mark_board(3);
	game3.mark_board(8);
	REQUIRE(game3.game_over()==true);
	REQUIRE(game3.get_winner() == "X");
	games.save_game(game3);

	//game4, winner will be O
	TicTacToe game4;
	game4.start_game("O");
	game4.mark_board(2);
	game4.mark_board(1);
	game4.mark_board(5);
	game4.mark_board(3);
	game4.mark_board(8);
	REQUIRE(game4.game_over()==true);
	REQUIRE(game4.get_winner() == "O");
	games.save_game(game4);

	int x; 
	int o;
	int t;
	games.get_winner_total(o, x, t);
	REQUIRE(x == 2);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}