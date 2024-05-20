#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D1;
int SCL_pin = D2;

void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!"); 
  lcd.setCursor(0,1);
  lcd.print("I am Arduino!"); 
}

void scrollRow(int row) {
  lcd.setCursor(0, row);
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayRight();
    delay(300);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("I am Arduino!");
}

void loop() {
  scrollRow(0);
  delay(1000);
  scrollRow(1);
  delay(1000);
}
