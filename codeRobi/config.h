#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

const int echoPin = 5;
const int trigPin = 2;

// Buzzer
const int buzzPin = 8;
// Configuración de Ojos
#define MATRIX_PIN 11

// Face Setup

const int scl = A0;
const int sda = A1;

// Motores
// Motor A (Izquierdo)
#define ENA 9
#define IN1 7
#define IN2 6

// Motor B (Derecho)
#define ENB 10
#define IN3 4
#define IN4 3

#endif