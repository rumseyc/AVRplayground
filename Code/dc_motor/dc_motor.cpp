/*******************************
Simple test to move a DC brushless motor with PWM
*********************************/

#define F_CPU 14745600

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

int main() {

  uint8_t motor_speed = 0xFF;

  DDRB |= _BV(PB1); //Set PB1 to output
  DDRC |= _BV(PC4); //Set PC4 to output
  //Clear OCnA register on compare match
  //WGM10 & WGM12 Set to 8 bit fast PWM mode
  //Use 1:1 Prescaler
  TCCR1A |= _BV(WGM10);
	TCCR1B |= _BV(CS10) | _BV(WGM12);
  TCCR1A |= _BV(COM1A1); //Turn on clock after its configured

  while(1) {
    OCR1A = 0xFF;
    PORTC |= _BV(PC4);//Turn on led
    _delay_ms(2000);
    OCR1A = 0x00;
    PORTC &= ~_BV(PC4);
    _delay_ms(2000);
  }

  return 0;
}
