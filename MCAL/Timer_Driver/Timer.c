/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Timer.c
 * 
 *  \category  : Timer Driver - MCAL
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Implementation of Timer driver functions
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "Timer.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

void TIMER_Init(void)
{
/* <----------------------------------------[ Timer0 Initialization Section ]--------------------------------------> */

    /* Initializations for Timer Mode */
    #if (TIMER0_MODE == 0)      /* Normal Mode */
    /* Do Nothing */

    #elif (TIMER0_MODE == 1)    /* Fast PWM Mode */
    SET_BIT(TCCR0, 6);          /* Set WGM00 bit */

    #elif (TIMER0_MODE == 2)    /* CTC Mode */
    SET_BIT(TCCR0, 3);          /* Set WGM01 bit */

    #elif (TIMER0_MODE == 3)    /* Phase Correct PWM Mode */
    SET_BIT(TCCR0, 3);          /* Set WGM01 bit */
    SET_BIT(TCCR0, 6);          /* Set WGM00 bit */

    #else
    #warning "Timer0 is set to normal mode due to incorrect value in configurations."
    #endif

    /* Initialization for OC0 pin configurations */
    #if (TIMER0_MODE == 0 || TIMER0_MODE == 2)  /* Normal Mode or CTC mode */
        #if (COMPARE_OUTPUT_MODE == 0)
        /* Do Nothing */

        #elif (COMPARE_OUTPUT_MODE == 1)
        SET_BIT(TCCR0, 4);              /* Set COM00 bit in TCCR0 register */

        #elif (COMPARE_OUTPUT_MODE == 2)
        SET_BIT(TCCR0, 5);              /* Set COM01 bit in TCCR0 register */

        #elif (COMPARE_OUTPUT_MODE == 3)
        SET_BIT(TCCR0, 4);              /* Set COM00 bit in TCCR0 register */
        SET_BIT(TCCR0, 5);              /* Set COM01 bit in TCCR0 register */

        #else
        #warning "OC0 pin is set to (Normal port operation, OC0 disconnected) mode due to wrong configuration."
        #endif

    #elif (TIMER0_MODE == 3 || TIMER0_MODE == 1)    /* Fast PWM Mode or Phase Correct PWM Mode */
        #if (COMPARE_OUTPUT_MODE == 0)
        /* Do Nothing */

        #elif (COMPARE_OUTPUT_MODE == 1)
        SET_BIT(TCCR0, 5);              /* Set COM01 bit in TCCR0 register */

        #elif (COMPARE_OUTPUT_MODE == 2)
        SET_BIT(TCCR0, 4);              /* Set COM00 bit in TCCR0 register */
        SET_BIT(TCCR0, 5);              /* Set COM01 bit in TCCR0 register */

        #else
        #warning "OC0 pin is set to (Normal port operation, OC0 disconnected) mode due to wrong configuration."
        #endif
    #endif
}


void TIMER_Start(void)
{
/* <----------------------------------------[ Timer0 Initialization Section ]--------------------------------------> */
    /* Initializations for Timer Clock Select */
    #if (TIMER0_CLOCK_SELECT == 0)
    /* Do Nothing */

    #elif (TIMER0_CLOCK_SELECT == 1)
    SET_BIT(TCCR0, 0);    /* CS00 bit */

    #elif (TIMER0_CLOCK_SELECT == 2)
    SET_BIT(TCCR0, 1);    /* CS01 bit */

    #elif (TIMER0_CLOCK_SELECT == 3)
    SET_BIT(TCCR0, 1);    /* CS01 bit */
    SET_BIT(TCCR0, 0);    /* CS00 bit */

    #elif (TIMER0_CLOCK_SELECT == 4)
    SET_BIT(TCCR0, 2);    /* CS02 bit */

    #elif (TIMER0_CLOCK_SELECT == 5)
    SET_BIT(TCCR0, 2);    /* CS02 bit */
    SET_BIT(TCCR0, 0);    /* CS00 bit */

    #elif (TIMER0_CLOCK_SELECT == 6)
    SET_BIT(TCCR0, 2);    /* CS02 bit */
    SET_BIT(TCCR0, 1);    /* CS01 bit */

    #elif (TIMER0_CLOCK_SELECT == 7)
    SET_BIT(TCCR0, 2);    /* CS02 bit */
    SET_BIT(TCCR0, 1);    /* CS01 bit */
    SET_BIT(TCCR0, 0);    /* CS00 bit */

    #else
    #warning "Timer0 is disabled due to incorrect value in configurations."
    #endif
}

void TIMER_Stop(void)
{
    TCCR0 = 0;
}

/* ================================================================================================================= */
/* ================                               END OF FILE: Timer.c                              ================ */
/* ================================================================================================================= */
