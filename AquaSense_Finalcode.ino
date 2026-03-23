#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int waterSensor = A0;
int soilSensor  = A1;
int buzzerPin   = 8;
int relayWater  = 7;
int relaySoil   = 6;

String lastLine1 = "";
String lastLine2 = "";


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);


  pinMode(buzzerPin, OUTPUT);
  pinMode(relayWater, OUTPUT);  
  pinMode(relaySoil, OUTPUT);


  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayWater, HIGH);
  digitalWrite(relaySoil, HIGH);
}


void loop() {
  int waterVal = analogRead(waterSensor);
  int soilVal  = analogRead(soilSensor);


  String waterState;
  bool waterHigh = false;
  if (waterVal <= 250) {
    waterState = "LOW";
    digitalWrite(relayWater, HIGH);
  }
  else if (waterVal < 00) {
    waterState = "MED";
    digitalWrite(relayWater, HIGH);
  }
  else {
    waterState = "HIGH";
    digitalWrite(relayWater, LOW);
    waterHigh = true;
  }


  String soilState;
  bool soilDry = false;
  if (soilVal >= 550) {
    soilState = "DRY";
    digitalWrite(relaySoil, LOW);
    soilDry = true;
  }
  else {
    soilState = "WET";
    digitalWrite(relaySoil, HIGH);
  }


  if (waterHigh) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  String line1;
  if (soilDry) {
    line1 = "WATERING...";
  }
  else {
    line1 = "Water Lvl: " + waterState;
  }

  String line2 = "Soil Status: " + soilState;

  if (line1 != lastLine1 || line2 != lastLine2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
    lastLine1 = line1;
    lastLine2 = line2;
  }


  Serial.print("Water: ");
  Serial.print(waterVal);
  Serial.print(" (");
  Serial.print(waterState);
  Serial.print(") | Soil: ");
  Serial.print(soilVal);
  Serial.print(" (");
  Serial.print(soilState);
  Serial.println(")");


  delay(300);
}


