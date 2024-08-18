#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int m1=A3;
int m2=A2;
int m3=A5;
int m4=A4;
int i=0;
int tr=A1;
int ec=A0;
int tr1=7;
int ec1=6;
int buz =3;
int sw =4;
int dist()
{
  digitalWrite(tr,1);
  delayMicroseconds(10);
  digitalWrite(tr,0);
  delayMicroseconds(2);
  int dst=pulseIn(ec,1)/58.2;
  return dst;
}

int dist1()
{
  digitalWrite(tr1,1);
  delayMicroseconds(10);
  digitalWrite(tr1,0);
  delayMicroseconds(2);
  int dst1=pulseIn(ec1,1)/58.2;
  return dst1;
}
void setup() {
  // put your setup code here, to run once:
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
lcd.begin(16,2);
lcd.print("WELCOME");
Serial.begin(9600);
  pinMode(tr,OUTPUT);
  pinMode(ec,INPUT);

   pinMode(tr1,OUTPUT);
  pinMode(ec1,INPUT);
  pinMode(sw,INPUT);
  
  pinMode(buz,OUTPUT);  
  digitalWrite(buz,0); 
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(m1,1);
    digitalWrite(m2,0);
    digitalWrite(m3,1);
    digitalWrite(m4,0);

    int dst1=dist();
    int dst2=dist1();
    int vib=digitalRead(sw);

    Serial.println("F:"+String(dst1) + "  B:"+String(dst2) + "  V:"+String(vib));
    lcd.clear();
    lcd.print("F:"+String(dst1) + "  B:"+String(dst2) + "  V:"+String(vib));
   delay(500);

   if(dst1<10)
   {
    
    digitalWrite(buz,1);
    delay(1000);
    digitalWrite(buz,0);
    int kk=0;
    while(kk<2000)
    {
     
    digitalWrite(m1,1);
    digitalWrite(m2,0);
    digitalWrite(m3,1);
    digitalWrite(m4,0);
    delay(1);

        digitalWrite(m1,0);
    digitalWrite(m2,0);
    digitalWrite(m3,0);
    digitalWrite(m4,0);
    delay(1);
    }
   }
  if(dst2<10)
  {
      digitalWrite(buz,1);
    delay(100);
    digitalWrite(buz,0);
     delay(100);
  }
    
  if(vib==0)
  {
    lcd.setCursor(0,1);
    lcd.print("ACCIDENT DETECTED");
    digitalWrite(m1,0);
    digitalWrite(m2,0);
    digitalWrite(m3,0);
    digitalWrite(m4,0);
    send_sms();
  }
}


  void send_sms()
{
 
  digitalWrite(buz,1);


Serial.println("Sending SMS...");
Serial.println("AT");    
delay(1000);  
Serial.println("ATE0");    
delay(1000);  
Serial.println("AT+CMGF=1");    
delay(1000);  
Serial.print("AT+CMGS=\"6304863902\"\r\n");// Replace x with mobile number
delay(1000);
Serial.println("Alert: Accident detected  ");
delay(100);
Serial.println((char)26);// ASCII code of CTRL+Z
delay(5000);

Serial.println("Sending SMS...");
Serial.println("AT");    
delay(1000);  
Serial.println("ATE0");    
delay(1000);  
Serial.println("AT+CMGF=1");    
delay(1000);  
Serial.print("AT+CMGS=\"6304863902\"\r\n");// Replace x with mobile number
delay(1000);
Serial.println("Alert: Accident detected");
delay(100);
Serial.println((char)26);// ASCII code of CTRL+Z
delay(5000);
digitalWrite(buz,0);
while(1);
}
