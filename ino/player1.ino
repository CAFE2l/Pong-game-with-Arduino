/*
 * PONG - ARDUINO JOGADOR 1 (Joystick Shield)
 * Hardware:
 * - Joystick (Eixo Y) no pino A1
 * - Botão (do Joystick) no pino 2
 * Lógica:
 * - Lê A1 (vertical) em vez de A0.
 * - Envia "P1:valor"
 * - Envia "BTN:1"
 */

// --- Pinos ---
// MUDANÇA: Joystick Y-axis é geralmente A1
const int potPin = A1; 
const int buttonPin = 2;

// --- Configurações de Suavização (Potenciômetro) ---
const int NUM_READINGS = 8;
const int MIN_CHANGE = 3; 

int readings[NUM_READINGS];
int readIndex = 0; 
long total = 0; 
int smoothedValue = 0; 
int lastSentValue = -1; 

// --- Configurações do Botão ---
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); 

  int initialReading = analogRead(potPin);
  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = initialReading;
    total += initialReading;
  }
}

void loop() {
  // === 1. SUAVIZAÇÃO DO POTENCIÔMETRO (lendo A1) ===
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(potPin); // Lê A1
  total = total + readings[readIndex];
  smoothedValue = total / NUM_READINGS;
  readIndex = (readIndex + 1) % NUM_READINGS;

  // === 2. PROCESSAMENTO DO BOTÃO ===
  buttonState = (digitalRead(buttonPin) == LOW);
  if (buttonState && !lastButtonState) {
    Serial.println("BTN:1");
  }
  lastButtonState = buttonState;

  // === 3. ENVIO DOS DADOS DO POTENCIÔMETRO ===
  if (abs(smoothedValue - lastSentValue) >= MIN_CHANGE) {
    Serial.print("P1:");
    Serial.println(smoothedValue);
    lastSentValue = smoothedValue;
  }
  
  delay(20); 
}