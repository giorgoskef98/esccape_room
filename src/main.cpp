#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {26, 25, 2, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 21, 22}; //connect to the column pinouts of the keypad

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 9, en = 13, d4 = 32, d5 = 33, d6 = 25, d7 = 26;
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//Variables
bool found_key = false;
int key[10];
char print_key[10];
int i = 0;

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello!!");
  delay(2000);
  lcd.clear();
  lcd.print("Insert Key!");
}

void loop() {
  char new_key = keypad.getKey();

  if (new_key) {
    key[i]        = new_key - '0';
    print_key[i]  = new_key;
    lcd.clear();
    lcd.print(print_key);
    if (key[i] == ('#'-'0')){
      if (key[0] == 4 && key[1] == 5 && key[2] == 2 && key[3] == 3){
        lcd.clear();
        lcd.print("Correct");
        delay(2000);
        lcd.clear();
        lcd.print("New Key: 999");
        delay(30000);
      }else{
        lcd.clear();
        lcd.print("Wrong! Try Again!");
        i = -1;
        key[10] = 0;
        print_key[0] = '0';
        print_key[1] = '0';
        print_key[2] = '0';
        print_key[3] = '0';
      }
    }
    if (key[i] == ('*'-'0')){
      lcd.clear();
      i = -1;
      key[10] = 0;
      print_key[0] = '0';
      print_key[1] = '0';
      print_key[2] = '0';
      print_key[3] = '0';
    }
    i++;
  }
}
 


