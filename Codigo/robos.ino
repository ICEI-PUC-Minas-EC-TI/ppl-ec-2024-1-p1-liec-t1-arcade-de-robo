#include <ESP32Servo.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT1;
Servo servoRobo;

bool servoCooldown = false;
unsigned long servoCooldownStart = 0;
const unsigned long servoCooldownDuration = 8000;

const int IN1A = 12;
const int IN2A = 13;
const int IN3B = 14;
const int IN4B = 15;

void setup() {
  Serial.begin(115200);
  SerialBT1.begin("ESP32 - Robo"); // Nome do dispositivo Bluetooth
  Serial.println("O dispositivo iniciou no modo escravo, aguardando um mestre para conectar...");
  pinMode(IN1A, OUTPUT);
  pinMode(IN2A, OUTPUT);
  pinMode(IN3B, OUTPUT);
  pinMode(IN4B, OUTPUT);
  servoRobo.attach(2);
  servoRobo.write(75); // Posição inicial do servo
}

void loop() {
  if (SerialBT1.available() > 0) {
    char received = SerialBT1.read();
    // Atacar balão com micro servo
    if (received == '0' && !servoCooldown) {
      servoRobo.write(135);
      delay(250); // Aguardar o servo atingir a posição
      servoRobo.write(75);
      servoCooldown = true;
      servoCooldownStart = millis();
    } else {
      // Controlar os motores de acordo com o comando recebido
      switch(received) {
        case '1': // Andar para frente
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, HIGH);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, HIGH);
          break;
        case '2': // Andar para frente-direita
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, HIGH);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, LOW);
          break;
        case '3': // Andar para frente-esquerda
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, HIGH);
          break;
        case '4': // Andar para trás
          digitalWrite(IN1A, HIGH);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, HIGH);
          digitalWrite(IN4B, LOW);
          break; 
        case '5': // Andar para trás-direita
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, HIGH);
          digitalWrite(IN4B, LOW);
          break;
        case '6': // Andar para trás-esquerda
          digitalWrite(IN1A, HIGH);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, LOW);
          break;
        case '7': // Virar para direita
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, HIGH);
          digitalWrite(IN3B, HIGH);
          digitalWrite(IN4B, LOW);
          break;
        case '8': // Virar para esquerda
          digitalWrite(IN1A, HIGH);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, HIGH);
          break;
        default: // Parar motores quando nenhum comando é recebido
          digitalWrite(IN1A, LOW);
          digitalWrite(IN2A, LOW);
          digitalWrite(IN3B, LOW);
          digitalWrite(IN4B, LOW);
          break;
      }
    }
  }
  // Verificar se o cooldown do servo terminou
  if (servoCooldown && (millis() - servoCooldownStart >= servoCooldownDuration)) {
    servoCooldown = false;
  }
}
