
#define BLYNK_PRINT Serial


#define BLYNK_TEMPLATE_ID "TMPL2kTf1wFU3"
#define BLYNK_TEMPLATE_NAME "IOT"
#define BLYNK_AUTH_TOKEN "wytmCHrB82um27FJI5LjsGJVKSp7BmTc"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "iot";  // type your wifi name
char pass[] = "11111";  // type your wifi password
 
int M1PWM = 22;
int M2PWM = 19;
int M1F = 2; //GPIO5
int M1R = 4; //GPIO4
int M2F = 12; //GPIO0
int M2R = 13; //GPIO2

int pinValue1;
int pinValue2;

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  analogWrite(M1PWM,pinValue1);
  Blynk.virtualWrite(V1,pinValue1);
  Serial.print("V1 Slider Value is ");
  Serial.println(pinValue1);
}

BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt();
  analogWrite(M2PWM,pinValue2);
  Blynk.virtualWrite(V1,pinValue2);
  Serial.print("V2 Slider Value is ");
  Serial.println(pinValue2);
}
 

void setup(){
  pinMode(M1PWM, OUTPUT);
  pinMode(M2PWM, OUTPUT);
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2R, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  
}

void loop(){
  Blynk.run();
 
}

// Control de la velocidad del motor
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  ledcWrite(pwmChannel, pinValue);
  Blynk.virtualWrite(V1, pinValue);
  Serial.print("V1 Slider Value is ");
  Serial.println(pinValue);
}

// Control de la dirección del motor
BLYNK_WRITE(V2) {
  int direction = param.asInt();
  if (direction == 1) { // Avanzar
    digitalWrite(M1F, HIGH);
    digitalWrite(M1R, LOW);
  } else if (direction == 2) { // Retroceder
    digitalWrite(M1F, LOW);
    digitalWrite(M1R, HIGH);
  } else { // Detener
    digitalWrite(M1F, LOW);
    digitalWrite(M1R, LOW);
  }
  Serial.print("V2 Direction is ");
  Serial.println(direction == 1 ? "Forward" : direction == 2 ? "Reverse" : "Stop");
}
