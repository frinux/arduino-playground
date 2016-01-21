#include <DHT.h> // DHT22 lib
#define DHT22_PIN 11 // DHT22 data input

DHT dht;

void setup() {
  
  dht.setup(DHT22_PIN);

  Serial.begin(115200);

  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)");
}

void loop() {
  
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.println(temperature);

  delay(1000);

}
