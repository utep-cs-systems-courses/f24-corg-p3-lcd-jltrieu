#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  // 2 MHz
  // period of 1000: 2kHz tone
  // period of 0: off
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void buzzer_update()
{
  if (switch_state_changed){
    static short cycles = 0;
    if (switch_state_down & SW1) cycles = 4211;
    if (switch_state_down & SW2) cycles = 2857;
    if (switch_state_down & SW3) cycles = 2222;
    if (switch_state_down & SW0) cycles = 0;
    buzzer_set_period(cycles);
  }
  switch_state_changed = 0;
}
