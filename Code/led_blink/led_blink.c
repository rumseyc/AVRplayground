/*******************************
Blink Led to test that all works well and that you can succesfully
program the avr
*********************************/

#define F_CPU 14745600

#include <avr/io.h>
#include <inttypes.h>

// PIN DEFINITIONS:
//
// PC4 -- LED anode

void delay_ms();

int main() {
  // LED as output
  DDRC |= (1<<PC4);

  // loop keeps looking forever
  while(1) {
    // turn on LED
    PORTC |= (1<<PC4);

    //delay for time to let the light stay on
    delay_ms();

    // turn off LED
    PORTC &= ~(1<<PC4);

    //delay for time to let the light stay off
    delay_ms();

  }

  return 0;
}


void delay_ms(){
  for( int i = 0; i < F_CPU; i++);
}
