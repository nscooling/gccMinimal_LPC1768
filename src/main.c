#pragma import(__use_no_semihosting_swi)

//#include "leds.h"
#include "serial.h"
#include "timer.h"
#include "LPC17xx.h"

#include <stdio.h> // semi-hosting needs retargeting
extern void retarget_init(); // see retartget.c

#define LED1  (1<<18)
#define LED2  (1<<20)
#define LED3  (1<<21)
#define LED4  (1<<23)

void delay(void)
{
  volatile int i;
  for(i = 0; i < 1000000; i++)
  {
    // do nothing
  }
}

void timerCallback(uint32_t currentCount)
{
  LPC_GPIO1->FIOPIN ^= LED1;
}

void SysTick_Handler()
{
 LPC_GPIO1->FIOPIN ^= LED1|LED4; 
}

int date;
char name[20];

int main(void)
{
  SysTick_Config(SystemCoreClock/10);
    retarget_init();
   LPC_GPIO1->FIODIR |= LED1|LED2|LED3|LED4; //CMSIS definitions
   LPC_GPIO1->FIOPIN ^= LED1;
   //init_serial0();
    //Timer0Init(&timerCallback);
   //putstring0("Hello from mbed on GCC\n\r");
   printf("hello world, please enter you name and a number\n\r ");
   scanf("%s %d", name, &date);
   printf("hello %s %d\n\r", name, date);
   fflush(stdin);
   char c = 'x';
   do {
      LPC_GPIO1->FIOPIN ^= LED2|LED3;
      delay();
      c = getchar();
      putchar(c);
      //fflush(stdout);
   } while(1);
   return 0;
}
