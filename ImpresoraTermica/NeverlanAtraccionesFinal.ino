
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Thermal.h>
#include <RTClib.h>
#include <Keypad.h>
SoftwareSerial printerSerial(2, 3); // RX, TX
Adafruit_Thermal printer(&printerSerial);
RTC_DS3231 rtc;
const int buttonPin1 = 4;
int buttonState1 = 0;
int counter = 0;
//teclado
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '*'},
  {'4', '5', '6', '#'},
  {'7', '8', '9', 'a'},
  {'0', 'm', 'i', 'd'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {13, 12, 11, 10};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup () {
  printerSerial.begin(19200);
  printer.begin();
  Serial.begin(9600);
  if (!rtc.begin()) {
    printerSerial.println("modulo no!");
  }
  //rtc.adjust(DateTime(__DATE__,__TIME__));
  pinMode(buttonPin1, INPUT_PULLUP);
  printer.wake();
  printer.setDefault();
  //printer.feed(3);
  printer.setSize('M');
  printer.justify('C');
  printerSerial.println("Bienvenido!");
  printer.setCodePage(0);
  printer.feed(3);
}

void loop () {
  char key = keypad.getKey();
  buttonState1 = digitalRead(buttonPin1);
  if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9') {
    char c=key;
    int num = c-'0';
    counter= counter+num;
    //tamaño de letra
    printer.setSize('S');
    //posicion del texto
    printer.justify('L');
    //desde aqui inicia el texto
    printerSerial.println("# Usuarios: " + String(key));
    printer.justify('C');
    printerSerial.println("Juego, bajo estricta\nsupervision de\nun adulto.");
    printer.justify('L');
    printerSerial.print("Fecha: ");
    printDateTime();
    printer.boldOn();
    printerSerial.println("Duracion: 15min");
    printer.boldOff();
    printer.justify('c');
    printerSerial.print("Hora de Entrada: ");
    horaEntrada();
    printerSerial.print("Hora de Salida: ");
    horaSalida();
    printer.justify('L');
    printerSerial.print("-Si se pasa el tiempo\ntendra que cancelar\notra vez.                   ");
    //printerSerial.print("Super Piramide N: ");
    if (counter < 10) {
      printerSerial.print("000");
    } else if (counter < 100) {
      printerSerial.print("00");
    } else if (counter < 1000) {
      printerSerial.print("0");
    }
    printerSerial.println(counter);
    printer.feed(3);
    delay(1000);
  }
  if (buttonState1 == LOW) {
    counter = 0;
    printer.setSize('S');
    printer.justify('C');
    printerSerial.print("Contador reiniciado");
    printer.feed(5);
    delay(1000);
  }
  if (key == 'a') {
    printer.feed(1);
    delay(1000);
  }
}
void printDateTime() {
  DateTime reloj = rtc.now();
  printerSerial.print(reloj.month(), DEC);
  printerSerial.print('/');
  printerSerial.print(reloj.day(), DEC);
  printerSerial.print('/');
  printerSerial.println(reloj.year(), DEC);
}
void horaEntrada() {
  DateTime reloj = rtc.now();
  if (reloj.hour() <= 9) {
    printerSerial.print("0");
  }
  printerSerial.print(reloj.hour(), DEC);
  printerSerial.print(':');
  if (reloj.minute() <= 9) {
    printerSerial.print("0");
  }
  printerSerial.print(reloj.minute(), DEC);
  printerSerial.println("");
}

void horaSalida() {
  DateTime reloj = rtc.now();
  DateTime later = reloj + TimeSpan(0, 0, 17, 0);
  if (later.hour() <= 9) {
    printerSerial.print("0");
  }
  printerSerial.print(later.hour(), DEC);
  printerSerial.print(':');
  if (later.minute() <= 9) {
    printerSerial.print("0");
  }
  printerSerial.print(later.minute(), DEC);
  printerSerial.println("");
}
