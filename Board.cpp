//
// Created by Bilge Kaan Yıldırım on 13.05.2024.
//

#include "Board.h"
#include <iostream>

using namespace std;

//Constructor
Board::Board(const int &boardSize, const int &winningCondition)
{
    size = boardSize;
    winCon = winningCondition;

    matrix = new char * [size];

    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new char[size];

        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = '-';
        }
    }
}

//Destructor
Board::~Board()
{
    for (int i = 0; i < size; ++i)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}

// Displays the current state of the game board
void Board::print_board()
{
    cout << endl;

    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << matrix[j][i];
        }
        cout << endl;
    }
    cout << endl;
}

// Drops a player's piece (char) into the specified column (int), returning True if successful and False otherwise.
bool Board::put_piece(const char &sign, const int &columnIndex)
{
    if (columnIndex >= size || columnIndex < 0)
    {
        return false;
    }

    for (int i = 0; i < size; ++i)
    {
        if (matrix[columnIndex][i] == '-')
        {
            matrix[columnIndex][i] = sign;
            return true;
        }
    }
    return false;
}

// Rotates the board 90 degrees clockwise, causing pieces to drop down due to gravity
void Board::turn_board_clockwise()
{
    char temp[size][size];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            temp[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = '-';
        }
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j >= 0; --j)
        {
            char chr = temp[i][j];
            put_piece(chr, i);
        }
    }
}

// Checks if the game is over and returns the winner's piece (char), 'D' for a draw, or '-' if the game continues
char Board::get_game_status()
{
    bool isEmpty = false;

    // Checks is there a place to put piece
    for (int i = 0; i < size && !isEmpty; ++i)
    {
        for (int j = 0; j < size && !isEmpty; ++j)
        {
            if (matrix[i][j] == '-')
            {
                isEmpty = true;
            }
        }
    }

    if (!isEmpty)
    {
        return 'D';
    }

    int XCounter = 0, OCounter = 0;
    bool XChk = false, OChk = false;

    // Checks vertically is there pieces in a line
    for (int i = 0; i < size && (!XChk || !OChk); ++i)
    {
        for (int j = 0; j < size && (!XChk || !OChk); ++j)
        {
            check_win_condition(i, j, XCounter, OCounter, XChk, OChk);

        }
        XCounter = 0;
        OCounter = 0;
    }

    if (XChk && OChk)
    {
        return 'D';
    }

    // Checks horizontally is there pieces in a line
    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j < size; ++j)
        {
            check_win_condition(j, i, XCounter, OCounter, XChk, OChk);
        }
        XCounter = 0;
        OCounter = 0;
    }

    if (XChk && OChk)
    {
        return 'D';
    }

    // Checks diagonally is there pieces in a line
    for (int i = 0; i < size; ++i)
    {
        check_win_condition(i, i, XCounter, OCounter, XChk, OChk);
    }
    XCounter = 0;
    OCounter = 0;

    if (XChk && OChk)
    {
        return 'D';
    }

    for (int i = 0; i < size; ++i)
    {
        check_win_condition(i, size - 1 - i, XCounter, OCounter, XChk, OChk);
    }
    XCounter = 0;
    OCounter = 0;

    if (XChk && OChk)
    {
        return 'D';
    }

    int XCounter1 = 0, OCounter1 = 0;

    for (int ctr = 0; ctr <= size - winCon; ++ctr)
    {
        for (int i = 0; i < size - ctr - 1; ++i)
        {
            check_win_condition(i, i + 1 + ctr, XCounter, OCounter, XChk, OChk);
            check_win_condition(i + 1 + ctr, i, XCounter1, OCounter1, XChk, OChk);
        }
        XCounter = 0;
        OCounter = 0;
        XCounter1 = 0;
        OCounter1 = 0;
    }

    if (XChk && OChk)
    {
        return 'D';
    }

    for (int ctr = 0; ctr <= size - winCon; ++ctr)
    {
        for (int i = 0; i < size - ctr - 1; ++i)
        {
            check_win_condition(i, size - i - 2 - ctr, XCounter, OCounter, XChk, OChk);
            check_win_condition(i + 1 + ctr, size - i - 1, XCounter1, OCounter1, XChk, OChk);
        }
        XCounter = 0;
        OCounter = 0;
        XCounter1 = 0;
        OCounter1 = 0;
    }

    if (XChk && OChk)
    {
        return 'D';
    }
    else if (XChk)
    {
        return 'X';
    }
    else if (OChk)
    {
        return 'O';
    }
    else
    {
        return '-';
    }
}

// Increases counters according to piece in indices and if the counter exceed the winning condition convert chks to true
void Board::check_win_condition(const int & i, const int & j, int &counter1, int &counter2, bool &chk1, bool &chk2)
{
    if (!chk1)
    {
        if (matrix[i][j] == 'X')
        {
            counter1++;
        }
        else
        {
            counter1 = 0;
        }
    }

    if (!chk2)
    {
        if (matrix[i][j] == 'O')
        {
            counter2++;
        }
        else
        {
            counter2 = 0;
        }
    }

    if (counter1 == winCon)
    {
        chk1 = true;
    }
    if (counter2 == winCon)
    {
        chk2 = true;
    }
}
