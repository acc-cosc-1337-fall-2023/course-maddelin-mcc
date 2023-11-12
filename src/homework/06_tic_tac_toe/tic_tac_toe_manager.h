#include "tic_tac_toe.h"
#include<vector>
#include<string>
#include<iostream>
#include<memory>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
    public: 
        void get_winner_total(int& o, int& x, int& t);
        void save_game(std::unique_ptr<TicTacToe>& b);

    private:
        std::vector<std::unique_ptr<TicTacToe>> games;
        int x_win =0;
        int o_win =0;
        int ties=0;
        void update_winner_count(std::string winner);
};

#endif