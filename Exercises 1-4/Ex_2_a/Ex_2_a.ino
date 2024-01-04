// time integer for 1s
int unit = 1000;

void setup() {
  Serial.begin(9600);
  //Pin outputs are chosen
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT); 
}

void loop() {
   digitalWrite(8, HIGH);           //Turns on red light (RL)
   Serial.println("STOP");          //Writes STOP
   delay(2*unit);                   //Keeps RL on for 2s
   digitalWrite(8, LOW);            //RL turns off
   digitalWrite(9, HIGH);           //Turns on yellow light (YL)
   delay(unit);                     //Keeps YL on for 1s
   digitalWrite(9, LOW);            //YL turns off 
   digitalWrite(10, HIGH);          //Turns on green light (GL)
   Serial.println("GO");            //Writes GO 
   delay(2*unit);                   //Keeps GL on for 2s
   digitalWrite(10, LOW);           //GL turns off
   digitalWrite(9, HIGH);           //Turns on yellow light (YL)
   delay(unit);                     //Keeps YL on for 1s
   digitalWrite(9, LOW);            //YL turns off 
}




