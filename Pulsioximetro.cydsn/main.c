/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "MAX30102.h"
#define MAX30105_ADDRESS          0x57 //7-bit I2C Address


const unsigned char ledBrightness = 0x1F; //Options: 0=Off to 255=50mA
const unsigned char sampleAverage = 8; //Options: 1, 2, 4, 8, 16, 32
const unsigned char ledMode = 3; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
const int sampleRate = 200; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
const int pulseWidth = 411; //Options: 69, 118, 215, 411
const int adcRange = 8192; //Options: 2048, 4096, 8192, 16384

volatile char data;
char Buffer[12]={};

CY_ISR(InterrupRx){
    data=UART_GetChar();//recibe el dato del bluetooth
    switch (data){
        case '5':{            
            break;
        }
        
        case '6':
        {   
            
            break;
        }
        default:
        {
            break;
        }
    }
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    IRQRX_StartEx(InterrupRx);
    UART_Start();
    UART_PutString("Iniciando\r\n");
    Max_Init(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        sprintf(Buffer,"%lu",Max_getIR());//lo codifica en ascci
        UART_PutString(Buffer);
        UART_PutString("\r\n");
        CyDelay(100);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
