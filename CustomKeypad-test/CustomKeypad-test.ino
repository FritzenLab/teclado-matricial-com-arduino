/*
 * Teclado matricial com Arduino. Funciona com teclado matriciais contato seco (somente chaves)
 * e utiliza pull-ups internos do Arduino para funcionar.
 * 
 * Baseado em:

 @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| 

* Esquema de ligação utilizado: http://arduinolearning.com/learning/basics/arduino-numeric-keypad.php
* 
* Sketch adaptado para utilização no blog FritzenLab por Clóvis Fritzen em 07/10/2017
* http://www.FritzenLab.com.br
* 
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad
char customKey;

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
