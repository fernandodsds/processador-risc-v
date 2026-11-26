const int PIN_DATA  = 2;
const int PIN_CLOCK = 3;
const int PIN_LATCH = 4;

String leituraAnterior = "";

void setup() {
  Serial.begin(115200);
  pinMode(PIN_DATA, INPUT_PULLUP);
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_LATCH, OUTPUT);
  
  Serial.println("Aguardando mudanca nos botoes...");
}

void loop() {
  // 1. Envia o pulso de Latch
  digitalWrite(PIN_LATCH, HIGH);
  delayMicroseconds(12);
  digitalWrite(PIN_LATCH, LOW);
  delayMicroseconds(6);

  String leituraAtual = "";

  // 2. Lê os 16 pulsos e monta uma string com o resultado
  for (int i = 0; i < 16; i++) {
    int estado = digitalRead(PIN_DATA);
    leituraAtual += String(estado);

    digitalWrite(PIN_CLOCK, HIGH);
    delayMicroseconds(6);
    digitalWrite(PIN_CLOCK, LOW);
    delayMicroseconds(6);
  }

  // 3. Só imprime na tela se a leitura atual for diferente da anterior
  if (leituraAtual != leituraAnterior) {
    Serial.print("Nova leitura: ");
    Serial.println(leituraAtual);
    leituraAnterior = leituraAtual; // Atualiza o estado guardado
  }

  delay(20); // Pequena pausa para evitar ruído mecânico (debounce)
}
