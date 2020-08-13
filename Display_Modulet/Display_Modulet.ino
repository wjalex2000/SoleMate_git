#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(25, 4); // number of options = # rows
  // Print a message to the LCD.
    
   lcd.print("----SoleMate----");
   delay(3000);
 
  
  lcd.setCursor(0,0);
  lcd.print("select phone?");
  lcd.setCursor(0,1);
  lcd.print("press ok");

}
 
void loop() {
   
  // Turn off the display:
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}
