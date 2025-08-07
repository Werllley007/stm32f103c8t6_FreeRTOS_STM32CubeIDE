/*
 * threads.c
 *
 *  Created on: Aug 6, 2025
 *      Author: werlley
 */

#include "threads.h"

setupThreads tipo_threads[N_THREADS] = {0};

osThreadAttr_t blink_thread_attr = {
		.name="Blink Task",
		.priority=osPriorityLow
};

void thread_setup(void){
	tipo_threads[BLINK_THREAD] = (setupThreads){
		.func = taskBlink,
		.arg = NULL,
		.attr = &blink_thread_attr,
		.ativar_thread = 1
	};
}

void thread_join(osThreadId_t id){
	// O FreeRTOS não tem um join nativo, mas você pode usar semáforos ou flags
	// Para este exemplo, apenas aguardamos a conclusão usando vTaskDelay
	if (id != NULL) {
		// Espera a thread terminar (você pode usar outros mecanismos de sincronização)
		while (eTaskGetState(id) != eDeleted) {
			vTaskDelay(100 / portTICK_PERIOD_MS);  // Delay de 100ms
		}
	}
}

int thread_init(void){
	thread_setup();

	for(uint32_t i = 0; i < N_THREADS; i++){
		if(tipo_threads[i].ativar_thread){
		//	continue;
		//}
		tipo_threads[i].id = osThreadNew(tipo_threads[i].func, tipo_threads[i].arg, tipo_threads[i].attr);

		if(tipo_threads[i].id == NULL){
			return -1;
		}
		}
	}

	return 0;
}

int thread_finish(void){
	stopGlobalThread();

	for(uint32_t i = 0; i < N_THREADS; i++){
		if(tipo_threads[i].ativar_thread){
			continue;
		}
		thread_join(tipo_threads[i].id);
		tipo_threads[i].ativar_thread = 0;
	}

	return 0;
}










