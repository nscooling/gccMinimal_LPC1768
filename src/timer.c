#include "timer.h"
#include "LPC17xx.h"
#include "core_cm3.h"

#define TIMER0_TICK_PER_SEC   10
#define TIMER0_IN_FREQ        25000000

static callbackFn callback;
static uint32_t count;

/*************************************************************************
 * Function Name: TIMER0_IRQHandler
 * Parameters: none
 *
 * Return: none
 *
 * Description: CMSIS Timer 0 interrupt handler
 *
 *************************************************************************/
void TIMER0_IRQHandler (void)
{
  ++count;
  callback(count);

  /*clear interrupt */
  LPC_TIM0->IR = 1;
  NVIC_ClearPendingIRQ(TIMER0_IRQn);
}

void Timer0Init(callbackFn fn)
{
  __disable_irq();
  // Enable TIM0 clocks
  //LPC_SC->PCONP |= 1; // should be 1 on reset anyway

  callback = fn;

  LPC_TIM0->TCR = 2;            // counting  disable and set reset
  LPC_TIM0->TCR = 0;            // release reset

  LPC_TIM0->CTCR = 0;	// Timer Mode: every rising PCLK edge
    
  LPC_TIM0->MCR = 0x03;  // Enable Interrupt and reset, Disable stop on MR0
  

  // set timer 0 period
  LPC_TIM0->PR = 18-1;

  LPC_TIM0->MR0 = (TIMER0_IN_FREQ)/(18 * TIMER0_TICK_PER_SEC);
  
  
  LPC_TIM0->IR = 1;			// init timer 0 interrupt

  LPC_TIM0->TCR = 1;            // counting Enable
  
  /*Enable NVIC TMR0 Interrupt*/
  NVIC_EnableIRQ(TIMER0_IRQn);
  __enable_irq();
}
