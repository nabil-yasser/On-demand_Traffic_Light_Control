/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Dio.c
 * 
 *  \category  : DIO Driver
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Implementation of DIO driver functions
 *
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "Dio.h"
#include "../Int_Driver/Interrupts.h"

extern uint8 counter;
/* ================================================================================================================= */
/* ================                                GLOBAL FUNCTIONS                                 ================ */
/* ================================================================================================================= */

/*************************************************************************************
 *  \Description     : Initializes DIO ports
 ************************************************************************************/
 void DIO_Init(DIO_Channel_et channelId, DIO_Port_et portId, DIO_Direction_et direction)
 {
    switch (portId)
    {
        case PORTA:
            if (direction == INPUT)
            {
                CLEAR_BIT(DDRA, channelId);
            }
            else if (direction == OUTPUT)
            {
                SET_BIT(DDRA, channelId);
            }
            else
            {
                /* Error Handle */
            }
        break;

        case PORTB:
        if (direction == INPUT)
        {
            CLEAR_BIT(DDRB, channelId);
        }
        else if (direction == OUTPUT)
        {
            SET_BIT(DDRB, channelId);
        }
        else
        {
                /* Error Handle */
        }
        break;

        case PORTC:
        if (direction == INPUT)
        {
            CLEAR_BIT(DDRC, channelId);
        }
        else if (direction == OUTPUT)
        {
            SET_BIT(DDRC, channelId);
        }
        else
        {
                /* Error Handle */
        }
        break;

        case PORTD:
        if (direction == INPUT)
        {
            CLEAR_BIT(DDRD, channelId);
        }
        else if (direction == OUTPUT)
        {
            SET_BIT(DDRD, channelId);
        }
        else
        {
                /* Error Handle */
        }
        break;

        default:
                /* Error Handle */
        break;
    }
 }

 /*************************************************************************************
 *  \Description     : Writes HIGH/LOW for a specific channel
 ************************************************************************************/
 void DIO_Write(DIO_Channel_et channelId, DIO_Port_et portId, DIO_Level_et level)
 {
    switch (portId)
    {
        case PORTA:
            if (level == LOW)
            {
                CLEAR_BIT(DATAA, channelId);
            }
            else if (level == HIGH)
            {
                SET_BIT(DATAA, channelId);
            }
            else
            {
                /* Error Handle */
            }
            break;

            case PORTB:
            if (level == LOW)
            {
                CLEAR_BIT(DATAB, channelId);
            }
            else if (level == HIGH)
            {
                SET_BIT(DATAB, channelId);
            }
            else
            {
                /* Error Handle */
            }
        break;

        case PORTC:
            if (level == LOW)
            {
                CLEAR_BIT(DATAC, channelId);
            }
            else if (level == HIGH)
            {
                SET_BIT(DATAC, channelId);
            }
            else
            {
                /* Error Handle */
            }
            break;

            case PORTD:
            if (level == LOW)
            {
                CLEAR_BIT(DATAD, channelId);
            }
            else if (level == HIGH)
            {
                SET_BIT(DATAD, channelId);
            }
            else
            {
                /* Error Handle */
            }
        break;

        default:
                /* Error Handle */
        break;
    }
 }

 /*************************************************************************************
 *  \Description     : Toggles a specific channel
 ************************************************************************************/
 void DIO_Toggle(DIO_Channel_et channelId, DIO_Port_et portId)
 {
    switch (portId)
    {
        case PORTA:
            TOGGLE_BIT(DATAA, channelId);
        break;

        case PORTB:
            TOGGLE_BIT(DATAB, channelId);
        break;

        case PORTC:
            TOGGLE_BIT(DATAC, channelId);
        break;

        case PORTD:
            TOGGLE_BIT(DATAD, channelId);
        break;

        default:
                /* Error Handle */
        break;
    }
 }

 /*************************************************************************************
 *  \Description     : Reads specific bit
 ************************************************************************************/
 void DIO_Read(DIO_Channel_et channelId, DIO_Port_et portId, uint8 *readValue)
 {
    switch (portId)
    {
        case PORTA:
            *readValue = GET_BIT(PINA, channelId);
        break;

        case PORTB:
            *readValue = GET_BIT(PINB, channelId);
        break;

        case PORTC:
            *readValue = GET_BIT(PINC, channelId);
        break;

        case PORTD:
            *readValue = GET_BIT(PIND, channelId);
        break;

        default:
                /* Error Handle */
        break;
    }
 }

/* ================================================================================================================= */
/* ================                               END OF FILE: Dio.c                                ================ */
/* ================================================================================================================= */
