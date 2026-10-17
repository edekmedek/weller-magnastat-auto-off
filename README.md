# Weller Magnastat Auto-Off

Automatsko isključivanje grijača Weller Magnastat lemne stanice nakon 10 minuta bez promjene reed kontakta, neovisno o položaju ručke.

## Kako radi

- Pri uključivanju uređaja relej uključuje grijač i pokreće brojač od 10 minuta.
- Svaka promjena reed kontakta (otvaranje ili zatvaranje) resetira brojač na 10 minuta.
- Promjene kontakta kraće od 50 ms ignoriraju se radi sprječavanja lažnih očitanja.
- Ako tijekom 10 minuta nema promjene reed kontakta, relej isključuje grijač.
- Sljedeća promjena reed kontakta ponovno uključuje grijač i pokreće novo odbrojavanje.
- Ugrađena LED na D13 svijetli kada je reed kontakt zatvoren.

Ovakva logika sprječava nepotreban rad grijača kada je ručka nepravilno položena u stalak pa reed kontakt ne registrira njezin položaj.

**Napomena:** Ako se lemilica koristi dulje od 10 minuta bez promjene reed kontakta, grijač će se također isključiti.

## Hardver

- Weller Magnastat lemna stanica
- Napon grijača: 25,3 V AC
- RF Nano / Arduino Nano ATmega328P
- USB-serijski adapter CH340
- Procesor: ATmega328P (Old Bootloader)
- HW-482 relejni modul 5 V
- Reed kontakt i magnet
- Napajanje 5 V za Nano i relej

## Spojevi

| Funkcija | Priključak |
|---|---|
| Reed kontakt | D2 – reed – GND |
| Relej | D7 – IN |
| Napajanje releja | 5 V – VCC, GND – GND |
| Kontrolna LED | D13 |

Jedan vod napajanja grijača od 25,3 V AC prekida se preko COM/NO kontakata releja.

## Parametri programa

- `REED_PIN = 2`
- `RELAY_PIN = 7`
- `LED_PIN = 13`
- `VRIJEME_GASENJA = 600000UL` (10 minuta)
- `DEBOUNCE_MS = 50UL` (filtriranje reed kontakta)

Relej je uključen kada je izlaz D7 HIGH, a isključen kada je LOW.

## Program

Arduino program nalazi se u:

`weller-auto-off/weller-auto-off.ino`

## Testiranje

Nova verzija programa testirana je na RF Nanu 17.10.2026.

- Isključivanje releja nakon 10 minuta bez promjene reed kontakta – uspješno.
- Ponovno uključivanje releja nakon promjene reed kontakta – uspješno.

## Sigurnost

Arduino i relejni modul napajaju se s 5 V. Relej prekida vod grijača od 25,3 V AC. Originalna Weller Magnastat regulacija temperature ostaje nepromijenjena.

Softverski timer nije neovisna sigurnosna zaštita. Potrebno je provjeriti ponašanje releja pri uključivanju, resetiranju i gubitku napajanja Arduina.