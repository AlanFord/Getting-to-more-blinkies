/////////////////////////////////////////////////////////////////////////
///	\file main.c
///	\brief This is the main program code.
///
///	Author: Alan Ford
/////////////////////////////////////////////////////////////////////////

#include "common.h"
#include "MCU/led.h"
#include "MCU/tick.h"

/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
  // uint32_t i = 0;

  /* TODO - Add your application code here */

  /* Infinite loop */
  while (1)
  {
    Led_Init();
    Tick_init();

    for ( ;; )
    {
    	Led_Toggle();
    	Tick_DelayMs(1000);
    }
  }
}
