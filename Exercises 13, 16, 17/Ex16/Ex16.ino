//int var = 5;
//int *pointer = &var;
//int a[5] = {9, 2, 42, 5, 8};
//int *pointer = &a[0];
int a = 4;
int b = 7;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*
  // part 1
  *pointer = 13;
  Serial.println(var);
  /*

  /*
  // part 2
  Serial.print("Address of pointer is ");
  Serial.println((unsigned int)&pointer);
  Serial.print("Value of pointer is ");
  Serial.println(*pointer, DEC);
  pointer++;
  
  delay(3000);
  */

  // part 3
  swap(&a, &b);
  delay(1000);
}

void swap(int *pointer_a, int *pointer_b) {
  int temp = *pointer_a;
  *pointer_a = *pointer_b;
  *pointer_b = temp;
  //Serial.println(temp);
  Serial.println(a);
  Serial.println(b);
  Serial.println(" ");
}