//
// Created by Bilge Kaan Yıldırım on 13.05.2024.
//

#ifndef HW5_PLAYER_H
#define HW5_PLAYER_H


#include "Board.h"

class Player
{
private:
    char sign;
    Board & board;

public:
    Player(Board & gameBoard, const char & playerSign); // Constructor
    bool put(const int & columnIndex);                  // Puts piece to the board
    void turn_board();                                  // Turns the board 90 degrees clockwise
    bool is_winner();                                   // Checks is the player win the game
    char get_symbol();                                  // Returns the sign of the player

};


#endif //HW5_PLAYER_H
