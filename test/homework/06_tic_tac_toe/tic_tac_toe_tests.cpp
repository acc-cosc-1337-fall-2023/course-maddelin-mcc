#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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
}
