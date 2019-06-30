#ifndef _MAX30102_H_
#define _MAX30102_H_

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
    
 
#define MAX30102_ADDRESS  0x57
   


unsigned char activeLEDs;    
    
void Max_Init(unsigned char powerLevel, unsigned char sampleAverage, unsigned char ledMode, int sampleRate, int pulseWidth, int adcRange);      
unsigned long Max_getIR(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif 