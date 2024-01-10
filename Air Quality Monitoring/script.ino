#include <LiquidCrystal.h>

#include <Timer.h>

#include <SoftwareSerial.h>
#include <MQ135.h>
Timer t;
SoftwareSerial myserial(9,10);
LiquidCrystal lcd(12,11,5,4,3,2);

#define heart 13
char *api_key="BYIK98CF6Y6UYXVF";     // Enter your Write API key from ThingSpeak
static char postUrl[150];
float air_quality;
int green=6;
int red=7;
//int tem;
void httpGet(String ip, String path, int port=80);

void setup()
{
  lcd.begin(16,2);
 myserial.begin(9600);  // wifi by default baud rate is 115200 
 Serial.begin(115200);   // for serial communication with Ardino
 Serial.println("Connecting Wifi....");
 connect_wifi("AT",1000);
 connect_wifi("AT+CWMODE=1",1000);
 connect_wifi("AT+CWQAP",1000); 
 connect_wifi("AT+RST",5000);
 connect_wifi("AT+CWJAP=\"ZONG-4G\",\"Pixels88375\"",10000);     // JAP is joint access point
 delay(5000);
 pinMode(green,OUTPUT);
 pinMode(red,OUTPUT);
 Serial.println("Wifi Connected"); 
 lcd.clear();
 lcd.print("WIFI Connected.");
 pinMode(heart, OUTPUT);
 delay(2000);
 t.oscillate(heart, 1000, LOW);
 t.every(1000, send2server);
}

void loop()
{

  MQ135 gasSensor = MQ135(A0);
  air_quality= gasSensor.getPPM();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AIR QUALITY:");
  lcd.setCursor(0,1);
  lcd.print(air_quality);
  lcd.print(" PPM");
  t.update();
  if(air_quality<=1000)
 { digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
}
  if(air_quality>1000)
  {digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  }
}

void send2server()
{

  char airStr[8];
  dtostrf(air_quality, 5, 3, airStr);
  sprintf(postUrl, "update?api_key=%s&field1=%s",api_key,airStr); 
  httpGet("api.thingspeak.com", postUrl, 80);
}

void httpGet(String ip, String path, int port)
{
  int resp;
  String atHttpGetCmd = "GET /"+path+" HTTP/1.0\r\n\r\n";
  String atTcpPortConnectCmd = "AT+CIPSTART=\"TCP\",\""+ip+"\","+port+"";
  connect_wifi(atTcpPortConnectCmd,1000);
  int len = atHttpGetCmd.length();
  String atSendCmd = "AT+CIPSEND=";
  atSendCmd+=len;
  connect_wifi(atSendCmd,1000);
  connect_wifi(atHttpGetCmd,1000);
}

void connect_wifi(String cmd, int t)
{
  int temp=0,i=0;
  while(1)
  {
    Serial.println(cmd);
    myserial.println(cmd); 
    while(myserial.available())
    {
      if(myserial.find("OK"))

      i=8;
    }
    delay(t);
    if(i>5)
    break;
    i++;
  }
  if(i==8)
  {
   Serial.println("OK");
     
  }
  else
  {
   Serial.println("Error");
    
  }
}
