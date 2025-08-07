/*
 * taskMainProjeto.h
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#ifndef COMPONENTES_TASKMAINPROJETO_H_
#define COMPONENTES_TASKMAINPROJETO_H_

#include "globalThreads.h"

#define SHUTDOWN_EVT		(1 << 2)
#define RESET_EVT			(1 << 11)
#define STANDBY_EVT			(1 << 12)

extern void startTaskScheduler(void);
extern void taskMain(void *args);
extern void finishTaskScheduler(void);

#endif /* COMPONENTES_TASKMAINPROJETO_H_ */
