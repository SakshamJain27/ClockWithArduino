#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7
int pos =0;

int minute = 12;
int hour = 00;
int second = 00;
void setup() {
  lcd.begin(16, 2);
  pinMode(13, INPUT);
  pinMode(10, INPUT);
}

void loop() {
  if (digitalRead(13)==LOW){
    hour++;
    if(hour==12){
      hour=1;
    }
  }
  if (digitalRead(10)==HIGH){
    minute++;
    if(minute==60){
      minute = 0;
    }
  }
  second++;
  if(second==60){
    second = 00;
    minute++;
    lcd.clear();
  }
  if(minute==60){
    minute = 00;
    hour++;
    lcd.clear();
  }
  if(hour==12){
    hour = 1;
    lcd.clear();
  }
  
  lcd.setCursor(4, 0);
  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(second);
  delay(987);
}
