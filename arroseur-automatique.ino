
#include <LowPower.h>


int ledPin = 13; // LED connected to digital pin 13
int secondledPin = 7; // LED connected to digital pin 13
int inPin = A0;   // pushbutton connected to digital pin 7
int valRaw = 0;   // variable to store the read value
int valReal = 0;   // variable to store the read value

int relayPin = 8;

void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(secondledPin,OUTPUT);

  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin, LOW);
  pinMode(inPin, INPUT);      // sets the digital pin 7 as input

}

void loop()
{
  digitalWrite(ledPin,HIGH);
  digitalWrite(secondledPin,HIGH);
  delay(20);
  digitalWrite(ledPin,LOW);
  digitalWrite(secondledPin,LOW);
  valRaw = analogRead(inPin);   // read the input pin
  valReal = map(valRaw, 1023, 0, 0, 100 );

  if(valReal < 85 ){ //80% d'humidité
    waterthatshite();
  }


    // ATmega328P, ATmega168
/*  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);
           */

 LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
                SPI_OFF, USART0_OFF, TWI_OFF);

}

void waterthatshite()
{
  digitalWrite(relayPin, HIGH);
  digitalWrite(secondledPin,HIGH);
  delay(30000); //30 secondes
  digitalWrite(relayPin, LOW);
  digitalWrite(secondledPin,LOW);
}

