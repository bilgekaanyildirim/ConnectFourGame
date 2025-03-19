//
// Created by Bilge Kaan Yıldırım on 13.05.2024.
//

#ifndef HW5_BOARD_H
#define HW5_BOARD_H

class Board
{
private:
    char ** matrix;
    int size;
    int winCon;
    void check_win_condition(const int & i, const int & j, int & counter1, int & counter2, bool & chk1, bool & chk2);   // Increases counters according to piece in indices and if the counter exceed the winning condition convert chks to true

public:
    Board(const int & boardSize, const int & winningCondition);     // Constructor
    ~Board();                                                       // Destructor
    void print_board();                                             // Displays the current state of the game board
    bool put_piece(const char & sign, const int & columnIndex);     // Drops a player's piece (char) into the specified column (int), returning True if successful and False otherwise.
    void turn_board_clockwise();                                    // Rotates the board 90 degrees clockwise, causing pieces to drop down due to gravity
    char get_game_status();                                         // Checks if the game is over and returns the winner's piece (char), 'D' for a draw, or '-' if the game continues

};


#endif //HW5_BOARD_H
