#include "Player.h"
#include <iostream>

// 1. KONSTRUKTOR: ustawianie wartości początkowych
// Podobnie jak w CS:GO: 100 HP, 100 pancerza (do testów), 800 dolarów na start
Player::Player() {
    health = 100;
    armor = 100;    // Dajemy pancerz na start do celów testowych
    money = 800;    // Kapitał początkowy
    accuracy = 1.0f;
}

// 2. Metoda ZAKUPU
void Player::buy(Weapon w) {
    int cost = w.getPrice(); // Pytamy obiekt broni o cenę

    if (money >= cost) {
        money -= cost;          // Odejmowanie funduszy
        inventory.push_back(w); // Dodawanie broni do ekwipunku (vector)
        std::cout << "[SKLEP] Kupiono: " << w.getName() << ". Pozostało: $" << money << std::endl;
    } else {
        std::cout << "[SKLEP] Brak funduszy na " << w.getName() << "! (Potrzeba: $" << cost << ")" << std::endl;
    }
}

// 3. Metoda OTRZYMYWANIA OBRAŻEŃ
void Player::takeDamage(int dmg) {
    // Prosta mechanika: pancerz pochłania 50% obrażeń
    int damageToHealth = dmg;

    if (armor > 0) {
        int absorbed = dmg / 2;          // Połowa obrażeń idzie w pancerz
        damageToHealth = dmg - absorbed; // Reszta idzie w punkty życia (HP)
        
        armor -= absorbed;
        if (armor < 0) armor = 0;        // Pancerz nie może być ujemny
    }

    health -= damageToHealth;
    if (health < 0) health = 0;          // HP nie może spaść poniżej zera

    std::cout << "[WALKA] Otrzymano obrażenia: " << dmg << ". (HP: " << health << " | Pancerz: " << armor << ")" << std::endl;
}

// 4. Wyświetlanie statusu
void Player::printStatus() {
    std::cout << "--- GRACZ: HP " << health << " | PANCERZ " << armor << " | PORTFEL $" << money << " ---" << std::endl;
}