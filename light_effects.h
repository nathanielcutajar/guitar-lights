#ifndef LIGHT_EFFECTS_H
#define LIGHT_EFFECTS_H

#include <Arduino.h>
#include <Adafruit_WS2801.h>

class LightEffects {
public:
  LightEffects(Adafruit_WS2801 strip);
  void rainbow(uint8_t wait);
  void fixedRainbow();
  void fixedColor(uint8_t r, uint8_t g, uint8_t b);
  void singleLight(uint8_t r, uint8_t g, uint8_t b);
  void dim();
  void brighten();
  void nextColor();
  void previousColor();
  void vivaMalta();
  void rotateClockwise();
  void rotateAnticlockwise();
  void whites();
  void greenPurple();
  void blink(uint8_t r, uint8_t g, uint8_t b, uint8_t delay);
  void candleLight();
private:
  Adafruit_WS2801 strip;
};

#endif