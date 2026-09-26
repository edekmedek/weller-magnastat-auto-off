# Weller Magnastat Auto-Off

Automatsko gasenje grijaca stare Weller Magnastat lemne stanice kada rucka ostane u stalku.

## Kako radi

- Rucka izvan stalka: grijanje je ukljuceno
- Rucka na stalku: reed kontakt se zatvara i built-in LED svijetli
- Pokrece se timer od 10 minuta
- Nakon 10 minuta relej iskljucuje grijac
- Podizanjem rucke grijac se odmah ponovno ukljucuje i timer se resetira

## Hardver

- Weller Magnastat lemna stanica
- Napon grijaca: 25.3 VAC
- Arduino Nano ATmega328P / CH340
- Processor: ATmega328P (Old Bootloader)
- HW-482 5 V relay module
- Reed kontakt i magnet
- 5 V napajanje za Nano i relej

## Spojevi

Reed kontakt: D2 - reed - GND

Relej: D7 - IN, 5V - VCC, GND - GND

Built-in LED D13 pokazuje stanje reed kontakta.

Jedan vod 25.3 VAC prema grijacu prekida se preko COM/NO kontakata releja.

## Pinovi

- D2: reed kontakt (INPUT_PULLUP)
- D7: relej
- D13: built-in LED
- Auto-off: 600000 ms / 10 minuta

## Program

Arduino program nalazi se u: weller-auto-off/weller-auto-off.ino

## Sigurnost

Arduino i relejni modul napajaju se s 5 V. Relej prekida 25.3 VAC vod grijaca. Originalna Weller Magnastat regulacija temperature ostaje nepromijenjena.
