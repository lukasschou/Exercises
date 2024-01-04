int unit = 1000; // counter time

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // Runs a counter from 0-7
  for(int i = 0; i < 8; i++){
    // Turns off every LED before tuning the right ones on again
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    Serial.println(i);
    display(i);
    delay(unit);
  }
}

// Uses the modulo operator to display the binary number on the LEDs
void display(int i){
  if (i % 4 < i && i > 3){ 
    digitalWrite(10, HIGH);
    i = i % 4;
  }
  if (i % 2 < i && i > 1){ 
    digitalWrite(9, HIGH); 
    i = i % 2;
  }
  if (i % 1 < i && i > 0){ 
    digitalWrite(8, HIGH);
  }
}




