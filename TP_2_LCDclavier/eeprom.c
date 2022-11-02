#include <xc.h>
#include "user.h"

unsigned char read_eeprom(unsigned char address){



int data_rd;
EEADRH = address >> 8;
EEADR = address; /*si un erreur, ici voir EEADRH*/




EECON1bits.EEPGD = 0; /*Access data EEPROM memory*/
EECON1bits.CFGS = 0; /*= Access Flash program or data EEPROM memory*/
EECON1bits.RD =1; /*Initiates an EEPROM read*/



data_rd = EEDATA; /*read data*/



return data_rd;
}





void write_eeprom(unsigned char address, unsigned char data_wr){




EEADRH = address >> 8;
EEADR = address; /*si un erreur, ici voir EEADRH*/



EECON1bits.EEPGD = 0; /*Access data EEPROM memory*/
EECON1bits.CFGS = 0; /*= Access Flash program or data EEPROM memory*/



EEDATA = data_wr; /*ecriture des data*/



EECON1bits.WREN = 1; /*Allows write cycles to Flash program/data EEPROM*/



INTCONbits.GIE = 0; /*Disable interrupt*/



EECON2 =0x55; //write sequence unlock
EECON2 = 0xAA; //write sequence unlock



EECON1bits.WR = 1; //initiates a data EEPROM erase/write cycle



while(EECON1bits.WR); //waits for write cycle to complete



GIE = 1; //restore interrupts
EECON1bits.WREN = 0; //disable write



}