bool this_state;
bool last_state;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
}

void loop() {
  this_state = digitalRead(9);
  if (this_state != last_state)
  {  
    //update the switch state
    last_state = this_state;  

    //"HIGH condition code"
    //switch goes from LOW to HIGH
    if(this_state == HIGH)        
    {
      //LED on pin 8 is Push ON, Push OFF
      digitalWrite(8,!digitalRead(8)); 
    }
  }
  delay(10);
}
