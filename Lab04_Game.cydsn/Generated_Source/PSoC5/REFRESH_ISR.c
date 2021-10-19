/*******************************************************************************
* File Name: REFRESH_ISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
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


/*******************************************************************************
* Function Name: REFRESH_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling REFRESH_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use REFRESH_ISR_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)REFRESH_ISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress REFRESH_ISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)REFRESH_ISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: REFRESH_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling REFRESH_ISR_Start or REFRESH_ISR_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after REFRESH_ISR_Start or REFRESH_ISR_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_SetPriority(uint8 priority)
{
    *REFRESH_ISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 REFRESH_ISR_GetPriority(void)
{
    uint8 priority;


    priority = *REFRESH_ISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_Enable(void)
{
    /* Enable the general interrupt. */
    *REFRESH_ISR_INTC_SET_EN = REFRESH_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 REFRESH_ISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*REFRESH_ISR_INTC_SET_EN & (uint32)REFRESH_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_Disable(void)
{
    /* Disable the general interrupt. */
    *REFRESH_ISR_INTC_CLR_EN = REFRESH_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void REFRESH_ISR_SetPending(void)
{
    *REFRESH_ISR_INTC_SET_PD = REFRESH_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: REFRESH_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void REFRESH_ISR_ClearPending(void)
{
    *REFRESH_ISR_INTC_CLR_PD = REFRESH_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
