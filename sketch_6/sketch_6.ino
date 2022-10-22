/*byte led=0; //Состояние светодиода
byte oldled=1; //Последнее состояние светодиода, для исключения ложных переключений
 
void setup()
{
 pinMode(13, OUTPUT);
 pinMode(2, INPUT);
 Serial.begin(9600);
}
 
void loop()
{
if(digitalRead(2)==HIGH) { //Когда нажата кнопка
   Serial.print("ВКЛЮЧЕНА     ");
   if (led==oldled) { //Проверка, что состояние кнопки изменилось
     led=!led;
   }
} else {
 oldled=led;
}
 digitalWrite(13,led); //Переключаем светодиод
 
}

*/

byte led=0; //Состояние светодиода
byte oldled=1; //Последнее состояние светодиода, для исключения ложных переключений
 long previousMillis = 0;
void setup()
{
 pinMode(13, OUTPUT);
 pinMode(2, INPUT);
}
 
void loop()
{
if(digitalRead(2)==HIGH) { //Когда нажата кнопка
   //Если от предыдущего нажатия прошло больше 100 миллисекунд
   if (millis() - previousMillis < 100) {
     //Запоминаем время первого срабатывания
     previousMillis = millis();
     if (led==oldled) { //Проверка, что состояние кнопки изменилось
       led=!led;
     }
   }
} else {
 oldled=led;
}
digitalWrite(13,led); //Переключаем светодиод
 
}
