/*
 * globalThreads.c
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#include "globalThreads.h"

static int flagInit = 1;
static int flagBoot = 0;

int initGlobalThread(void){
	return flagInit;
}

void stopGlobalThread(void){
	flagInit = 0;
}

void bootOK(void){
	flagBoot = 1;
}
