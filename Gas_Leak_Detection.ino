#include <MQ2.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// MQ2 Sensor
int smokeA0 = A0;
int sensorThres = 185;
MQ2 mq2(smokeA0);

// LEDs
int led_RED = 11;
int led_GREEN = 12;

// Buzzer
const int buzzer = 7;

// Relay
int RELAY_PIN = 5;

void setup()
{
  pinMode(led_GREEN, OUTPUT);
  pinMode(led_RED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  mq2.begin();
}

void loop()
{
  int analogSensor = analogRead(smokeA0);

  lcd.setCursor(0, 0);
  lcd.print("Smoke Level:");
  lcd.print(analogSensor - 50);

  if (analogSensor - 50 > sensorThres)
  {
    lcd.setCursor(0, 1);
    lcd.print("....Alert....!!!");

    digitalWrite(led_GREEN, LOW);
    digitalWrite(led_RED, HIGH);

    tone(buzzer, 1000, 10000);

    digitalWrite(RELAY_PIN, HIGH);

    delay(100);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print(".....Normal.....");

    digitalWrite(led_GREEN, HIGH);
    digitalWrite(led_RED, LOW);

    noTone(buzzer);

    digitalWrite(RELAY_PIN, LOW);

    delay(100);
  }

  delay(500);
}
