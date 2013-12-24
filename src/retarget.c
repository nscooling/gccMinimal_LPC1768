#include "serial.h"
#include <stdio.h>
void retarget_init()
{
  // Initialize UART
  init_serial0();
  //putstring0("retarget_init\n\r");
}

int _write (int fd, char *ptr, int len)
{
  /* Write "len" of char from "ptr" to file id "fd"
   * Return number of char written.
   * Need implementing with UART here. */
   //putstring0("_write");
   for(; len > 0 ; --len) putchar0(*ptr++);
  return len;
}

char buffer[10];

#if 0
int _read (int fd, char * ptr, int len) {
  char c;
  int  i;
  putstring0("_read ");

  for (i = 0; i < len; i++) {
    c = getchar0();
    if (c == 0x0D) break;
    *ptr++ = c;
    putchar0(c);
  }
  return (len - i);
}
#else
int _read (int fd, char * ptr, int len) {
  *ptr = getchar0();
  putchar0(*ptr++);
  return 1;
}
#endif

void _ttywrch(int ch) {
  /* Write one char "ch" to the default console
   * Need implementing with UART here. */
  putchar0(ch);
}

/* SystemInit will be called before main */
//void SystemInit()
//{
//    retarget_init();
//}

