#ifndef __SERIAL_H__
#define __SERIAL_H__

#ifdef __cplusplus
extern "C" {
#endif
   
void init_serial0 (void);
void putchar0 (char c);
void putstring0 (const char *str);
char getchar0 (void);

//#define   init_serial   init_serial0
//#define   putchar      putchar0
//#define   putstring    putstring0
//#define   getchar      getchar0

#ifdef __cplusplus
}
#endif

#endif


