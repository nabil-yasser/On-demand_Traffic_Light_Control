/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : Timer_Cfg.h
 * 
 *  \category  : Timer Driver - MCAL
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Configurations file for Timer Driver
 *
 *********************************************************************************************************************/

#ifndef TIMER_CFG_H
#define TIMER_CFG_H

/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

/* <-----------------------------------------[ Timer0 User Configurations ]----------------------------------------> */

 /* ================================================================================================================= */
 /* ================                              Clock Configurations                               ================ */
 /* ================================================================================================================= */
 #define F_CPU 1000000UL            /* 1 MHz clock */

/**********************************************************************************************************************
 *  User Configurations for Timer Mode:
 *  0 -> Normal Mode                (Default)
 *  1 -> PWM, Phase Correct Mode
 *  2 -> CTC Mode
 *  3 -> Fast PWM Mode
 *********************************************************************************************************************/
#define TIMER0_MODE 0

/**********************************************************************************************************************
 *  User Configurations for Timer Clock Select:
 *  0 -> Disable Timer.                (Default)
 *  1 -> Enable Timer, no prescaler.
 *  2 -> Clk / 8 Prescaler.
 *  3 -> Clk / 64 Prescaler.
 *  4 -> Clk / 256 Prescaler.
 *  5 -> Clk / 1024 Prescaler.
 *  6 -> External clock source on T0 pin. Clock on falling edge.
 *  7 -> External clock source on T0 pin. Clock on rising edge.
 *********************************************************************************************************************/
#define TIMER0_CLOCK_SELECT 4

/**********************************************************************************************************************
 *  User Configurations for OC0 pin operation:

 *  ########### NORMAL / CTC MODES ###########
 *  0 -> Normal port operation, OC0 disconnected.                (Default)
 *  1 -> Toggle OC0 on compare match.
 *  2 -> Clear OC0 on compare match.
 *  3 -> Set OC0 on compare match.
 *  Note: This configuration only works in NORMAL/CTC mode.
 *
 *************************************************************************

 ########### FAST PWM MODE ###########
 *  0 -> Normal port operation, OC0 disconnected.                (Default)
 *  1 -> Clear OC0 on compare match, set OC0 at BOTTOM (non-inverting mode).
 *  2 -> Set OC0 on compare match, clear OC0 at BOTTOM (inverting mode).
 *  Note: This configuration only works in FAST PWM mode.
 *
 *************************************************************************

 ########### PHASE CORRECT PWM MODE ###########
 *  0 -> Normal port operation, OC0 disconnected.                (Default)
 *  1 -> Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting.
 *  2 -> Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting.
 *  Note: This configuration only works in PHASE CORRECT PWM mode.
 *********************************************************************************************************************/
#define COMPARE_OUTPUT_MODE 0


#endif /* TIMER_CFG_H */

/* ================================================================================================================= */
/* ================                              END OF FILE: Timer_Cfg.h                           ================ */
/* ================================================================================================================= */
