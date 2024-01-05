struct Animal {  //Declare new Animal struct
  int weight;    //Set member weight of Animal struct
  bool alive;
  float speed;
  float height;
  int age;
  int ID;
};

void setup() {
  Serial.begin(9600);

  // define 2 animals and print their information
  Animal hummingbird = { 50, false, 4.2, 11.3, 2, 1 };
  printAnimal(hummingbird);
  Animal cat = { 500, true, 5.1, 22.7, 1, 2 };
  printAnimal(cat);

  // swaps the animals weight and print their information again
  swapWeight(&hummingbird, &cat);
  printAnimal(hummingbird);
  printAnimal(cat);

  // compare the animals by if they are dead or alive,
  // and makes the "best" one have the lowest ID
  compare(&hummingbird, &cat);
  printAnimal(hummingbird);
  printAnimal(cat);
}

void printAnimal(struct Animal a) {
  Serial.print("The animals weight is ");
  Serial.println(a.weight);
  if (a.alive == 1) {
    Serial.println("The animal is alive");
  } else {
    Serial.println("The animal is dead");
  }
  Serial.print("The animals speed is ");
  Serial.println(a.speed);
  Serial.print("The animals height is ");
  Serial.println(a.height);
  Serial.print("The animals age is ");
  Serial.println(a.age);
  Serial.print("The animals ID is ");
  Serial.println(a.ID);
  Serial.println(" ");
}

void swapWeight(struct Animal *a, struct Animal *b) {
  int temp = (*a).weight;
  (*a).weight = (*b).weight;
  (*b).weight = temp;
}

void compare(struct Animal *a, struct Animal *b) {
  if ((*a).alive == true && (*b).alive == false) {
    if ((*a).ID > (*b).ID) {
      int temp = (*a).ID;
      (*a).ID = (*b).ID;
      (*b).ID = temp;
    }
  } else if ((*a).alive == false && (*b).alive == true) {
    if ((*a).ID < (*b).ID) {
      int temp = (*a).ID;
      (*a).ID = (*b).ID;
      (*b).ID = temp;
    }
  }
}