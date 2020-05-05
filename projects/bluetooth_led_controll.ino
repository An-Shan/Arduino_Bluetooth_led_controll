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
	//若收到「序列埠監控視窗」的資料,則送到藍牙模組
	if(Serial.available()>0){
		cmd=Serial.read();
		BT.println(cmd);
		switch(cmd){
			case 'o':
			case'O':
				digitalWrite(led, HIGH);
				break;
			case'x':
			case 'X':
				digitalWrite(led, LOW);
				break;
		}
	}
	// 若收到藍牙模組的資料,則送到「序列埠監控視窗」
	if(BT.available()>0){
		cmd=BT.read();
		Serial.println(cmd);
		switch(cmd){
			case 'o':
			case'O':
				digitalWrite(led, HIGH);
				break;
			case'x':
			case 'X':
				digitalWrite(led, LOW);
				break;
		}
	}
}