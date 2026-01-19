#include <iostream>
#include <windows.h>
#include <ctime>
#include "GameRound.h" // Podłączamy naszą klasę gry

int main() {
    // Ustawienie kodowania
    SetConsoleOutputCP(CP_UTF8);
    
    // Inicjalizacja generatora liczb losowych
    srand(time(0));

    // Tworzymy obiekt rundy i uruchamiamy grę
    GameRound game;
    game.start();

    // Pauza, żeby okno się nie zamykało (opcjonalnie)
    system("pause"); 
    return 0;
}