#include "mgos_arduino_lora1276.h"

LORA *mgos_LORA_create(int NSSPin, int NRESETPin, int txEnPin, int rxEnPin)
{
    return new LORA(NSSPin, NRESETPin, txEnPin, rxEnPin);
}

void mgos_LORA_close(LORA *lora)
{
    if (lora != nullptr)
    {
        delete lora;
        lora = nullptr;
    }
}

bool mgos_LORA_init(LORA *lora)
{
    if (lora == nullptr)
        return false;
    return lora->init();
}
///  Initialise rx mode.
///  @return  1 if ok, 0 otherwise
bool mgos_LORA_rxInit(LORA *lora)
{
    if (lora == nullptr)
        return false;
    return lora->rxInit();
}
///  Transmit packet through RF
///  @param sendbuf		buf of data to send
///  @param	sendLen		length of data to send,less than 64 bytes
///	 @return  1 if tx ok, 0 otherwise
bool mgos_LORA_txPacket(LORA *lora, uint8_t* sendbuf, int sendLen)
{
    if (lora == nullptr)
        return false;
    return lora->txPacket(sendbuf, sendLen);
}
///  Receive packet from RF
///  @param recvbuf		buf to save the rx data
///	 @return length of rx data
int mgos_LORA_rxPacket(LORA *lora, uint8_t* recvbuf)
{
    if (lora == nullptr)
        return 0;
    return lora->rxPacket(recvbuf);
}
///  Inquire interrupt.
///  @param irqMask		interrupt flag
///  @return  1 if interrupt occur, 0 if no interrupt
bool mgos_LORA_waitIrq(LORA *lora, int irqMask)
{
    if (lora == nullptr)
        return false;
    return lora->waitIrq(irqMask);
}
///  Enter standby mode.
void mgos_LORA_enterStbyMode(LORA *lora)
{
    if (lora == nullptr)
        return ;
    return lora->enterStbyMode();
}
///  Enter sleep mode.
void mgos_LORA_enterSleepMode(LORA *lora)
{
    if (lora == nullptr)
        return ;
    lora->enterSleepMode();
}
///  Clear interrupt
void mgos_LORA_clrInterrupt(LORA *lora)
{
    if (lora == nullptr)
        return ;
    lora->clrInterrupt();
}
///  Set RF frequency.
///	 @param	freq	    value of frequency
///  @return  1 if ok, 0 otherwise
///  @note: the range is 137~1020Mhz for lora1276 ,137~525Mhz for lora1278
bool mgos_LORA_setFrequency(LORA *lora, uint32_t freq)
{
    if (lora == nullptr)
        return false;
    return lora->setFrequency(freq);
}
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
bool mgos_LORA_setRFpara(LORA *lora, int BW, int CR, int SF, int CRC)
{
    if (lora == nullptr)
        return false;
    return lora->setRFpara(BW, CR, SF, CRC);
}
///  Set preamble length.
///	 @param	len			preamble length
///  @return  1 if ok, 0 otherwise
bool mgos_LORA_setPreambleLen(LORA *lora, int length)
{
    if (lora == nullptr)
        return false;
    return lora->setPreambleLen(length);
}
///  Set header mode
///	 @param	mode		LR_IMPLICIT_HEADER_MODE or LR_EXPLICIT_HEADER_MODE
///  @note	if SF=6 ,it must be implicit header mode
bool mgos_LORA_setHeaderMode(LORA *lora, int mode)
{
    if (lora == nullptr)
        return false;
    return lora->setHeaderMode(mode);
}
///  Set payload length
///	 @param	len		payload length
///  @note	in  implicit header mode ,payload length must be set first
///   		length is fix in  implicit header mode
bool mgos_LORA_setPayloadLength(LORA *lora, int len)
{
    if (lora == nullptr)
        return false;
    return lora->setPayloadLength(len);
}
///  Set tx power.
///	 @param	power		    power level,0 to 15
///  @return  1 if ok, 0 otherwise
bool mgos_LORA_setTxPower(LORA *lora, int power)
{
    if (lora == nullptr)
        return false;
    return lora->setTxPower(power);
}
///  Set rx time out.
///	 @param	 symbTimeOut	actual timeout = symTimeout * (2^SF/BW)
///  @return  1 if ok, 0 otherwise
bool mgos_LORA_setRxTimeOut(LORA *lora, int symbTimeOut)
{
    if (lora == nullptr)
        return false;
    return lora->setRxTimeOut(symbTimeOut);
}
///  Read rssi
///	 @param	 mode	   0 read  current rssi, 1 read rssi of last packet received
///  @return   value of rssi
int readRSSI(LORA *lora, int mode)
{
    if (lora == nullptr)
        return false;
    return lora->readRSSI(mode);
}
