#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES); // if up, sense down
  P2IES &= (p2val | ~SWITCHES); // if down, sense up
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  buzzer_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = ~p2val & SWITCHES;
  switch_state_changed = 1;
  // just boilerplate for now, add function calls to other updates for updating
  buzzer_update();
}
