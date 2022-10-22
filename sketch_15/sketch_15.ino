#define DATA_PIN 13 // пин данных (англ. data)
#define LATCH_PIN 12 // пин такта (англ. clock)
#define CLOCK_PIN 11 // пин строба (англ. latch)
int clicks = 0;
int a=0,b=0;
boolean buttonWasUp = true;
byte segments[10] = {
 0b01111101, 0b00100100, 0b01111010, 0b01110110, 0b00100111, 
 0b01010111, 0b01011111, 0b01100100, 0b01111111, 0b01110111
};
void setup()
{
 pinMode(DATA_PIN, OUTPUT);
 pinMode(CLOCK_PIN, OUTPUT);
 pinMode(LATCH_PIN, OUTPUT);

 //digitalWrite(LATCH_PIN, HIGH);
}
void loop()
{
  delay(500);
  if(clicks<100)
  {
  clicks +=1;
    a = clicks/10; 
    b = clicks%10;
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segments[b]); 
    digitalWrite(LATCH_PIN, HIGH);
    
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segments[a]); 
    digitalWrite(LATCH_PIN, HIGH);
  }
  else clicks=0;
}
