/*
 * scheduler.c
 *
 *  Created on: Nov 28, 2022
 *      Author: ASUS
 */

#include "scheduler.h"
#include "stdio.h"
sTasks SCH_Tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;
int TICK = 10;
int *nullptr = NULL;
void SCH_Init(void){
	// reset all
	for(int i= 0; i< SCH_MAX_TASKS; i++){
		SCH_Delete(i);
	}
}
void SCH_Add_Task( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	if(current_index_task< SCH_MAX_TASKS){
		SCH_Tasks_G[current_index_task].ptask = pFunction;
		SCH_Tasks_G[current_index_task].Delay = DELAY/TICK;
		SCH_Tasks_G[current_index_task].Period = PERIOD/TICK;
		SCH_Tasks_G[current_index_task].RunMe = 0;
		SCH_Tasks_G[current_index_task].TaskID = current_index_task;

	// ++
		current_index_task++;
	}
}
void SCH_Update(void){
	for(int i = 0; i< current_index_task; i++){
		if(SCH_Tasks_G[i].Delay > 0){
			SCH_Tasks_G[i].Delay--;
		}
		else{
			SCH_Tasks_G[i].Delay = SCH_Tasks_G[i].Period;
			SCH_Tasks_G[i].RunMe += 1;
		}
	}
}
void SCH_Dispatch_Task(void){
	for(int i= 0; i< current_index_task; i++){
		if(SCH_Tasks_G[i].RunMe > 0){
			SCH_Tasks_G[i].RunMe --;
			(*SCH_Tasks_G[i].ptask)();
		}
	}
}
void SCH_Delete(uint8_t ID){
	if(ID < 0|| ID > SCH_MAX_TASKS){
		return;
	}
	else{
		for(int i = ID; i< current_index_task; i++){
			if(i== current_index_task - 1 ){
				SCH_Tasks_G[i].ptask = 0x0000;
				SCH_Tasks_G[i].Period = 0;
				SCH_Tasks_G[i].RunMe = 0;
				SCH_Tasks_G[i].Delay = 0;
			}else{
				SCH_Tasks_G[i].ptask = SCH_Tasks_G[i+ 1].ptask;
				SCH_Tasks_G[i].Period = SCH_Tasks_G[i+ 1].Period;
				SCH_Tasks_G[i].Delay = SCH_Tasks_G[i+ 1].Delay;
			}
		}
	}
	current_index_task--;
}
