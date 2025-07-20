# 🐍 Snake Game in C (Console Version with Sound)

A retro-style **Snake Game** written in C for Windows Console.  
Includes colorful visuals, lifelines, background music, and sound effects for an enhanced experience.

---

## 🎮 Features

- ⬆️ Keyboard-controlled snake movement using arrow keys
- 💥 Sound effects for eating, collision, and game over
- 🎵 Background music menu and during gameplay
- 🧱 Game border, pause/resume, and dynamic snake growth
- ❤️ 3 Lifelines for extended gameplay
- 💾 Score recording with player name and timestamp
- 📜 View past scores in the Game Records

---

## 🧱 Built With

- **C (Standard Library)**
- **Windows.h**, **conio.h**, and **mmsystem.h** for console control and sound playback

---

## 🖥️ How to Run

### 🛠 Prerequisites
- Windows OS
- Code::Blocks, Turbo C++, or any C-compatible compiler on Windows
- Add `winmm.lib` to your linker settings if using GCC/MinGW: -lwinmm


### ▶️ Running the Game

1. Clone or download this repository
2. Open the `.c` file in your C compiler/IDE
3. Build and run the project

> **NOTE:** Make sure the following sound files are placed at the correct paths (or update them in code):
- `mainmenu.wav`
- `eat.wav`
- `bite.wav`
- `over.wav`

| Key         | Action                           |
|-------------|----------------------------------|
| Arrow Keys  | Move the snake                   |

Example folder path:
## 📝 Score Recording

All player scores with names and timestamps are saved in a local file:

```txt
Game_Records.txt
    
# 📘 Function Reference Table

| Function             | Description                       |
| -------------------- | --------------------------------- |
| `playGame()`         | Main game loop with snake logic   |
| `recordScore()`      | Saves score to `Game_Records.txt` |
| `displayGameScore()` | Displays all recorded scores      |
| `displayMenu()`      | Handles main menu interaction     |
| `boundary()`         | Draws the game boundary           |
| `playSound()`        | Plays sound asynchronously        |
| `gotoxy()`           | Moves console cursor to (x, y)    |
| `hideCursor()`       | Hides blinking console cursor     |
| `setConsoleColor()`  | Sets text color in console        |
```

## 🎥 Demo

Here’s a quick look at the Snake Game in action:

### 🐍 Gameplay Preview

![Snake Game Demo](demo.gif)

> 📌 The snake moves with arrow keys, eats the food, and grows in length. If it hits the boundary or itself, the game ends — unless you have lifelines!

---

### 📸 Screenshots

#### Main Menu

![Main Menu](screenshot1.png)

#### In-Game Action

![Gameplay](screenshot2.png)

#### Game Over Screen

![Game Over](screenshot3.png)

---


