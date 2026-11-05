#include <Servo.h>

Servo meuServo;
int pinoServo = 10;

void setup() {
  meuServo.attach(pinoServo);
}

void loop() {
  // Girar devagar de 0° até 180°
  for (int angulo = 0; angulo <= 180; angulo += 1) {
    meuServo.write(angulo);
    delay(15); // Aumente este valor (ex: 30) para deixar mais lento, ou diminua para ser mais rápido
  }

  delay(500);

  // Girar devagar de 180° de volta para 0°
  for (int angulo = 180; angulo >= 0; angulo -= 1) {
    meuServo.write(angulo);
    delay(15); // Ajuste a velocidade aqui também
  }

  delay(500);
}
