#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

Servo myservo;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D5;
int SCL_pin = D6;

int myFunction(int, int);
int trigPin = D0;
int echoPin = D1;
int ledijo = D3;
int ledmerah = D2;
long duration;
int distance;

void setup()
{
  pinMode(ledijo, OUTPUT);
  pinMode(ledmerah, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(D4);
  Serial.begin(9600);

  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(distance);
  Wire.begin(SDA_pin, SCL_pin);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  Serial.print(" Jarak: ");
  Serial.print(distance);
  Serial.print(" cm");
  lcd.clear();
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 10)
  {
    digitalWrite(ledijo, HIGH);
    digitalWrite(ledmerah, LOW);
    myservo.write(180);
    delay(1000);
  }
  else
  {
    digitalWrite(ledijo, LOW);
    digitalWrite(ledmerah, HIGH);
    myservo.write(0);
    delay(1000);
  }
}

int myFunction(int x, int y)
{
  return x + y;
}