// Pines de relés
#define RELAY4 16
#define RELAY3 17
#define RELAY2 23
#define RELAY1 32

// Array con los pines de los relés
int relays[] = {RELAY1, RELAY2, RELAY3, RELAY4};
int totalRelays = 4;

void setup() {
  Serial.begin(115200);

  // Configurar pines como salida
  for (int i = 0; i < totalRelays; i++) {
    pinMode(relays[i], OUTPUT);
    digitalWrite(relays[i], LOW);   // iniciar apagados
  }

  Serial.println("Iniciando prueba de relés...");
}

void loop() {

  // Secuencia de encendido uno por uno
  for (int i = 0; i < totalRelays; i++) {

    Serial.print("Prendiendo rele: ");
    Serial.println(i + 1);

    digitalWrite(relays[i], HIGH);  // Encender
    delay(500);                     // Mantener 500 ms

    digitalWrite(relays[i], LOW);   // Apagar
    delay(200);                     // Pequeña pausa
  }
}