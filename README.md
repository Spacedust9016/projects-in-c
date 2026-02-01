# Tic-Tac-Toe Console Game

A polished console-based Tic-Tac-Toe game written in C with enhanced visuals and smart AI.

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey)

## Features

- **Beautiful Console Graphics** - Box-drawing characters and colored output
- **Smart AI Opponent** - Uses strategic moves (win, block, center, corners)  
- **Color-Coded Display** - Green for player, Red for computer, Yellow info
- **Scoreboard** - Tracks wins, losses, and draws across games
- **Play Again** - Continue playing without restarting
- **Input Validation** - Handles invalid inputs gracefully

## Preview

```
  ╔════════════════════════════════════════════╗
  ║     TIC TAC TOE                            ║
  ╚════════════════════════════════════════════╝

  ┌─────────── SCOREBOARD ───────────┐
  │   Player (X): 2                  │
  │   Computer (O): 1                │
  │   Draws: 0                       │
  └──────────────────────────────────┘

       1     2     3
    ╔═════╦═════╦═════╗
    ║     ║     ║     ║
  1 ║  X  ║     ║  O  ║
    ║     ║     ║     ║
    ╠═════╬═════╬═════╣
    ║     ║     ║     ║
  2 ║     ║  X  ║     ║
    ║     ║     ║     ║
    ╠═════╬═════╬═════╣
    ║     ║     ║     ║
  3 ║  O  ║     ║  X  ║
    ║     ║     ║     ║
    ╚═════╩═════╩═════╝
```

## Compilation

### Windows (GCC/MinGW)
```bash
gcc -o tic_tac_toe tic_tac_toe.c
```

### Linux/macOS
```bash
gcc -o tic_tac_toe tic_tac_toe.c
```

## How to Run

```bash
./tic_tac_toe
```

## Controls

| Input | Description |
|-------|-------------|
| 1-3 | Row number |
| 1-3 | Column number |
| Y/N | Play again prompt |

## AI Strategy

The computer uses a priority-based strategy:

1. **Win** - If it can win, it takes the winning move
2. **Block** - If player can win, it blocks
3. **Center** - Takes center if available
4. **Corners** - Prefers corner positions
5. **Edges** - Takes edge positions last

## Project Structure

```
projects-in-c/
├── tic_tac_toe.c    # Main game source code
├── README.md        # Documentation
└── .gitignore       # Git ignore file
```

## Building from Source

1. Clone the repository:
```bash
git clone https://github.com/spacedust9016/projects-in-c.git
cd projects-in-c
```

2. Compile:
```bash
gcc -o tic_tac_toe tic_tac_toe.c
```

3. Run:
```bash
./tic_tac_toe
```

## Contributing

Feel free to submit issues and pull requests!

---

Enjoy the game!
