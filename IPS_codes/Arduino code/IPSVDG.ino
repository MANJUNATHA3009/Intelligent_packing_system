#include<LiquidCrystal.h>
#include<DHT.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Keypad.h>

#include<String.h>
#define Type DHT11
const int rs = 12, en = 13, d4 = 8, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int X=A1;
int Y=A2;
int ldr=A0;
int IR=40;
int IN1=6;
int IN2=7;
//int gps;
int DHT11PIN=38;
DHT HT(DHT11PIN,Type);
float Humidity;
float tempC;
int valueX;
int valueY;
int value1;
long randNum;
char keyp[6],ch;//keypad
String s;//keypad
String s1;
int str_len;
 char textmessage[20],mystr[20];
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {38,40,42,44}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {46,48,50,52}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
//TinyGPS gps;
void setup() {
  pinMode(DHT11PIN,INPUT);
  pinMode(X,INPUT);
pinMode(Y,INPUT);
pinMode(ldr,INPUT);
pinMode(IR,INPUT);
HT.begin();
  Serial.begin(9600);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INTELLIGENT PACKAGE");
   lcd.setCursor(0,1);
   lcd.print("SYSTEM");
  delay(1000);
 }
void loop(){
  IRcheck();
  tempcheck();
  accelometerRead();
  ldrcheck();
  keycheck();
  }

void IRcheck(){
  if(digitalRead(IR)==0){
    lcd.clear();
    lcd.print("OBJECT PLACED");
    delay(1000);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    delay(1000);
  }
  else{
    lcd.clear();
    lcd.print("NO OBJECT");
    delay(1000);
  }
}
void accelometerRead(){
  valueX=analogRead(X);
  valueY=analogRead(Y);
  
  Serial.println(valueX);
  Serial.println(valueY);
  delay(1000);
  if(valueX>400 || valueX<300)
  {
    lcd.clear();
    lcd.print("FELL DOWN");
    //Serial.print("A");
    
    delay(3000);
  }
//  if(valueY>400 || valueY<300)
//  {
//    lcd.clear();
//    lcd.print("FELL DOWN");
////    delay(1000);
//  }
  else{
     lcd.clear();
    lcd.print("NORMAL");
   
   Serial.print("NORMAL");
    delay(3000);
    
  }
}
  void tempcheck(){
    Humidity=HT.readHumidity();
    tempC=HT.readTemperature();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity:");
    lcd.print(Humidity);
    lcd.setCursor(0,1);
    lcd.print("Temp:");
    lcd.print(tempC);
    Serial.print("Humidity:");
    Serial.print(Humidity);
    Serial.print("Temperature:");
    Serial.print(tempC);
    Serial.println(" c ");
    delay(3000);
  }
  


void ldrcheck(){
  value1=analogRead(ldr);
  Serial.print(value1);
  lcd.clear();
  lcd.print("LDRValue:");
  lcd.print(ldr);
  delay(1000);
  if(value1<300){
    lcd.clear();
    lcd.print("SEALED BOX");
    delay(3000);
  }
  
  else{
     lcd.clear();
     lcd.setCursor(0,0);
    lcd.print("SOMEONE TRY TO");
    lcd.setCursor(0,1);
    lcd.print("OPEN THE PACKAGE");
    delay(2000);
  }
}

void keycheck(){
//  if(gps==20)
//  {
//    gps=0;
randNum=random(100000,999999);
    s1=String(randNum);
    Serial.println("$OTP:"+s1+"#");
    delay(2000);
    for(int i=0;i<3;i++)
    {
    lcd.clear();
    lcd.print("ENTER OTP");
    
    delay(2000);
    keyPressed();
    if(s==s1)
    {
      lcd.clear();
     lcd.print("OTP MATCHED");
     delay(2000);
     lcd.setCursor(0,1);
     lcd.print("UNLOCKING PACKAGE");
     delay(2000);
      
    }
  }
}

//    digitalWrite(IN1,LOW);
//    digitalWrite(IN2,HIGH);
//    delay(1000);
void keyPressed()
{
  int l=0;
  while(1)
  {
    while(ch=customKeypad.getKey())
    {
      keyp[l]=ch;
      Serial.println(keyp[l]);
      lcd.setCursor(l,1);
      lcd.print(keyp[l]);
      
      l++;
    }
    keyp[6]='\0';
    if(l==6)
      break;
  }
  s=String(keyp);
  delay(1000);
} 
