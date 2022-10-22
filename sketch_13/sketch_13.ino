#define FIRST_LED_PIN 2
#define LAST_LED_PIN 11
void setup()
{
 // Так все пины от 2-го по 11-й друг за другом станут выходами
 for (int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; ++pin)
 pinMode(pin, OUTPUT);
}
void loop()
{
 // получаем время в миллисекундах, прошедшее с момента
 // включения микроконтроллера
 unsigned int ms = millis();
 // нехитрой арифметикой вычисляем, какой светодиод
 // должен гореть именно сейчас. Смена будет происходить
 // каждые 120 миллисекунд. Y % X — это остаток от
 // деления Y на X; плюс, минус, скобки — как в алгебре.
 for (int i = 8; i > 4; i--) { //11 0
   
 digitalWrite(i, HIGH);
 delay(1000);
 digitalWrite(i, LOW);
 }
 // включаем нужный светодиод на 10 миллисекунд, затем —
 // выключаем. На следующем проходе цикла он снова включится,

}
