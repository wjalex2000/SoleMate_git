#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//int input = A0;

//int counter= 30;
//int kill = 13;
//int motor1 = 9;
//int motor2 = 10;

int ok = 8;
int down = 7;
int screenNumber=0;
int buttonstate = 0;
int buttonstate2 = 0;


void setup() {
  Serial.begin(9600);
  Serial.print("Measuring Temp \n");
  pinMode(down,INPUT);

  lcd.begin(16, 2); // number of options = # rows
  
 lcd.print("----SoleMate----");
   delay(3000);
  
  lcd.setCursor(0,0);
  lcd.print("select phone?   ");
  lcd.setCursor(0,1);
  lcd.print("press ok");

}

void loop() {

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

  if (screenNumber == 0){
    lcd.setCursor(0,0);
    lcd.print("select Phone?  ");
    lcd.setCursor(0,1);
    lcd.print("press run or next");
  
  } else if (screenNumber == 1){
    lcd.setCursor(0,0);
    lcd.print("select keys?   ");
    lcd.setCursor(0,1);
    lcd.print("press run or next");
 
  } else if (screenNumber == 2){
    lcd.setCursor(0,0);
    lcd.print("select wallet?   ");
    lcd.setCursor(0,1);
    lcd.print("press run or next");
 
  } else if (screenNumber == 3){
    lcd.setCursor(0,0);
    lcd.print("select shoes?   ");
    lcd.setCursor(0,1);
    lcd.print("press run or next");
    
  } else if( buttonstate2==1){
  //if(cursor ==1)
 // if (cursor==2)
 // if(cursor ==3)
  //if(cursor =4)
}
}
