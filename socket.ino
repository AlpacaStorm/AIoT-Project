#include <ESP32Servo.h>
#include <SocketIOClient.h>
SocketIOClient client;

byte mac[] = { 0xAA, 0x00, 0xBE, 0xEF, 0xFE, 0xEE };


char hostname[] = "192.168.1.107";
int port = 8888;

extern String RID;
extern String Rname;
extern String Rcontent;

long interval = 5000; 
const int trigPin = 5;
const int echoPin = 17;
static const int servoPin1 = 4;
static const int servoPin2 = 0;
static int count = 0;

Servo servo1;
Servo servo2;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  Ethernet.begin(mac);
  if (!client.connect(hostname, port)) {
    Serial.println("Not connected.");
　}
  client.connected();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  servo1.attach(servoPin1, 500, 2400);
  servo2.attach(servoPin2, 500, 2400);
}

void loop() {
  // Clears the trigPin
  servo1.write(90);
  servo2.write(90);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  delay(100);
  
  if(distanceCm < 20){
      client.send("hi");
      while (client.monitor()) {        
          if(Rcontent == '0') {
            servo1.write(10);
            servo2.write(170);
            delay(1000);
            servo1.write(90);
            servo2.write(90);
          }else {
            servo1.write(170);    //can
            servo2.write(10);
            delay(1000);
            servo1.write(90);
            servo2.write(90);
          }
      }
  }
}
