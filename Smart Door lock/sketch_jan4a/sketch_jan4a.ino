#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
//------------LCD Display-----------
const int LCD_ADDRESS= 0x27;
const int LCD_COLUMNS= 16;
const int LCD_ROWS= 2;

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

//-------------keypad-------------------
const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};    // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};  // connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

//----------------password----------------------

String inputPassword="";
String systemPassword="2003#";

int password_length=5;
//-------------------lock------------------------
int lock=10;
void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
  
  Serial.begin(9600);
  pinMode(lock, OUTPUT);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Your pass:");
  
  int i=0;
  while(1){
  	char key=keypad.getKey();
  	if(key){
    	if(inputPassword.length()<password_length){
      		inputPassword=inputPassword+key;
          	
        	lcd.setCursor(i,1);
        	lcd.print("*");
          	i++;
      		if(inputPassword.length()==password_length){
              if(inputPassword==systemPassword){
              	lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Door Unlocked");
                digitalWrite(lock, HIGH);
                delay(3000);
                inputPassword=""; //password reset
                break;
              }
              else{
              	lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Access Denied");
                delay(2000);
                inputPassword=""; //password reset
                break;
              }
      		}
    	}
  	}
  }
 
digitalWrite(lock, LOW);
  
}
