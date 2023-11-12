//cpp
#include "tic_tac_toe.h"
using std::cout;

//public funtions
bool TicTacToe::game_over()
{
    if(check_column_win()||check_row_win()||check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if(check_board_full())
    {
        winner = "C";
        return true;
    }
    else{
        return false;
    }
}
void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}
void TicTacToe::mark_board(int position){
    pegs[position-1] = player;
    set_next_player();
}
//private functions
void TicTacToe::clear_board()
{
    //using auto& is a reference which allows us to access the elements directly in the loop
    for(auto& peg: pegs)
    {
        peg = " ";
    }
}
void TicTacToe::set_next_player()
{
    if(player== "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }

}
bool TicTacToe::check_board_full()
{
    for(int i = 0; i < pegs.size(); i++)
    {
        if(pegs[i] == " ")
        {
            return false;
        }
    }
    return true;
}
void TicTacToe::set_winner()
{
    if(player == "X"){
        winner = "O";
    }
    else{
        winner = "X";
    }
}
//friend functions
void display_board(const TicTacToe& game)
{//assume size is always 9 or 16
    if (game.pegs.size() == 9)
    {
        for (int i = 0; i < game.pegs.size(); i+=3)
        {       
            cout<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"\n";
        }
    }
    else
    {
       for (int i = 0; i < game.pegs.size(); i+=4)
        {       
            cout<<game.pegs[i]<<"|"<<game.pegs[i+1]<<"|"<<game.pegs[i+2]<<"|"<<game.pegs[i+3]<<"\n";
        } 
    }
}
//protected functions
bool TicTacToe::check_column_win()
{
    return false;
}
bool TicTacToe::check_row_win()
{
    return false;
}
bool TicTacToe::check_diagonal_win()
{
    return false;
    
}
