#include <Arduino.h>
int pin_list[] = {13, 12, 14, 27, 26, 25}; 
int num = sizeof(pin_list)/sizeof(pin_list[0]); 

void setup() {
  for(int i=0; i<num; i++){
     pinMode(pin_list[i], OUTPUT);
  }
}

void loop() {

  for (int i=0;i<num;i++){
     digitalWrite(pin_list[i], HIGH);
     delay(500);
  }  


  for (int i=0;i<num;i++){
     digitalWrite(pin_list[i], LOW);
     delay(500);
   }
} 