#include <IRremote.h>

const int IR_PIN = 13; 

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
  
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW); 
  }
  Serial.println("Press the buttons");
}

void loop() {
  if (IrReceiver.decode()) {
    long command = IrReceiver.decodedIRData.command;
    Serial.print("Code: ");
    Serial.println(command, HEX);

    int count = -1; 
    switch (command) {
      case 0xC:  count = 0; break; 
      case 0x10: count = 1; break; 
      case 0x11: count = 2; break;
      case 0x12: count = 3; break; 
      case 0x14: count = 4; break; 
      case 0x15: count = 5; break; 
      case 0x16: count = 6; break; 
      case 0x18: count = 7; break; 
      case 0x19: count = 8; break; 
      case 0x1A: count = 9; break; 
    }

    if (count != -1) {
      Serial.print("Lamp is on: ");
      Serial.println(count);
      
      for (int i = 0; i < 10; i++) {
        if (i < count) {
          digitalWrite(i + 2, HIGH);
        } else {
          digitalWrite(i + 2, LOW);  
        }
      }
    }

    IrReceiver.resume(); 
  }
}