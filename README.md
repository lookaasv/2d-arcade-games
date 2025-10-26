# 🎮 2D Arcade Games - C++ Game Suite

An educational project featuring modern reinterpretations of classic **Pong**, **Breakout**, and **Snake** games, built in **C++** using the **Raylib** graphics library. Created as part of a computer science certification project.

## 📦 Project Contents
- **Pong** – Classic tennis game with collisions, score, and particle effects.  
- **Breakout (Arkanoid)** – Includes levels, extendable features (power-ups, sound, scoring).  
- **Snake** – Classic snake game with progressive speed increase.  
- **Sorting Visualizer** – Interactive visualization of Quick Sort, Bubble Sort, and Selection Sort.

## 🛠️ Technologies
- **C++** (main language)  
- **[Raylib](https://www.raylib.com/)** (2D/3D graphics library)  
- Object-oriented, procedural, and functional programming styles  

## 🖼️ Features
- Dynamic **particle effects** (explosions, collisions)  
- Modular and well-commented code  
- Keyboard controls  
- Adjustable FPS using `SetTargetFPS`  
- Easily extendable (scoreboards, levels, sound, modes)

## 🔧 Requirements
**Hardware:** Basic GPU with 2D rendering support  
**Software:** C++ compiler (GCC/MSVC) + [Raylib](https://www.raylib.com/)  

## ▶️ Build & Run

### Linux/macOS:
g++ -o breakout breakout.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./breakout

### Windows (MSVC):
g++ -o breakout.exe breakout.cpp -lraylib -lopengl32 -lgdi32 -lwinmm
breakout.exe

## 📚 References
- [Raylib Documentation](https://www.raylib.com/)
- [freeCodeCamp C++ Tutorial](https://www.youtube.com/watch?v=vLnPwxZdW4Y)
- [C++ Reference](https://en.cppreference.com/)
