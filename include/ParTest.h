#ifndef PARTEST_H
#define PARTEST_H

void vParTestInitialise( void );

void vParTestSetLED( unsigned portBASE_TYPE uxLED, signed portBASE_TYPE xValue );

void vParTestToggleLED( unsigned portBASE_TYPE uxLED );


unsigned portBASE_TYPE uxParTextGetLED( unsigned portBASE_TYPE uxLED );

#endif
