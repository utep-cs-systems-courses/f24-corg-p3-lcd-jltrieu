#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

unsigned char buzzer_mode = 0, buzzer_state = 0;

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

void buzzer_switch_update()
{
  if (switch_state_changed){
    if (switch_state_down & SW0) buzzer_mode = 0;
    if (switch_state_down & SW1) buzzer_mode = 1;
    if (switch_state_down & SW2) buzzer_mode = 2;
    if (switch_state_down & SW3) buzzer_mode = 3;
    buzzer_state = 0; // reset
    buzzer_timer_update(); //force an update
  }
  switch_state_changed = 0;
}

void buzzer_timer_update()
{
  static short cycles = 0;
  switch (buzzer_mode){
    case 0:
      if(buzzer_state > 2){
	cycles = 0;
	buzzer_state = 0;
	break;
      }
      if(buzzer_state == 0){
	cycles = 4211;
      }
      if(buzzer_state == 1){
	cycles = 2857;
      }
      if(buzzer_state == 2){
	cycles = 2222;
      }
      buzzer_state++;
      break;
    case 1:
    case 2:
    case 3:
      cycles = 0;
      break;
  }
  buzzer_set_period(cycles);
}
