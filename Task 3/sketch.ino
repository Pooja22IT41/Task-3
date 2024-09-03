#include <Keypad.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const byte ROWS = 4;  
const byte COLS = 4;  
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    
byte colPins[COLS] = {A3, A2, A1, A0}; 


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";  
String inputPassword;      
bool locked = true;        

void setup() {
  lcd.begin(16, 2);       
  lcd.print("Enter Password");
  delay(1000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(locked ? "Locked" : "Unlocked");

  char key = keypad.getKey();  

  if (key) {
    
    if (key == '*') {
      inputPassword = "";
      lcd.setCursor(0, 1);
      lcd.print("Cleared      ");
    }
    
    else if (key == '#') {
      if (inputPassword == password) {
        locked = !locked;  
        lcd.setCursor(0, 1);
        lcd.print(locked ? "Locked" : "Unlocked");
        delay(1000);
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Wrong Password");
        delay(1000);
      }
      inputPassword = "";  
      lcd.clear();
    } 
    
    else {
      inputPassword += key;
      lcd.setCursor(0, 1);
      lcd.print(inputPassword);
    }
  }
}
