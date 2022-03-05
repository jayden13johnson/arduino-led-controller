
#include <FastLED.h> 

#define NUM_LEDS 200
#define LED_PIN 6 
#define trigPin 9
#define echoPin 10

uint8_t hue = 0;
long duration;
int distance;
int LED_number;
CRGB leds[NUM_LEDS];  

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50); 
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, 4000);  
 // Serial.begin(9600); 
  
}

void loop() {


 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);
 distance = duration *0.034/2;

// Serial.print("Distance: ");
// Serial.println(distance); 

 if(distance < 200) {
  if(44 + floor((distance/1.667) + 10 < LED_number)) {          //leds[44] is the first one on the ground (rest are on the wall). This line is to prevent random jumping when the object is still due to inconsistencies in the sensor.
   FastLED.clear();
   FastLED.show();
   LED_number = 44 + floor((distance/1.667));
   leds[LED_number - 2] = CRGB::Green;
    leds[LED_number - 1] = CRGB::Red;
    leds[LED_number] = CRGB::Red;
    leds[LED_number + 1] = CRGB::Red;
    leds[LED_number + 2] = CRGB::Green;

     FastLED.show(); 
  }
 }

}
