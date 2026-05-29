#define PHOTORESISTOR_PIN A0
#define PHOTORESISTOR_MIN 1
#define PHOTORESISTOR_MAX 50
#define LED_PIN 9
#define LED_MIN 0
#define LED_MAX 255

void setup(){
  Serial.begin(9600);
}

short formatter(short from_num, short from_left, short from_right, short to_left, short to_right);
short getPhotoresistorInput();
void setLed(short lightness);

void loop(){
  setLed(formatter(getPhotoresistorInput(), PHOTORESISTOR_MIN, PHOTORESISTOR_MAX, LED_MIN, LED_MAX));
  delay(3); 
}


short getPhotoresistorInput(){
  return analogRead(PHOTORESISTOR_PIN);
}
short formatter(short from_num, short from_left, short from_right, short to_left, short to_right){
  if (from_num < from_left)
    return to_left;
  if (from_num > from_right)
    return to_right;
  return map(from_num, from_left, from_right, to_left, to_right);
}
void setLed(short lightness){
  analogWrite(LED_PIN, lightness);
}