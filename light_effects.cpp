#include "light_effects.h"
#include "helper_functions.h"

LightEffects::LightEffects(Adafruit_WS2801 lightStrip) {
  strip = lightStrip;
}

void LightEffects::rainbow(uint8_t wait) {
  // TODO Remove nested for loop and use the main class loop as loop to not make main loop wait for it to finish the cycle
  for (int j = 0; j < 256; j++) {  // 3 cycles of all 256 colors in the wheel
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) % 255));
    }
    delay(wait);
  }
}

void LightEffects::fixedRainbow() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(i % 255));
  }
}

void LightEffects::fixedColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int n = 0; n < strip.numPixels(); n++) {
    strip.setPixelColor(n, r, g, b);
  }
}

// NOTE Could be used as a notification LED
void LightEffects::singleLight(uint8_t r, uint8_t g, uint8_t b) {
  fixedColor(0, 0, 0);
  strip.setPixelColor(1, r, g, b);
}

void LightEffects::dim() {
  for (int n = 0; n < strip.numPixels(); n++) {
    // TODO First check if value when subtracted, is equal to 0 and stop. Then reduce value
    // if(strip[n].getPixelColor()){

    // }
  }
}

void LightEffects::brighten() {
  for (int n = 0; n < strip.numPixels(); n++) {
    // TODO First check if value when subtracted, is equal to 255 and stop. Then increase value
  }
}

void LightEffects::nextColor() {
  for (int n = 0; n < strip.numPixels(); n++) {
    // TODO Set as one color, then iterate through color wheel
  }
}

void LightEffects::previousColor() {
  for (int n = 0; n < strip.numPixels(); n++) {
    // TODO Set as one color, then iterate through color wheel
  }
}

void LightEffects::vivaMalta() {
  for (int i = 0; i < strip.numPixels() / 2; i++) {
    strip.setPixelColor(i, 255, 255, 255);
  }
  for (int i = strip.numPixels() / 2; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 255, 0, 0);
  }
}

// NOTE This mostly implies for when having split colors
void LightEffects::rotateClockwise() {
}

// NOTE This mostly implies for when having split colors
void LightEffects::rotateAnticlockwise() {
}

void LightEffects::whites(){
  //TODO Go through 3 different colors of white (if possible since it's RGB)
}

void LightEffects::greenPurple(){
  //TODO Half green, half purple
}

// NOTE This is mostly for notifications if going in menus or waiting for user input
void LightEffects::blink(uint8_t r, uint8_t g, uint8_t b, uint8_t delay) {
}

void LightEffects::candleLight() {
}