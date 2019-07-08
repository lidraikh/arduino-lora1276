// lora_rx.pde

// Caution:lora can only work under 3.3V
// please make sure the supply of you board is under 3.3V
// 5v supply will destroy lora module!!

// This code runs in rx mode and  works with lora_tx.pde 
// Flow:receive packet from tx->print to serial
// data of packet is "swwxABCDEFGHIm"

#include<LORA.h>
#include <SPI.h>
#include <SoftwareSerial.h>
LORA lora;

unsigned char flag=1;    //  flag of rx mode
unsigned char rx_len;
unsigned char rx_buf[20];

void setup() {
  Serial.begin(9600);
  if(!lora.init())
  {
     Serial.println("Init fail!");
  }
   lora.rxInit();    // wait for packet from master
}
void loop() 
{
    if(flag==1)
    {
        if(lora.waitIrq(LR_RXDONE_MASK))    // wait for RXDONE interrupt
        {
            lora.clrInterrupt();
            rx_len=lora.rxPacket(rx_buf);  // read rx data
            Serial.write(rx_buf,rx_len);    // print out by serial
            Serial.println();
            lora.rxInit();    // wait for packet from master
        }
    }
}
