#pragma once

// Funkcja przyjmuje dystans do wroga oraz odrzut broni
// Zwraca: true (Trafienie) lub false (Pudło)
bool hitTarget(int distance, float recoil);