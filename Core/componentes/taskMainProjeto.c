/*
 * taskMainProjeto.c
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#include "taskMainProjeto.h"

osThreadId_t threadx;

void startTaskScheduler(void){
	osThreadAttr_t thread_attr;
	memset(&thread_attr, 0, sizeof(thread_attr));

	thread_attr.name = "taskMain";
	thread_attr.priority = osPriorityAboveNormal;
	thread_attr.stack_size = 128 * 4;  // Ajuste o tamanho da pilha conforme necessário

	// Criando a tarefa main
	threadx = osThreadNew(taskMain, NULL, &thread_attr);
	if (threadx == NULL) {
		// Em caso de erro ao criar a thread
		while (1);
	}
}

void taskMain(void *args){
	//Iniciando a estrutura do IPC
	if(thread_init()){
		while(1);
	}

	bootOK();

	uint32_t flags = osThreadFlagsWait(SHUTDOWN_EVT | RESET_EVT | STANDBY_EVT, osFlagsWaitAny, osWaitForever);

	// Agora você pode usar 'flags' para verificar qual evento ocorreu
	if (flags & SHUTDOWN_EVT) {
		// Executa código para shutdown
	}
	if (flags & RESET_EVT) {
		// Executa código para reset
	}
	if (flags & STANDBY_EVT) {
		// Executa código para standby
	}

	thread_finish();

	osDelay(1000);
}

void finishTaskScheduler(void){
	osThreadYield();
	osThreadExit();
}

