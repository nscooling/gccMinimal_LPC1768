#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdint.h>

typedef void (*callbackFn)(uint32_t);

void Timer0Init(callbackFn fn);


#endif
