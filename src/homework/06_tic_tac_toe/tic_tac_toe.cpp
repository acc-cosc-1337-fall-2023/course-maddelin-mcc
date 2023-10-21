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
void TicTacToe::display_board() const 
{
    for (int i = 0; i < pegs.size(); i+=3)
    {
            cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
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
bool TicTacToe::check_column_win()
{
    //check for a vertical win
    for(int j = 0; j < 3; j++)
    {
        if(pegs[j*1]!=" "&&pegs[j*1]==pegs[j*1+3] &&pegs[j*1]==pegs[j*1+6])
        {
            return true;
        }
    }
    return false;
}
bool TicTacToe::check_row_win()
{
    //check for a horizontal win
    for(int i = 0; i < 3; i++)
    {
        if( pegs[i*3] != " " && pegs[i*3]==pegs[i*3+1] && pegs[i*3]==pegs[i*3+2])
        {
            return true;
        }
    }
    return false;
}
bool TicTacToe::check_diagonal_win()
{
    //check for diagonal win
    if((pegs[4] != " ")&&( (pegs[4]==pegs[0] && pegs[4]==pegs[8]) || (pegs[4]==pegs[2] && pegs[4]==pegs[6]) )) 
    {
        return true;
    }
    else
    {
        return false;
    }
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