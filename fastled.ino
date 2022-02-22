#include <FastLED.h> 

#define NUM_LEDS 15
#define LED_PIN 6

CRGB leds[NUM_LEDS];

int a = 0;                                                                                             


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(60); 
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, 300);  
  Serial.begin(9600);

}

void loop() {
int b = a % 3;

switch(b) {
  case 0:
    for(int i=0; i<=NUM_LEDS-1; i++) {
    leds[i] = CRGB::Red; 
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for(int i=NUM_LEDS-2; i>=0; i--) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  a++;
  Serial.println(a);
  break;
  case 1:
  for(int i=0; i<=NUM_LEDS-1; i++) {
    leds[i] = CRGB::Blue; 
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for(int i=NUM_LEDS-2; i>=0; i--) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  a++;
  break;
    case 2:
  for(int i=0; i<=NUM_LEDS-1; i++) {
    leds[i] = CRGB::Green; 
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  for(int i=NUM_LEDS-2; i>=0; i--) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;
    FastLED.show();
  }
  a++;
  break;
}


}
