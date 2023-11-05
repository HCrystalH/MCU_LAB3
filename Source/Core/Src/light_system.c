/*
 * light_system.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Admin
 */

#include "light_system.h"
#include "main.h"
#include "software_timer.h"
#include "7SEG.h"

enum TrafficLightState{
	RED,
	YELLOW,
	GREEN
};

int red_cycle = 0;
int yellow_cycle = 0;
int green_cycle = 0;
enum TrafficLightState vertical = RED;
enum TrafficLightState horizontal = GREEN;
int display_flag;

void SetRedCycle(int duration){
	red_cycle = duration;
}
void SetYellowCycle(int duration){
	yellow_cycle = duration;
}
void SetGreenCycle(int duration){
	green_cycle = duration;
}

int GetRedCycle(){
	return red_cycle;
}

int GetYellowCycle(){
	return yellow_cycle;
}

int GetGreenCycle(){
	return green_cycle;
}


void DisplayRedLight(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_RED_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin|LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}

void DisplayYellowLight(){
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_RED_HOR_Pin|LED_RED_VER_Pin|LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}

void DisplayGreenLight(){
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_HOR_Pin|LED_GREEN_VER_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_HOR_Pin|LED_YELLOW_VER_Pin|LED_RED_HOR_Pin|LED_RED_VER_Pin, GPIO_PIN_SET);
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HOR_1_Pin|EN_HOR_2_Pin|EN_VER_1_Pin|EN_VER_2_Pin);
	}
}

void Scan2LEDs(uint16_t led1, uint16_t led2){
	if(timer_flag2 == 1){
		set_Timer2(100, get_interrupt_cycle());
		HAL_GPIO_TogglePin(GPIOA, led1|led2);
	}
}

void Scan4LEDs(){
	if(timer_flag4 == 1){
		set_Timer4(100, get_interrupt_cycle());
		update_display(&display_flag);
	}
}
