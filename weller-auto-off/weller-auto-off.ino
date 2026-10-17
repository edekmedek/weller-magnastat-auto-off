const byte REED_PIN = 2;
const byte RELAY_PIN = 7;
const byte LED_PIN = 13;

const unsigned long VRIJEME_GASENJA = 600000UL; // 10 minuta
const unsigned long DEBOUNCE_MS = 50UL;

bool stabilnoStanje;
bool zadnjeOcitanje;
unsigned long vrijemePromjeneOcitanja = 0;
unsigned long vrijemeZadnjeAktivnosti = 0;

void setup() {
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  pinMode(RELAY_PIN, OUTPUT);

  stabilnoStanje = digitalRead(REED_PIN);
  zadnjeOcitanje = stabilnoStanje;
  digitalWrite(LED_PIN, stabilnoStanje == LOW ? HIGH : LOW);
  vrijemeZadnjeAktivnosti = millis();
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  unsigned long sada = millis();
  bool ocitanje = digitalRead(REED_PIN);

  if (ocitanje != zadnjeOcitanje) {
    zadnjeOcitanje = ocitanje;
    vrijemePromjeneOcitanja = sada;
  }

  if (ocitanje != stabilnoStanje &&
      sada - vrijemePromjeneOcitanja >= DEBOUNCE_MS) {
    stabilnoStanje = ocitanje;
    vrijemeZadnjeAktivnosti = sada;
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(LED_PIN, stabilnoStanje == LOW ? HIGH : LOW);
  }

  if (sada - vrijemeZadnjeAktivnosti >= VRIJEME_GASENJA) {
    digitalWrite(RELAY_PIN, LOW);
  }
}
