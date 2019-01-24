#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

const unsigned char nu1[]="+918428380941";
const unsigned char m1[]="OTP:";
int m1f= 4;
const byte ROWS = 4; 
const byte COLS = 3; 
char hexaKeys[ROWS][COLS] = 
{
  {
    '1','2','3'              }
  ,
  {
    '4','5','6'              }
  ,
  {
    '7','8','9'              }
  ,
  {
    '*','0','#'              }
};
byte rowPins[ROWS] = {
  A3, A2, A1, A0}; 
byte colPins[COLS] = {
  7, 6, 5}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
char customKey ;
int pos;
unsigned char v1[13]="270019DAC226";
unsigned char rfid[13];
unsigned char otpnu[5];
unsigned char otpenter[5];
int r1,r2;
char n,n1;
boolean stringComplete = false; 
String inputString = "";  
boolean f1,f2,f3;
void setup()
{
  r1=1;
  otpnu[0]=1;
  otpnu[1]=2;
  otpnu[2]=3;
  otpnu[3]=4;
  Serial.begin(9600);
  pinMode(m1f, OUTPUT);
  digitalWrite(m1f, LOW); 
  lcd.begin(16, 2);
  lcd.print("Locker System");
  delay(1000);
  digitalWrite(m1f, LOW); 

  GSM_MODEM_Init();
}

void loop ()
{

  if(f1==0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Show your card");
  }
  if(stringComplete)
  {
    f1=1;
    //Serial.println(inputString);
    for(n1=0;n1<=11;n1++)
    {
      rfid[n1]=inputString[n1];
    }
    r1=String_Compare(v1,rfid,10);
    lcd.setCursor(0, 1);
    //lcd.print(r1);
    stringComplete=false;
    n=0;
    inputString="";
  }
  if(r1==0&&f1==1&&f2==0)
  {
    lcd.setCursor(0, 0);
    lcd.print("OTP sending      ");
    for(int i=0;i<4;i++)
    otpnu[i]=random(0,9);
    GSM_MODEM_Send(nu1,m1);
    lcd.setCursor(0, 0);
    lcd.print("OTP sent        ");
    delay(5000);
    f2=1;
  }
  else if(f1==1&&r1!=0)
  {
    lcd.setCursor(0, 0);
    lcd.print("Access denied     ");
    lcd.setCursor(0, 1);
    lcd.print("Wrong card         ");
    delay(3000);
    lcd.setCursor(0, 1);
    lcd.print("                   ");
    f1=0;
  }
  if(f1==1&&f2==1)
  {
    lcd.setCursor(0, 0);
    lcd.print("Enter OTP     ");
    customKey = customKeypad.getKey(); 
    if(customKey)
    {
 
       lcd.setCursor(0+pos,1);
      lcd.print(customKey);
      otpenter[pos]=customKey-48;
      pos++;
      if(pos>3)pos=0;
    }
    if(customKey=='*')
    {
      if(otpenter[0]==otpnu[0]&&otpenter[1]==otpnu[1]&&otpenter[2]==otpnu[2]&&otpenter[3]==otpnu[3])
      {
        lcd.setCursor(0, 0);
        lcd.print("OTP ok        ");
        digitalWrite(m1f, HIGH); 
        delay(2000);
        digitalWrite(m1f, LOW);
      }
      else
      {
        lcd.setCursor(0, 0);
        lcd.print("OTP error        ");

      }
      delay(3000);
      lcd.setCursor(0, 1);
      lcd.print("                   ");
      f1=0;
      f2=0;
      pos=0;
    }
  }

}
void GSM_MODEM_Enter()
{
  Serial.write(0x0D);
  Serial.write(0x0a);
  delay(50);
}
void GSM_MODEM_Init()
{
  Serial.print("AT");
  GSM_MODEM_Enter();
  Serial.print("AT");
  Serial.print("AT+CMGF=1");
  GSM_MODEM_Enter();
  Serial.print("AT+CNMI=2,2,0,0,0");
  GSM_MODEM_Enter();
}
void GSM_MODEM_Send(const unsigned char *Number,const unsigned char *Message)
{  
  GSM_MODEM_Init();

  Serial.print("AT+CMGS=");
  Serial.write('"');
  while(*Number)
  {
    Serial.write(*Number++);  
  }
  Serial.write('"');  
  GSM_MODEM_Enter();

  while(*Message)
  {
    Serial.write(*Message++); 
  } 
  Serial.write(otpnu[0]+48);
  Serial.write(otpnu[1]+48);
  Serial.write(otpnu[2]+48);
  Serial.write(otpnu[3]+48);
  Serial.write(0x1A);

}
void serialEvent() 
{
  while (Serial.available()) 
  {

    char inChar = (char)Serial.read(); 
    inputString += inChar;
    n++;
    stringComplete=1;
  }
}
int String_Compare(unsigned char src[],unsigned char dest[],unsigned char v)
{
  int i;
  return src[i]-dest[i];
}
