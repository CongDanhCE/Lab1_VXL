/*
 * global.h
 *
 *  Created on: Oct 25, 2022
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
// red 1, green 1, yellow 1
#define INIT1		1
#define RED1		2
#define GREEN1		3
#define YELLOW1		4
// red 2, green 2, yellow 2
#define INIT2		5
#define RED2		6
#define GREEN2		7
#define YELLOW2		8


#define INIT 					10
#define Mode1					11
#define Mode2					12
#define Mode3					13
#define Mode4					14


extern int count;
extern int mode;
extern int EN;
extern int status1;
extern int status2;
extern int red_time;
extern int green_time;
extern int yellow_time;
extern int led_buffer_red[2];
extern int led_buffer_green[2];
extern int led_buffer_yellow[2];

#endif /* INC_GLOBAL_H_ */
