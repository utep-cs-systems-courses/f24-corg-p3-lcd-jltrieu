#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"
#include "timer.h"

char redrawScreen = 1;

void update_shape();

void main()
{
  P1DIR |= BIT6; //this is used to keep trackque of interrupts
  P1OUT |= BIT6;
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();

  enableWDTInterrupts();
  or_sr(0x8);
  clearScreen(COLOR_RED);
  
  while (1) {
    if(redrawScreen) {
      redrawScreen = 0;
      update_shape();
    }
    P1OUT &= ~BIT6; 
    or_sr(0x10); // CPU OFF
    P1OUT |= BIT6;
  }
}

short currentY = screenHeight/2; //start centered

void update_shape()
{
  //reuses buzzer state vars
  drawString8x12(10, currentY, "jazz music :)", COLOR_RED, COLOR_RED); //clear the text
  if(!buzzer_mode){
    currentY += 10;
  }
  else{
    currentY -= 10;
  }
  //make sure currentY doesnt fall out of bounds
  if(currentY >= screenHeight){
    currentY = screenHeight - 1;
  }
  if(currentY <= 0){
    currentY = 1;
  }
  drawString8x12(10, currentY, "jazz music :)", COLOR_WHITE, COLOR_RED);
  redrawScreen = 0;
}
