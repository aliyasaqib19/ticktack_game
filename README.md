# 🎲 Game of 21 – Dice Game (C++)

## Overview
This is a **simple dice-based game** written in **C++**, where the player competes against a computer to get as close to **21** as possible without exceeding it.  

The game:
- Simulates dice rolls (1–6).
- Tracks scores for both the **Human Player** and **Computer**.
- Declares a winner based on who is closest to 21.
- Stores player scores in a text file (`scores.txt`) for record-keeping.
- Allows players to **view past game results**.

---

## Features
- **Object-Oriented Design (OOP)** using:
  - `Player` base class with `HumanPlayer` and `ComputerPlayer` subclasses.
  - Dice rolling logic encapsulated in a `Dice` class.
- **Randomized Dice Rolls** using `rand()`.
- **Score Persistence**:
  - Game results saved to `scores.txt`.
  - Past scores can be displayed after the session.
- **Replay Feature** – Play multiple rounds in one session.

---

## How to Play
1. Run the compiled program.
2. Enter your name when prompted.
3. Press **Enter** to roll the dice each turn.
4. The computer will automatically roll after you.
5. Try to stay as close to **21** as possible without exceeding it.
6. After each round, choose:
   - **Play Again (y)** to restart.
   - **Quit (n)** to exit.
7. At the end, press **`y`** to view all saved scores.

---

## Controls
- **Press Enter** to roll the dice on your turn.
- **Press `y` or `n`** when asked to replay or view records.

---


