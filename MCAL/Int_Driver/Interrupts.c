/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Interrupts.c
 * 
 *  \category  : MCAL Layer
 * 
 *  \date      : 3 November 2022
 * 
 *  \brief     : ISR Implementation for Interrupts ATmega32
 *  
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "Interrupts.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/*************************************************************************************
 *  \Description     : Initializes Interrupts
 ************************************************************************************/
void INT_Init(void)
{
    #if (GLOBAL_INTERRUPTS_ENABLE == 0)
    intDisable();
    #warning "Global interrupts are disabled, if you want to use interrupts put it to 1."

    #elif (GLOBAL_INTERRUPTS_ENABLE == 1)
    intEnable();

    #else
    #warning "Global interrupts are disabled due to bad configurations."
    #endif
    /* <----------------------------------------[ Sense Control Section ]------------------------------------------> */

    /* Initializations for INT0 */
    #if (INT0_SENSE_CONTROL == 0)
    /* Do Nothing */

    #elif (INT0_SENSE_CONTROL == 1)
    SET_BIT(MCUCR, 0);

    #elif (INT0_SENSE_CONTROL == 2)
    SET_BIT(MCUCR, 1);

    #elif (INT0_SENSE_CONTROL == 3)
    MCUCR |= (1 << 0) | (1 << 1);

    #else
    #warning "INT0 Sense control is set to 0 due to bad configurations."
    #endif

    /* Initializations for INT1 */
    #if (INT1_SENSE_CONTROL == 0)
    /* Do Nothing */

    #elif (INT1_SENSE_CONTROL == 1)
    SET_BIT(MCUCR, 2);

    #elif (INT1_SENSE_CONTROL == 2)
    SET_BIT(MCUCR, 3);

    #elif (INT1_SENSE_CONTROL == 3)
    MCUCR |= (1 << 2) | (1 << 3);

    #else
    #warning "INT1 Sense control is set to 0 due to bad configurations."
    #endif

    /* Initializations for INT0 */
    #if (INT2_SENSE_CONTROL == 0)
    /* Do Nothing */

    #elif (INT2_SENSE_CONTROL == 1)
    SET_BIT(MCUCSR, 6);

    #else
    #warning "INT2 Sense control is set to 0 due to bad configurations."
    #endif

    /* <----------------------------------------[ Enable/Disable Section ]-----------------------------------------> */

    /* Initializations for INT0 */
    #if (INT0_ENABLE == 0)
    /* Do Nothing */

    #elif (INT0_ENABLE == 1)
    SET_BIT(GICR, 6);   /* Enables INT0 */

    #else
    #warning "INT0 is disabled due to bad configurations."
    #endif

    /* Initializations for INT1 */
    #if (INT1_ENABLE == 0)
    /* Do Nothing */

    #elif (INT1_ENABLE == 1)
    SET_BIT(GICR, 7);   /* Enables INT1 */

    #else
    #warning "INT1 is disabled due to bad configurations."
    #endif

    /* Initializations for INT2 */
    #if (INT2_ENABLE == 0)
    /* Do Nothing */

    #elif (INT2_ENABLE == 1)
    SET_BIT(GICR, 5);   /* Enables INT2 */

    #else
    #warning "INT2 is disabled due to bad configurations."
    #endif
}


/* ================================================================================================================= */
/* ================                            END OF FILE: Interrupts.c                            ================ */
/* ================================================================================================================= */
