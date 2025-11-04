/*
  CÓDIGO PONG - JOGADOR 1
  - Envia dados como "P1:valor"
  - Envia o botão como "BTN:1"
*/

// --- Pinos ---
const int POT_PIN = A0;   // Eixo Y (VRy) do Joystick
const int BTN_PIN = 2;    // Botão (SW) do Joystick

// --- Controle do Botão ---
int lastBtnState = HIGH; // Estado anterior (HIGH = solto)

void setup() {
  Serial.begin(9600);
  
  // Botão com resistor interno (conecte o pino SW ao GND)
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
  
  // --- Leitura do Joystick ---
  int potValue = analogRead(POT_PIN);
  
  // Envia o valor de P1
  Serial.print("P1:");
  Serial.println(potValue);

  // --- Leitura do Botão ---
  int btnState = digitalRead(BTN_PIN);
  
  // Checa se o botão FOI pressionado (transição de HIGH para LOW)
  if (btnState == LOW && lastBtnState == HIGH) {
    Serial.println("BTN:1");
    delay(50); // Anti-debounce
  }
  lastBtnState = btnState; // Salva o estado atual
  
  // Delay para estabilidade
  delay(20);
}