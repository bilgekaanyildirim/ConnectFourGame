//
// Created by Bilge Kaan Yıldırım on 13.05.2024.
//

#include "Player.h"

// Constructor
Player::Player(Board & gameBoard, const char &playerSign) : board(gameBoard), sign(playerSign) {}

// Puts piece to the board
bool Player::put(const int &columnIndex)
{
    return board.put_piece(sign, columnIndex);
}

// Turns the board 90 degrees clockwise
void Player::turn_board()
{
    board.turn_board_clockwise();
}

// Checks is the player win the game
bool Player::is_winner()
{
    if (sign == board.get_game_status())
    {
        return true;
    }
    return false;
}

// Returns the sign of the player
char Player::get_symbol()
{
    return sign;
}
