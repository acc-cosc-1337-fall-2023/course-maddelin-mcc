#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include"tic_tac_toe_manager.h"
#include"tic_tac_toe_3.h"
#include"tic_tac_toe_4.h"
#include<memory>
using std::unique_ptr; using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test if there is a tie"){
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();

	game->mark_board(1);
	REQUIRE(game->game_over() == false);
	game->mark_board(2);
	REQUIRE(game->game_over() == false);
	game->mark_board(3);
	REQUIRE(game->game_over() == false);
	game->mark_board(4);
	REQUIRE(game->game_over() == false);
	game->mark_board(5);
	REQUIRE(game->game_over() == false);
	game->mark_board(7);
	REQUIRE(game->game_over() == false);
	game->mark_board(6);
	REQUIRE(game->game_over() == false);
	game->mark_board(9);
	REQUIRE(game->game_over() == false);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test First Player = X")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	REQUIRE(game->get_player()=="X");
}

TEST_CASE("Test First Player = O")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("O");
	REQUIRE(game->get_player()=="O");
}

TEST_CASE("Test Win by First Column")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(9);
	game->mark_board(7);
	REQUIRE(game->game_over()==true);
}

TEST_CASE("Test Win by Second Column")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(8);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Third Column")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by First Row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(9);
	game->mark_board(3);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Second Row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Third Row")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(6);
	game->mark_board(8);
	game->mark_board(3);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Top Left Diagonal")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Bottom Left Diagonal")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(6);
	game->mark_board(5);
	game->mark_board(9);
	game->mark_board(3);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager.get_winner_total")
{
	TicTacToeManager games;

	//game 1, x will win
	unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
	game1->start_game("X");
	game1->mark_board(7);
	game1->mark_board(6);
	game1->mark_board(5);
	game1->mark_board(9);
	game1->mark_board(3);
	REQUIRE(game1->game_over()==true);
	REQUIRE(game1->get_winner() == "X");
	games.save_game(game1);

	//game2, will be a tie
	unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
	game2->start_game("X");
	game2->mark_board(1);
	game2->mark_board(2);
	game2->mark_board(3);
	game2->mark_board(4);
	game2->mark_board(5);
	game2->mark_board(7);
	game2->mark_board(6);
	game2->mark_board(9);
	game2->mark_board(8);
	REQUIRE(game2->game_over() == true);
	REQUIRE(game2->get_winner() == "C");
	games.save_game(game2);

	//game3, winner will be X
	unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
	game3->start_game("X");
	game3->mark_board(2);
	game3->mark_board(1);
	game3->mark_board(5);
	game3->mark_board(3);
	game3->mark_board(8);
	REQUIRE(game3->game_over()==true);
	REQUIRE(game3->get_winner() == "X");
	games.save_game(game3);

	//game4, winner will be O
	unique_ptr<TicTacToe> game4 = make_unique<TicTacToe3>();
	game4->start_game("O");
	game4->mark_board(2);
	game4->mark_board(1);
	game4->mark_board(5);
	game4->mark_board(3);
	game4->mark_board(8);
	REQUIRE(game4->game_over()==true);
	REQUIRE(game4->get_winner() == "O");
	games.save_game(game4);

	int x; 
	int o;
	int t;
	games.get_winner_total(o, x, t);
	REQUIRE(x == 2);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}

//TESTS FOR TICTACTOE4
TEST_CASE("Test Win by First Column4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	game->mark_board(4);
	game->mark_board(13);
	
	REQUIRE(game->game_over()==true);
}

TEST_CASE("Test Win by Second Column4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(10);
	game->mark_board(4);
	game->mark_board(14);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Third Column4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(1);
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(11);
	game->mark_board(14);
	game->mark_board(15);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Fourth Column4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(1);
	game->mark_board(8);
	game->mark_board(2);
	game->mark_board(12);
	game->mark_board(3);
	game->mark_board(16);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by First Row4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Second Row4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(5);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(8);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Third Row4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(9);
	game->mark_board(1);
	game->mark_board(10);
	game->mark_board(2);
	game->mark_board(11);
	game->mark_board(3);
	game->mark_board(12);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Fourth Row4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	game->mark_board(1);
	game->mark_board(14);
	game->mark_board(2);
	game->mark_board(15);
	game->mark_board(3);
	game->mark_board(16);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Top Left Diagonal4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(11);
	game->mark_board(4);
	game->mark_board(16);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test Win by Bottom Left Diagonal4")
{
	unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
	game->start_game("X");
	game->mark_board(13);
	game->mark_board(14);
	game->mark_board(10);
	game->mark_board(15);
	game->mark_board(7);
	game->mark_board(16);
	game->mark_board(4);
	REQUIRE(game->game_over()==true);
	REQUIRE(game->get_winner() == "X");
}
