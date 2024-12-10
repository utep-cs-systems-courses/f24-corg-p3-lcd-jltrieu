#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_switch_update();
void buzzer_timer_update();

extern unsigned char buzzer_mode;
extern unsigned char buzzer_state;

#endif
