#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"

int main()
{
  P1DIR |= BIT6; //this is used to keep trackque of interrupts
  P1OUT |= BIT6;
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();

  buzzer_set_period(0);
  clearScreen(COLOR_RED);

  or_sr(0x8); //GIE ON
  P1OUT &= ~BIT6; 
  or_sr(0x10); // CPU OFF
  P1OUT |= BIT6;
}

