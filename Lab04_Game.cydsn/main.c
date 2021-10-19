/* 
* ========================================
*  File Name: main.c                                      
*  Dan Higginbotham                     
*  ECE381 Microcontrollers              
*  03/09/21                               
*  Lab 4 – Game using timers and PRS
*                                       
* ========================================
*/
#include <stdlib.h>
#include "project.h"
#include "Refresh_Timer.h"
#include "LCD.h"
#include "Control.h"
#include "CONTROL_ISR.h"
#include "PRS.h"
   
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    Refresh_Timer_Start();
    REFRESH_ISR_Start();
    LCD_Start();
    CONTROL_ISR_Start();
    LCD_LoadCustomFonts(LCD_customFonts);
    PRS_Start();

    for(;;){}
}

/* [] END OF FILE */
