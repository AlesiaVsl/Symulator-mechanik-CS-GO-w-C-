#pragma once // Zabezpieczenie przed wielokrotnym dołączeniem pliku
#include <string>

class Weapon {
private:
    std::string name;   // Nazwa broni
    int damage;         // Obrażenia
    int ammo;           // Aktualna amunicja w magazynku
    float recoil;       // Odrzut
    
    int maxAmmo;        // Pojemność magazynka (do pełnego przeładowania)
    int price;          // Cena zakupu

public:
    // Konstruktor: inicjalizuje konkretną broń (np. AK-47, Glock)
    Weapon(std::string n, int d, int a, float r, int p);

    
    void shoot();       // Wykonaj strzał
    void reload();      // Przeładuj broń

    // Gettery (metody dostępowe):
    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    int getPrice() const { return price; }
    float getRecoil() const { return recoil; }
};