//TMP36 sensor testing
int input = A0;

void setup() {
  Serial.begin(9600);
  Serial.print("Measuring Temp \n");
}

void loop() {
  int raw = analogRead(input);
  float voltage = raw * 5.0;
  voltage /= 1024.0;
  Serial.print(voltage);
  Serial.print("Volts \n");
  float tempC = (voltage - 0.5) * 100;
  Serial.print(tempC); 
  Serial.print("Degrees Celcius \n");
  float temF = (tempC * 9.0 / 5.0) + 32.0;
  Serial.print(temF); 
  Serial.print("Degrees Farenheit \n");
  
  delay(1000);
}
