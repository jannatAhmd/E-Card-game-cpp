# E-Card Game (C++)

Console card game against the computer, based on the "E-Card" game from the anime Kaiji. Personal project, built by reusing and extending my own Rock Paper Scissors project.

## How the game works
- The game has 12 rounds, divided into 4 groups of 3 rounds.
- Each player holds 5 cards: 4 Citizens and 1 special card, which is a Emperor a Slave.
- The Emperor and Slave roles alternate between the groups. A random draw decides who starts with the Emperor in the first group.
- The player holding the Emperor throws a card first. If nobody wins, the other player throws, and the order continues until a player wins the round.

## Winning rules
- Emperor beats Citizen
- Citizen beats Slave
- Slave beats Emperor
- Citizen against Citizen is a draw, so the next card is played
- After 4 consecutive Citizen draws, the fifth round is not played and the Slave holder wins, because the Slave beats the Emperor

## Features
- 12 rounds against a computer opponent that plays random cards
- Shows each player's number of won rounds
- Shows the overall score and the final winner at the end

## Tech stack
C++, Visual Studio, console application

## How to run
1. Open e card.vcxproj in Visual Studio.
2. Press F5.

## What I learned
Following the exact rules of a game and turning them into code, and extending an existing project (Rock Paper Scissors) into a new one.