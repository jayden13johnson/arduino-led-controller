#include <FastLED.h> 

#define NUM_LEDS 200
#define LED_PIN 6

uint8_t hue = 0;
CRGB leds[NUM_LEDS];  

void setup() {
  // put your setup code here, to run once:

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50); 
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, 4000);  
  Serial.begin(9600); 

}

void loop() {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i*10), 255, 255);
  }
  EVERY_N_MILLISECONDS(5){
    hue++;
  }
  FastLED.show();

}
