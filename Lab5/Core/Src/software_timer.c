/*
 * software_timer.c
 *
 *  Created on: Dec 12, 2022
 *      Author: ASUS
 */

#include "software_timer.h"

int TICK = 10;

int timer1_flag = 0;
int timer1_counter = 0;

void setTimer1(int duration){
	timer1_counter = duration/TICK;
	timer1_flag = 0;
}
void timerRun(){
	// timer 1
	if(timer1_counter> 0){
		timer1_counter-- ;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}
