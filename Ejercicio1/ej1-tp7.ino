/*PULSADOR1, PULSADOR2, PULSADOR3 y LED1, LED2
Se debe realizar un programa que realice las siguientes funciones:
a) Al presionar el PULSADOR1, se debe empezar a incrementar el brillo del
LED1 de forma muy tenue o lentamente.
b) Si el PULSADOR2 es presionado, se debe iniciar el LED1 en su brillo
máximo, e irlo decrementando.
c) El botón PULSADOR3 cambiaría el led a ser utilizado por el LED2, para
ejecutar a) y b) sobre LED2. Si nuevamente es presionado, cambiaría el led
a ser utilizado por LED1, y así sucesivamente.
Recuerde el uso de buenas prácticas de programación. Debe utilizar la lógica de
una máquina de estados y evitar el uso de bucles.*/

#include <string.h>
#define PULSADOR1 9
#define PULSADOR2 8
#define PULSADOR3 6

char estado=' ';
int brillo=0;
int led=10;

void setup() {
Serial.begin(9600);
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(PULSADOR1,INPUT);
pinMode(PULSADOR2,INPUT);
pinMode(PULSADOR3,INPUT);
}

void loop() {

if(digitalRead(PULSADOR1)==HIGH){
  Serial.println("Hola Pulsador 1");
  estado='I';
  }
if(digitalRead(PULSADOR2)==HIGH){
  Serial.println("Hola Pulsador 2");
  brillo=255;
  estado='D';
}
if(digitalRead(PULSADOR3)==HIGH){
  Serial.println("Hola Pulsador 3");
  estado='C';
}
delay(1000);
if(estado=='I'){
  if(brillo<255){
  brillo++;
  }
 }
if(estado=='D'){
  if(brillo>0){
  brillo--;
  }
 }
if(estado=='C'){
  
  if(led==10){
    led=11;
    }
  else if(led==11){
    led=10;
    }  
  }
delay(1000);
 if(led==10){
  analogWrite(A0,brillo);
 } else if(led==11){
  analogWrite(A1,brillo);
 }
 Serial.print("El brillo es ");
 Serial.println(brillo);
 Serial.print("El led controlado es "); //el led rojo es el 11, el azul el 10
 Serial.println(led);
 Serial.print("El estado es ");
 Serial.println(estado);
 delay(1000);
}
