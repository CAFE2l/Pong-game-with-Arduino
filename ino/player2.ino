/*
 * PONG - ARDUINO JOGADOR 2 (Direita)
 * * Hardware:
 * - 1 Potenciômetro no pino A0 (do *segundo* Arduino)
 * * Lógica:
 * - Usa suavização (média móvel) para o potenciômetro.
 * - Envia "P2:valor" apenas quando o valor muda significativamente.
 */

// --- Pinos ---
const int potPin = A0;

// --- Configurações de Suavização (Potenciômetro) ---
const int NUM_READINGS = 8; // Número de leituras para a média móvel
const int MIN_CHANGE = 3;   // Mudança mínima para enviar novos dados (evita ruído)

int readings[NUM_READINGS]; // Array para guardar as leituras
int readIndex = 0;          // O índice da leitura atual
long total = 0;             // A soma das leituras
int smoothedValue = 0;      // O valor suavizado (média)
int lastSentValue = -1;     // O último valor enviado

void setup() {
  Serial.begin(9600);

  // Inicializa o array de leituras com o valor atual
  int initialReading = analogRead(potPin);
  for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = initialReading;
    total += initialReading;
  }
}

void loop() {
  // === 1. SUAVIZAÇÃO DO POTENCIÔMETRO ===
  
  // Remove a leitura mais antiga do total
  total = total - readings[readIndex];
  
  // Faz a nova leitura e a armazena
  readings[readIndex] = analogRead(potPin);
  
  // Adiciona a nova leitura ao total
  total = total + readings[readIndex];
  
  // Calcula a média
  smoothedValue = total / NUM_READINGS;
  
  // Avança para o próximo índice
  readIndex = (readIndex + 1) % NUM_READINGS;

  // === 2. ENVIO DOS DADOS DO POTENCIÔMETRO ===
  
  // Só envia os dados para o PC se houver uma mudança significativa
  if (abs(smoothedValue - lastSentValue) >= MIN_CHANGE) {
    Serial.print("P2:"); // <--- MUDANÇA IMPORTANTE
    Serial.println(smoothedValue);
    lastSentValue = smoothedValue; // Atualiza o último valor enviado
  }

  // Delay para estabilidade. 20ms = ~50 leituras por segundo
  delay(20); 
}