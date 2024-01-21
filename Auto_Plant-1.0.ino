
const int Humidity_Pin = 2;  // Analog pin connected to HR202 & FR28 sensor
#define RELAY_PIN 4 // ESP32 pin GPIO4, which connects to the pump the via the relay



void setup() {
  Serial.begin(9600);  // Initialize serial communication

  pinMode(RELAY_PIN, OUTPUT);     // initialize digital pin GPI4 as an output.

}

void loop() {
  int sensorValue = analogRead(Humidity_Pin);  // Read analog value from the sensor
  Serial.println(sensorValue);
  
    delay(6000);

  float humidity = calculateHumidity(sensorValue);  // Convert sensor value to humidity percentage

  Serial.println("Humidity: ");
  Serial.print(humidity);
  Serial.println("% \n");

    delay(1000);  // Delay between readings (adjust as needed)

  // Wet = 500 — 1000 | Dry = 4095 
  if(sensorValue > 1900){
    
      digitalWrite(RELAY_PIN, HIGH); // turn on pump 4 seconds 
    delay(4000); //4000 = About 1 Dl 
      digitalWrite(RELAY_PIN, LOW);  // turn off pump 4 seconds
  
  }
  
  if(sensorValue > 1400){
    
      digitalWrite(RELAY_PIN, HIGH); // turn on pump 4 seconds 
  delay(1500); //1500 = About 0,3 Dl
  digitalWrite(RELAY_PIN, LOW);  // turn off pump 4 seconds

  }
  
  if(sensorValue < 1000){
    delay(10000);
  }

}

// Function to calculate humidity based on sensor value
float calculateHumidity(int sensorValue) {

  // Conversion formula specific to HR202 sensor
  float humidity = (float)sensorValue * 100 / 1024;
 
  return humidity;
}
