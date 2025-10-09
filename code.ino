// Pong Controller - Arduino
// Controles: 2 potenciômetros (um para jogador, outro não usado) + 1 botão
const int potPin1 = A0; // Potenciômetro para jogador
const int potPin2 = A1; // Potenciômetro extra (não usado no jogo atual)
const int buttonPin = 2; // Botão para iniciar
// Configurações de suavização
const int NUM_READINGS = 8; // Número de leituras para média
const int MIN_CHANGE = 3; // Mudança mínima para enviar dados
int playerPos = 0;
int unusedPot = 0;
bool buttonState = false;
bool lastButtonState = false;
// Arrays para suavização
int readings[NUM_READINGS];
int readIndex = 0;
long total = 0;
int smoothedValue = 0;
int lastSentValue = -1;
void setup() {
Serial.begin(9600);
pinMode(buttonPin, INPUT_PULLUP);
// Inicializa o array de leituras com valores neutros
    int initialReading = analogRead(potPin1);
    for (int i = 0; i < NUM_READINGS; i++) {
    readings[i] = initialReading;
    total += initialReading;
}
// Envia sinal de inicialização
Serial.println("ARDUINO_READY");
delay(100);
}
void loop() {
// === SUAVIZAÇÃO DO POTENCIÔMETRO ===
// Remove a leitura mais antiga do total
total = total - readings[readIndex];
// Faz nova leitura
readings[readIndex] = analogRead(potPin1);
// Adiciona a nova leitura ao total
total = total + readings[readIndex];
// Calcula a média
smoothedValue = total / NUM_READINGS;
// Avança o índice de leitura
readIndex = (readIndex + 1) % NUM_READINGS;
// === PROCESSAMENTO DO BOTÃO ===
buttonState = digitalRead(buttonPin) == LOW;
// Detecta borda de subida do botão
if (buttonState && !lastButtonState) {
    Serial.println("BTN:1");
}
lastButtonState = buttonState;
// === ENVIO DOS DADOS DO POTENCIÔMETRO ===
// Só envia se houver mudança significativa
if (abs(smoothedValue - lastSentValue) >= MIN_CHANGE) {
    Serial.print("P1:");
    Serial.println(smoothedValue);
    lastSentValue = smoothedValue;
}
delay(20); // Delay reduzido para mais responsividade
}