/*
 * app.c
 *
 *  Created on: Feb 5, 2026
 *      Author: Mohamed Magdy
 */
#include "../HAL/LED.h"
#include "../HAL/button.h"
#include <avr/io.h>
#include <util/delay.h>


void main() {
  LEDS_init();
  button_init();
  enable_pull_up();

  while (1) {
    if (!(button1_pin_id & (1 << button1_pinx))) {
      LED_on(LED_RED);
    } else {
      LED_off(LED_RED);
    }

    _delay_ms(10);
  }
}
