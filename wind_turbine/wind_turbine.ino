const int voltageSensorPin = A0; // Analog input pin for the voltage sensor
const int motorPin = 9; // Digital output pin to control the motor
const int ledPin = 8; // Digital output pin to control the LED

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW); // Turn off the motor initially
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Turn off the LED initially
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(voltageSensorPin); // Read the analog voltage
  float voltage = sensorValue * (5.0 / 1023.0); // Convert the analog value to voltage
  
  Serial.print("Generated Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  
  // Check for generated voltage (wind turbine working)
  if (voltage > 0.1) { // Adjust the threshold according to your setup
    digitalWrite(motorPin, HIGH); // Turn ON the motor to spin the shaft
    digitalWrite(ledPin, HIGH);   // Turn ON the LED
  } else {
    digitalWrite(motorPin, LOW);  // Turn OFF the motor
    digitalWrite(ledPin, LOW);    // Turn OFF the LED
  }
  
  delay(1000); // Add a small delay before taking the next reading
}
