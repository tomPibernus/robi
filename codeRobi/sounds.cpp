// Sonidos.cpp
#include "Sounds.h" // Conectamos con nuestro header
#include "config.h"
// Aquí IMPLEMENTAMOS las funciones

void sonidoTriste(int pin) {
   for (int i = 0; i < 20; i++) {
      int tonoRandom = random(500, 2000);
      tone(pin, tonoRandom);
      delay(10);
    }
    noTone(pin);
  
}