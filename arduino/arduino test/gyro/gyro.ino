int sensorPin_x = 5;
int sensorValue_x = 0;
int sensorPin_y = 4;
int sensorValue_y = 0;
int sensorPin_ref = 3;
int sensorValue_ref = 0;
int delayValue;
float x_av, y_av, x_deg, y_deg;
unsigned long previousMillis, currMillis;
void setup() {
Serial.begin(9600);
}

void loop() {
  currMillis = millis();
  sensorValue_x = analogRead(sensorPin_x);
  sensorValue_y = analogRead(sensorPin_y);
  sensorValue_ref = analogRead(sensorPin_ref);
  delayValue = currMillis - previousMillis;
  x_av = (((sensorValue_x - sensorValue_ref) * 5000)/1024) * .67;  //4 x out   deg/s
  y_av = (((sensorValue_y - sensorValue_ref) * 5000)/1024) * .67;  //4 x out
  x_deg = (x_av * delayValue)/1000;
  y_deg = (y_av * delayValue)/1000;
  Serial.print(x_deg); Serial.print("            ");Serial.println(y_deg);
//  Serial.print(sensorValue_x);
//  Serial.print("   ");
//  Serial.print(sensorValue_y);
//  Serial.print("   ");
//  Serial.println(sensorValue_ref);
//  Serial.print(currMillis); Serial.print(" ");Serial.println(previousMillis);
  previousMillis = currMillis;
  delay(20);
}
