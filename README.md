# Symulator mechanik CS:GO (Projekt zaliczeniowy)

Prosty symulator napisany w języku C++, prezentujący podstawowe mechaniki gier typu FPS, takie jak ekonomia, system strzelania oraz fizyka trafień.

## Struktura Projektu:
- **Weapon**: Klasa odpowiedzialna za atrybuty broni (obrażenia, magazynek, odrzut).
- **Player**: Klasa zarządzająca stanem gracza (HP, pancerz, portfel, ekwipunek).
- **BulletPhysics**: Moduł obliczający trafienie na podstawie dystansu i odrzutu.
- **GameRound**: Klasa kontrolująca logikę rundy (faza zakupów, walka, warunki zwycięstwa).

## Jak uruchomić:
Skompiluj wszystkie pliki za pomocą g++:
```bash
g++ main.cpp weapon.cpp Player.cpp BulletPhysics.cpp GameRound.cpp -o game.exe
.\game.exe
