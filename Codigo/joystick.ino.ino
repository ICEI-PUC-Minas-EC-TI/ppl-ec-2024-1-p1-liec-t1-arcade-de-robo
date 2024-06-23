#include <BluetoothSerial.h>

const int left = 19;
const int right = 21;
const int down = 22;
const int up = 23;
const int botao1 = 2;
const int botao2 = 16;
const int botao3 = 26;
const int botao4 = 26;
const int botao5 = 32;
const int botao6 = 34;
const int botao7 = 13;
const int botao8 = 12;
const int botao9 = 5;
const int botao10 = 18;

String toSend;

BluetoothSerial SerialBT1;

uint8_t address[6] = {0x98, 0xF4, 0xAB, 0x65, 0x28, 0x9A}; // Endereço MAC do dispositivo remoto
bool connected = false;

void connectToRemoteDevice() {
  Serial.println("Tentando conectar ao dispositivo remoto...");
  connected = SerialBT1.connect(address);
  if (connected) {
    Serial.println("Conectado com sucesso!");
  } else {
    Serial.println("Falha ao conectar. Tentando novamente...");
    delay(5000); // Espera antes de tentar reconectar novamente
  }
}

void setup() {
  Serial.begin(115200);
  SerialBT1.begin("ESP32test", true); // Inicializa o Bluetooth no ESP32
  
  Serial.println("O dispositivo iniciou no modo mestre, certifique-se de que o dispositivo BT remoto está ligado!");

  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(down, INPUT);
  pinMode(up, INPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);
  pinMode(botao4, INPUT);
  pinMode(botao5, INPUT);
  pinMode(botao6, INPUT);
  pinMode(botao7, INPUT);
  pinMode(botao8, INPUT);
  pinMode(botao9, INPUT);
  pinMode(botao10, INPUT);

  connectToRemoteDevice(); // Função para conectar ao dispositivo remoto
}

void loop() {
  if (!connected) {
    connectToRemoteDevice(); // Reconectar se a conexão for perdida
  }
  else {
    if (digitalRead(down) == HIGH && digitalRead(left) == HIGH){
        SerialBT1.print('6');
    }
    else if (digitalRead(up) == HIGH && digitalRead(left) == HIGH){
        SerialBT1.print('3');
    }
    else if (digitalRead(down) == HIGH && digitalRead(right) == HIGH){
        SerialBT1.print('5');
    }
    else if (digitalRead(up) == HIGH && digitalRead(right) == HIGH){
        SerialBT1.print('2');
    }
    else if (digitalRead(down) == HIGH){
        SerialBT1.print('4');
    }
    else if (digitalRead(up) == HIGH){
        SerialBT1.print('1');
    }
    else if (digitalRead(right) == HIGH){
        SerialBT1.print('7');
    }
    else if (digitalRead(left) == HIGH){
        SerialBT1.print('8');
    }
    else if (digitalRead(botao1) == HIGH){
        SerialBT1.print('0');
        Serial.println("botao");
    }
    else{
        SerialBT1.print('9');
    }
    delay(50);
  }
  connected = SerialBT1.connect(address);
}
