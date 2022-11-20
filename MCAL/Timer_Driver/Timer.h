/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Timer.h
 * 
 *  \category  : Timer Driver - MCAL
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Header file for Timer Driver
 *
 *********************************************************************************************************************/

#ifndef TIMER_H
#define TIMER_H

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include <math.h>
#include "../../Utilities/MCU_Hardware.h"
#include "../../Utilities/Macros.h"
#include "../../Configs/Timer_Cfg.h"

/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

/* PRESCALER DEFINITION*/
#if (TIMER0_CLOCK_SELECT == 0)
#define PRESCALER 1.00

#elif (TIMER0_CLOCK_SELECT == 1)
#define PRESCALER 1.00

#elif (TIMER0_CLOCK_SELECT == 2)
#define PRESCALER 8.00

#elif (TIMER0_CLOCK_SELECT == 3)
#define PRESCALER 64.00

#elif (TIMER0_CLOCK_SELECT == 4)
#define PRESCALER 256.00

#elif (TIMER0_CLOCK_SELECT == 5)
#define PRESCALER 1024.00
#endif

/* ================================================================================================================= */
/* ================                            GLOBAL FUNCTION PROTOTYPES                           ================ */
/* ================================================================================================================= */

/*************************************************************************************
 *  \Description     : Initializes Timers
 ************************************************************************************/
 void TIMER_Init(void);

 /*************************************************************************************
 *  \Description     : Starts Timer functionality
 ************************************************************************************/
 void TIMER_Start(void);

/*************************************************************************************
 *  \Description     : Stops Timer functionality
 ************************************************************************************/
 void TIMER_Stop(void);

 /*************************************************************************************
 *  \Description     : Making delay using Timer0
 ************************************************************************************/
 static inline void TIMER_Delay(uint32 delayValue) __attribute__((__always_inline__));

 void TIMER_Delay(uint32 delayTime)
 {
    #if (TIMER0_CLOCK_SELECT > 0 && TIMER0_CLOCK_SELECT <= 7)   /* Check if Timer is enabled */
         /* Timer Calculations */
         #if (TIMER0_MODE == 0)
             uint32 overflowCounter = 0;                                 /* Counts number of overflows happened */
             double tmpDelayTicks = (1e-3  / (PRESCALER / F_CPU)) * delayTime;   /* Number of ticks in one millisecond */
             uint32 delayTicks = (uint32)fabs(tmpDelayTicks + 0.5);  /* Number of ticks required to make this delay */
             uint32 timerOverflow = ceil(delayTicks / 256.00);           /* Overflow Number = (DelayTicks / Maximum Ticks) */
             uint8 timerInitialValue = fabs((256.00 - (delayTicks / timerOverflow)));   /* Calculating initial value */
             TCNT0 = timerInitialValue;                                  /* Initializes the timer */
         #endif

         TIMER_Start();

         #if (TIMER0_MODE == 0)
             while (overflowCounter < timerOverflow)
             {
                 /* Initializations for Timer Value */
                 TCNT0 = timerInitialValue;

                 while (GET_BIT(TIFR, 0) == 0);      /* Wait for flag to be raised */
                 SET_BIT(TIFR, 0);                   /* Clears flag after overflow */
                 overflowCounter++;                  /* Increase Counter by one */
             }
         #elif (TIMER0_MODE == 2)
             while (GET_BIT(TIFR, 1) == 0);
             SET_BIT(TIFR, 1);
         #endif

         // TIMER_Stop();

     #else
        #warning "Timer is disabled and cannot function"
     #endif
 }

#endif /* TIMER_H */

/* ================================================================================================================= */
/* ================                                END OF FILE: Timer.h                             ================ */
/* ================================================================================================================= */
