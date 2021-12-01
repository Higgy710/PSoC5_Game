## INTRODUCTION:

The purpose of the lab was to use Timers functions, Pseudo-Random Sequencer, and PWMs to make a simple side-scrolling action game using the LCD and push buttons from previous labs. I decided to implement infinite play, enhanced graphics, and PWM for my game enhancements.

## MATERIALS:

•	1 x PSoC 5 (CY8C5888LTI-LP097)

•	1 x Hitachi HD33780 LCD

•	2 x Breadboards

•	2 x 10kΩ Resistors

•	2 x Push Buttons

•	1 x 2N2222 NPN transistor

•	1 x 2N2907 PNP transistor

•	1 x 10kΩ Resistor (or potentiometer to adjust volume)

•	1 x Speaker 

•	1 x 100µF Capacitor

•	24G Jumper Wires

•	USB Extension Cable

•	PSoC Creator 4.3

## HARDWARE:

![image](https://user-images.githubusercontent.com/47610444/144160548-8a9656fd-d5a4-4cfb-9f7a-277810a7e4d8.png)

Figure 1: Breadboard Diagram


## SOFTWARE:

In PSoC Creator, I created the top-down schematic seen in Figure 2. The schematic contains a PWM, PRS, LCD, 2 digital input pins, a refresh timer, and an interrupt for the timer and one for the control pins. The timer clock was set to 50KHz with the timer period set to 25000. This allowed the refresh rate to be every 500ms. The timer was also set to 16-bit resolution, fixed function, rising edge. The PWM has a 1MHz clock and was set to fixed-function, 16-bit resolution, 9000 period and compare value 6000. This gave a nice “BUZZ” sound when the PWM was active. The digital input pins dive mode was set to resistive pull down and number of pins set to 2. Finally, the PRS was set to 16-bit resolution with a 12MHz clock.

![image](https://user-images.githubusercontent.com/47610444/144160816-660eb665-6df1-449e-8d07-1a47c563cf6a.png)

Figure 2: Top-down Schematic

Each component was assigned to a pin. Figure 3 shows the configuration for the pin placement. Control[1:0] was set to P3[5:4], LCD to P2[6:0], and PWM_OUT to P1[7].

![image](https://user-images.githubusercontent.com/47610444/144160908-fc0c18ed-c7c6-4bbd-a018-b8aae96d264d.png)

Figure 3: Pin Configuration

Under the LCD configuration menu, I drew my custom characters for the player and the obstacles.

![image](https://user-images.githubusercontent.com/47610444/144160949-5d644d6d-fc65-4e1f-808a-aa8e5689fe68.png)

Figure 4: Player and obstacle custom LCD characters

## CODE:

The only code in main.c was starting all the modules. In CONTROL_ISR, I used an if-else-if statement to read which button was pressed and update the character position to either to row 0 or row 1 of the LCD.

The bulk of the code lies in the REFRESH_ISR. First, I defined and initialized my parameters. These included a random integer, number of lives, a period integer used to speed up the refresh ISR, and a char for the player and obstacles. I also initialized  6 obstacles for when the game first starts.

Under CY_ISR is where the rest of the code is located. I mainly used if-else statements to see if any of the obstacles have reached the left of the LCD. If it has, the column is set to 15(the right-most side of the LCD) and the row is determined randomly by the PRS, otherwise the column is decremented by 1. After the 6th obstacle has reached the left of the screen, the refresh timer period is reduced by 1/10th.

Next, there’s an if-else statement that checks if the number of lives is greater than zero. If number of lives hasn’t reached zero, an if-else statement checks to see if the player and obstacle row and column are equal. If they are, a “BUZZ” is made by the PWM, number of lives is decremented, and the number of lives left is displayed on the screen. Otherwise the PWM stops and the player and obstacle characters are displayed on the screen. If the number lives have reached zero, “GAMEOVER!!” is displayed in the middle of the top row and “Reset to restart” is displayed on the bottom of the row. Finally, the period parameter is updated with the current period and the Refresh_Timer_ReadStatusRegister() function is called.



https://user-images.githubusercontent.com/47610444/144162622-613c8790-ca24-4d6e-9656-a82dfa0e6b28.mp4



## APPENDIX

```
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

CONTROL_ISR.c

CY_ISR(CONTROL_ISR_Interrupt)
{
    #ifdef CONTROL_ISR_INTERRUPT_INTERRUPT_CALLBACK
        CONTROL_ISR_Interrupt_InterruptCallback();
    #endif /* CONTROL_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START CONTROL_ISR_Interrupt` */
        if (Control_Read() == 1)
        {
         CharacterPos = 0;
        }
        else if (Control_Read() == 2)
        {
         CharacterPos = 1;   
        }
        Control_ClearInterrupt();
    /* `#END` */
}

/*******************************************************************************
* File Name: REFRESH_ISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*  File Name: main.c                                      
*  Dan Higginbotham                     
*  ECE381 Microcontrollers              
*  03/09/21                               
*  Lab 4 – Game using timers and PRS
*                                       
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <REFRESH_ISR.h>
#include "cyapicallbacks.h"

#if !defined(REFRESH_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START REFRESH_ISR_intc` */
    #include "Refresh_Timer.h"
    #include "LCD.h"
    #include "Control.h"
    #include "CONTROL_ISR.h"
    #include "PRS.h"
    #include "PWM.h"

    int random;
    int lives = 3;
    int period;
    char Player = LCD_CUSTOM_0;
    char Obstacle = LCD_CUSTOM_1;
    char Obstacle2 = LCD_CUSTOM_2;

    volatile int CharacterPos = 0;
    
    int Obstacle1Col = 7;
    int Obstacle1Row = 0;
    int Obstacle2Col = 10;
    int Obstacle2Row = 1;
    int Obstacle3Col = 13;
    int Obstacle3Row = 0;
    int Obstacle4Col = 16;
    int Obstacle4Row = 1;
    int Obstacle5Col = 19;
    int Obstacle5Row = 0;
    int Obstacle6Col = 21;
    int Obstacle6Row = 1;
    
/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: REFRESH_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_Start(void)
{
    /* For all we know the interrupt is active. */
    REFRESH_ISR_Disable();

    /* Set the ISR to point to the REFRESH_ISR Interrupt. */
    REFRESH_ISR_SetVector(&REFRESH_ISR_Interrupt);

    /* Set the priority. */
    REFRESH_ISR_SetPriority((uint8)REFRESH_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    REFRESH_ISR_Enable();
}


/*******************************************************************************
* Function Name: REFRESH_ISR_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    REFRESH_ISR_Disable();

    /* Set the ISR to point to the REFRESH_ISR Interrupt. */
    REFRESH_ISR_SetVector(address);

    /* Set the priority. */
    REFRESH_ISR_SetPriority((uint8)REFRESH_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    REFRESH_ISR_Enable();
}


/*******************************************************************************
* Function Name: REFRESH_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_Stop(void)
{
    /* Disable this interrupt. */
    REFRESH_ISR_Disable();

    /* Set the ISR to point to the passive one. */
    REFRESH_ISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: REFRESH_ISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for REFRESH_ISR.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(REFRESH_ISR_Interrupt)
{
    #ifdef REFRESH_ISR_INTERRUPT_INTERRUPT_CALLBACK
        REFRESH_ISR_Interrupt_InterruptCallback();
    #endif /* REFRESH_ISR_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START REFRESH_ISR_Interrupt` */

    random = (PRS_Read() % 2);

    
    if(Obstacle1Col == 0)           // Obstacl 1 reaches left side of screen
    {
        Obstacle1Col = 15;          // Move obstacle1 back to right side of screen
        Obstacle1Row = random;      // Randomly pick top or bottom for obstacle
    }
    else                            // Obstacle1 not at the far left of the screen yet
    {
        Obstacle1Col--;             // Move obstacle1 to the left
    }
    if(Obstacle2Col == 0)           // Obstacle2 reaches left side of screen
    {
        Obstacle2Col = 15;          // Move obstacle2 back to right side of screen
        Obstacle2Row = random;      // Randomly pick top or bottom for obstacle
    }
    else                            // Obstacle2 not at the far left of the screen yet
    {
        Obstacle2Col--;             // Move obstacle2 to the left
    }
    if(Obstacle3Col == 0)           // Obstacle3 reaches left side of screen
    {
        Obstacle3Col = 15;          // Move obstacle3 back to right side of screen
        Obstacle3Row = random;      // Randomly pick top or bottom for obstacle
    }
    else                            // Obstacle3 not at the far left of the screen yet
    {
        Obstacle3Col--;             // Move obstacle3 to the left
    }
    if(Obstacle4Col == 0)           // Obstacle4 reaches left side of screen
    {
        Obstacle4Col = 15;          // Move obstacle4 back to right side of screen
        Obstacle4Row = random;      // Randomly pick top or bottom for obstacle
    }
    else                            // Obstacle4 not at the far left of the screen yet
    {
        Obstacle4Col--;             // Move obstacle4 to the left
    }
    if(Obstacle5Col == 0)           // Obstacle5 reaches left side of screen
    {
        Obstacle5Col = 15;          // Move obstacle5 back to right side of screen
        Obstacle5Row = random;      // Randomly pick top or bottom for obstacle
    }
    else                            // Obstacle5 not at the far left of the screen yet
    {
        Obstacle5Col--;             // Move obstacle5 to the left
    }
    if(Obstacle6Col == 0)           // Obstacle6 reaches left side of screen
    {
        Obstacle6Col = 15;          // Move obstacle6 back to right side of screen
        Obstacle6Row = random;      // Randomly pick top or bottom for obstacle
        Refresh_Timer_WritePeriod(period*0.9);
    }
    else                            // Obstacle6 not at the far left of the screen yet
    {
        Obstacle6Col--;             // Move obstacle6 to the left
    }
    
    if (lives > 0)
    {
    
        if( (Obstacle6Row == CharacterPos && Obstacle6Col == 0) ||
            (Obstacle5Row == CharacterPos && Obstacle5Col == 0) ||
            (Obstacle4Row == CharacterPos && Obstacle4Col == 0) ||
            (Obstacle3Row == CharacterPos && Obstacle3Col == 0) ||
            (Obstacle2Row == CharacterPos && Obstacle2Col == 0) ||
            (Obstacle1Row == CharacterPos && Obstacle1Col == 0)     )
        {   
            /* If obstacle and player are in same spot,
            reduce lives by 1 and display # lives left */
            PWM_Start();            // Play sound player loses a live
            lives--;
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("OOF!");
            LCD_Position(1,0);
            LCD_PrintString("Lives: ");
            LCD_PrintDecUint16(lives);
        }
        else
        {
            // Display 6 obstacles on LCD
            PWM_Stop();
            LCD_ClearDisplay();
            LCD_Position(CharacterPos, 0);
            LCD_PutChar(Player);
            LCD_Position(Obstacle1Row, Obstacle1Col);
            LCD_PutChar(Obstacle);
            LCD_Position(Obstacle2Row, Obstacle2Col);
            LCD_PutChar(Obstacle2);
            LCD_Position(Obstacle3Row, Obstacle3Col);
            LCD_PutChar(Obstacle);
            LCD_Position(Obstacle4Row, Obstacle4Col);
            LCD_PutChar(Obstacle2);
            LCD_Position(Obstacle5Row, Obstacle5Col);
            LCD_PutChar(Obstacle);
            LCD_Position(Obstacle6Row, Obstacle6Col);
            LCD_PutChar(Obstacle2);
        }
    }
    else
    {
        /* If number of lives are 0,
           Display end game screen */
        PWM_Stop();
        LCD_ClearDisplay();
        LCD_Position(0,3);
        LCD_PrintString("GAMEOVER!!");
        LCD_Position(1,0);
        LCD_PrintString("Reset to restart");
    }
    
    period = Refresh_Timer_ReadPeriod();
    Refresh_Timer_ReadStatusRegister();
    
    /* `#END` */
}
```
