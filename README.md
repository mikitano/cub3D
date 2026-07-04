*This project has been created as part of the 42 curriculum by mkitano, namatias.*

# cub3D

A simple 3D raycasting engine inspired by the original Wolfenstein 3D, developed using C and the MLX42 graphics library.

---

# Description

cub3D is a graphics programming project from the 42 curriculum whose objective is to build a real-time first-person renderer using the **Raycasting** technique.

Instead of using a 3D graphics API such as OpenGL or Vulkan, the engine projects a 2D map into a pseudo-3D environment by casting one ray per screen column and computing the distance to the nearest wall.

The project focuses on:

- Computer graphics fundamentals
- Raycasting mathematics
- Real-time rendering
- Event handling
- Texture mapping
- Memory management
- Performance optimization

The engine parses a configuration file (`.cub`) describing the map, wall textures, floor/ceiling colors and the player's initial position before rendering the world.

---

# Features

### Mandatory

- Raycasting renderer
- Textured walls
- Floor and ceiling colors
- WASD movement
- Left/Right camera rotation
- Collision detection
- Map parser and validation
- PNG textures
- ESC and window close support

### Bonus

- Mouse rotation
- Minimap
- Additional performance optimizations

---

# Controls

| Key | Action |
|------|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| SHIFT | Run |
| N | Show minimap |
| ← / → | Rotate camera |
| M | Active mouse rotate |
| Mouse | Rotate camera (bonus) |
| ESC | Exit game |

---

# Project Structure

```text
cub3D/
├── include/
├── src/
├── lib/
│   ├── libft/
│   └── MLX42/
├── textures/
├── maps/
├── Makefile
└── README.md
```

---

# Instructions

## Requirements

- Linux
- C compiler (gcc or clang)
- CMake (required by MLX42)
- GLFW dependencies

## Clone

```bash
git clone https://github.com/mikitano/cub3D
cd cub3D
```

## Compile

```bash
make
```

## Run

```bash
./cub3D maps/example.cub
```

---

# Map Format

The engine expects a `.cub` configuration file containing:

- North texture
- South texture
- East texture
- West texture
- Floor color
- Ceiling color
- Map layout

Example:

```text
NO textures/north.png
SO textures/south.png
WE textures/west.png
EA textures/east.png

F 100,100,100
C 40,100,255

111111111
100000001
10N000001
100000001
111111111
```

---

# Technical Overview

The rendering pipeline follows these steps every frame:

1. Read player input
2. Update movement and rotation
3. Cast one ray for each screen column
4. Compute wall distance
5. Select the correct texture
6. Draw textured walls
7. Draw optional minimap
8. Display the rendered image

---

# Technologies

- C
- MLX42
- GLFW
- libft

---

# Performance Notes

Several optimizations were implemented during development, including:

- Direct pixel buffer manipulation instead of `mlx_put_pixel()`
- Reduced floating-point operations where possible
- Cached rendering calculations
- Efficient minimap rendering
- Single image buffer reused every frame

---

# Resources

### Raycasting

- https://lodev.org/cgtutor/raycasting.html
- https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/
- https://www.youtube.com/watch?v=gYRrGTC7GtA

### Graphics

- MLX42 Documentation
- GLFW Documentation

### Mathematics

- Vector algebra
- Trigonometry
- Camera plane projection

---

# AI Usage

Artificial Intelligence was used as a learning and productivity tool during the development of this project.

It assisted with:

- understanding raycasting mathematics;
- discussing rendering algorithms;
- explaining graphics concepts;
- improving documentation.

All design decisions, implementation, debugging, testing, and final code integration were carried out manually.

---

# License

This project was developed for educational purposes as part of the 42 curriculum.
