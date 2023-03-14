 #include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int buzzer = 3;
int MOSFET = 6;

RF24 radio(9,10);

char man[]= "";

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(MOSFET,OUTPUT);
  pinMode(buzzer,OUTPUT);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  digitalWrite(MOSFET,LOW);
}

void loop() {
  while (radio.available()) {
    
    char man[32]=""; 
    radio.read(&man,sizeof(man));
    Serial.println(man);
  if(char man = "F.I.R.E"){
      digitalWrite(buzzer,HIGH);
      digitalWrite(MOSFET,HIGH);
       delay(1000);
  }
      exit(0);
    }
    digitalWrite(MOSFET,LOW);
  }
  
