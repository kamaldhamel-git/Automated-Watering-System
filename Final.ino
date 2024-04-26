#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT22
#define OLED_RESET -1

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(OLED_RESET);

char auth[] = "LdsnW_azDke_Zak8TvqgojC10TyxUQQY"; // authentication token from blynk template
char ssid[] = "CareerHub C"; // coonnected wifi ssid 
char pass[] = "C@reerHub123321"; // passowrd

const int pumpPin = D3;
const int moisturePin = A0;
const int moistureThreshold = 500;  // Value for detect low or high moisture
BlynkTimer timer;

void checkMoisture() {
  int moistureValue = analogRead(moisturePin);
  if (moistureValue < moistureThreshold) {
    digitalWrite(pumpPin, HIGH);  // Turn on pump
    Blynk.virtualWrite(V2, "Moisture: Low");  // To Ppdate Blynk app
  } else {
    digitalWrite(pumpPin, LOW);  // Turn off pump
    Blynk.virtualWrite(V2, "Moisture: Normal");  // To Update Blynk app
  }
}

void readTemperatureHumidity() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Humidity: ");
  display.println(humidity);
  display.print("Temperature: ");
  display.println(temperature);
  display.display();
  Blynk.virtualWrite(V0, temperature);  // Update Blynk app
  Blynk.virtualWrite(V1, humidity);  // Update Blynk app
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(pumpPin, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  timer.setInterval(10000L, readTemperatureHumidity);
  timer.setInterval(60000L, checkMoisture);
}

void loop() {
  Blynk.run();
  timer.run();
}
