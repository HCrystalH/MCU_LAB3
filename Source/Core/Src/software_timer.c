/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Admin
 */
#include "main.h"
#include "software_timer.h"

int timer1_counter =0;
int timer2_counter =0;
int timer3_counter =0;

int timer1_flag =0;
int timer2_flag =0;
int timer3_flag =0;

void setTimer1(int duration,int interrupt_cycle){
	timer1_counter = duration/interrupt_cycle;
	timer1_flag =0;
}

void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_counter = duration;
	timer3_flag = 0;
}

void timerRun(){
	timer1_counter--;

	if(timer1_counter <=0){
		timer1_flag =1;
	}
}

// Timer interrupt callback function
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM2){
		button_reading();
	}
}

