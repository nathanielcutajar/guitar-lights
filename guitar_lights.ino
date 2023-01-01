#include <IRremote.h>
#include <SPI.h>
#include <Adafruit_WS2801.h>
#include "light_effects.h"

#define IR_REMOTE_POWER 0xBA45FF00
#define IR_REMOTE_MODE 0xB946FF00
#define IR_REMOTE_MUTE 0xB847FF00
#define IR_REMOTE_PLAY_PAUSE 0xBB44FF00
#define IR_REMOTE_PREVIOUS 0xBF40FF00
#define IR_REMOTE_NEXT 0xBC43FF00
#define IR_REMOTE_EQ 0xF807FF00
#define IR_REMOTE_MINUS 0xEA15FF00
#define IR_REMOTE_PLUS 0xF609FF00
#define IR_REMOTE_SHUFFLE 0xE619FF00
#define IR_REMOTE_U_SD 0xF20DFF00
#define IR_REMOTE_NUM_0 0xE916FF00
#define IR_REMOTE_NUM_1 0xF30CFF00
#define IR_REMOTE_NUM_2 0xE718FF00
#define IR_REMOTE_NUM_3 0xA15EFF00
#define IR_REMOTE_NUM_4 0xF708FF00
#define IR_REMOTE_NUM_5 0xE31CFF00
#define IR_REMOTE_NUM_6 0xA55AFF00
#define IR_REMOTE_NUM_7 0xBD42FF00
#define IR_REMOTE_NUM_8 0xAD52FF00
#define IR_REMOTE_NUM_9 0xB54AFF00

const int irReceiverPin = 2;
uint8_t dataPin = 4;
uint8_t clockPin = 5;
uint16_t ledCount = 160;
Adafruit_WS2801 strip = Adafruit_WS2801(ledCount, dataPin, clockPin);
IRrecv irrecv(irReceiverPin);
unsigned long int received_value = 0;
LightEffects effects(strip);

void setup() {
  irrecv.enableIRIn();
  strip.begin();
  strip.show();
  Serial.begin(9600);
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.decodedRawData != 0) {
      received_value = IrReceiver.decodedIRData.decodedRawData;
    }
    irrecv.resume();
    Serial.println(received_value, HEX);
  }

  switch (received_value) {
    case IR_REMOTE_POWER:
      effects.fixedColor(0, 0, 0);
      break;
    case IR_REMOTE_NUM_0:
      effects.rainbow(20);
      break;
    case IR_REMOTE_NUM_1:
      effects.fixedRainbow();
      break;
    case IR_REMOTE_NUM_7:
      effects.fixedColor(255, 0, 0);
      break;
    case IR_REMOTE_NUM_8:
      effects.fixedColor(0, 255, 0);
      break;
    case IR_REMOTE_NUM_9:
      effects.fixedColor(0, 0, 255);
      break;
    case IR_REMOTE_EQ:
      Serial.println(strip.getPixelColor(1));
      break;
    case IR_REMOTE_PLUS:
      effects.brighten();
      break;
    case IR_REMOTE_MINUS:
      effects.dim();
      break;
    case IR_REMOTE_NEXT:
      effects.nextColor();
      break;
    case IR_REMOTE_PREVIOUS:
      effects.previousColor();
      break;
    case IR_REMOTE_NUM_6:
      effects.vivaMalta();
      break;
  }

  strip.show();
  delay(100);  //Used so that it does not check constantly
}