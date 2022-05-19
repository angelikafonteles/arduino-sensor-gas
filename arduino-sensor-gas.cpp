// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define PIN_LED_1 	6
#define PIN_LED_2 	5
#define PIN_LED_3 	4
#define PIN_LED_4 	3
#define PIN_LED_5 	2
#define PIN_GAS 	A3


// the setup routine runs once when you press reset:
void setup()  {
  lcd.begin(16, 2);
  lcd.print("SISTEMA DE GAS");
  // initialize the digital pin as an output.
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(PIN_LED_5, OUTPUT);
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  int value = analogRead(PIN_GAS);
  Serial.println(value);
  value = map(value, 300, 750, 0, 100);
  digitalWrite(PIN_LED_1, HIGH);
  digitalWrite(PIN_LED_2, value >= 20 ? HIGH : LOW);
  digitalWrite(PIN_LED_3, value >= 40 ? HIGH : LOW);
  digitalWrite(PIN_LED_4, value >= 60 ? HIGH : LOW);
  digitalWrite(PIN_LED_5, value >= 80 ? HIGH : LOW);
  clear_screen();
  lcd.print("NIVEL: ");
  lcd.print(value);
  lcd.print("%");
  delay(100); // wait for a quarter second
}

void clear_screen(){
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("             ");
  lcd.setCursor(0,1);
}