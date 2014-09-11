#include <IRremote.h>

const int pinRemoteController = 13;
const int pinLed = 4;
IRrecv irrecv(pinRemoteController);  
decode_results dResults; 

void setup(){
  pinMode(pinRemoteController, OUTPUT);
  pinMode(pinLed, OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop(){
  if (irrecv.decode(&dResults)){
    Serial.println(dResults.value, HEX);
    float button = (dResults.value);
    //20DF10EF is the code of the power button on the remote control(LG TV)
    if(button == 0x20DF10EF){
      if (digitalRead(pinLed) == HIGH){
        Serial.println("TURN OFF");
        digitalWrite(pinLed, LOW);
      } else {
        Serial.println("TURN ON");
        digitalWrite(pinLed, HIGH);
      }
    }
    irrecv.resume();
  }
}

