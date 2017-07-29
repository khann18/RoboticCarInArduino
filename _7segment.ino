// this code requires a 7-segment common anode display, connected to the pins initialized.
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int two = 2;
int zero = 0;
int one = 1;
int thirteen = 13;
int twelve = 12;
int a3 = A3;
int a2 = A2;
int a1 = A1;
int a0 = A0;
int checkled = 0;

void zeroF() { // this function prints out zero on the 7-segment.
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, LOW);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void oneF() { // this function prints out one on the 7-segment.
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(thirteen, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(twelve, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(a1, HIGH);
}

void twoF() {  // this function prints out two on the 7-segment.
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void threeF() { // this function prints out three on the 7-segment.
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}
// the rest of the functions from this point on (unless specified) print a number on the 7-segment.

void fourF() { 
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, HIGH);
}

void fiveF() {
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, HIGH);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void sixF() {
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, HIGH);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void sevenF() {
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, LOW);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, LOW);
}

void eightF() {
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void nineF() {
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, LOW);
} 

void hF() { // this prints H on the 7-segment
  digitalWrite(one, HIGH);// for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(two, LOW);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, HIGH);
}

void eF() { // this prints E on the 7-segment
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, HIGH);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, LOW);
}

void lF() { // this prints L on the 7-segment
  digitalWrite(one, HIGH); // for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, HIGH);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(two, LOW);
  digitalWrite(twelve, LOW);
  digitalWrite(thirteen, HIGH);
}

void pF() { // this prints P on the 7-segment
  digitalWrite(one, HIGH);// for supplying 5 VOLTS to the 7-segment
  digitalWrite(a0, LOW);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(two, LOW);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, LOW);
}

void resetled() { // this function resets the led.
  digitalWrite(one, HIGH); 
  digitalWrite(a0, HIGH);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(two, HIGH);
  digitalWrite(twelve, HIGH);
  digitalWrite(thirteen, HIGH); 
} 

void setup() // setup to initialize the variables above to voltages.
{ 
  Serial.begin(9600);       
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(zero,OUTPUT);
  pinMode(one, OUTPUT);
  pinMode(thirteen, OUTPUT);
  pinMode(a3, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a0, OUTPUT);
  pinMode(twelve, OUTPUT);
  pinMode(two, OUTPUT); 
  
} 

void loop() { // loop() prints out H, E, L, P, then 1-9 onto the 7-segment each with 1 second displays in between the actions.
  hF();
  delay(1000);
  eF();
  delay(1000);
  lF();
  delay(1000);
  pF();
  delay(1000);
  oneF();
  delay(1000);
  twoF();
  delay(1000);
  threeF();
  delay(1000);
  fourF();
  delay(1000);
  fiveF();
  delay(1000);
  sixF();
  delay(1000);
  sevenF();
  delay(1000);
  eightF();
  delay(1000);
  nineF();
  delay(1000); 
}

