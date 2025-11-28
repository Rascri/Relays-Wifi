#define BLYNK_TEMPLATE_ID "TMPL2SgIi-Kc7"
#define BLYNK_TEMPLATE_NAME "Reles prueba"
#define BLYNK_AUTH_TOKEN "bJogUwkKQrASJBxMelGFpjztskc9dCYJ"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "wifi de rafa";
char pass[] = "*******";

// Pines de relés
#define RELAY4 16
#define RELAY3 17
#define RELAY2 23
#define RELAY1 32

void setup()
{
  Serial.begin(115200);

  // Inicializar pines como salida
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Apagar todos los relés por defecto (0)
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  // Conexión a WiFi + Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Control individual desde Blynk
BLYNK_WRITE(V0) {
  digitalWrite(RELAY1, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(RELAY2, param.asInt());
}

BLYNK_WRITE(V2) {
  digitalWrite(RELAY3, param.asInt());
}

BLYNK_WRITE(V3) {
  digitalWrite(RELAY4, param.asInt());
}

void loop()
{
  Blynk.run();
}
