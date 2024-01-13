#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h> // Add this line

const char *ssid = "iq";
const char *password = "8573968332";
const char *serverUrl = "http://www.smartsynk.com/led_control.php"; 

const int ledPinD1 = D1;
const int ledPinD2 = D2;
const int ledPinD3 = D3;
const int ledPinD4 = D4;
const int ledPinD5 = D5;
const int ledPinD6 = D6;
const int ledPinD7 = D7;
const int ledPinD8 = D8;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(ledPinD1, OUTPUT);
  pinMode(ledPinD2, OUTPUT);
  pinMode(ledPinD3, OUTPUT);
  pinMode(ledPinD4, OUTPUT);
  pinMode(ledPinD5, OUTPUT);
  pinMode(ledPinD6, OUTPUT);
  pinMode(ledPinD7, OUTPUT);
  pinMode(ledPinD8, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  // Read the current LED status from the server
  WiFiClient wifiClient;  // Create a WiFiClient object
  HTTPClient http;
  
  // Get the WiFi status
  int wifiStatus = WiFi.status();

  // Convert const char* to String for concatenation
  String url = String(serverUrl) + "?wifi_status=" + String(wifiStatus);

  http.begin(wifiClient, url);
   
  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();

    // Parse JSON
    const size_t capacity = JSON_OBJECT_SIZE(8) + 200;
    DynamicJsonDocument doc(capacity);
    deserializeJson(doc, payload);

    // Access JSON data
    int led1 = doc["led1"];
    int led2 = doc["led2"];
    int led3 = doc["led3"];
    int led4 = doc["led4"];
    int led5 = doc["led5"];
    int led6 = doc["led6"];
    int led7 = doc["led7"];
    int led8 = doc["led8"];

    // Print values
    Serial.print(httpCode);
    Serial.print("Value 1: ");
    Serial.println(led1);
    Serial.print("Value 2: ");
    Serial.println(led2);
        Serial.print(payload);
    
        
        
    // Update LED pins based on values
    digitalWrite(ledPinD1, led1 ? HIGH : LOW);
    digitalWrite(ledPinD2, led2 ? HIGH : LOW);
    digitalWrite(ledPinD3, led3 ? HIGH : LOW);
    digitalWrite(ledPinD4, led4 ? HIGH : LOW);
    digitalWrite(ledPinD5, led5 ? HIGH : LOW);
    digitalWrite(ledPinD6, led6 ? HIGH : LOW);
    digitalWrite(ledPinD7, led7 ? HIGH : LOW);
    digitalWrite(ledPinD8, led8 ? HIGH : LOW);
  } else {
    Serial.println("Error getting LED status");
  }

  http.end();

  // Add a delay before the next iteration
  delay(5000); // Adjust the delay as needed
}
