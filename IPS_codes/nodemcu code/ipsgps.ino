#include<ESP8266WiFi.h>
#include<WiFiClientSecure.h>
#include<UniversalTelegramBot.h>
#include<ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "smile123";
const char* password = "123456789";

// Initialize Telegram BOT
#define BOTtoken "5364480516:AAGhtXDqX54ch7oE86Piq6GG6-b8LF_cq6A"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "596045813"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


char Start_buff[70]; 
int i,z;             
char ch;
int str_len;
 char textmessage[20];



void MESSAGE_SEND();
void WAITING();
void setup() 
{
    // initialize the Serial
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");

    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "SMART PARKING SYSTEM USING ARDUINO");
  
//TEST();   
    
}
void loop() 
{
  
  WAITING();
    
}
void MESSAGE_SEND()
{
  bot.sendMessage(CHAT_ID, "SEND START TO CONTINUE"); 
  // myBot.sendMessage(msg_sender_id1, "WELCOME TO ATM"); 
  
}


char Serial_read(void)
{
      char ch;
      while(Serial.available() == 0);
      ch = Serial.read(); 
      return ch;
}
void WAITING()
{
   Serial.println("WAIT");
  
  buffer_clear();
        msg.text[0]='\0';
        msg.text[1]='\0';
        msg.text[2]='\0' ;
        msg.text[3]='\0';
        msg.text[4]='\0';
        msg.text[5]='\0';
           
 while(1)
 { 
      if (Serial.available() > 0)
      {
          ch=Serial.read();
          Serial.print(ch);
        }
           Serial.println("hello");
        
          while(Serial_read()!='$');
          i=0;
          while((ch=Serial_read())!='#')
          {
            Start_buff[i] = ch;
             i++;
          }  
          Start_buff[i]='\0';
       }
       Serial.println(Start_buff);
       bot.sendMessage(CHAT_ID, Start_buff); 
      delay(100);

       
   if((Start_buff[0]=='E'))
 {
  String one = "PACKAGE LOCATION AT:https://www.google.com/maps/?q=";
String two = "," ;   
String message = one +"12.9258" +two + "77.5266";

// Convert String to char array

  charint str_len = message.length() + 1;
    textmessage[str_len];
    
   message.toCharArray(textmessage,str_len);
   Serial.println(textmessage);
    bot.sendMessage(CHAT_ID,textmessage);
    delay(100);
   }
   if((Start_buff[0]=='S'))
    {
    String one = "PACKAGE LOCATION AT:https://www.google.com/maps/?q=";
  String two = "," ;   
  String message = one +"12.9092" +two + "77.5666";


   Convert String to char array
  int str_len = message.length() + 1;
  char textmessage[str_len];
  message.toCharArray(textmessage,str_len);
  Serial.println(textmessage);
    bot.sendMessage(CHAT_ID,textmessage);
  delay(100);
   }
 }

}
void buffer_clear()
{
  for(z=0;z<60;z++)
  {
    Start_buff[z]='\0';
     textmessage[z]='\0';
    
  } 
}
void buffer1_clear()
{
  for(z=0;z<5;z++)
  {
   
   textmessage[z]='\0';
    
  } 

}
void TEST()
{
 Serial.begin(9600);
    Serial.println("Starting TelegramBot...");

    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
const char* ssid = "smile12345";
const char* password = "123456789";

// Initialize Telegram BOT
#define BOTtoken "5316821345:AAHqngITgMw-_tFsqia94d69j85BBkCSyJE"  // your Bot Token (Get from Botfather))

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  bot.sendMessage(CHAT_ID, "INTELLIGENT PACKAGE SYSTEM");


  MESSAGE_SEND();
WAITING();
  
