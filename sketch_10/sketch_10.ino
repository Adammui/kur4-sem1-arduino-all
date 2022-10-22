int LED=13;
int LDR=A0;
int Poti=A1;
int cnt=0;

void setup() {
 pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() {
 /*if (analogRead(LDR)>analogRead(Poti)) cnt=0;
 if (analogRead(LDR)<analogRead(Poti)) cnt++;
     Serial.print("LDR");
Serial.println(LDR);
 Serial.print("POTI");
Serial.println(Poti);

 if(cnt>300)
 {
  //Serial.println("включение");
  digitalWrite(LED,HIGH);
  do{
    delay(1000);
  }while(analogRead(LDR)<analogRead(Poti));
  cnt=0;
  digitalWrite(LED,LOW);
 }
 delay(10);*/

 int val = analogRead(LDR);
  Serial.println(val);
  if (val < 300) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}
