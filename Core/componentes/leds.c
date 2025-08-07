/*
 * leds.c
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#include "leds.h"

setupLeds ledx[N_LEDS] = {0};

int led_estado(listLeds led, uint8_t estado){
	if(led >= N_LEDS || (led < 0)){
		return -1;
	}

	HAL_GPIO_WritePin(ledx[led].GPIOx, ledx[led].GPIO_pin, (estado==0?GPIO_PIN_RESET:GPIO_PIN_SET));

	return 0;
}

int led_on(listLeds led){
	return led_estado(led, 1);
}

int led_off(listLeds led){
	return led_estado(led, 0);
}

void led_setup(void){
	ledx[LED_PC13] = (setupLeds){
		.GPIOx = GPIOC,
		.GPIO_pin = GPIO_PIN_13
	};
}

void taskBlink(void *args){
	led_setup();

	listLeds led = LED_PC13;

	while(initGlobalThread()){
		led_on(led);
		osDelay(TEMPO_PISCA);

		led_off(led);
		osDelay(TEMPO_PISCA);
	}
}

