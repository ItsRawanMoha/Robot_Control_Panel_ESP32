#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Smart_Methods1";
const char* password = "123456789";

const String url = "http://192.168.8.146/ShowMovComCopy.php";
String payload = "";

// Define LED pins
const int forwardsPin = 2;
const int backwardsPin = 0;
const int leftPin = 4;
const int rightPin = 16;
const int stopPin = 17;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(forwardsPin, OUTPUT);
  pinMode(backwardsPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  pinMode(rightPin, OUTPUT);
  pinMode(stopPin, OUTPUT);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());
}

void loop() {
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println();
    Serial.println(payload);
    // Control LEDs based on payload
    if(payload == "forwards") {
      digitalWrite(forwardsPin, HIGH);
      digitalWrite(backwardsPin, LOW);
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, LOW);
      digitalWrite(stopPin, LOW);
    } else if(payload == "backwards") {
      digitalWrite(forwardsPin, LOW);
      digitalWrite(backwardsPin, HIGH);
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, LOW);
      digitalWrite(stopPin, LOW);
    } else if(payload == "left") {
      digitalWrite(forwardsPin, LOW);
      digitalWrite(backwardsPin, LOW);
      digitalWrite(leftPin, HIGH);
      digitalWrite(rightPin, LOW);
      digitalWrite(stopPin, LOW);
    } else if(payload == "right") {
      digitalWrite(forwardsPin, LOW);
      digitalWrite(backwardsPin, LOW);
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, HIGH);
      digitalWrite(stopPin, LOW);
    } else if(payload == "stop") {
      digitalWrite(forwardsPin, LOW);
      digitalWrite(backwardsPin, LOW);
      digitalWrite(leftPin, LOW);
      digitalWrite(rightPin, LOW);
      digitalWrite(stopPin, HIGH);
    }
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println(":-(");
  }
  
}