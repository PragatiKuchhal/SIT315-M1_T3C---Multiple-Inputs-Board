// Define PIR sensor pins
const int pirSensorPin1 = 2;
const int pirSensorPin2 = 3;

// Define RGB LED pins
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set PIR sensor pins as inputs
  pinMode(pirSensorPin1, INPUT_PULLUP);
  pinMode(pirSensorPin2, INPUT_PULLUP);

  // Set RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Attach interrupts to PIR sensor pins
  attachInterrupt(digitalPinToInterrupt(pirSensorPin1), pirSensorISR1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pirSensorPin2), pirSensorISR2, CHANGE);
}

void loop() {
  // Main program loop
}

// Interrupt Service Routine (ISR) for PIR sensor 1
void pirSensorISR1() {
  // Read PIR sensor 1 input
  int pirSensorState1 = digitalRead(pirSensorPin1);
  
  // Print PIR sensor 1 status
  Serial.print("PIR Sensor 1: ");
  Serial.println(pirSensorState1 == HIGH ? "Motion Detected" : "No Motion");

  // Control RGB LED based on motion detection from PIR sensor 1
  if (pirSensorState1 == HIGH) {
    // Display red color
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else {
    // Turn off the RGB LED
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}

// Interrupt Service Routine (ISR) for PIR sensor 2
void pirSensorISR2() {
  // Read PIR sensor 2 input
  int pirSensorState2 = digitalRead(pirSensorPin2);
  
  // Print PIR sensor 2 status
  Serial.print("PIR Sensor 2: ");
  Serial.println(pirSensorState2 == HIGH ? "Motion Detected" : "No Motion");

  // Control RGB LED based on motion detection from PIR sensor 2
  if (pirSensorState2 == HIGH) {
    // Display blue color
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else {
    // Turn off the RGB LED
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
