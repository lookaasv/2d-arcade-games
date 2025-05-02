# 🎮 2D Arcade Games - C++ Game Suite

Un proiect educațional ce conține reinterpretări ale jocurilor clasice **Pong**, **Breakout** și **Snake**, dezvoltate în C++ folosind biblioteca grafică **Raylib**. Proiectul a fost realizat ca parte a examenului de atestare profesională la informatică.

## 📦 Conținutul Proiectului

- **Pong** – Joc de tenis clasic cu coliziuni, scor, efecte vizuale și interactivitate sporită prin particule.
- **Breakout (Arkanoid)** – Joc cu niveluri și posibilități de extindere (caracteristici precum power-ups, scoruri, sunete).
- **Snake** – Joc clasic unde șarpele crește și jocul devine progresiv mai rapid.
- **Sorting Visualizer** – Vizualizare interactivă a algoritmilor Quick Sort, Bubble Sort și Selection Sort.

## 🛠️ Tehnologii Utilizate

- **C++** – limbajul principal de implementare
- **[Raylib](https://www.raylib.com/)** – bibliotecă C/C++ pentru grafică 2D/3D
- Programare orientată pe obiecte, procedurală și funcțională

## 🖼️ Caracteristici Notabile

- Folosirea de **particule** pentru efecte vizuale dinamice (ex: explozii, coliziuni)
- Cod structurat modular, comentat și ușor de extins
- Control prin tastatură
- FPS ajustabil prin funcția `SetTargetFPS` pentru controlul dificultății
- Posibilitatea de extindere: tabele de scor, sunet, nivele noi, moduri de joc

## 🔧 Cerințe de sistem

### Hardware:
- Calculator cu placă grafică ce suportă 2D rendering
- RAM minimă (proiectul este lightweight)

### Software:
- Un compilator C++ (ex: GCC, MSVC)
- Biblioteca [Raylib](https://www.raylib.com/): poate fi instalată prin manageri de pachete (vcpkg, brew, etc.)

## ▶️ Compilare și rulare

### Linux/macOS:
```bash
g++ -o breakout breakout.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./breakout
```

### Windows (cu MSVC):
```bash
g++ -o breakout.exe breakout.cpp -lraylib -lopengl32 -lgdi32 -lwinmm
breakout.exe
```


## 📚 Referințe și resurse

- [Raylib Documentation](https://www.raylib.com/)
- [freeCodeCamp C++ Tutorial](https://www.youtube.com/watch?v=vLnPwxZdW4Y)
- [Programarea orientată pe obiecte în C++](https://en.cppreference.com/)
- [Particule în grafica 2D](#)
