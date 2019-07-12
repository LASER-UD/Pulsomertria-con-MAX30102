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




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    LCD_Start();
    LCD_Position(1,0);
    LCD_PrintString("hOLA ME AMAS");
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        LCD_PrintString("hOLA ME AMAS");
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
