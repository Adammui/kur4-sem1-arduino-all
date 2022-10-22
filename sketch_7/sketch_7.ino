int ledr=12;
int ledy=11;
int ledg=10;
int cnt=0;
int state=1;

void setup()
{
  pinMode(ledr,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(ledg,OUTPUT);
}
void loop()
{
cnt++;
if(cnt==100)
{
  cnt=0;
  Statemashine();
}
delay(10);
}

void Statemashine(void)
{
  switch(state)
  {
  case 1:
  digitalWrite(ledr,HIGH);
  digitalWrite(ledy,LOW);
  digitalWrite(ledg,LOW);
  state++;
  break;
  case 2:
  digitalWrite(ledr,LOW);
  digitalWrite(ledy,HIGH);
  digitalWrite(ledg,LOW);
  state++;
  break;
  case 3:
  digitalWrite(ledr,LOW);
  digitalWrite(ledy,LOW);
  digitalWrite(ledg,HIGH);
  state=1;
  break;
  }
  }
