// important! This code requires the use of an ultrasonic and the Chrono Timer library

// This code can measure the dimensions of a rectangular or square object. Have the car facing the object some distance away (3 feet is good). The car will move forward toward the object,
// and once it senses it, it will stop, and circumnavigate around the object, then print the dimensions (in inches) to the Serial monitor.
#include <Servo.h> //servo library
#include <Chrono.h> // chrono timer library 
Servo myservo; // create servo object to control servo
Chrono chrono;
int Echo = A4;  // controls ultrasonic
int Trig = A5; // controls ultrasonic
int in1 = 9; 
int in2 = 8;
int in3 = 7;
int in4 = 6;
int ENA = 11; // pin for right side motors
int ENB = 5; // pin for left side motors
int ABS = 110; // voltage applied (controls speed, a value between 0 and 255)
int middleDistance = 0 ; // initialize middleDistance
int rightDistance1, rightDistance2, rightDistance3, leftDistance1, leftDistance2, leftDistance3;
int count = 0;
int timeTURNleft = (405); // delay for turning left
int timeTURNright = 600; // delay for turning right. These delays can be different depending on the car used
int checkled = 0;
double array[1];
int countnow[1] = {0};


void sidescrape() { // the sidescrape function is the function used while the car is traversing along one side of the object. This function will be called 4 times.
  myservo.write(180); // the ultrasonic is facing the object.
  _mForward();
  rightDistance2 = Distance_test();
  chrono.restart(); // make sure the timer is at 0.
  count = 1; // count is according to which side the car will be on.
  if (rightDistance2 <= 50 && count == 1) {
    chrono.start();
  }

  else if (rightDistance2 <= 50 && count == 2) {
    chrono.start();
    //Serial.println(chrono.elapsed());
  }
  
  while ((rightDistance2 <= 50 && count == 1) || (rightDistance2 <= 50 && count == 2) || (rightDistance2 <= 50 && count == 3) || (rightDistance2 <= 50 && count == 4)) {
    _mForward();
    rightDistance2 = Distance_test();
    delay(3);
    //Serial.println(chrono.elapsed());
    // continually take distance measurements until it realizes that the distance is very large (i.e. the car has moved past the object.)
  }
 /** if(rightDistance2 > 50) {
    count++;
  } */

  
  if (count == 1) {
  //Serial.println("Elapsed time: ");
  //Serial.println(chrono.elapsed());
  double timeS = (chrono.elapsed() / 1000.0); // calculations for determining the dimension of one side.
  double inches = (22.4) * timeS; // 22.4 inches/second is the speed of the car.
  /*double units = (1.56936597614) * (timeS);
  double inches = units * 24;
  double x1 = inches; */
  int x;
  countnow[0] = x; 
  x++;
// 22.4 inches/s
    Serial.println(inches);
    Serial.println(" inches");
  
  //array[0] = x1;
 // printled();
  delay(300); // 300
 _mStop();
 chrono.stop(); // the timer should be stopped. It is ok to stop the timer now since we already recorded the timer value earlier with chrono.elapsed()
 chrono.restart(); // restart the timer so it goes back to zero.
 }
}

void TURN() { // the TURN function handles each turn of the car. This will be executed 4 times.
  rightDistance2 = Distance_test(); 
  if (rightDistance2 > 80) {
    _mleft();
    delay(timeTURNleft);
    _mStop();
    count++;
  }
  //chrono.restart();
  //chrono.start();
}

void _mForward() // move the car forward
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 //Serial.println("go forward!");
}

void _mBack() // move the car backwards
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 //Serial.println("go back!");
}

void _mleft() // The car will take a left turn. Depending on the delay, it can turn at various angles
{
 analogWrite(ENA,155);
 analogWrite(ENB,155);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 //Serial.println("go left!");
}

void _mright() // The car will take a right turn. Depending on the delay, it can turn at various angles
{
 analogWrite(ENA,155);
 analogWrite(ENB,155);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 //Serial.println("go right!");
} 
void _mStop() // stop the car.
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  //Serial.println("Stop!");
} 
 /*Ultrasonic distance measurement Sub function*/
int Distance_test()  // Function that controls measurements for the ultrasonic HC-sr04.
{
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance/58;       
  return (int)Fdistance;
}  

void setup() // intialize the pins to voltage inputs or voltage outputs.
{ 
  myservo.attach(3);// attach servo on pin 3 to servo object
  Serial.begin(9600);     
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  _mStop();
} 

void loop() // loop will consistently be executed.
{ 
    
    myservo.write(90);//setservo position according to scaled value
    delay(100);
    middleDistance = Distance_test();
    
    if (middleDistance > 20) {
      _mForward();
    } // keep going forward until it senses an object.

    else if(middleDistance <= 20) { // it has sensed an object. Now it shall circumnavigate it
      _mStop();
      delay(500);
      _mright();
      delay(timeTURNright);
      _mStop();
      delay(100);

      sidescrape(); // goes right (disregard this measurement)
      TURN();
      _mForward();
      delay(300); // 300
      sidescrape(); // goes up and count == 1 (measurement matters)
      TURN();
      _mForward();
      delay(300);
      sidescrape(); // goes left and count == 2 (measurement matters)
      TURN();
      _mForward();
      delay(300);
      sidescrape(); // goes down (disregard this measurement)
      TURN();
      _mForward();
      delay(300);
      _mStop();
      delay(3000); // the two above measurements that matter will indicate the dimensions of the object in inches.
      }
    }
