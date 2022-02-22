#include <FastLED.h> 

#define NUM_LEDS 150
#define LED_PIN 6

CRGB leds[NUM_LEDS];

int a = 0;                                                                                             


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(30); 
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, 1000);  
  Serial.begin(9600);

}

void loop() {
    for(int i=0; i>=NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(100);
    }
}
