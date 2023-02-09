#ifndef Zebra_h
#define Zebra_h

#include "Arduino.h"

#define Debug 

uint16_t CRC16_CalculateBuf(uint8_t *ptr, uint16_t len);
uint8_t Crc_check( uint8_t *ptr);

void Response(void);
bool Stop_Reading(void);  
void Start_Reader(void);
bool Start_Reading(uint8_t pow, uint8_t Session, uint8_t Flag, uint8_t SL, uint8_t Q );
  /*
  pow =        0-27

  SL Asserted 3   msg[8]
  SL Asserted 2
  Both        1

  Flag Parameter  msg[10]
  A           0
  B           1
  AB          2

  Session 0   0   msg[9]
  Session 1   1
  Session 2   2
  Session 3   3


  Q    Sets the number of slots in the round.   msg[11]
       The possible values of Q are 0-15.
  */
void Kill_Epc_16(byte *epc, byte *password);
void Kill_Epc_12(byte *epc, byte *password);
void Write_Epc_16(byte *OldEpc, byte *password, byte *NewEpc);
void Write_Epc_12(byte *OldEpc, byte *password, byte *NewEpc); // şifresiz epcler için password 0 gönderilir.
void Lock_Epc_Memory_16(byte *epc, byte *password, bool LockStatus); 









#endif