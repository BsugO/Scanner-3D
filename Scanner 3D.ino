/*
 Name:		Scanner_3D.ino
 Created:	3/7/2020 12:22:56 PM
 Author:	PTL21166W-PAN006
*/

#include <Stepper.h>

const int stepsPerRevolution = 2048;
int val = 10;
int aux = 0;
int estado = 0;
int ledPin = 13;
int foto = 0;
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
	myStepper.setSpeed(1);
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	
}

void loop() {
	digitalWrite(ledPin, HIGH);
	myStepper.step(0);
	while (aux <= 2050)
	{
		estado = map(aux, 0, 2050, 0, 100);
		myStepper.step(val);
		Serial.println(aux);
		Serial.print(estado);
		Serial.println(" %");
		digitalWrite(ledPin, LOW);
		Serial.print("foto ");
		Serial.println(foto);
		delay(300);
		digitalWrite(ledPin, HIGH);
		delay(3000);
		aux = aux + val;
		foto++;
	}
	Serial.println("*-_Fim_-*");
	delay(10000);
}