/*****************************************************************************
 *   blinky.c:  SYSTICK C file for NXP LPC13xx Family Microprocessors
 *
 *   Copyright(C) 2008, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2008.08.20  ver 1.00    Preliminary version, first Release
 *
******************************************************************************/
#include "LPC13xx.h"                        /* LPC13xx definitions */
#include "gpio.h"

#define SYSTICK_DELAY		5000

volatile uint32_t TimeTick = 0;

/* SysTick interrupt happens every 10 ms */
void SysTick_Handler(void)
{
  TimeTick++;
}

void delaySysTick(uint32_t tick)
{
  uint32_t timetick;

  /* Clear SysTick Counter */
  SysTick->VAL = 0;
  /* Enable the SysTick Counter */
  SysTick->CTRL |= SYSTICK_ENABLE;

  timetick = TimeTick;
  while ((TimeTick - timetick) < tick);
  
  /* Disable SysTick Counter */
  SysTick->CTRL &= ~SYSTICK_ENABLE;
  /* Clear SysTick Counter */
  SysTick->VAL = 0;
  return;
}

/* Main Program */

int main (void) {

  SystemInit();

  /* Called for system library in core_cmx.h(x=0 or 3). */
  SysTick_Config( SYSTICK_DELAY );
  
  if ( !(SysTick->CTRL & (1<<SYSTICK_CLKSOURCE)) )
  {
	/* When external reference clock is used(CLKSOURCE in
	Systick Control and register bit 2 is set to 0), the 
	SYSTICKCLKDIV must be a non-zero value and 2.5 times 
	faster than the reference clock. 
	When core clock, or system AHB clock, is used(CLKSOURCE 
	in Systick Control and register bit 2 is set to 1), the 
	SYSTICKCLKDIV has no effect to the SYSTICK frequency. See 
	more on Systick clock and status register in Cortex-M3 
	rechnical Reference Manual. */
	LPC_SYSCON->SYSTICKCLKDIV = 0x08;
  }

  /* Enable AHB clock to the GPIO domain. */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
  
  /* Set port 2_0 to output */
  GPIOSetDir( 2, 0, 1 );

  while (1)                                /* Loop forever */
  {
	delaySysTick(SYSTICK_DELAY);
	GPIOSetValue( 2, 0, 0 );
	delaySysTick(SYSTICK_DELAY);
	GPIOSetValue( 2, 0, 1 );
  }
}
