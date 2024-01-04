#include <LiquidCrystal_I2C.h>

int val = 0;
float voltage = 0;
float celscius = 0;

// the location of the lcd is 0x27
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
}

void loop() {
  // the average tempearture of 10 measuments
  for (int i = 0; i <= 9; i++){
    val = val + analogRead(A0);
    Serial.println(val);
    delay(500);
  }
  val = val/10;
  voltage = 5./1023.*val;
  celscius = voltage * 100;
  
  // print voltage and degrees
  Serial.println(val);
  Serial.print(voltage);
  Serial.println("V");
  Serial.print(celscius);
  Serial.println("°C");

  // turn on LEDs according to the temperature
  // and writes a message accordingly
  if (celscius < 24){
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);

    lcd.setCursor(0,1);
    lcd.print("                ");  // clears the second row
  }
  else if (celscius > 30){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    lcd.setCursor(0,1);
    lcd.print("");

    lcd.setCursor(0,1);
    lcd.print("Warning. HOT!!!");
  }
  else {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    lcd.setCursor(0,1);
    lcd.print("                ");
  }

  // prints the temperature on the LCD display
  lcd.setCursor(0,0);
  lcd.print(celscius);
  lcd.setCursor(5,0);
  lcd.print(char(223));
  lcd.setCursor(6,0);
  lcd.print("C");
  
}
