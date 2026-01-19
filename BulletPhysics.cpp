#include "BulletPhysics.h"
#include <cstdlib> // Do generatora liczb losowych (rand)
#include <iostream>

bool hitTarget(int distance, float recoil) {
    // 1. Bazowa szansa na trafienie (100%)
    int chance = 100;

    // 2. Im większy dystans i odrzut, tym mniejsza szansa
    // Wzór: Szansa = 100 - (Dystans * Odrzut)
    // Przykład: Dystans 20m, Odrzut 1.5 -> Kara 30% -> Szansa 70%
    int penalty = (int)(distance * recoil);
    chance -= penalty;

    // Minimalna szansa to zawsze 10% (łut szczęścia), jeśli cel jest bardzo daleko
    if (chance < 10) chance = 10;

    // 3. Losujemy liczbę (od 0 do 99)
    int randomValue = rand() % 100;

    // 4. Jeśli wylosowana wartość jest mniejsza niż nasza szansa — trafiliśmy
    if (randomValue < chance) {
        return true; 
    } else {
        return false;
    }
}