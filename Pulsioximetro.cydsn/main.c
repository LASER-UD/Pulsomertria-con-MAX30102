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
unsigned char cont=0,pulse=0;
unsigned char frecuencia=30;
char Buffer[20]={};
bool bandera=false;
unsigned long aux[4]={0,0,0,0};

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
    UART_PutString("*.kwl\r\n");
    UART_PutString("clear_panel()\r");
    UART_PutString("set_grid_size(17,8)\r");
    UART_PutString("add_text(12,2,large,C,Frecuencia Cardiaca,255,26,57,)\r");
    UART_PutString("add_text_box(12,5,2,L,No C,245,240,245,A)\r");
    UART_PutString("add_gauge(10,4,4,50,100,50,F,,,10,5)\r");
    UART_PutString("add_roll_graph(1,0,8,462.0,471.0,50,T,Oxymetria,tiempo,Oxymetria,1,0,1,0,1,1,thin,none,1,1,47,218,107)\r");
    UART_PutString("add_monitor(1,5,5,,1)\r");
    UART_PutString("run()\r");
    UART_PutString("*\r");
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("Ubique su dedo");
    Max_Init(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        //sprintf(Buffer,"*T%d,%d*",,cont);//lo codifica en ascci
        aux[0]=aux[1];
        aux[1]=aux[2];
        aux[2]=aux[3];
        aux[3]=Max_getIR();
        sprintf(Buffer,"*T%lu*",aux[2]);//lo codifica en ascci
        UART_PutString(Buffer);
        //UART_PutString("\r\n");
        if(aux[1]>46000){
            if((aux[1]>aux[0])&(aux[1]>aux[2])&(aux[3]-400<aux[2])){
                pulse++;
            }
            cont=cont+1;
            if(cont==200){//cada 20 segundo mide la frecuencia cardiaca
                frecuencia=(unsigned char)(pulse*3);
                cont=0;
                pulse=0;
                sprintf(Buffer,"*F%d*/r*A%d*",frecuencia,frecuencia);//lo codifica en ascci
                UART_PutString(Buffer);
                bandera=true;
            }
        }else{
            if(bandera){
                UART_PutString("*F50*/r*ANo C*");//lo codifica en ascci
                bandera=false;
            }
        
        }
        CyDelay(50);
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
