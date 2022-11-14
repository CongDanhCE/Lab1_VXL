/*
 * check_mode.c
 *
 *  Created on: Oct 27, 2022
 *      Author: ASUS
 */
#include "check_mode.h"

void checkCount(){
	switch(count){
	case 0:
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(mode == Mode2){
			display7SEG1(0);
		}
		else if(mode == Mode3){
			display7SEG1(0);
		}
		else if(mode == Mode4){
			display7SEG1(0);
		}
		break;
	case 1:
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, RESET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(mode == Mode2){
			display7SEG1(2);
		}
		else if(mode == Mode3){
			display7SEG1(3);
		}
		else if(mode == Mode4){
			display7SEG1(4);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, RESET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(mode == Mode2){
			display7SEG(led_buffer_red[0]);
		}
		else if(mode == Mode3){
			display7SEG(led_buffer_green[0]);
		}
		else if(mode == Mode4){
			display7SEG(led_buffer_yellow[0]);
		}
		break;
	case 3:
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, RESET);
		if(mode == Mode2){
			display7SEG1(led_buffer_red[1]);
		}
		else if(mode == Mode3){
			display7SEG1(led_buffer_green[1]);
		}
		else if(mode == Mode4){
			display7SEG1(led_buffer_yellow[1]);
		}
		break;
	default:
		break;
	}
}
void ledMode2(){
	// SET green, yellow
	HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
	HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
	HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
	HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
	// set EN0 ,EN1, EN2, EN3
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void ledMode3(){
	// SET red, yellow
	HAL_GPIO_WritePin(Led_Red1_GPIO_Port, Led_Red1_Pin, 1);
	HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
	HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
	HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
	// set EN0 ,EN1, EN2, EN3
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void ledMode4(){
	// SET red, green
	HAL_GPIO_WritePin(Led_Red1_GPIO_Port, Led_Red1_Pin, 1);
	HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
	HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
	HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
	// set EN0 ,EN1, EN2, EN3
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void checkMode(){
	switch(mode){
	case INIT:
		// set all
		HAL_GPIO_WritePin(Led_Red1_GPIO_Port, Led_Red1_Pin, 1);
		HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
		HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
		HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
		HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
		HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		mode = Mode1;
		break;
	// Mode 1: Normal
	case Mode1:
		fsm_auto_run();
		if(isButton1Pressed() == 1){
			mode = Mode2;
			count = 0;
			setTimer5(250);
			// set up red led blinky
			HAL_GPIO_WritePin(Led_Red1_GPIO_Port, Led_Red1_Pin, 1);
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
		}
		break;
	// Mode 2: set red duration
	case Mode2:
		// set up led mode 2
		if(timer5_flag == 1){
			count++;
			if(count >= 4){
				count = 0;
			}
			checkCount();
			setTimer5(250);
		}
		// led mode 2: blinky red 2s
		ledMode2();
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(Led_Red1_GPIO_Port, Led_Red1_Pin);
			HAL_GPIO_TogglePin(Led_Red2_GPIO_Port, Led_Red2_Pin);
			setTimer3(2000);
		}
		// readingInputRed
		if(isButton2Pressed() == 1){
			led_buffer_red[1]++;
		}

		// Update red if > 99
		if(led_buffer_red[1] > 9){
			led_buffer_red[0] ++;
			led_buffer_red[1] = 0;
			if(led_buffer_red[0] > 9){
				led_buffer_red[0] = 0;
			}
		}
		//update red_time
		if(isButton3Pressed() == 1){
			red_time = led_buffer_red[0] * 10 + led_buffer_red[1];
		}
		// switch mode
		if(isButton1Pressed() == 1){
			mode = Mode3;
			setTimer3(2000);
			count = 0;
			setTimer5(250);
		}
		break;

	case Mode3:
		// set up led mode 3:P blinky green
		ledMode3();
		if(timer5_flag == 1){
			count++;
			if(count >= 4){
				count = 0;
			}
			checkCount();
			setTimer5(250);
		}
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(Led_Green1_GPIO_Port, Led_Green1_Pin);
			HAL_GPIO_TogglePin(Led_Green2_GPIO_Port, Led_Green2_Pin);
			setTimer3(2000);
		}
		// reading input green
		if(isButton2Pressed() == 1){
			led_buffer_green[1]++;
		}
		// update if > 99
		if(led_buffer_green[1] > 9){
			led_buffer_green[0] ++;
			led_buffer_green[1] = 0;
			if(led_buffer_green[0] > 9){
				led_buffer_green[0] = 0;
			}
		}
		//update green
		if(isButton3Pressed() == 1){
			green_time = led_buffer_green[0] * 10 + led_buffer_green[1];
		}
		// out mode 3
		if(isButton1Pressed() == 1){
			mode = Mode4;
			setTimer3(2000);
			count = 0;
			setTimer5(250);
		}
		break;

	case Mode4:
		// set led mode 4: blinky yellow
		ledMode4();
		if(timer5_flag == 1){
			count++;
			if(count >= 4){
				count = 0;
			}
			checkCount();
			setTimer5(250);
		}
		//blinky yellow led
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(Led_Yellow1_GPIO_Port, Led_Yellow1_Pin);
			HAL_GPIO_TogglePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin);
			setTimer3(2000);
		}
			// reading Input yellow
			if(isButton2Pressed() == 1){
				led_buffer_yellow[1]++;
			}
			// update if > 99:
			if(led_buffer_yellow[1] > 9){
				led_buffer_yellow[0] ++;
				led_buffer_yellow[1] = 0;
				if(led_buffer_yellow[0] > 9){
					led_buffer_yellow[0] = 0;
				}
			}
			//update yellow time
			if(isButton3Pressed() == 1){
				yellow_time = led_buffer_yellow[0] * 10 + led_buffer_yellow[1];
			}
		// out mode 4, in 1
		if(isButton1Pressed() == 1){
			mode = Mode1;
			status1 = INIT1;
			status2 = INIT2;
			setTimer3(2000);
			setTimer4(250);
		}
		break;

	default:
		break;
	}
}

