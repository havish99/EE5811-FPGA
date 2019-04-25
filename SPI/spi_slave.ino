#include<SPI.h>

volatile boolean received;
volatile byte Slavereceived,Slavesend;
volatile char recvd;
int x;
void setup()

{
  Serial.begin(115200);
                // Setting pin 7 as OUTPUT
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  pinMode(SS,INPUT);
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  SPI.setDataMode(SPI_MODE1);
  SPI.setBitOrder(MSBFIRST);
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  Slavereceived = SPDR;
  recvd = SPDR;// Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}

void loop()
{ 
  if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
     
     Serial.println(Slavereceived); 
     received = false;
      
  //Slavesend=0;                             
  //SPDR = Slavesend;                           //Sends the x value to master via SPDR 
 //delay(2000);
}
}
