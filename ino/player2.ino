/*
  CÓDIGO PONG - JOGADOR 2
  - Envia dados como "P2:valor"
  - (O botão não é usado pelo JavaScript)
*/

// --- Pinos ---
const int POT_PIN = A0;   // Eixo Y (VRy) do Joystick

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // --- Leitura do Joystick ---
  int potValue = analogRead(POT_PIN);
  
  // Envia o valor de P2
  Serial.print("P2:");
  Serial.println(potValue);
  
  // Delay para estabilidade
  delay(20);
}