#include "Weapon.h"  // Dołączamy nagłówek klasy
#include <iostream>  // Potrzebne do obsługi wyjścia tekstowego (std::cout)

// 1. IMPLEMENTACJA KONSTRUKTORA
// Przypisujemy wartości wejściowe (n, d, a...) do pól klasy (name, damage, ammo...)
Weapon::Weapon(std::string n, int d, int a, float r, int p) 
    : name(n), damage(d), ammo(a), maxAmmo(a), recoil(r), price(p) 
{
    // maxAmmo ustawiamy na wartość 'a', aby wiedzieć ile amunicji przywrócić podczas przeładowania
}

// 2. IMPLEMENTACJA STRZELANIA
void Weapon::shoot() {
    // Sprawdzenie: czy w magazynku jest amunicja?
    if (ammo > 0) {
        ammo--; // Zmniejszamy o 1 (skrót od ammo = ammo - 1)
        
        // Wyświetlamy komunikat o strzale
        std::cout << "Pif-paf! (" << name << ") Amunicja: " << ammo << "/" << maxAmmo << std::endl;
        
        // W tym miejscu można rozbudować logikę o odrzut (recoil)
    } else {
        std::cout << "*Klik*... Magazynek pusty! Naciśnij R, aby przeładować." << std::endl;
    }
}

// 3. IMPLEMENTACJA PRZEŁADOWANIA
void Weapon::reload() {
    std::cout << "Przeładowywanie " << name << "..." << std::endl;
    ammo = maxAmmo; // Przywracamy pełny magazynek
    std::cout << "Gotowe! Amunicja: " << ammo << std::endl;
}