#include <Arduino.h>
#include <TM1637Display.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


// Module connection pins (Digital Pins)
#define CLK 2
//#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   1000
int I= 4;
int P= 7;
int DIO= 3;
int counter= 10;
TM1637Display display(CLK, DIO);

RF24 radio(9,10);

const byte address[6] = "00001";

void setup() {
  Serial.begin(19200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
   
}

void loop() {
  if (counter >=0){
   if(digitalRead(I)== HIGH){
     display.setBrightness(0x0f);
      display.showNumberDec(counter);
     if(digitalRead(P)==HIGH){
      digitalWrite(DIO, HIGH);
      display.setBrightness(0x0f);
      display.showNumberDec(counter);
      counter--;
      delay(TEST_DELAY);  
    }
      else{
        digitalWrite(DIO, LOW);
        counter=10;
        display.showNumberDec(counter);
        }
   
   }
   else{
    digitalWrite(DIO,LOW);
    counter=10;
    display.showNumberDec(counter);
 }
             if(counter <=0){
                   const char data[] = "F.I.R.E";
                      Serial.println(data);
                     radio.write(&data,sizeof(data));  
                                      }
  } 
  
  

  

}   
    
