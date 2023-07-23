#define POWER_PIN  4
#define SIGNAL_PIN A5


int value = 0; // variable to store the sensor value
int mb ;

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF 
  value= map(value,0,1023,0,523);
  if (value > 0){
    Serial.println("water detected");
  }
  else{
    Serial.println("water not detected");
    delay(3000);
  }
}