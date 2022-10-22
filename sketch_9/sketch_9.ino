#include <math.h>
int minute=1;
int row_excel = 0; // количество строк
int test = 123; // тестовая переменная, которая будет передана excel
int test_2 = 456; // вторая тестовая переменная, которая будет передана excel

#define TERMIST_B 4300
#define VIN 5.0

void setup() {
  Serial.begin  (9600);
  Serial.println("CLEARDATA"); 
  Serial.println("LABEL,Time,Temperature,Counter"); // заголовки столбцов
}

void loop() {
  row_excel++; 
  Serial.print("DATA, TIME,");
// вычисляем температуру в °С с помощью магической формулы. 
// Используем при этом не целые числа, а вещественные. Их ещё 
// называют числами с плавающей (англ. float) точкой. В 
// выражениях с вещественными числами обязательно нужно явно 
// указывать дробную часть у всех констант. Иначе дробная 
// часть результата будет отброшена 
float voltage = analogRead(A0) * VIN / 1024.0; 
float r1 = voltage / (VIN - voltage); 
float temperature = 1./( 1./(TERMIST_B)*log(r1)+1./(25. + 273.) ) - 273;
// печатаем текущую минуту и температуру, разделяя их табом. 
// println переводит курсор на новую строку, а print — нет 
Serial.print(temperature); 
Serial.print(",");
Serial.println(row_excel);
delay(6000); 
// засыпаем на минуту 
++minute;
}
