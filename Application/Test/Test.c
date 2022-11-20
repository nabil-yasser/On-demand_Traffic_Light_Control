/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Test.c
 * 
 *  \category  : Application Layer
 * 
 *  \date      : 20 Nov. 2022
 * 
 *  \brief     : Implementation of Application Test Functions
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "Test.h"

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/*************************************************************************************
 *  \Description     : Calls and validate DIO driver outputs
 ************************************************************************************/
uint8 DIO_Test(void)
{
    uint8 readValue = 0;

    /* DIO_Init function test */
    DIO_Init(PIN0, PORTA, OUTPUT);
    if (GET_BIT(DDRA, PIN0) != OUTPUT)
    {
        return 1;
    }

    DIO_Init(PIN3, PORTA, INPUT);
    if (GET_BIT(DDRA, PIN3) != INPUT)
    {
        return 1;
    }

    DIO_Init(PIN5, PORTB, OUTPUT);
    if (GET_BIT(DDRB, PIN5) != OUTPUT)
    {
        return 1;
    }

    DIO_Init(PIN7, PORTC, OUTPUT);
    if (GET_BIT(DDRC, PIN7) != OUTPUT)
    {
        return 1;
    }

    /* DIO_Write function test */
    DIO_Write(PIN0, PORTA, HIGH);
    if (GET_BIT(PINA, PIN0) != HIGH)
    {
        return 1;
    }

    DIO_Write(PIN7, PORTC, LOW);
    if (GET_BIT(PINC, PIN7) != LOW)
    {
        return 1;
    }

    /* DIO_Toggle function test */
    DIO_Toggle(PIN5, PORTB);
    if (GET_BIT(PINB, PIN5) != HIGH)
    {
        return 1;
    }

    /* DIO_Read function test */
    DIO_Read(PIN0, PORTA, &readValue);
    if (readValue != HIGH)
    {
        return 1;
    }

    DIO_Read(PIN7, PORTC, &readValue);
    if (readValue != LOW)
    {
        return 1;
    }

    return 0;
}

/*************************************************************************************
 *  \Description     : Calls and validate TIMER driver outputs
 ************************************************************************************/
uint8 TIMER_Test(void)
{
    /* TIMER_Init function test */
    TIMER_Init();

    /* Initializations for Timer Mode Test */
    #if (TIMER0_MODE == 0)      /* Normal Mode */
    if (GET_BIT(TCCR0, 3) != 0 || GET_BIT(TCCR0, 6) != 0)
    {
        return 1;
    }

    #elif (TIMER0_MODE == 1)    /* Fast PWM Mode */
    if (GET_BIT(TCCR0, 3) != 0 || GET_BIT(TCCR0, 6) != 1)
    {
        return 1;
    }

    #elif (TIMER0_MODE == 2)    /* CTC Mode */
    if (GET_BIT(TCCR0, 3) != 1 || GET_BIT(TCCR0, 6) != 0)
    {
        return 1;
    }

    #elif (TIMER0_MODE == 3)    /* Phase Correct PWM Mode */
    if (GET_BIT(TCCR0, 3) != 1 || GET_BIT(TCCR0, 6) != 1)
    {
        return 1;
    }
    #endif


    /* Initialization for OC0 pin configurations Test */
    #if (TIMER0_MODE == 0 || TIMER0_MODE == 2)  /* Normal Mode or CTC mode */
        #if (COMPARE_OUTPUT_MODE == 0)
        if (GET_BIT(TCCR0, 4) != 0 || GET_BIT(TCCR0, 5) != 0)
        {
            return 1;
        }

        #elif (COMPARE_OUTPUT_MODE == 1)
        if (GET_BIT(TCCR0, 4) != 1 || GET_BIT(TCCR0, 5) != 0)
        {
            return 1;
        }

        #elif (COMPARE_OUTPUT_MODE == 2)
        if (GET_BIT(TCCR0, 4) != 0 || GET_BIT(TCCR0, 5) != 1)
        {
            return 1;
        }

        #elif (COMPARE_OUTPUT_MODE == 3)
        if (GET_BIT(TCCR0, 4) != 1 || GET_BIT(TCCR0, 5) != 1)
        {
            return 1;
        }
        #endif

    #elif (TIMER0_MODE == 3 || TIMER0_MODE == 1)    /* Fast PWM Mode or Phase Correct PWM Mode */
        #if (COMPARE_OUTPUT_MODE == 0)
        if (GET_BIT(TCCR0, 4) != 0 || GET_BIT(TCCR0, 5) != 0)
        {
            return 1;
        }

        #elif (COMPARE_OUTPUT_MODE == 1)
        if (GET_BIT(TCCR0, 4) != 0 || GET_BIT(TCCR0, 5) != 1)
        {
            return 1;
        }

        #elif (COMPARE_OUTPUT_MODE == 2)
        if (GET_BIT(TCCR0, 4) != 1 || GET_BIT(TCCR0, 5) != 1)
        {
            return 1;
        }
        #endif
    #endif


    /* TIMER_Start function test */
    TIMER_Start();
    #if (TIMER0_CLOCK_SELECT == 0)
    if (GET_BIT(TCCR0, 0) != 0 || GET_BIT(TCCR0, 1) != 0 || GET_BIT(TCCR0, 2) != 0)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 1)
    if (GET_BIT(TCCR0, 0) != 1 || GET_BIT(TCCR0, 1) != 0 || GET_BIT(TCCR0, 2) != 0)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 2)
    if (GET_BIT(TCCR0, 0) != 0 || GET_BIT(TCCR0, 1) != 1 || GET_BIT(TCCR0, 2) != 0)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 3)
    if (GET_BIT(TCCR0, 0) != 1 || GET_BIT(TCCR0, 1) != 1 || GET_BIT(TCCR0, 2) != 0)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 4)
    if (GET_BIT(TCCR0, 0) != 0 || GET_BIT(TCCR0, 1) != 0 || GET_BIT(TCCR0, 2) != 1)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 5)
    if (GET_BIT(TCCR0, 0) != 1 || GET_BIT(TCCR0, 1) != 0 || GET_BIT(TCCR0, 2) != 1)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 6)
    if (GET_BIT(TCCR0, 0) != 0 || GET_BIT(TCCR0, 1) != 1 || GET_BIT(TCCR0, 2) != 1)
    {
        return 1;
    }

    #elif (TIMER0_CLOCK_SELECT == 7)
    if (GET_BIT(TCCR0, 0) != 1 || GET_BIT(TCCR0, 1) != 1 || GET_BIT(TCCR0, 2) != 1)
    {
        return 1;
    }
    #endif

    /* TIMER_delay function test */
    TIMER_Delay(500);


    /* TIMER_Stop function test */
    TIMER_Stop();
    if (TCCR0 != 0)
    {
        return 1;
    }

    return 0;
}

/*************************************************************************************
 *  \Description     : Calls and validate Interrupts driver outputs
 ************************************************************************************/
uint8 INT_Test(void)
{
    INT_Init();

    /* Initializations for INT0 */
    #if (INT0_SENSE_CONTROL == 0)
    if (GET_BIT(MCUCR, 0) != 0 || GET_BIT(MCUCR, 1) != 0)
    {
        return 1;
    }

    #elif (INT0_SENSE_CONTROL == 1)
    if (GET_BIT(MCUCR, 0) != 1 || GET_BIT(MCUCR, 1) != 0)
    {
        return 1;
    }

    #elif (INT0_SENSE_CONTROL == 2)
    if (GET_BIT(MCUCR, 0) != 0 || GET_BIT(MCUCR, 1) != 1)
    {
        return 1;
    }

    #elif (INT0_SENSE_CONTROL == 3)
    if (GET_BIT(MCUCR, 0) != 1 || GET_BIT(MCUCR, 1) != 1)
    {
        return 1;
    }
    #endif

    /* Initializations for INT1 */
    #if (INT1_SENSE_CONTROL == 0)
    if (GET_BIT(MCUCR, 2) != 0 || GET_BIT(MCUCR, 3) != 0)
    {
        return 1;
    }

    #elif (INT1_SENSE_CONTROL == 1)
    if (GET_BIT(MCUCR, 2) != 1 || GET_BIT(MCUCR, 3) != 0)
    {
        return 1;
    }

    #elif (INT1_SENSE_CONTROL == 2)
    if (GET_BIT(MCUCR, 2) != 0 || GET_BIT(MCUCR, 3) != 1)
    {
        return 1;
    }

    #elif (INT1_SENSE_CONTROL == 3)
    if (GET_BIT(MCUCR, 2) != 1 || GET_BIT(MCUCR, 3) != 1)
    {
        return 1;
    }
    #endif

    /* Initializations for INT0 */
    #if (INT2_SENSE_CONTROL == 0)
    if (GET_BIT(MCUCSR, 6) != 0)
    {
        return 1;
    }

    #elif (INT2_SENSE_CONTROL == 1)
    if (GET_BIT(MCUCSR, 6) != 1)
    {
        return 1;
    }
    #endif

    /* Initializations for INT0 */
    #if (INT0_ENABLE == 0)
    if (GET_BIT(GICR, 6) != 0)
    {
        return 1;
    }

    #elif (INT0_ENABLE == 1)
    if (GET_BIT(GICR, 6) != 1)
    {
        return 1;
    }
    #endif

    /* Initializations for INT1 */
    #if (INT1_ENABLE == 0)
    if (GET_BIT(GICR, 7) != 0)
    {
        return 1;
    }

    #elif (INT1_ENABLE == 1)
    if (GET_BIT(GICR, 7) != 1)
    {
        return 1;
    }
    #endif

    /* Initializations for INT2 */
    #if (INT2_ENABLE == 0)
    if (GET_BIT(GICR, 5) != 0)
    {
        return 1;
    }

    #elif (INT2_ENABLE == 1)
    if (GET_BIT(GICR, 5) != 1)
    {
        return 1;
    }
    #endif

    return 0;
}

/*************************************************************************************
 *  \Description     : Calls and validate LED driver outputs
 ************************************************************************************/
uint8 LED_Test(void)
{
    LED_Init(PIN2, PORTC);
    if (GET_BIT(DDRC, PIN2) != OUTPUT)
    {
        return 1;
    }

    LED_Init(PIN5, PORTD);
    if (GET_BIT(DDRD, PIN5) != OUTPUT)
    {
        return 1;
    }

    LED_On(PIN2, PORTC);
    if (GET_BIT(PINC, PIN2) != HIGH)
    {
        return 1;
    }

    LED_Off(PIN2, PORTC);
    if (GET_BIT(PINC, PIN2) != LOW)
    {
        return 1;
    }

    LED_Toggle(PIN5, PORTD);
    if (GET_BIT(PIND, PIN5) != HIGH)
    {
        return 1;
    }

    return 0;
}

/*************************************************************************************
 *  \Description     : Calls and validate DIO driver outputs
 ************************************************************************************/
uint8 BUTTON_Test(void)
{
    uint8 readValue = 0;
    BUTTON_Init(PIN3, PORTD);
    if (GET_BIT(DDRD, PIN3) != INPUT)
    {
        return 1;
    }

    BUTTON_Read(PIN3, PORTD, &readValue);
    if (readValue != HIGH)
    {
        return 1;
    }

    return 0;
}


/* ================================================================================================================= */
/* ================                               END OF FILE: Test.c                               ================ */
/* ================================================================================================================= */
