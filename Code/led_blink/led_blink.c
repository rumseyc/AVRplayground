/*******************************
Blink Led to test that all works well and that you can succesfully
program the avr
*********************************/

#define F_CPU 14745600

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

// PIN DEFINITIONS:
//
// PC4 -- LED anode

int main() {
  // LED as output
  DDRC |= (1<<PC4);

  // loop keeps looking forever
  while(1) {
    // turn on LED
    PORTC |= (1<<PC4);

    //delay for time to let the light stay on
    _delay_ms(500);

    // turn off LED
    PORTC &= ~(1<<PC4);

    //delay for time to let the light stay off
    _delay_ms(500);

  }

  return 0;
}
