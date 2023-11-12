#include "tic_tac_toe_4.h"
#include "tic_tac_toe_3.h"

//private functions
/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/
bool TicTacToe4::check_column_win()
{
    //check for a vertical win
    for(int j = 0; j < 4; j++)
    {
        if(pegs[j*1]!=" "&&pegs[j*1]==pegs[j*1+4] &&pegs[j*1]==pegs[j*1+8]&&pegs[j*1]==pegs[j*1+12])
        {
            return true;
        }
    }
    return false;
}
/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/
bool TicTacToe4::check_row_win()
{
    //check for a horizontal win
    for(int i = 0; i < 4; i++)
    {
        if( pegs[i*4] != " " && pegs[i*3]==pegs[i*4+1] && pegs[i*4]==pegs[i*4+2]&& pegs[i*4]==pegs[i*4+3])
        {
            return true;
        }
    }
    return false;
}
/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/
bool TicTacToe4::check_diagonal_win()
{
    //check for diagonal win
    if(pegs[0] != " " && pegs[0]==pegs[5] && pegs[0]==pegs[10] && pegs[0]==pegs[15]) 
    {
        return true;
    }
    else if (pegs[3] != " " && pegs[3]==pegs[6] && pegs[3]==pegs[9] && pegs[3]==pegs[12])
    {
        return true;
    }
    else
    {
        return false;
    }
}
