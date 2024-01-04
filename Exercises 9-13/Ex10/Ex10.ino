int val = 0;
float voltage = 0;
float celscius = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  val = analogRead(A0);
  voltage = 5./1023.*val;
  celscius = voltage * 100;
  
  // print voltage and degrees
  Serial.println(val);
  Serial.print(voltage);
  Serial.println("V");
  Serial.print(celscius);
  Serial.println("°C");

  // turn on LEDs according to the temperature
  if (celscius < 24){
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else if (celscius > 30){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else {
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
}
