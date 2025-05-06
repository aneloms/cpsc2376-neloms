# Project 04 – Connect 4 SDL

## 🕹️ Description

A two-player Connect 4 game built in C++ with SDL2. Players take turns dropping pieces into a grid by pressing arrow keys. The game detects wins and draws, shows player turns, and supports restarts.

## 🎮 Controls

- Left/Right Arrow Keys: Move selection
- Enter: Drop piece
- R: Restart game
- Esc: Quit game

## 🧪 Screenshot

![Screenshot](screenshot.png)

## ✨ Extra Features

- Column highlighting for current selection
- Display of current player's turn
- Win/draw messages
- Sound effect on piece drop

## 🧱 Build Instructions

Ensure SDL2, SDL2_ttf, and SDL2_mixer are installed.

Compile with:

```bash
g++ main.cpp game.cpp -o connect4 -lSDL2 -lSDL2_ttf -lSDL2_mixer
