# Rotated Connect Four Game

This project is a **C++ implementation** of a modified **Connect Four game** where players take turns placing pieces on a dynamic square board.  
In addition to placing pieces, players can rotate the board **90 degrees clockwise**, causing pieces to fall due to gravity.

## Features
- Dynamic **square-shaped board** with user-defined size.
- Two-player **turn-based** gameplay with pieces `'X'` and `'O'`.
- Players can **place a piece** or **rotate the board 90° clockwise**.
- Pieces drop down naturally after rotation, following **gravity mechanics**.
- The game ends when a player forms a **line of N pieces** or the board is full (draw).

## Files
- `main.cpp` → The main game loop handling player interactions.
- `Board.h` → Header file defining the **Board class**.
- `Board.cpp` → Implementation of **board mechanics** (placing pieces, rotating board, checking win conditions).
- `Player.h` → Header file defining the **Player class**.
- `Player.cpp` → Implementation of **player actions**.
