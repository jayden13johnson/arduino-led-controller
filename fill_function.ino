#include <FastLED.h> 

#define NUM_LEDS 100
#define LED_PIN 6

CRGB leds[NUM_LEDS];  

void setup() {
  // put your setup code here, to run once:

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(30); 
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, 3000);  
  Serial.begin(9600);

}

void loop() {
 fill_solid(leds, NUM_LEDS, CRGB::Red);
 FastLED.show();
 delay(500);

 fill_solid(leds, NUM_LEDS, CRGB::Green);
 FastLED.show();
 delay(500);

 fill_solid(leds, NUM_LEDS, CRGB::Blue);
 FastLED.show();
 delay(500);
}
