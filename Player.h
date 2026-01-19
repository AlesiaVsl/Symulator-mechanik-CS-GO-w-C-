#pragma once
#include <vector>     // Potrzebne do stworzenia listy (ekwipunku)
#include "Weapon.h"   

class Player {
private:
    int health;       // Punkty życia (HP)
    int armor;        // Pancerz
    int money;        // Pieniądze
    float accuracy;   // Celność gracza 
    
    
    // Działa jak dynamiczna lista (plecak), do której możemy dodawać nową broń.
    std::vector<Weapon> inventory; 

public:
    // Konstruktor: ustawia początkowe pieniądze i punkty życia
    Player();

    // Metody zdefiniowane w zadaniu:
    void buy(Weapon w);       // Zakup broni
    void takeDamage(int dmg); // Otrzymywanie obrażeń (z uwzględnieniem pancerza)
    
    // Wyświetlanie statusu (aby widzieć stan HP i portfela w konsoli)
    void printStatus();
};