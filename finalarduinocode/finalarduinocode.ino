#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//int input = A0;

//int counter= 30;
int kill = 13;
int killsw = 10;
int motor1 = 9;
//int motor2 = 10;

int ok = 8;
int down = 7;
int screenNumber=0;
int ind = 0;
int buttonstate = 0;
int buttonstate2 = 0;
int kstate =0;
int x=0;
int y=0;
int time;
double c=0;

void setup() {
  Serial.begin(9600);

  pinMode(motor1, OUTPUT);
  pinMode(down,INPUT);
  pinMode(ok,INPUT);
  pinMode(killsw,INPUT);
  

  lcd.begin(16, 2); // number of options = # rows
  Serial.print("sibal");
 lcd.print("----SoleMate----");
   delay(3000);
  
  lcd.setCursor(0,0);
  lcd.print("select phone?   ");
  lcd.setCursor(0,1);
  lcd.print("press ok");

}


//void(* resetFunc) (void) = 0;

void loop() {
kstate = digitalRead(killsw);
 buttonstate = digitalRead(down);
buttonstate2 = digitalRead(ok);
 if (buttonstate == 1) {
    if (screenNumber < 4) {
      screenNumber = screenNumber + 1;
    }
    else {
      screenNumber = 0;
      }
    //delay a little to avoid bouncing
    delay(300);
    }

  if (screenNumber == 0 && ind == 0){
    lcd.setCursor(0,0);
    lcd.print("select Phone?  ");
    lcd.setCursor(0,1);
    lcd.print("run or next?");
  
  } else if (screenNumber == 1 && ind == 0){
    lcd.setCursor(0,0);
    lcd.print("select keys?   ");
    lcd.setCursor(0,1);
    lcd.print("run or next?");
 
  } else if (screenNumber == 2 && ind == 0){
    lcd.setCursor(0,0);
    lcd.print("select wallet?   ");
    lcd.setCursor(0,1);
    lcd.print("run or next?");
 
  } else if (screenNumber == 3 && ind == 0){
    lcd.setCursor(0,0);
    lcd.print("select shoes?   ");
    lcd.setCursor(0,1);
    lcd.print("run or next?");
    
  }
  if( buttonstate2==1){
    ind = 1;
    lcd.setCursor(0,1);
    lcd.print("                ");
    
        if(screenNumber == 0){
        lcd.setCursor(0,0);
        lcd.print("cleaning a Phone");
        //control();
        x=1;  
        y=1;    
        time = 10;  
      } else if(screenNumber ==1){
        lcd.setCursor(0,0);
        lcd.print("cleaning keys   ");
        x=1;  
        y=1;       
        time = 20;  
      } else if (screenNumber ==2 ){
        lcd.setCursor(0,0);
        lcd.print("cleaning wallet");
        x=1;  
        y=1;       
        time = 30;
      } else if (screenNumber == 3){
        lcd.setCursor(0,0);
        lcd.print("cleaning shoes ");
        x=1;  
        y=1;       
        time = 40;
      }
     }
     
     if(x==1){
      Serial.print("motor1 workibg");
      analogWrite(motor1,255);
      delay(500);
      c += 0.5;
      analogWrite(motor1,0);     
      }
      if(y==1){ 
      //x=kstate;
      x=1;
      }
      Serial.print(c);
      if(c==time){
       // resetFunc();
       x=0;
       lcd.setCursor(0,0);
       lcd.print("complete!          ");
      }
      
}

void control(){
  kstate = digitalRead(killsw);
          while(kstate==0){
           Serial.print(kstate);
           analogWrite(motor1, 255);
           if(kstate==0){
           delay(10000);
           } else{
           break;
           }
          }
          analogWrite(motor1,0);
  
  // phone 40 do    60 rpm
  // keys 60 do     60 rpm
  // wallet no temp 60 rpm
  // shoes 50 do    60 rpm

 }
 
/*
double tempCK() {
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
  
  return tempC
}
int motorPin = 9;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  analogWrite(motorPin,123);
} 
*/
