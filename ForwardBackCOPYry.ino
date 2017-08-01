//www.elegoo.com
//2016.09.12

// this code requires the use of an ultrasonic.
// This code is meant to mimick an object's movement (or hand movement). If the distance between the object and the car is increasing, the car will move forward. If the distance is
// decreasing, then the car will move back. 

#include <Servo.h> //servo library
Servo myservo; // create servo object to control servo
int Echo = A4;  // controls ultrasonic.
int Trig = A5; // controls ultrasonic.
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int ENA = 11; // controls right side wheel
int ENB = 5; // controls left side wheel.
int ABS = 90; // (or 135) ABS is the variable that controls voltage applied to motors, thus speed. It can be a variable between 0 and 255. 
int dist = 0;
int spdUP[6] = {90, 100, 110, 120, 130, 135}; // 140, 150, 160, 170, 180, 190 (can also be measurements used) - this array is used for speed up function
int spdDown[9] = {90, 88, 86, 84, 82, 80, 78, 76, 74}; // 120, 110, 100, 90, 80, 70, 60, 50, 40 (can also be measurements used) - this array is used for speed down function.
int rightDistance = 0,leftDistance = 0,middleDistance = 0 ; // initailize distance variables.
void _mForward() // move the car forward.
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 Serial.println("go forward!");
}

void _mBack() // move the car backwards.
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 Serial.println("go back!");
}

void _mleft() // turn the car left (depending on delay, can turn in various angles).
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,LOW);
 digitalWrite(in2,HIGH);
 digitalWrite(in3,HIGH);
 digitalWrite(in4,LOW);
 Serial.println("go left!");
}

void _mright() // turn the car right (depending on delay, can turn in various angles)
{
 analogWrite(ENA,ABS);
 analogWrite(ENB,ABS);
 digitalWrite(in1,HIGH);
 digitalWrite(in2,LOW);
 digitalWrite(in3,LOW);
 digitalWrite(in4,HIGH);
 Serial.println("go right!");
} 
void _mStop() // stop the car (0 voltage)
{
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  Serial.println("Stop!");
} 
 /*Ultrasonic distance measurement Sub function*/
int Distance_test()   // Distance function for the ultrasonic sensor HC-sr04
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

void setup() // initialize pins to voltage input or voltage output.
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

void loop() // execute following statements continuosly.
{ 
    myservo.write(90);//setservo position according to scaled value
    delay(1); 
   // middleDistance = Distance_test();
    //#ifdef send
    //Serial.print("middleDistance=");
    //Serial.println(middleDistance);
    //#endif
  dist = Distance_test();
  
    if(dist > 70) 
    {
      int dis1;
      int dis2;
      int dis3;

      dis1 = Distance_test();
      delay(1);
      dis2 = Distance_test(); // take 3 distance measurements.
      delay(1);
      dis3 = Distance_test();
      delay(1);

      if((dis1 < dis2) || (dis2 < dis3)) { // check to see if the distance is relatively increasing between car and object/hand.
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      for(int i = 0; i < 6; i++) {
        delay(1);
        ABS = spdUP[i]; // use speed up function to catch up.
        analogWrite(ENA, ABS);
        analogWrite(ENB, ABS);
        dist = Distance_test(); // take distance measurements.
        
        // if(dist < 50) {
        //  break;
        // }
      }
      }
      else if((dis1 == dis2) && (dis2 == dis3)) { // if no relative change in distance, stop car.
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        
      }
    }
    else if(dist < 70) {
      int dis4;
      int dis5;
      int dis6;

      dis4 = Distance_test();
      delay(1);
      dis5 = Distance_test(); // take 3 distance measurements to compare.
      delay(1);
      dis6 = Distance_test();

      if((dis4 > dis5) || (dis5 > dis6)) { // distance is relatively decreasing.
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      for(int x = 0; x < 6; x++) {
        delay(1);
        ABS = spdUP[x]; // use the speed down function
        analogWrite(ENA, ABS);
        analogWrite(ENB, ABS);
        dist = Distance_test();
     //   if (dist > 20) {
       //   break;
       // }
         if (dist < 10) { 
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
        
        }
      }
    }
    else if((dis4 == dis5) && (dis5 == dis6)) {
      analogWrite(ENA, 0); // last cases, no relative change in distance, stop car.
      analogWrite(ENB, 0);
    }
    }
    else {
      analogWrite(ENA, 0); // if all else does not execute, stop car.
      analogWrite(ENB, 0);
    }
   
}
     
      
      
      
      
      
      
    
