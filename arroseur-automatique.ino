
#include <LowPower.h>


int ledPin = 13; // LED connected to digital pin 13
int inPin = 7;   // pushbutton connected to digital pin 7
int val = 0;   // variable to store the read value

int relayPin = 8;

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(relayPin,OUTPUT);
  digitalWrite(relayPin, LOW);
  pinMode(inPin, INPUT);      // sets the digital pin 7 as input
  
}

void loop()
{
  digitalWrite(13,HIGH);
  delay(20);
  digitalWrite(13,LOW);
  val = digitalRead(inPin);   // read the input pin
  if(val == HIGH){
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
  delay(60000); //1 minute
  digitalWrite(relayPin, LOW);
}

