/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : App.c
 * 
 *  \category  : Application Layer
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Implementation of Application
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "App.h"

uint8 carRedFlag = LOW, carYellowFlagRtoG = LOW, carYellowFlagGtoR = LOW, carGreenFlag = LOW, keyPressed = LOW;
uint8 trafficMode = 0;

/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

void APP_Setup(void)
{
    LED_Init(CARS_RED, CARS_PORT);
    LED_Init(CARS_YELLOW, CARS_PORT);
    LED_Init(CARS_GREEN, CARS_PORT);
    LED_Init(PEOPLE_RED, PEOPLE_PORT);
    LED_Init(PEOPLE_YELLOW, PEOPLE_PORT);
    LED_Init(PEOPLE_GREEN, PEOPLE_PORT);
    TIMER_Init();
    INT_Init();
}

void APP_Loop(void)
{
    /* Allow Cars to move and Stop People */
    LED_On(CARS_GREEN, CARS_PORT);              /* Cars Green ON for 5s*/
    LED_On(PEOPLE_RED, PEOPLE_PORT);            /* People Red ON for 5s */
    carGreenFlag = HIGH;                        /* Raise Green Flag */
    TIMER_Delay(5000);
    LED_Off(CARS_GREEN, CARS_PORT);             /* Cars Green OFF */
    carGreenFlag = LOW;                         /* Clear Green Flag */

    /* Blink for 5s before stopping cars and allowing people */
    for (uint8 i = 0; i < 10; i++)
    {
        LED_Toggle(CARS_YELLOW, CARS_PORT);     /* Blink Cars Yellow every 500ms */
        carYellowFlagGtoR = HIGH;                   /* Raise Yellow Flag */
        LED_Toggle(PEOPLE_YELLOW, PEOPLE_PORT); /* Blink People Yellow every 500ms */
        TIMER_Delay(500);
    }
    carYellowFlagGtoR = LOW;                        /* Clear Yellow Flag */
    LED_Off(PEOPLE_YELLOW, PEOPLE_PORT);
    LED_Off(CARS_YELLOW, CARS_PORT);
    LED_Off(PEOPLE_RED, PEOPLE_PORT);           /* People Red OFF */

    /* Stop Cars and Allow people to pass the street */
    LED_On(CARS_RED, CARS_PORT);                /* Cars Red ON for 5s*/
    LED_On(PEOPLE_GREEN, PEOPLE_PORT);          /* People Green ON for 5s */
    carRedFlag = HIGH;                          /* Raise Red Flag */
    TIMER_Delay(5000);
    LED_Off(PEOPLE_GREEN, PEOPLE_PORT);         /* People Green OFF for 5s */
    carRedFlag = LOW;                           /* Clear Red Flag */

    for (uint8 i = 0; i < 10; i++)
    {
        LED_Toggle(CARS_YELLOW, CARS_PORT);     /* Blink Cars Yellow every 500ms */
        LED_Toggle(PEOPLE_YELLOW, PEOPLE_PORT); /* Blink People Yellow every 500ms */
        carYellowFlagRtoG = HIGH;               /* Raise Yellow Flag */
        TIMER_Delay(500);
    }
    carYellowFlagRtoG = LOW;                    /* Clear Yellow Flag */
    LED_Off(PEOPLE_YELLOW, PEOPLE_PORT);
    LED_Off(CARS_YELLOW, CARS_PORT);
    LED_Off(CARS_RED, CARS_PORT);               /* Cars Red OFF */
}

ISR(EXT_INT0)
{
    if (keyPressed == LOW)
    {
        keyPressed = HIGH;
        if (carGreenFlag == HIGH || carYellowFlagGtoR == HIGH || carYellowFlagRtoG == HIGH)
        {
            /* Warn Cars traffic is going to be Red */
            LED_Off(CARS_GREEN, CARS_PORT);
            for (uint8 i = 0; i < 10; i++)
            {
                LED_Toggle(CARS_YELLOW, CARS_PORT);     /* Blink Cars Yellow every 500ms */
                LED_Toggle(PEOPLE_YELLOW, PEOPLE_PORT); /* Blink People Yellow every 500ms */
                TIMER_Delay(500);
            }
            LED_Off(PEOPLE_YELLOW, PEOPLE_PORT);
            LED_Off(CARS_YELLOW, CARS_PORT);

            /* Stop cars and Allow people to pass street */
            LED_Off(PEOPLE_RED, PEOPLE_PORT);
            LED_On(PEOPLE_GREEN, PEOPLE_PORT);
            LED_On(CARS_RED, CARS_PORT);
            TIMER_Delay(5000);

            /* Warn people that traffic is going to be Red */
            LED_Off(CARS_RED, CARS_PORT);
            for (uint8 i = 0; i < 10; i++)
            {
                LED_Toggle(CARS_YELLOW, CARS_PORT);     /* Blink Cars Yellow every 500ms */
                LED_Toggle(PEOPLE_YELLOW, PEOPLE_PORT); /* Blink People Yellow every 500ms */
                TIMER_Delay(500);
            }
            LED_Off(PEOPLE_YELLOW, PEOPLE_PORT);
            LED_Off(CARS_YELLOW, CARS_PORT);
            LED_Off(PEOPLE_GREEN, PEOPLE_PORT);

            if (carGreenFlag == HIGH)
            {
                /* Stop people and Allow Cars */
                LED_On(PEOPLE_RED, PEOPLE_PORT);
                LED_On(CARS_GREEN, CARS_PORT);
            }
            else if (carYellowFlagGtoR == HIGH)
            {
                /* Stop people and Allow Cars */
                LED_On(PEOPLE_RED, PEOPLE_PORT);
            }
            else if (carYellowFlagRtoG == HIGH)
            {
                /* Stop people and Allow Cars */
                LED_On(CARS_RED, CARS_PORT);
            }
        }
        else if (carRedFlag == HIGH)
        {
            TIMER_Delay(5000);
        }
    }
    keyPressed = LOW;
}

/* ================================================================================================================= */
/* ================                                END OF FILE: App.c                               ================ */
/* ================================================================================================================= */
