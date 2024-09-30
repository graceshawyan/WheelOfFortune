# Wheel Of Fortune

## Table of Contents
- [Description](#description)
- [Features](#features)
- [How to Play](#how-to-play)
- [Gameplay Flow](#gameplay-flow)
- [Installation](#installation)

## Description
This is a **Wheel Of Fortune-inspired game** built in C++. Players can spin the wheel, guess consonants, buy vowels, and attempt to solve a puzzle chosen from multiple categories. The game dynamically tracks the player's money and progress.

## Features
- Multiple categories: **Movies**, **Food and Drinks**, **Phrases**, **Song Lyrics**.
- Interactive gameplay: Spin the wheel, guess consonants, buy vowels, or solve the puzzle.
- Randomized prizes for puzzle solving.
- Input validation for player actions.
- Game over conditions based on money or correct puzzle solving.

## How to Play
1. Choose a category from Movies, Food and Drinks, Phrases, or Song Lyrics.
2. Spin the wheel to guess consonants or buy vowels with your earnings.
3. Try to solve the puzzle before running out of money.
4. Win a random prize if you solve the puzzle correctly!

## Gameplay Flow
1. **Spin the wheel**: Earn money for each correct consonant.
2. **Guess a consonant**: Choose a consonant to reveal letters in the puzzle.
3. **Buy a vowel**: Spend $700 to reveal a vowel in the puzzle.
4. **Solve the puzzle**: Attempt to solve and win the game.

## Installation

To run the Wheel of Fortune game on your local machine, follow these steps:

```bash
# Clone the repository
git clone https://github.com/graceshawyan/WheelOfFortune.git

# Go into the project directory
cd WheelOfFortune

# Compile the game (for example, using g++)
g++ -o WheelOfFortune main.cpp

# Run the game
./WheelOfFortune
