#include <Stepper.h>

// Define os passos para uma volta completa (360 graus)
const int passosVoltaCompleta = 2048; 

// Calcula os passos para 180 graus (2048 / 2 = 1024)
const int passos180Graus = 1024;
const int passos90Graus = 516;

// Inicializa a biblioteca (Ordem dos pinos: IN1, IN3, IN2, IN4)
Stepper meusStepper(passosVoltaCompleta, 8, 10, 9, 11);

void setup() {
  // Define a velocidade para 12 RPM
  meusStepper.setSpeed(3);
}

void loop() {
  // Gira 180 graus no sentido horário
  meusStepper.step(passos90Graus);
  delay(2000); // Aguarda 2 segundos parado

  // Gira 180 graus no sentido anti-horário
  meusStepper.step(-passos90Graus);
  delay(2000); // Aguarda 2 segundos parado
}
