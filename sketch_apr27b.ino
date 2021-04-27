#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2,3);
int redPin=11;
int greenPin=10;
int bluePin=9;
String buffer=""; //안드로이드에서 보낸 값을 받는 변수
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available()){ //수신데이터가 존재하는 경우
    char data=BTSerial.read();
    if(data=='\n'){
      Serial.println(buffer);
      int brightness=buffer.substring(1).toInt(); //문자 1번째부터 끝까지(즉, 숫자 값만 가져오기)
      switch(buffer[0]){
        case 'R':
          analogWrite(redPin, brightness);
          break;
        case 'G':
          analogWrite(greenPin, brightness);
          break;
        case 'B':
          analogWrite(bluePin, brightness);
          break;
      }
      buffer=""; //한번 수행하고 나면 반드시 초기화해주어야 함
    }else{
      buffer+=data;
    }
  }

}
