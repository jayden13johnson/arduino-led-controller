const int led = 13;
const int photoR = A0;

int lightLevel;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(photoR, INPUT);
  digitalWrite(led, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(photoR);
  Serial.print("The photoresistor is reading : ");
  Serial.println(lightLevel);
  if (lightLevel < 2) {
      digitalWrite(led, HIGH);
  }
  else if (lightLevel > 2) {
    digitalWrite(led, LOW);
  } 
  delay(100);

}
