#ifndef switches_included
#define switches_included

#define SW0 BIT0
#define SW1 BIT1
#define SW2 BIT2
#define SW3 BIT3

#define SWITCHES 15

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down; // holds the value of depressed switches
extern char switch_state_changed; //boolean

#endif
