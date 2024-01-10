#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "Lukas telefon";
const char* pass = "11111111";

WiFiClient client;

unsigned long channelID = 2397610;        //your TS channal
const char* APIKey = "0BS644K2B0YXL7I5";  //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 10 * 1000;  //post data every 20 seconds

void setup() {
  Serial.begin(115200);
  pinMode(D2, OUTPUT);
  pinMode(D3, INPUT);
  WiFi.begin(ssid, pass);
}

float data;  //measured data

void loop() {
  digitalWrite(D2, LOW);
  if (digitalRead(D2) == 1) {
    data = 1;
  }
  else {
    data = 0;
  }

  long rssi = WiFi.RSSI();

  ThingSpeak.begin(client);
  client.connect(server, 80);  //connect(URL, Port)

  ThingSpeak.setField(1, data);               //set data on the X graph
  ThingSpeak.setField(2, rssi);               //set data on the X graph
  ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS

  //ThingSpeak.setField(2, data, rssi);               //set data on the X graph
  //ThingSpeak.writeFields(channelID, APIKey);  //post everything to TS

  client.stop();
  delay(postDelay);  //wait and then post again
}