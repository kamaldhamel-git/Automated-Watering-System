# Automated-Watering-System
The automated watering system is a IoT based irrigation project which uses Node MCU ESP8266 board, Capacitive Soil Moisture Sensor v1.2, 0.96 inch OLED Display, DHT22, 5V relay module, Water Pump and Breadboard and Jumper wires. I have integrated the Blynk App for remote controlling. Before the code upload to the ESP8266 board we need to add the appropriate libraries for the components used, Here we first need to add some of the libraries;
1. Library for ESP8266, DHT22, Blynk and Adafruit SSD1306 OLED display.
2. Make sure to replace "YourWiFiSSID" and "YourWiFiPassword" with your actual Wi-Fi credentials.
3. Provide the actual Blynk Template-id, template-name and template-token.
4. Virtual pins V0 and V1 in the Blynk app are used to display temperature and humidity values, and virtual pin V2 is used to indicate moisture status and control the water pump manually through a button widget. 
After adding the libraries and by providing the actual values of the blnk and other componential values, we can simply upload the code to the board and can see the progress.
