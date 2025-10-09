# 🎮 Pong com Arduino

![Status](https://img.shields.io/badge/status-conclu%C3%ADdo-brightgreen)
![Tecnologia](https://img.shields.io/badge/tecnologia-HTML%2FCSS%2FJS-blue)
![Hardware](https://img.shields.io/badge/hardware-Arduino-cyan)

Um projeto que recria o clássico jogo Pong, mas com um diferencial: a raquete do jogador é controlada em tempo real por uma placa Arduino utilizando um potenciômetro. A interface do jogo foi desenvolvida com HTML, CSS e JavaScript puro, e a comunicação com o hardware é feita através da Web Serial API.

---

### 🕹️ Demonstração do Jogo


![Demo do Jogo](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExd25kaDN0cHc1cWF2cmZudG1pb2Q2ZDBzbXF6cG1sYjZudWw0b2ZmayZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/L115Z3zIqN3x5iS2j/giphy.gif)

---

### ✨ Funcionalidades

* **Controle Real com Arduino:** A raquete do jogador é controlada com precisão por um potenciômetro.
* **Calibração Automática:** Ao conectar a placa, o jogo calibra automaticamente os valores mínimo e máximo do potenciômetro, garantindo que a raquete use 100% da área útil da tela.
* **Movimento Suave:** A raquete possui um sistema de suavização de movimento para uma jogabilidade mais fluida e controlável.
* **Inteligência Artificial Simples:** Um oponente (CPU) que reage aos movimentos da bola.
* **Sistema de Pontuação:** O jogo termina quando um dos jogadores atinge 3 pontos, com uma tela de vitória.
* **Pausa e Reinício:** Controles completos para pausar, retomar e iniciar uma nova partida.
* **Interface Retro:** Visual inspirado nos jogos clássicos dos anos 80.

---

### 🛠️ Tecnologias e Hardware Utilizados

#### Hardware
| Componente | Imagem | Descrição |
| :--- | :---: | :--- |
| **PC / Notebook** | | Um computador para rodar a interface (jogo) e a Arduino IDE. |
| **Arduino Uno / Funduino** | <img src="https://upload.wikimedia.org/wikipedia/commons/3/38/Arduino_Uno_-_R3.jpg" width="150"> | A placa microcontroladora principal. (Funduino é um clone compatível com o Arduino Uno). |
| **Cabo USB A-B** | <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cb/USB_A_to_B.jpg/256px-USB_A_to_B.jpg" width="150"> | O cabo azul padrão para conectar o Arduino ao computador. |
| **Protoboard, Potenciômetro e Botão** | | Para montar o circuito de controle do jogador. |

#### Software
* **HTML5**
* **CSS3** (Puro, sem frameworks)
* **JavaScript** (Puro, com estrutura de classes)
* **Web Serial API** (Para a comunicação entre o navegador e a placa)
* **Arduino IDE** (Para gravar o código C++ na placa)
* **Visual Studio Code** (Para desenvolver a interface do jogo)

---

### 🚀 Como Jogar

Siga os passos abaixo para rodar o projeto.

#### 1. Montagem do Circuito
Conecte os componentes na sua placa Arduino/Funduino da seguinte forma:
* **Potenciômetro:**
    * Pino do meio → `A0`
    * Um pino lateral → `5V`
    * Outro pino lateral → `GND`
* **Botão (Push-button):**
    * Um terminal → `Pino 2`
    * Outro terminal → `GND`

#### 2. Gravar o Código na Placa
1.  Abra o arquivo `pong_controller.ino` na **Arduino IDE**.
2.  Conecte a sua placa no computador com o cabo USB.
3.  Selecione a placa e a porta correta no menu `Ferramentas`.
4.  Clique no botão **"Carregar"** (seta para a direita) para gravar o código.

#### 3. Iniciar o Jogo
1.  Abra o arquivo `pong.html` em um navegador compatível (**Google Chrome** ou **Microsoft Edge**).
2.  Clique no botão **"CONECTAR ARDUINO"** e selecione a porta serial em que sua placa está conectada.
3.  **CALIBRAÇÃO:** Assim que conectar, o status mudará para "Calibrando...". Você terá 5 segundos para **girar o potenciômetro de um extremo ao outro** várias vezes.
4.  Após a calibração, clique em **"INICIAR JOGO"** ou aperte o botão na sua protoboard.

**Pronto! Agora é só jogar.**
