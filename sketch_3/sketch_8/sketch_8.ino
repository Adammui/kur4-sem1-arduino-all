//конечный автомат с режимами
int LEDred=12;
int LEDyellow=11;
int LEDgreen=10;
int cnt=0;
int state_normal=1;
byte state_sleep=1;
char regim='';
void setup()
{
  pinMode(LEDred,OUTPUT);
  pinMode(LEDyellow,OUTPUT);
  pinMode(LEDgreen,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()) {
    
    char incomingChar = Serial.read();
    if ( toLowerCase(incomingChar)=='N')
    {
      Serial.print("Нормальный режим работы");
      Serial.print("/n");
      regim='N';
    }
     else if ( toLowerCase(incomingChar)=='S')
    {
      Serial.print("Спить");
      Serial.print("/n");
      regim='S';
    }
     else if ( toLowerCase(incomingChar)=='R')
    {
      Serial.print("Горит красным");
      Serial.print("/n");
      regim='R';
    }
     else if ( toLowerCase(incomingChar)=='G')
    {
      Serial.print("Горит зеленым");
      Serial.print("/n");
      regim='G';
    }
  cnt++;
  if(cnt==100)
  {
    cnt=0;
    Statemashine();
   }
    delay(10);
  }
}

void Statemashine(void)
{
  switch(regim)
  {
    case 'N':
    Normal();
      if( state_normal==4)
        {state_normal=1;}
      else {state_normal++;}
    break;

    case 'S':
    digitalWrite(LEDred,LOW);
    digitalWrite(LEDyellow,state_sleep);
    digitalWrite(LEDgreen,LOW);
    delay(500);
    state_sleep= !state_sleep;
    break;

    case 'R':
    digitalWrite(LEDred,HIGH);
    digitalWrite(LEDyellow,LOW);
    digitalWrite(LEDgreen,LOW);
    break;
    
    case 'G':
    digitalWrite(LEDred,HIGH);
    digitalWrite(LEDyellow,LOW);
    digitalWrite(LEDgreen,LOW);
    delay(500);
    state=1;
    break;
    
    case '' :
    digitalWrite(LEDred,LOW);
    digitalWrite(LEDyellow,LOW);
    digitalWrite(LEDgreen,LOW);
    break;
    }
}


void Normal(void)
{
  switch(state_normal)
  {
    case 1:
    digitalWrite(LEDred,HIGH);
    digitalWrite(LEDyellow,LOW);
    digitalWrite(LEDgreen,LOW);
    delay(2500);
    //state++;
    break;

    case 2:
    digitalWrite(LEDred,HIGH);
    digitalWrite(LEDyellow,HIGH);
    digitalWrite(LEDgreen,LOW);
    delay(500);
    //state++;
    break;

    case 3:
    digitalWrite(LEDred,LOW);
    digitalWrite(LEDyellow,LOW);
    digitalWrite(LEDgreen,HIGH);
    delay(2500);
    //state++;
    break;
    
    case 4:
    digitalWrite(LEDred,LOW);
    digitalWrite(LEDyellow,HIGH);
    digitalWrite(LEDgreen,LOW);
    delay(500);
   //state_normal=1;
    break;
    
    }
}
