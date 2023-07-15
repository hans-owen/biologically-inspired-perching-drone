#include <Arduino.h>

#define LED_PIN 25
#define FC_SIGNAL_PIN 1
#define MOTOR_FORWARD 2
#define MOTOR_REVERSE 3
#define ADC_PIN 27

int speed = 255;
int currentThreshold = 40;
bool closed = false;

// put function declarations here:
void motorforward() {
  analogWrite(MOTOR_FORWARD, speed);
  analogWrite(MOTOR_REVERSE, 0);
}

void motorreverse() {
  analogWrite(MOTOR_FORWARD, speed);
  analogWrite(MOTOR_REVERSE, 0);
}

void motorstop() {
  analogWrite(MOTOR_FORWARD, 0);
  analogWrite(MOTOR_REVERSE, 0);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(FC_SIGNAL_PIN, INPUT);
  pinMode(MOTOR_FORWARD, OUTPUT);
  pinMode(MOTOR_REVERSE, OUTPUT);
  pinMode(ADC_PIN, INPUT);

  Serial.begin(115200);
  Serial.println("Startup...");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Signals
  int current = analogRead(ADC_PIN); // read the current value from the ADC
  int fcSignal = digitalRead(FC_SIGNAL_PIN); // read the FC signal

  if (fcSignal == HIGH){
    // set FC signal status indicator
    digitalWrite(LED_PIN, LOW); 
    if (current > currentThreshold)
    {
      while (current > currentThreshold)
      {
       // stop the motor if the current exceeds the threshold
       motorstop();
       current = analogRead(ADC_PIN);
       Serial.print("current = ");
       Serial.println(current);
      }
    }
    else if (current < currentThreshold)
    {
      motorreverse();
      current = analogRead(ADC_PIN);
      Serial.print("current = ");
      Serial.println(current);
    }
  }
  
  else if (fcSignal == LOW){
    // set FC signal status indicator
    digitalWrite(LED_PIN, HIGH); 
    motorforward();
    current = analogRead(ADC_PIN);
    Serial.print("current = ");
    Serial.println(current);
  }
   
  // print the current value
  Serial.print("x = ");
  Serial.println(current);
  //delay(1000);
}