#include "serial.h"
#include "LPC17xx.h"

void init_serial0 (void)
{
  /* 0. Disable Transmit on Uart */
   LPC_UART0->TER = 0;
  /* 1. Set UART0 Rx Tx in Pin Function Select Register 0 */
  LPC_PINCON->PINSEL0 |= 0x50; 
  
  /* 2. LCR: 8 bits, no parity, 1 stop bit */
  LPC_UART0->LCR = 0x03;
  
  /* 3. DLL: Get access using DLAB bit in LCR */
  LPC_UART0->LCR |= 0x80;
  
  /* 4. Set baud rate to 9600 baud based on default 25MHz pClk (SystemCoreClock/4) */
  // UARTbaud = pClk/ (16 * (256 x DLM + DLL) * ( 1 + (DIVADDVAL/MULVAL)))
  LPC_UART0->DLL = (25000000/(16*9600));  // ~25MHz/(16*9600)
  LPC_UART0->DLM = 0;
  // LPC_UART0->FDR = MULVAL | DIVADDVAL; 
   LPC_UART0->FDR = (1 << 4) | 0; // MULVAL = 1 | DIVADDVAL = 0;
  
  /* 5. Clear DLAB bit */
  LPC_UART0->LCR &= ~0x80;
  /* 6. Enable Transmit on Uart */
  LPC_UART0->TER = (1<<7);
}

/* Output a single character */
void putchar0 (char c)
{
  /* Wait until Tx ready flag set */
  while ((LPC_UART0->LSR & 0x20) == 0){
      /* Do nothing */ ;
  }
   /* Write character */
   LPC_UART0->THR = c; 
}

/* Output a character string */
void putstring0 (const char *str)
{
  while (*str) {
      putchar0 (*str++);
  }
}

/* Input a single character */
char getchar0 (void)
{ 
   /* Wait until Rx ready flag set */
   while ((LPC_UART0->LSR & 0x01) == 0){
      /* Do nothing */ ; 
   }
   /* Read character */
   return LPC_UART0->RBR;
}

void init_serial (void) {
   init_serial0();
}
int  sendchar(int ch)
{
   putchar0(ch);
   return ch;
}

int  getkey(void)
{
   return getchar0();
}

