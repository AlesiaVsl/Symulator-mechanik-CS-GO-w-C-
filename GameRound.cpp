#include "GameRound.h"
#include <iostream>
#include <windows.h> // Do pauzy i kolorów (opcjonalnie)

void GameRound::start() {
    std::cout << "=== SYMULATOR CS:GO: RUNDA 1 ===" << std::endl;

    // 1. Tworzenie graczy
    Player me;      // Ty
    Player enemy;   // Przeciwnik (Bot)

    // Wyświetlamy status początkowy
    std::cout << "\n[GRACZ] Dołączono do gry." << std::endl;
    me.printStatus();

    // 2. Faza Zakupów (Buy Phase)
    std::cout << "\n--- FAZA ZAKUPÓW ---" << std::endl;
    
    // Tworzymy dostępne bronie
    Weapon glock("Glock-18", 15, 20, 0.5f, 200);
    Weapon deagle("Desert Eagle", 40, 7, 2.0f, 700);
    Weapon ak47("AK-47", 35, 30, 1.5f, 2700);

    // Próba zakupu
    me.buy(deagle); // Kupujemy Deagle'a
    me.buy(ak47);   // Próbujemy kupić AK-47 (nie powinno starczyć pieniędzy)

    // 3. Faza Walki (Combat Phase)
    int distance = 30; // Dystans 30 metrów
    std::cout << "\n--- FAZA WALKI (Dystans: " << distance << "m) ---" << std::endl;

    // Robimy 3 strzały
    for (int i = 1; i <= 3; i++) {
        std::cout << "\nStrzal " << i << ":" << std::endl;
        
        // Strzelamy z Deagle'a (broń pod indeksem 0 w ekwipunku)
        // Uwaga: w prawdziwej grze wybralibyśmy broń, tutaj upraszczamy
        deagle.shoot(); 

        // Sprawdzamy trafienie (Fizyka)
        bool isHit = hitTarget(distance, deagle.getRecoil());

        if (isHit) {
            std::cout << ">>> TRAFIENIE! Przeciwnik otrzymuje obrażenia." << std::endl;
            enemy.takeDamage(deagle.getDamage());
        } else {
            std::cout << ">>> PUDŁO! Pocisk minął cel." << std::endl;
        }
    }

    // 4. Wynik rundy (Win Conditions)
    std::cout << "\n--- WYNIK RUNDY ---" << std::endl;
    enemy.printStatus(); // Pokaż HP przeciwnika
}