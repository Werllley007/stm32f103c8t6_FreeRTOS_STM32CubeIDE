/*
 * threads.h
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#ifndef COMPONENTES_THREADS_H_
#define COMPONENTES_THREADS_H_

#include "globalThreads.h"

typedef enum{
	BLINK_THREAD=0,
	N_THREADS
}listThreads;

typedef struct{
	osThreadId_t id;
	osThreadFunc_t func;
	void *arg;
	osThreadAttr_t *attr;
	unsigned int ativar_thread;
}setupThreads;

extern void thread_setup(void);
extern void thread_join(osThreadId_t id);
extern int thread_init(void);
extern int thread_finish(void);

#endif /* COMPONENTES_THREADS_H_ */
