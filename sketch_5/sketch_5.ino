#define LED_PIN 9
// для работы с текстом существуют объекты-строки (англ. string)
String message;
void setup()
{
 pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600);
}
void loop()
{
 // передаваемые с компьютера данные поставляются байт за
 // байтом, в виде отдельных символов (англ. character). Нам
 // нужно последовательно их обрабатывать пока (англ. while)
 // в порту доступны (англ. available) новые данные
 while (Serial.available()) { 
 // считываем (англ. read) пришедший символ в переменную
 char incomingChar = Serial.read();
 // не стоит путать целые числа и символы. Они соотносятся
 // друг с другом по таблице, называемой кодировкой. Например
 // '0' — это 48, '9' — 57, 'A' — 65, 'B' — 66 и т.п.

 if (toLowerCase(incomingChar) == 'o')
 {
  Serial.print("Включено");
   message="255";
 }
 else if (toLowerCase(incomingChar) == 'f')
 {
  Serial.print("Выключено");
    message="0";
 }
 else if (incomingChar >= '0' && incomingChar <= '9') 
 {
   // если пришёл символ-цифра, добавляем его к сообщению
   message += incomingChar;
 } 
 else if (incomingChar == '\n') 
 {
   // если пришёл символ новой строки, т.е. enter, переводим
   // накопленное сообщение в целое число (англ. to integer).
   // Так последовательность символов '1', '2', '3' станет
   // числом 123. Результат выводим на светодиод
   analogWrite(LED_PIN, message.toInt());
   // обнуляем накопленное сообщение, чтобы начать всё заново
   message = "";
 }
 }
 // посылайте сообщения-числа с компьютера через Serial Monitor
}
