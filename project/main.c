#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"

int main()
{
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();

  buzzer_set_period(0);
  clearScreen(COLOR_RED);

  or_sr(0x18); //CPU off, GIE on
}

