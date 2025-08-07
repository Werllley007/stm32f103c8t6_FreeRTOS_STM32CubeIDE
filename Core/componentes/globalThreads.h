/*
 * globalThreads.h
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#ifndef COMPONENTES_GLOBALTHREADS_H_
#define COMPONENTES_GLOBALTHREADS_H_

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "threads.h"
#include "leds.h"
#include "taskMainProjeto.h"

extern int initGlobalThread(void);
extern void stopGlobalThread(void);
extern void bootOK(void);


#endif /* COMPONENTES_GLOBALTHREADS_H_ */
