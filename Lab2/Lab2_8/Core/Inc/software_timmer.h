/*
 * software_timmer.h
 *
 *  Created on: Oct 17, 2022
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer4_flag;
extern int led_buffer [4];
void setTimer1(int duration);
void setTimer4(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
