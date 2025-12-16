#include "config.h"


void moveForward() {
  // Speed Control (0-255)
  analogWrite(ENA, 130); // Motor A Speed
  analogWrite(ENB, 130); // Motor B Speed

  // Motor A Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBack() {
  // Speed Control (0-255)
  analogWrite(ENA, 130); // Motor A Speed
  analogWrite(ENB, 130); // Motor B Speed

  // Motor A Back
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B Back
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
