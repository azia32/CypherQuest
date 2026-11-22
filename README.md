[README.md](https://github.com/user-attachments/files/35239421/README.md)
# CRYPTGAME

A text-based code-breaking game written in C++. The player decrypts a coded word in each of five levels. Each level is harder than the one before it.

## Features

- Five levels with different ciphers.
- Score system. Faster answers give more points.
- Final rank based on score.
- Guesses are not case-sensitive.
- Start menu with input checks.
- ASCII art title banner.

## Requirements

- A C++ compiler that supports C++11 or later (for example, g++ or MSVC).
- Windows is best. The game uses `system("pause")`, which works on Windows only (see Known issues).

## Build and run

Compile with g++:

```
g++ -std=c++11 main.cpp -o cryptgame
```

Run the game:

```
./cryptgame
```

On Windows, run `cryptgame.exe` instead.

## How to play

1. At the menu, press `1` to start or `2` to quit.
2. Read the coded word and the hint on the screen.
3. Type your guess and press Enter.
4. If you are correct, you go to the next level.
5. If you use all your guesses, the game ends.

Complete all five levels to win.

## Levels

| Level | Cipher | Guesses |
|-------|--------|---------|
| 1 | Reversed word | 5 |
| 2 | Caesar cipher (right shift) | 4 |
| 3 | Caesar cipher (shift of less than 5) | 4 |
| 4 | Caesar cipher (left shift) | 4 |
| 5 | Combined: word order, word reversal, and left shift | 4 |

## Scoring

Each level gives a maximum of 25 points. You lose 5 points for each wrong guess before the correct answer.

| Guess number | Points |
|--------------|--------|
| 1st | 25 |
| 2nd | 20 |
| 3rd | 15 |
| 4th | 10 |
| 5th (Level 1 only) | 5 |

The maximum total score is 125.

## Ranks

If you win:

| Score | Rank |
|-------|------|
| 115 or more | Master Cryptbreaker |
| 90 to 114 | Cipher Analyst |
| 65 to 89 | Codebreaker |
| Less than 65 | Survivor |

If you lose:

| Score | Rank |
|-------|------|
| 50 or more | Field Operative |
| 20 to 49 | Novice Decoder |
| Less than 20 | Uninitiated |

## Code structure

| Part | Purpose |
|------|---------|
| `lowercase()` | Changes a string to lowercase for guess checks |
| `reversestring()` | Reverses a string (Level 1 and Level 5) |
| `caesarLeft()` | Shifts letters to the left (Level 4 and Level 5) |
| `showTitle()` and `mainMenu()` | Show the banner and the start menu |
| `getRank()` and `showSummary()` | Find the rank and show the final result |
| `level1()` to `level5()` | Game logic for each level |
| `main()` | Runs the menu and the levels in order |

## Known issues

- `system("pause")` does not work on Linux or macOS. Remove it or replace it with `cin.get();` on those systems.

## Team

| Member | Work |
|--------|------|
| A | Program structure, Levels 2 and 3, start menu, banner, Git repository |
| Usman | Level 1, score algorithm, `lowercase` function |
| Hadi | Levels 4 and 5, `caesarLeft`, `showSummary`, `getRank` |
