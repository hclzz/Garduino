#include <Servo.h>

// Definindo os pinos dos LEDs
const int ledVerde = 3;
const int ledAmarelo = 4;
const int ledVermelho = 5;

// Definindo o pino do sensor de umidade do solo
const int sensorUmidade = A0;

// Definindo o pino do servo motor e criando o objeto do servo
const int servoPin = 6;
Servo servoMotor;

// Definindo o pino do relé que controla a bomba de água
const int bombaPin = 7;

// Definindo os limites de umidade para os LEDs
const int limiteUmido = 600;    // Acima desse valor, o solo está úmido (LED verde)
const int limiteModerado = 400; // Entre esse valor e limiteUmido, o solo está moderado (LED amarelo)

void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Configurando o pino do relé como saída
  pinMode(bombaPin, OUTPUT);

  // Inicializando o servo motor no pino especificado
  servoMotor.attach(servoPin);

  // Iniciando a comunicação serial para monitorar o valor do sensor (opcional)
  Serial.begin(9600);

  // Posicionando o servo em estado fechado inicialmente
  servoMotor.write(0); // 0 graus, assumindo que essa posição fecha a válvula

  // Inicializando a bomba desligada
  digitalWrite(bombaPin, HIGH); // Desliga a bomba (sinal HIGH desativa o relé)
}

void loop() {
  // Lendo o valor do sensor de umidade
  int leituraUmidade = analogRead(sensorUmidade);

  // Exibindo o valor da umidade no monitor serial (opcional)
  Serial.print("Umidade do solo: ");
  Serial.println(leituraUmidade);

  // Condições para acender o LED apropriado com base na umidade
  if (leituraUmidade >= limiteUmido) {
    // Solo úmido
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

    // Fechando a válvula de água e desligando a bomba
    servoMotor.write(0); // Servo na posição fechada (0 graus)
    digitalWrite(bombaPin, HIGH); // Desliga a bomba (sinal HIGH desativa o relé)
    
  } else if (leituraUmidade >= limiteModerado) {
    // Umidade moderada
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

    // Fechando a válvula de água e desligando a bomba
    servoMotor.write(0); // Servo na posição fechada (0 graus)
    digitalWrite(bombaPin, HIGH); // Desliga a bomba (sinal HIGH desativa o relé)

  } else {
    // Solo seco
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    // Abrindo a válvula de água e ligando a bomba
    servoMotor.write(90); // Servo na posição aberta (90 graus)
    digitalWrite(bombaPin, LOW); // Liga a bomba (sinal LOW ativa o relé)
  }

  // Atraso para evitar leituras muito frequentes
  delay(1000);
}
