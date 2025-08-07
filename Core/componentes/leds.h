/*
 * leds.h
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#ifndef COMPONENTES_LEDS_H_
#define COMPONENTES_LEDS_H_


#include "globalThreads.h"

#define TEMPO_PISCA 1000

typedef enum{
	LED_PC13=0,
	N_LEDS
}listLeds;

typedef struct{
	GPIO_TypeDef 	*GPIOx;
	uint16_t 		GPIO_pin;
}setupLeds;

extern int led_estado(listLeds led, uint8_t estado);
extern int led_on(listLeds led);
extern int led_off(listLeds led);
extern void led_setup(void);
extern void taskBlink(void *args);


#endif /* COMPONENTES_LEDS_H_ */
