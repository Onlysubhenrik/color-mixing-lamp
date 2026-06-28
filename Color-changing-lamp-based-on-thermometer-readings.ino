// currently doing research on how to adapt my code to work with a thermometer


const int SensorPin = A0;
const int greenLEDPin = 9;
const int redLEDPin = 10;
const int blueLEDPin = 11;

int R = 0;
int G = 0;
int B = 0;
int T = -1;
  


void setup() {
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop (){
  //thermometer values between 15-45 is going to display a red color and values between 15-0 is going to display a increasingly white color, anything below 0 is going to be shown as a cold and blue color
  int sensorVal = analogRead(SensorPin);
  //float voltage = (sensorVal/1024.0) * 5;
  //float T = (voltage - .5) * 100;
  delay(1000);
  Serial.println(T);
if (T < 0) {
  R = 0;
  G = 0;
  B = 255;
}
else if (T >= 0 && T < 7) {
    float t = T / 7.0;
    R = (int)(100 + t * 80);
    G = (int)(160 + t * 50);
    B = 255;
}
else if (T >= 7 && T <= 15) {
    float t = (T - 7) / 8.0;
    R = (int)(100 + t * 155);
    G = (int)(160 + t * 95);
    B = 255;
}
else if (T >= 15 && T <= 25) {
    float t = (T - 15) / 10.0;
    R = 255;
    G = (int)(255 - t * 105);
    B = (int)(255 - t * 255);
}
  else if (T > 25) {
    R = 255;
    G = 0;
    B = 0;
}





  analogWrite(redLEDPin, R);
  analogWrite(greenLEDPin, G);
  analogWrite(blueLEDPin, B);
  delay(1000);
  Serial.println(T);
  }
