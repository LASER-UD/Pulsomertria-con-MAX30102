#include <project.h>
#include "I2C.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "MAX30102.h"

#define MAX30102_DIETEMPINT     0x1F
#define MAX30102_INTSTAT1 		0x00
#define MAX30102_INTSTAT2 	    0x01
#define MAX30102_INTENABLE1 	0x02
#define MAX30102_INTENABLE2 	0x03

// FIFO Registers
#define MAX30102_FIFOWRITEPTR  	0x04
#define MAX30102_FIFOOVERFLOW  	0x05
#define MAX30102_FIFOREADPTR  	0x06
#define MAX30102_FIFODATA 		0x07

// Configuration Registers
#define MAX30102_FIFOCONFIG  		0x08
#define MAX30102_MODECONFIG  		0x09
#define MAX30102_PARTICLECONFIG  	0x0A    // Note, sometimes listed as "SPO2" config in datasheet (pg. 11)
#define MAX30102_LED1_PULSEAMP  	0x0C
#define MAX30102_LED2_PULSEAMP  	0x0D
#define MAX30102_LED3_PULSEAMP  	0x0E
#define MAX30102_LED_PROX_AMP  	    0x10
#define MAX30102_MULTILEDCONFIG1    0x11
#define MAX30102_MULTILEDCONFIG2    0x12

// Die Temperature Registers
#define MAX30102_DIETEMPINT  		0x1F
#define MAX30102_DIETEMPFRAC  	    0x20
#define MAX30102_DIETEMPCONFIG  	0x21

// Proximity Function Registers
#define MAX30102_PROXINTTHRESH  	0x30

// Part ID Registers
#define MAX30102_REVISIONID  		0xFE
#define MAX30102_PARTID  			0xFF    // Should always be 0x15. Identical to MAX30102.

// MAX30102 Commands
// Interrupt configuration (pg 13, 14)
#define MAX30102_INT_A_FULL_MASK 		0b10000000
#define MAX30102_INT_A_FULL_ENABLE  	0x80
#define MAX30102_INT_A_FULL_DISABLE  	0x00

#define MAX30102_INT_DATA_RDY_MASK      0b01000000
#define MAX30102_INT_DATA_RDY_ENABLE 	0x40
#define MAX30102_INT_DATA_RDY_DISABLE   0x00

#define MAX30102_INT_ALC_OVF_MASK       0b00100000
#define MAX30102_INT_ALC_OVF_ENABLE  	0x20
#define MAX30102_INT_ALC_OVF_DISABLE    0x00

#define MAX30102_INT_PROX_INT_MASK      0b00010000
#define MAX30102_INT_PROX_INT_ENABLE    0x10
#define MAX30102_INT_PROX_INT_DISABLE   0x00

#define MAX30102_INT_DIE_TEMP_RDY_MASK  0b00000010
#define MAX30102_INT_DIE_TEMP_RDY_ENABLE  0x02
#define MAX30102_INT_DIE_TEMP_RDY_DISABLE  0x00

#define MAX30102_SAMPLEAVG_MASK 	0b11100000
#define MAX30102_SAMPLEAVG_1  	    0x00
#define MAX30102_SAMPLEAVG_2  	    0x20
#define MAX30102_SAMPLEAVG_4  	    0x40
#define MAX30102_SAMPLEAVG_8  	    0x60
#define MAX30102_SAMPLEAVG_16  	    0x80
#define MAX30102_SAMPLEAVG_32  	    0xA0

#define MAX30102_ROLLOVER_MASK  	0xEF
#define MAX30102_ROLLOVER_ENABLE    0x10
#define MAX30102_ROLLOVER_DISABLE   0x00

#define MAX30102_A_FULL_MASK  	    0xF0

// Mode configuration commands (page 19)
#define MAX30102_SHUTDOWN_MASK  	0x7F
#define MAX30102_SHUTDOWN  		    0x80
#define MAX30102_WAKEUP  			0x00

#define MAX30102_RESET_MASK  		0xBF
#define MAX30102_RESET  			0x40

#define MAX30102_MODE_MASK  		0xF8
#define MAX30102_MODE_REDONLY  	    0x02
#define MAX30102_MODE_REDIRONLY  	0x03
#define MAX30102_MODE_MULTILED  	0x07

// Particle sensing configuration commands (pgs 19-20)
#define MAX30102_ADCRANGE_MASK  	0x9F
#define MAX30102_ADCRANGE_2048  	0x00
#define MAX30102_ADCRANGE_4096  	0x20
#define MAX30102_ADCRANGE_8192  	0x40
#define MAX30102_ADCRANGE_16384  	0x60

#define MAX30102_SAMPLERATE_MASK    0xE3
#define MAX30102_SAMPLERATE_50  	0x00
#define MAX30102_SAMPLERATE_100  	0x04
#define MAX30102_SAMPLERATE_200  	0x08
#define MAX30102_SAMPLERATE_400  	0x0C
#define MAX30102_SAMPLERATE_800  	0x10
#define MAX30102_SAMPLERATE_1000    0x14
#define MAX30102_SAMPLERATE_1600    0x18
#define MAX30102_SAMPLERATE_3200    0x1C
#define MAX30102_PULSEWIDTH_MASK    0xFC
#define MAX30102_PULSEWIDTH_69  	0x00
#define MAX30102_PULSEWIDTH_118 	0x01
#define MAX30102_PULSEWIDTH_215 	0x02
#define MAX30102_PULSEWIDTH_411  	0x03
//Multi-LED Mode configuration (pg 22)
#define MAX30102_SLOT1_MASK  		0xF8
#define MAX30102_SLOT2_MASK  		0x8F
#define MAX30102_SLOT3_MASK  		0xF8
#define MAX30102_SLOT4_MASK  		0x8F

#define SLOT_NONE  			    	0x00
#define SLOT_RED_LED  			    0x01
#define SLOT_IR_LED  				0x02
#define SLOT_GREEN_LED  			0x03
#define SLOT_NONE_PILOT  			0x04
#define SLOT_RED_PILOT 	    		0x05
#define SLOT_IR_PILOT    			0x06
#define SLOT_GREEN_PILOT        	0x07

#define MAX_30105_EXPECTEDPARTID    0x15


bool Max_Beginread (unsigned char sladress){
    unsigned int cont=0;   
    bool out=true;
    do{
            cont++;
            if(cont==1000){
                UART_PutString("Tiempo excedido");
                out=false;
                break;
                
            }
            //Espera mienstras el esclavo le responde
        }while(I2C_MasterSendStart(sladress, I2C_READ_XFER_MODE)!=I2C_MSTR_NO_ERROR);
        return out;
}      //sladress= direccion del esclavo

bool Max_Beginwrite(unsigned char sladress){
    unsigned int cont=0;   
    bool out=true;
    do{
            cont++;
            if(cont==1000){
                UART_PutString("Tiempo excedido\r\n");
                out=false;
                break;   
            }
    }while(I2C_MasterSendStart(sladress, I2C_WRITE_XFER_MODE)!=I2C_MSTR_NO_ERROR);
    return out;
}

unsigned char Max_Read(unsigned char adress, unsigned char leer){                   
    unsigned char data=0;
    if(Max_Beginwrite(adress)){
        I2C_MasterWriteByte(leer);//Pone direccion de memoria que quiere leer  
        I2C_MasterSendRestart(adress, I2C_READ_XFER_MODE); // Re transmite para obtener datos
        data=I2C_MasterReadByte(I2C_NAK_DATA);
        I2C_MasterSendStop();
    }
    return data;
} //adress es el slave adress del dispositivo, leer es la direccion del registro que se desea ver

void Max_Write(char slvadr, unsigned char adress, unsigned char load){
    if(Max_Beginwrite(slvadr)){
        I2C_MasterWriteByte(adress);
        I2C_MasterWriteByte(load);
        I2C_MasterSendStop();
    }
    
}

void bitMask(unsigned char reg, unsigned char mask, unsigned char thing)
{
  // Lee el original
  unsigned char originalContents = Max_Read(MAX30102_ADDRESS, reg);
  // lo enmascara
  originalContents = originalContents & mask;
  // Escribe de nuevo
  Max_Write(MAX30102_ADDRESS, reg, originalContents | thing);
}

void softReset(void) {
  bitMask(MAX30102_MODECONFIG, MAX30102_RESET_MASK, MAX30102_RESET);
  // Timeout after 100ms
  unsigned char startTime=0;
  while (startTime < 100)
  {
    unsigned char response = Max_Read(MAX30102_ADDRESS, MAX30102_MODECONFIG);
    if ((response & MAX30102_RESET) == 0) break; //Esta listo
    startTime++;
    CyDelay(1); 
    
  }
}

void enablePROXINT(void) {
  bitMask(MAX30102_INTENABLE1, MAX30102_INT_PROX_INT_MASK, MAX30102_INT_PROX_INT_ENABLE);
}

void setLEDMode(unsigned char mode) {
  // Set which LEDs are used for sampling -- Red only, RED+IR only, or custom.
  // See datasheet, page 19
  bitMask(MAX30102_MODECONFIG, MAX30102_MODE_MASK, mode);
}



void setADCRange(unsigned char adcRange) {
  // adcRange: one of MAX30102_ADCRANGE_2048, _4096, _8192, _16384
  bitMask(MAX30102_PARTICLECONFIG,MAX30102_ADCRANGE_MASK, adcRange);
}

void setSampleRate(unsigned char sampleRate) {
  // sampleRate: one of MAX30102_SAMPLERATE_50, _100, _200, _400, _800, _1000, _1600, _3200
  bitMask(MAX30102_PARTICLECONFIG, MAX30102_SAMPLERATE_MASK, sampleRate);
}

void setPulseWidth(unsigned char pulseWidth) {
  // pulseWidth: one of MAX30102_PULSEWIDTH_69, _188, _215, _411
  bitMask(MAX30102_PARTICLECONFIG, MAX30102_PULSEWIDTH_MASK, pulseWidth);
}

// NOTE: Amplitude values: 0x00 = 0mA, 0x7F = 25.4mA, 0xFF = 50mA (typical)
// See datasheet, page 21
void setPulseAmplitudeRed(unsigned char amplitude) {
  Max_Write(MAX30102_ADDRESS, MAX30102_LED1_PULSEAMP, amplitude);
}

void setPulseAmplitudeIR(unsigned char amplitude) {
  Max_Write(MAX30102_ADDRESS, MAX30102_LED2_PULSEAMP, amplitude);
}

void setPulseAmplitudeGreen(unsigned char amplitude) {
  Max_Write(MAX30102_ADDRESS, MAX30102_LED3_PULSEAMP, amplitude);
}

void setPulseAmplitudeProximity(unsigned char amplitude) {
  Max_Write(MAX30102_ADDRESS, MAX30102_LED_PROX_AMP, amplitude);
}

void setProximityThreshold(unsigned char threshMSB) {
  // Set the IR ADC count that will trigger the beginning of particle-sensing mode.
  // The threshMSB signifies only the 8 most significant-bits of the ADC count.
  // See datasheet, page 24.
  Max_Write(MAX30102_ADDRESS, MAX30102_PROXINTTHRESH, threshMSB);
}

//
// FIFO Configuration
//

//Set sample average (Table 3, Page 18)
void setFIFOAverage(unsigned char numberOfSamples) {
  bitMask(MAX30102_FIFOCONFIG, MAX30102_SAMPLEAVG_MASK, numberOfSamples);
}

//Resets all points to start in a known state
//Page 15 recommends clearing FIFO before beginning a read
void clearFIFO(void) {
  Max_Write(MAX30102_ADDRESS, MAX30102_FIFOWRITEPTR, 0);
  Max_Write(MAX30102_ADDRESS, MAX30102_FIFOOVERFLOW, 0);
  Max_Write(MAX30102_ADDRESS, MAX30102_FIFOREADPTR, 0);
}

//Enable roll over if FIFO over flows
void enableFIFORollover(void) {
  bitMask(MAX30102_FIFOCONFIG, MAX30102_ROLLOVER_MASK, MAX30102_ROLLOVER_ENABLE);
}

//Disable roll over if FIFO over flows
void disableFIFORollover(void) {
  bitMask(MAX30102_FIFOCONFIG, MAX30102_ROLLOVER_MASK, MAX30102_ROLLOVER_DISABLE);
}

//Set number of samples to trigger the almost full interrupt (Page 18)
//Power on default is 32 samples
//Note it is reverse: 0x00 is 32 samples, 0x0F is 17 samples
void setFIFOAlmostFull(unsigned char numberOfSamples) {
  bitMask(MAX30102_FIFOCONFIG, MAX30102_A_FULL_MASK, numberOfSamples);
}

//Read the FIFO Write Pointer
unsigned char getWritePointer(void) {
  return (Max_Read(MAX30102_ADDRESS, MAX30102_FIFOWRITEPTR));
}

//Read the FIFO Read Pointer
unsigned char getReadPointer(void) {
  return (Max_Read(MAX30102_ADDRESS, MAX30102_FIFOREADPTR));
}

void enableSlot(unsigned char slotNumber, unsigned char device) {


  switch (slotNumber) {
    case (1):
      bitMask(MAX30102_MULTILEDCONFIG1, MAX30102_SLOT1_MASK, device);
      break;
    case (2):
      bitMask(MAX30102_MULTILEDCONFIG1, MAX30102_SLOT2_MASK, device << 4);
      break;
    case (3):
      bitMask(MAX30102_MULTILEDCONFIG2, MAX30102_SLOT3_MASK, device);
      break;
    case (4):
      bitMask(MAX30102_MULTILEDCONFIG2, MAX30102_SLOT4_MASK, device << 4);
      break;
    default:
      //Shouldn't be here!
      break;
  }
}

//Clears all slot assignments
void disableSlots(void) {
  Max_Write(MAX30102_ADDRESS, MAX30102_MULTILEDCONFIG1, 0);
  Max_Write(MAX30102_ADDRESS, MAX30102_MULTILEDCONFIG2, 0);
}


void Max_Init(unsigned char powerLevel, unsigned char sampleAverage, unsigned char ledMode, int sampleRate, int pulseWidth, int adcRange) {
  I2C_Start();
  softReset();  //Reset toda la configuracion
  //FIFO Configuration
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  //The chip will average multiple samples of same type together if you wish
  if (sampleAverage == 1) setFIFOAverage(MAX30102_SAMPLEAVG_1); //No averaging per FIFO record
  else if (sampleAverage == 2) setFIFOAverage(MAX30102_SAMPLEAVG_2);
  else if (sampleAverage == 4) setFIFOAverage(MAX30102_SAMPLEAVG_4);
  else if (sampleAverage == 8) setFIFOAverage(MAX30102_SAMPLEAVG_8);
  else if (sampleAverage == 16) setFIFOAverage(MAX30102_SAMPLEAVG_16);
  else if (sampleAverage == 32) setFIFOAverage(MAX30102_SAMPLEAVG_32);
  else setFIFOAverage(MAX30102_SAMPLEAVG_4);

  //setFIFOAlmostFull(2); //Set to 30 samples to trigger an 'Almost Full' interrupt
  enableFIFORollover(); //Allow FIFO to wrap/roll over
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  //Mode Configuration
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  if (ledMode == 3) setLEDMode(MAX30102_MODE_MULTILED); //Watch all three LED channels
  else if (ledMode == 2) setLEDMode(MAX30102_MODE_REDIRONLY); //Red and IR
  else setLEDMode(MAX30102_MODE_REDONLY); //Red only
  activeLEDs = ledMode; //Used to control how many bytes to read from FIFO buffer
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  //Particle Sensing Configuration
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  if(adcRange < 4096) setADCRange(MAX30102_ADCRANGE_2048); //7.81pA per LSB
  else if(adcRange < 8192) setADCRange(MAX30102_ADCRANGE_4096); //15.63pA per LSB
  else if(adcRange < 16384) setADCRange(MAX30102_ADCRANGE_8192); //31.25pA per LSB
  else if(adcRange == 16384) setADCRange(MAX30102_ADCRANGE_16384); //62.5pA per LSB
  else setADCRange(MAX30102_ADCRANGE_2048);

  if (sampleRate < 100) setSampleRate(MAX30102_SAMPLERATE_50); //Take 50 samples per second
  else if (sampleRate < 200) setSampleRate(MAX30102_SAMPLERATE_100);
  else if (sampleRate < 400) setSampleRate(MAX30102_SAMPLERATE_200);
  else if (sampleRate < 800) setSampleRate(MAX30102_SAMPLERATE_400);
  else if (sampleRate < 1000) setSampleRate(MAX30102_SAMPLERATE_800);
  else if (sampleRate < 1600) setSampleRate(MAX30102_SAMPLERATE_1000);
  else if (sampleRate < 3200) setSampleRate(MAX30102_SAMPLERATE_1600);
  else if (sampleRate == 3200) setSampleRate(MAX30102_SAMPLERATE_3200);
  else setSampleRate(MAX30102_SAMPLERATE_50);

  //The longer the pulse width the longer range of detection you'll have
  //At 69us and 0.4mA it's about 2 inches
  //At 411us and 0.4mA it's about 6 inches
  if (pulseWidth < 118) setPulseWidth(MAX30102_PULSEWIDTH_69); //Page 26, Gets us 15 bit resolution
  else if (pulseWidth < 215) setPulseWidth(MAX30102_PULSEWIDTH_118); //16 bit resolution
  else if (pulseWidth < 411) setPulseWidth(MAX30102_PULSEWIDTH_215); //17 bit resolution
  else if (pulseWidth == 411) setPulseWidth(MAX30102_PULSEWIDTH_411); //18 bit resolution
  else setPulseWidth(MAX30102_PULSEWIDTH_69);
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  //LED Pulse Amplitude Configuration
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  //Default is 0x1F which gets us 6.4mA
  //powerLevel = 0x02, 0.4mA - Presence detection of ~4 inch
  //powerLevel = 0x1F, 6.4mA - Presence detection of ~8 inch
  //powerLevel = 0x7F, 25.4mA - Presence detection of ~8 inch
  //powerLevel = 0xFF, 50.0mA - Presence detection of ~12 inch

  setPulseAmplitudeRed(powerLevel);
  setPulseAmplitudeIR(powerLevel);
  setPulseAmplitudeGreen(powerLevel);
  setPulseAmplitudeProximity(powerLevel);
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  //Multi-LED Mode Configuration, Enable the reading of the three LEDs
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
  enableSlot(1, SLOT_RED_LED);
  if (ledMode > 1) enableSlot(2, SLOT_IR_LED);
  if (ledMode > 2) enableSlot(3, SLOT_GREEN_LED);
  //enableSlot(1, SLOT_RED_PILOT);
  //enableSlot(2, SLOT_IR_PILOT);
  //enableSlot(3, SLOT_GREEN_PILOT);
  //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

  clearFIFO(); //Reset the FIFO before we begin checking the sensor
}


unsigned long Max_getIR(void)
{
  unsigned char readPointer = getReadPointer();
  unsigned char writePointer = getWritePointer();

  //int numberOfSamples = 0;

  //Do we have new data?
  if (readPointer != writePointer)
  {
    unsigned char temp[sizeof(uint32_t)]; //Array of 4 bytes that we will convert into long
    unsigned long tempLong=0;
    //numberOfSamples = writePointer - readPointer;    //Calculate the number of readings we need to get from sensor
    if(Max_Beginwrite(MAX30102_ADDRESS)){
        I2C_MasterWriteByte(MAX30102_FIFODATA);//Pone direccion de la fifo 
        I2C_MasterSendRestart(MAX30102_ADDRESS, I2C_READ_XFER_MODE); // Re transmite para obtener datos   
        temp[3] = 0;
        temp[2] = I2C_MasterReadByte(I2C_NAK_DATA);
        temp[1] = I2C_MasterReadByte(I2C_NAK_DATA);
        temp[0] = I2C_MasterReadByte(I2C_NAK_DATA);
        I2C_MasterSendStop();
        memcpy(&tempLong, temp, sizeof(tempLong));     //Convert array to long
        tempLong &= 0x3FFFF;
    }     
    return tempLong;     
    }else{
    
        return 0x0000;
    }        
      
}

