#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5,4,3,2);
#include <Ultrasonic.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 13
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
}
void loop(){
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
Serial.print("MS: "); Serial.print(microsec);
Serial.print(", CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
delay(500);

  lcd.setCursor (0,0);
  lcd.print ("MS: ");lcd.print(microsec);
  lcd.setCursor (0,1);
  lcd.print ("CM: ");lcd.print(cmMsec);
  lcd.print ("IN: ");lcd.print(inMsec);
  delay(1000);
  lcd.clear();
}

