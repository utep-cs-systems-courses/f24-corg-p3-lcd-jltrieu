#include <msp430.h>
#include "buzzer.h"
#include "timer.h"

void __interrupt_vec(WDT_VECTOR) WDT()
{
  static unsigned short count = 0;
  if(++count > 250){
    redrawScreen = 1;
    buzzer_timer_update();
    count = 0;
  }
}

