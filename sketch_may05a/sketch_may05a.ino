//define
#include <SoftwareSerial.h>
SoftwareSerial BT(8,9);// 接收腳, 傳送腳
int led=13;
char cmd;

//setup
void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(led, OUTPUT);
}

//loop
void loop()
{
  if(Serial.available()>0){
    cmd=Serial.read();
    //BT.println(cmd);
    switch(cmd){
      case 'o':
      case'O':
        digitalWrite(led, HIGH);
        //Serial.println("開燈囉~");
        break;
      case'x':
      case 'X':
        digitalWrite(led, LOW);
        //Serial.println("關燈囉~");
        break;
    }
  }
  if(BT.available()>0){
    cmd=BT.read();
    Serial.println(cmd);
    switch(cmd){
      case 'o':
      case'O':
        digitalWrite(led, HIGH);
        //Serial.println("開燈囉~");
        break;
      case'x':
      case 'X':
        digitalWrite(led, LOW);
        //Serial.println("關燈囉~");
        break;
    }
  }
}
