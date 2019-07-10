/*
 * Arduino lora1276 library API wrapper
 */

#ifndef _MGOS_ARDUINO_LORA1276_H_
#define _MGOS_ARDUINO_LORA1276_H_
#endif

#include "LORA.h"

#ifdef __cplusplus
extern "C"
{
#endif

    
    
    // Code goes here
    LORA *mgos_LORA_create(int NSSPin, int NRESETPin, int txEnPin, int rxEnPin);

    void mgos_LORA_close(LORA *lora);

    ///  @return  1 if ok, 0 otherwise
    bool mgos_LORA_init(LORA *lora);
    ///  Initialise rx mode.
    ///  @return  1 if ok, 0 otherwise
    bool mgos_LORA_rxInit(LORA *lora);
    ///  Transmit packet through RF
    ///  @param sendbuf		buf of data to send
    ///  @param	sendLen		length of data to send,less than 64 bytes
    ///	 @return  1 if tx ok, 0 otherwise
    bool mgos_LORA_txPacket(LORA *lora, uint8_t* sendbuf, int sendLen);
    ///  Receive packet from RF
    ///  @param recvbuf		buf to save the rx data
    ///	 @return length of rx data
    int mgos_LORA_rxPacket(LORA *lora, uint8_t* recvbuf);
    ///  Inquire interrupt.
    ///  @param irqMask		interrupt flag
    ///  @return  1 if interrupt occur, 0 if no interrupt
    bool mgos_LORA_waitIrq(LORA *lora, int irqMask);
    ///  Enter standby mode.
    void mgos_LORA_enterStbyMode(LORA *lora);
    ///  Enter sleep mode.
    void mgos_LORA_enterSleepMode(LORA *lora);
    ///  Clear interrupt
    void mgos_LORA_clrInterrupt(LORA *lora);
    ///  Set RF frequency.
    ///	 @param	freq	    value of frequency
    ///  @return  1 if ok, 0 otherwise
    ///  @note: the range is 137~1020Mhz for lora1276 ,137~525Mhz for lora1278
    bool mgos_LORA_setFrequency(LORA *lora, uint32_t freq);
    ///  Set RF parameter.
    ///	 @param	BW	        bandwidth , range from 7.8k to 500k
    ///	 @param	CR	        coding rate , range from 4/5 to 4/8
    ///	 @param	SF	        spreading factor , range from 6 to 12
    ///	 @param	CRC	        LR_PAYLOAD_CRC_ON:enable CRC,
    ///					  LR_PAYLOAD_CRC_OFF:disable CRC
    ///  @return  1 if ok, 0 otherwise
    ///  @note: the RF data rate depends on bandwidth and spreading factor
    ///  coding rate affects time on air
    ///	 if SF=6 ,it will turn to implict mode in this function
    bool mgos_LORA_setRFpara(LORA *lora, int BW, int CR, int SF, int CRC);
    ///  Set preamble length.
    ///	 @param	len			preamble length
    ///  @return  1 if ok, 0 otherwise
    bool mgos_LORA_setPreambleLen(LORA *lora, int length);
    ///  Set header mode
    ///	 @param	mode		LR_IMPLICIT_HEADER_MODE or LR_EXPLICIT_HEADER_MODE
    ///  @note	if SF=6 ,it must be implicit header mode
    bool mgos_LORA_setHeaderMode(LORA *lora, int mode);
    ///  Set payload length
    ///	 @param	len		payload length
    ///  @note	in  implicit header mode ,payload length must be set first
    ///   		length is fix in  implicit header mode
    bool mgos_LORA_setPayloadLength(LORA *lora, int len);
    ///  Set tx power.
    ///	 @param	power		    power level,0 to 15
    ///  @return  1 if ok, 0 otherwise
    bool mgos_LORA_setTxPower(LORA *lora, int power);
    ///  Set rx time out.
    ///	 @param	 symbTimeOut	actual timeout = symTimeout * (2^SF/BW)
    ///  @return  1 if ok, 0 otherwise
    bool mgos_LORA_setRxTimeOut(LORA *lora, int symbTimeOut);
    ///  Read rssi
    ///	 @param	 mode	   0 read  current rssi, 1 read rssi of last packet received
    ///  @return   value of rssi
    int readRSSI(int mode);

#ifdef __cplusplus
}
#endif /* __cplusplus */