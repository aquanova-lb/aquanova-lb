#include <Ultrasonic.h>
Ultrasonic ultrasonic(8,7); 
unsigned int distance_1;

int distance_flag = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance();
}

void distance(){
  if(distance_flag == 0){
    distance_1= ultrasonic.read();
    delay(1000);
    Serial.print("distance : ");
    Serial.print(distance_1);
    distance_flag = 1;
  }
}
