/**********************************************************************************************************************
 *
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  \file      : App.h
 * 
 *  \category  : Application Layer
 * 
 *  \date      : 26 Oct. 2022
 * 
 *  \brief     : Header file for Application
 *
 *********************************************************************************************************************/

#ifndef APP_H
#define APP_H

/* ================================================================================================================= */
/* ================                                    INCLUDES                                     ================ */
/* ================================================================================================================= */

#include "../ECUAL/LED_Driver/Led.h"
#include "../ECUAL/Button_Driver/Button.h"
#include "../MCAL/Timer_Driver/Timer.h"
#include "../MCAL/Int_Driver/Interrupts.h"

/* ================================================================================================================= */
/* ================                              GLOBAL CONSTANT MACROS                             ================ */
/* ================================================================================================================= */

#define CARS_PORT PORTA
#define CARS_RED PIN0
#define CARS_YELLOW PIN1
#define CARS_GREEN PIN2

#define PEOPLE_PORT PORTB
#define PEOPLE_RED PIN0
#define PEOPLE_YELLOW PIN1
#define PEOPLE_GREEN PIN2

/* ================================================================================================================= */
/* ================                            GLOBAL FUNCTION PROTOTYPES                           ================ */
/* ================================================================================================================= */

void APP_Setup(void);

void APP_Loop(void);


#endif /* APP_H */

/* ================================================================================================================= */
/* ================                                END OF FILE: App.h                               ================ */
/* ================================================================================================================= */
