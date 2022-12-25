/*
 * global.h
 *
 *  Created on: Dec 12, 2022
 *      Author: ASUS
 */
#include "main.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

extern int OK_flag;
extern int RST_flag;
extern int current_flag;
extern int current_mode;

#define	INIT	0
#define GET_ADC		1
#define WAIT 	2
#define MAX_BUFFER_SIZE 30
#define ENROR	3

#define GET_OLD_ADC	10
#define GET_NEW_ADC	11

extern uint8_t buffer[ MAX_BUFFER_SIZE ];
extern uint8_t command_length;

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

#endif /* INC_GLOBAL_H_ */
