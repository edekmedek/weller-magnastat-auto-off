const byte REED_PIN = 2;
const byte RELAY_PIN = 7;
const byte LED_PIN = 13;

const unsigned long VRIJEME_GASENJA = 600000UL; // 10 minuta

unsigned long vrijemeStavljanja = 0;
bool timerAktivan = false;

void setup() {
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
  bool reedZatvoren = (digitalRead(REED_PIN) == LOW);

  digitalWrite(LED_PIN, reedZatvoren ? HIGH : LOW);

  if (reedZatvoren) {
    if (!timerAktivan) {
      vrijemeStavljanja = millis();
      timerAktivan = true;
    }

    if (millis() - vrijemeStavljanja >= VRIJEME_GASENJA) {
      digitalWrite(RELAY_PIN, LOW);
    }
  } else {
    digitalWrite(RELAY_PIN, HIGH);
    timerAktivan = false;
  }
}
