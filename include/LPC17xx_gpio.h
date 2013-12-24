#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdint.h>

/*
  Pin Name        
  P0[30:0][1];    
  P1[31:0][2];    
  P2[13:0];
  P3[26:25];
  P4[29:28]

Fast General purpose input/output. These are typically shared with other
peripherals functions and will therefore not all be available in an
application. Packaging options may affect the number of GPIOs
available in a particular device.
Some pins may be limited by requirements of the alternate functions of
the pin. For example, the pins containing the I2C0 functions are
open-drain for any function selected on that pin.

[1] P0[14:12] are not available.
[2] P1[2], P1[3], P1[7:5], P1[13:11] are not available.

*/

#define FIO0DIRr         (*(volatile uint32_t*)0x2009C000)
#define FIO0MASKr        (*(volatile uint32_t*)0x2009C010)
#define FIO0PINr         (*(volatile uint32_t*)0x2009C014)
#define FIO0SETr         (*(volatile uint32_t*)0x2009C018)
#define FIO0CLRr         (*(volatile uint32_t*)0x2009C01C)

#define FIO1DIRr         (*(volatile uint32_t*)0x2009C020)
#define FIO1MASKr        (*(volatile uint32_t*)0x2009C030)
#define FIO1PINr         (*(volatile uint32_t*)0x2009C034)
#define FIO1SETr         (*(volatile uint32_t*)0x2009C038)
#define FIO1CLRr         (*(volatile uint32_t*)0x2009C03C)

#define FIO2DIRr         (*(volatile uint32_t*)0x2009C040)
#define FIO2MASKr        (*(volatile uint32_t*)0x2009C050)
#define FIO2PINr         (*(volatile uint32_t*)0x2009C054)
#define FIO2SETr         (*(volatile uint32_t*)0x2009C058)
#define FIO2CLRr         (*(volatile uint32_t*)0x2009C05C)

#define FIO3DIRr         (*(volatile uint32_t*)0x2009C060)
#define FIO3MASKr        (*(volatile uint32_t*)0x2009C070)
#define FIO3PINr         (*(volatile uint32_t*)0x2009C074)
#define FIO3SETr         (*(volatile uint32_t*)0x2009C078)
#define FIO3CLRr         (*(volatile uint32_t*)0x2009C07C)

#define FIO4DIRr         (*(volatile uint32_t*)0x2009C080)
#define FIO4MASKr        (*(volatile uint32_t*)0x2009C090)
#define FIO4PINr         (*(volatile uint32_t*)0x2009C094)
#define FIO4SETr         (*(volatile uint32_t*)0x2009C098)
#define FIO4CLRr         (*(volatile uint32_t*)0x2009C09C)


#endif

