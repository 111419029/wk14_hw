#define FIRST_LED_CONTROLL_PIN 2



void setup() {
  Serial.begin(9600);
  for(char i = FIRST_LED_CONTROLL_PIN; i < FIRST_LED_CONTROLL_PIN + 10; i++){
    pinMode(i, OUTPUT);
  }
}

void setLedBar(int ledOnCount){ // make 0~10 led on
  ledOnCount += FIRST_LED_CONTROLL_PIN;
  for (char i = FIRST_LED_CONTROLL_PIN; i < FIRST_LED_CONTROLL_PIN + 10; i++){
    digitalWrite(i, (i < ledOnCount));
  }
}

void loop() {
  int sensorRead = analogRead(A0);
  int ledBar = map (sensorRead, 0, 1023, 0, 10);
  setLedBar(ledBar);
  
}
