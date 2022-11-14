/*
 * fsm_auto.c
 *
 *  Created on: Oct 25, 2022
 *      Author: ASUS
 */

#include "fsm_auto.h"
//set up: back up green, yellow buffer
int count_red1[2] = { 0, 0};
int count_green1[2] = { 0 , 0 };
int count_yellow1[2] = { 0 , 0 };

int count_red2[2] = { 0, 0};
int count_green2[2] = { 0 , 0 };
int count_yellow2[2] = { 0 , 0 };


int ledbuffer1[2]={0, 0};
int ledbuffer2[2]= {0, 0};

void decreaseAfter1s(){

	// 1
	switch(status1){
	case RED1:
		count_red1[1]--;
		if(count_red1[1]< 0){
			count_red1[1] = 9;
			count_red1[0]--;
		}
		break;
	case GREEN1:
		count_green1[1]--;
		if(count_green1[1]< 0){
			count_green1[1] = 9;
			count_green1[0]--;
		}
		break;
	case YELLOW1:
		count_yellow1[1]--;
		if(count_yellow1[1]< 0){
			count_yellow1[1] = 9;
			count_yellow1[0]--;
		}
		break;
	default:
		break;
	}

	switch(status2){
	case RED2:
		count_red2[1]--;
		if(count_red2[1]< 0){
			count_red2[1] = 9;
			count_red2[0]--;
		}
		break;
	case GREEN2:
		count_green2[1]--;
		if(count_green2[1]< 0){
			count_green2[1] = 9;
			count_green2[0]--;
		}
		break;
	case YELLOW2:
		count_yellow2[1]--;
		if(count_yellow2[1]< 0){
			count_yellow2[1] = 9;
			count_yellow2[0]--;
		}
		break;
	default:
		break;
		}
}
void checkEN(){
	switch(EN){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(status1 == RED1){
			display7SEG(count_red1[0]);
		}
		else if(status1 == GREEN1){
			display7SEG(count_green1[0]);
		}
		else if(status1 == YELLOW1){
			display7SEG(count_yellow1[0]);
		}
		display7SEG1(0);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, RESET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(status1 == RED1){
			display7SEG(count_red1[1]);
		}
		else if(status1 == GREEN1){
			display7SEG(count_green1[1]);
		}
		else if(status1 == YELLOW1){
			display7SEG(count_yellow1[1]);
		}
		display7SEG1(1);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, RESET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, SET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(status2 == RED2){
			display7SEG(count_red2[0]);
		}
		else if(status2 == GREEN2){
			display7SEG(count_green2[0]);
		}
		else if(status2 == YELLOW2){
			display7SEG(count_yellow2[0]);
		}
		display7SEG1(0);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, SET);
		HAL_GPIO_WritePin(EN5_GPIO_Port, EN5_Pin, RESET);
		HAL_GPIO_WritePin(EN6_GPIO_Port, EN6_Pin, SET);
		HAL_GPIO_WritePin(EN7_GPIO_Port, EN7_Pin, SET);
		if(status2 == RED2){
			display7SEG(count_red2[1]);
		}
		else if(status2 == GREEN2){
			display7SEG(count_green2[1]);
		}
		else if(status2 == YELLOW2){
			display7SEG(count_yellow2[1]);
		}
		display7SEG1(1);
		break;
	default:
		break;
	}
}

void fsm_auto_run(){
	// red green yellow 1
	switch(status1){
		case INIT1:
			HAL_GPIO_WritePin(Led_Red1_GPIO_Port,Led_Red1_Pin, 1);
			HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
			status1= RED1;
			setTimer1(red_time*1000);
			count_red1[0] = led_buffer_red[0];
			count_red1[1] = led_buffer_red[1];
			count_green1[0] = led_buffer_green[0];
			count_green1[1] = led_buffer_green[1];
			count_yellow1[0] = led_buffer_yellow[0];
			count_yellow1[1] = led_buffer_yellow[1];
			break;
		case RED1:
			// led red1 0
			HAL_GPIO_WritePin(Led_Red1_GPIO_Port,Led_Red1_Pin, 0);
			HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
			//if(timer1_flag == 1){
				//status1 = GREEN1;
				//setTimer1(green_time*1000);
			//}
			if (count_red1[0] == 0 && count_red1[1] == 0) {
				status1 = GREEN1;
				count_red1[0] = led_buffer_red[0];
				count_red1[1] = led_buffer_red[1];
			}
			break;
		case GREEN1:
			// led green1 0
			HAL_GPIO_WritePin(Led_Red1_GPIO_Port,Led_Red1_Pin, 1);
			HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 1);
			//if(timer1_flag == 1){
				//status1 = YELLOW1;
				//setTimer1(yellow_time* 1000);
			//}
			if (count_green1[0] == 0 && count_green1[1] == 0) {
				status1 = YELLOW1;
				count_green1[0] = led_buffer_green[0];
				count_green1[1] = led_buffer_green[1];
			}
			break;
		case YELLOW1:
			HAL_GPIO_WritePin(Led_Red1_GPIO_Port,Led_Red1_Pin, 1);
			HAL_GPIO_WritePin(Led_Green1_GPIO_Port,Led_Green1_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow1_GPIO_Port,Led_Yellow1_Pin, 0);
			//if(timer1_flag == 1){
				//status1 = RED1;
				//setTimer1(red_time* 1000);
			//}
			if (count_yellow1[0] == 0 && count_yellow1[1] == 0) {
				status1 = RED1;
				count_yellow1[0] = led_buffer_yellow[0];
				count_yellow1[1] = led_buffer_yellow[1];
			}
			break;
		default:
			break;
	}
	// red green yellow 2
	switch(status2){
		case INIT2:
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port,Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
			status2 = GREEN2;
			setTimer2(green_time*1000);
			count_red2[0] = led_buffer_red[0];
			count_red2[1] = led_buffer_red[1];
			count_green2[0] = led_buffer_green[0];
			count_green2[1] = led_buffer_green[1];
			count_yellow2[0] = led_buffer_yellow[0];
			count_yellow2[1] = led_buffer_yellow[1];
			break;
		case RED2:
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port,Led_Red2_Pin, 0);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
			//if(timer2_flag == 1){
				//setTimer2(green_time * 1000);
				//status2 = GREEN2;
			//}
			if (count_red2[0] == 0 && count_red2[1] == 0) {
				status2 = GREEN2;
				count_red2[0] = led_buffer_red[0];
				count_red2[1] = led_buffer_red[1];
			}
			break;
		case GREEN2:
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port,Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 1);
			//if(timer2_flag == 1){
				//setTimer2(yellow_time * 1000);
				//status2 = YELLOW2;
			//}
			if (count_green2[0] == 0 && count_green2[1] == 0) {
				status2 = YELLOW2;
				count_green2[0] = led_buffer_green[0];
				count_green2[1] = led_buffer_green[1];
			}
			break;
		case YELLOW2:
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port,Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port,Led_Green2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port,Led_Yellow2_Pin, 0);
			//if(timer2_flag == 1){
				//setTimer2(red_time * 1000);
				//status2 = RED2;
			//}
			if (count_yellow2[0] == 0 && count_yellow2[1] == 0) {
				status2 = RED2;
				count_yellow2[0] = led_buffer_yellow[0];
				count_yellow2[1] = led_buffer_yellow[1];
			}
			break;
		default:
			break;
	}
	checkEN();
	if(timer4_flag == 1){
		EN++;
		if(EN > 3){
			EN = 0;
			decreaseAfter1s();
		}
		setTimer4(250);
	}
}



