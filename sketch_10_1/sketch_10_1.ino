/*const int pinPhoto = A0;
int raw = 0;

void setup() {
  Serial.begin(9600);
  pinMode( pinPhoto, INPUT );
}

void loop() {
  raw = analogRead( pinPhoto );
  Serial.println( raw );
  delay(200);
}
*/
const int pinPhoto = A0;
const int pot = A1;
const int led = 13;
int raw = 0;
int p = 0;

void setup() {
  pinMode( pinPhoto, INPUT );
  pinMode( led, OUTPUT );
  Serial.begin(9600);
}

void loop() {
  raw = analogRead( pinPhoto );
  p = analogRead(pot);
  Serial.println( p );
  if( raw < p)
    digitalWrite( led, HIGH );
  else
    digitalWrite( led, LOW );
  delay(200);
}
