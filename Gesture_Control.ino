#include <NewPing.h>

#define TRIGGER_PIN 9     // Trigger pin of the ultrasonic sensor
#define ECHO_PIN 10       // Echo pin of the ultrasonic sensor
#define MAX_DISTANCE 200  // Maximum distance we care about (in cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int distance = sonar.ping_cm(); // Read distance in cm

  if (distance > 0 && distance < 10) {
    Serial.println("VOL_UP"); // Volume up command if distance is < 10 cm
  } else if (distance >= 10 && distance < 20) {
    Serial.println("VOL_DOWN"); // Volume down command if distance is between 10-20 cm
  } else if (distance >= 20 && distance < 30) {
    Serial.println("PLAY_PAUSE"); // Play/Pause if distance is between 20-30 cm
  } else if (distance >= 30 && distance < 40) {
    Serial.println("FORWARD"); // Forward command if distance is between 30-40 cm
  } else if (distance >= 40 && distance < 50) {
    Serial.println("BACKWARD"); // Backward command if distance is between 40-50 cm
  }
  
  delay(500); // Delay for a smoother read rate
}
