#include <Arduino.h>

int x_pin = A0;
int y_pin = A1;
int x_mid = 508;
int y_mid = 503;
#define led1 8
#define led2 5
#define led3 6
#define led4 7

void setup() {
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  Serial.begin(9600);

}

void loop() {
  int x_val = analogRead(x_pin);
  int y_val = analogRead(y_pin);


  if (x_val < 500) {
    Serial.println("Moved to the left");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (x_val > 515) {
    Serial.println("Moved to the right");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (y_val < 500) {
    Serial.println ("moved forward");
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led4, LOW);
  }
  else if (y_val > 515) {
    Serial.println ("moved backward");
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
 
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}
