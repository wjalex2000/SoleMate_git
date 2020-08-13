//TMP36 sensor testing
int input = A0;
int kill_pin = 2; 

void setup() {
  Serial.begin(9600);
  pinMode(kill_pin, INPUT);
  Serial.print("Measuring Temp \n");
}

void loop() {

  bool kill = true;
  Serial.print("Default State: Killed \n");

  while(false){
    if (digitalRead(kill_pin)==1){
      if (kill == true){
        kill = false;
        Serial.print("Machine Alive \n");
        tempMeasure();
      }
    }else{
      kill = false;
      Serial.print("Machine Killed \n");
    }
  }
}

void tempMeasure(){
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
