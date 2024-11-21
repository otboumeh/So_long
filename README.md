# So Long

## Overview

The **So Long** project is a game inspired by the classic Super Mario style. The goal is to create a simple 2D game using the **42 curriculum**'s framework, focusing on player movement, collision detection, and interaction with objects within the game world. The project is designed to practice fundamental concepts of **graphic rendering**, **event handling**, and **user interface** development.

---

## Features

- **Player Movement**: Control a character using the keyboard (e.g., arrows or WASD keys).
- **Graphics Rendering**: Display the character and the environment in a window using a graphics library (like MiniLibX).
- **Collision Detection**: Handle interactions between the character and obstacles or boundaries.
- **Game Loop**: Continuously update the game state and render new frames.
- **Game Environment**: A level consisting of various blocks, platforms, and collectible items.

---

## Functions Implemented

- `init_game`: Initializes the game window and sets up the initial game state.
- `render`: Draws the game environment and updates the player’s position.
- `move_player`: Moves the player based on keyboard inputs (e.g., left, right, jump).
- `collision_detection`: Detects collisions between the player and other game elements.
- `check_win`: Checks if the player has reached the goal.
- `game_over`: Ends the game if the player falls off the screen or hits an obstacle.

---

## Game Mechanics

1. **Player Controls**:
   - Arrow keys or WASD to move left, right, or jump.
   - The objective is to navigate through the level, avoid obstacles, and reach the end goal.
   
2. **Collision Detection**:
   - The game checks for collisions with platforms and obstacles, ensuring that the player cannot move through them.

3. **Game Loop**:
   - The game runs in a continuous loop where it waits for player input, updates the game state, and re-renders the screen.

---

## How to Play

1. Compile the program:
   ```bash
   make
2. Run the game:
   ```bash
   ./so_long map.ber
2. Use the keyboard keys to move and navigate the character across the game world.

3. Complete the level by reaching the exit without falling off or hitting obstacles.

---

## Conclusion

The **So Long** project is a fun and challenging introduction to creating 2D games and handling game logic. It provides hands-on experience with game design, graphics, and programming logic, while also helping you learn to manage user input and create a smooth interactive experience. Completing this project will help you sharpen your skills in C and enhance your understanding of low-level game development techniques.

