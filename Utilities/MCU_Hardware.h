/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : MCU_Hardware.h
 * 
 *  \category  : 
 * 
 *  \date      : 22 Sept. 2022
 * 
 *  \brief     : ARM Cortex-M4 TM4C123GH6PM Registers definitions
 *  
 *  \details   : All MCU ARM Cortex-M4 related addresses
 *
 *********************************************************************************************************************/

#ifndef MCU_HARDWARE_H
#define MCU_HARDWARE_H

/* ================================================================================================================= */
/* ================                                     INCLUDES                                    ================ */
/* ================================================================================================================= */

#include "Std_Types.h"

/* ================================================================================================================= */
/* ================                         GLOBAL DATA TYPES AND STRUCTURES                        ================ */
/* ================================================================================================================= */

typedef struct  
{
    uint8 PSR10     :1;
    uint8 PSR2      :1;
    uint8 PUD       :1;
    uint8 ACME      :1;
    uint8           :1;
    uint8 ADTS      :3;
} SFIOR_BF;

typedef struct
{
    uint8 MUX       :5;
    uint8 ADLAR     :1;
    uint8 REFS      :2;
} ADMUX_BF;

typedef struct
{
    uint8 ADPS      :3;
    uint8 ADIE      :1;
    uint8 ADIF      :1;
    uint8 ADATE     :1;
    uint8 ADSC      :1;
    uint8 ADEN      :1;
} ADCSRA_BF;

/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

/* <-----------------------------------------------[ MCU Registers ]-----------------------------------------------> */

#define SREG                                        (*(volatile uint8*)(0x5F))

/* <------------------------------------------[ DIO Peripheral Registers ]-----------------------------------------> */

/* DIO PORTA Registers */
#define DATAA										(*(volatile uint8*)(0x3B))
#define DDRA										(*(volatile uint8*)(0x3A))
#define PINA										(*(volatile uint8*)(0x39))

/* DIO PORTB Registers */
#define DATAB										(*(volatile uint8*)(0x38))
#define DDRB										(*(volatile uint8*)(0x37))
#define PINB										(*(volatile uint8*)(0x36))

/* DIO PORTC Registers */
#define DATAC										(*(volatile uint8*)(0x35))
#define DDRC										(*(volatile uint8*)(0x34))
#define PINC										(*(volatile uint8*)(0x33))

/* DIO PORTD Registers */
#define DATAD										(*(volatile uint8*)(0x32))
#define DDRD										(*(volatile uint8*)(0x31))
#define PIND										(*(volatile uint8*)(0x30))

/* <-----------------------------------------[ Timer Peripheral Registers ]----------------------------------------> */

/* Timer0 Registers */
#define TCNT0                                       (*(volatile uint8*)(0x52))
#define TCCR0                                       (*(volatile uint8*)(0x53))
#define OCR0                                        (*(volatile uint8*)(0x5C))

/* Timer1 Registers */
#define TCNT1H                                      (*(volatile uint8*)(0x4D))
#define TCNT1L                                      (*(volatile uint8*)(0x4C))
#define OCR1AH                                      (*(volatile uint8*)(0x4B))
#define OCR1AL                                      (*(volatile uint8*)(0x4A))
#define OCR1BH                                      (*(volatile uint8*)(0x49))
#define OCR1BL                                      (*(volatile uint8*)(0x48))
#define ICR1H                                       (*(volatile uint8*)(0x47))
#define ICR1L                                       (*(volatile uint8*)(0x46))

/* Timer2 Registers */
#define TCNT2                                       (*(volatile uint8*)(0x44))
#define OCR2                                        (*(volatile uint8*)(0x43))

/* Timer Interrupts Registers */
#define TIMSK                                       (*(volatile uint8*)(0x59))
#define TIFR                                        (*(volatile uint8*)(0x58))

/* <------------------------------------------[ ADC Peripheral Registers ]-----------------------------------------> */

#define SFIOR                                       (*(volatile SFIOR_BF*)(0x50))
#define ADMUX                                       (*(volatile ADMUX_BF*)(0x27))
#define ADCSRA                                      (*(volatile ADCSRA_BF*)(0x26))
#define ADCH                                        (*(volatile uint8*)(0x25))
#define ADCL                                        (*(volatile uint8*)(0x24))

/* <--------------------------------------------[ Interrupts Registers ]-------------------------------------------> */

#define MCUCR                                       (*(volatile uint8*)(0x55))
#define MCUCSR                                      (*(volatile uint8*)(0x54))
#define GICR                                        (*(volatile uint8*)(0x5B))
#define GIFR                                        (*(volatile uint8*)(0x5A))

#endif /* MCU_HARDWARE_H */

/* ================================================================================================================= */
/* ================                           END OF FILE: MCU_Hardware.h                           ================ */
/* ================================================================================================================= */
