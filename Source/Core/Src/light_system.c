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
enum TrafficLightState VERTICAL = RED;
enum TrafficLightState HORIZONTAL = GREEN;
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
	// Turn on Red LEDs
	HAL_GPIO_WritePin(GPIOA, RED_HORIZONTAL_Pin|RED_VERTICAL_Pin, GPIO_PIN_RESET);
	// Turn off other LEDs
	HAL_GPIO_WritePin(GPIOA, YELLOW_HORIZONTAL_Pin|YELLOW_VERTICAL_Pin|
					GREEN_HORIZONTAL_Pin|GREEN_VERTICAL_Pin, GPIO_PIN_SET);
	// Blink
	if(timer2_flag == 1){
		setTimer2(1000, GetInterruptCycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HORI1_Pin|EN_HORI2_Pin|EN_VER1_Pin|EN_VER2_Pin);
	}
}

void DisplayYellowLight(){
	// Turn on Yellow LEDs
	HAL_GPIO_WritePin(GPIOA, YELLOW_HORIZONTAL_Pin|YELLOW_VERTICAL_Pin, GPIO_PIN_RESET);
	// Turn off other LEDs
	HAL_GPIO_WritePin(GPIOA, RED_HORIZONTAL_Pin|RED_VERTICAL_Pin|
					GREEN_HORIZONTAL_Pin|GREEN_VERTICAL_Pin, GPIO_PIN_SET);
	// Blink
	if(timer2_flag == 1){
		setTimer2(1000, GetInterruptCycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HORI1_Pin|EN_HORI2_Pin|EN_VER1_Pin|EN_VER2_Pin);
	}
}

void DisplayGreenLight(){
	// Turn on Green LEDs
	HAL_GPIO_WritePin(GPIOA, GREEN_HORIZONTAL_Pin|GREEN_VERTICAL_Pin, GPIO_PIN_RESET);
	// Turn off other LEDs
	HAL_GPIO_WritePin(GPIOA, RED_HORIZONTAL_Pin|RED_VERTICAL_Pin|
					YELLOW_HORIZONTAL_Pin|YELLOW_VERTICAL_Pin, GPIO_PIN_SET);
	// Blink
	if(timer2_flag == 1){
		setTimer2(1000, GetInterruptCycle());
		HAL_GPIO_TogglePin(GPIOA, EN_HORI1_Pin|EN_HORI2_Pin|EN_VER1_Pin|EN_VER2_Pin);
	}
}

void Scan2LEDs(uint16_t led1, uint16_t led2){
	if(timer2_flag == 1){
		setTimer2(100, GetInterruptCycle());
		HAL_GPIO_TogglePin(GPIOA, led1|led2);
	}
}

void Scan4LEDs(){
	if(timer4_flag == 1){
		setTimer4(100, GetInterruptCycle());
		update_display(&display_flag);
	}
}

// Set up initial state
void InitTrafficLight(){
	// initialize for traffic system LEDs
	HAL_GPIO_WritePin(GPIOA, RED_VERTICAL_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, YELLOW_VERTICAL_Pin | GREEN_VERTICAL_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, GREEN_HORIZONTAL_Pin, RESET);
	HAL_GPIO_WritePin(GPIOA, YELLOW_HORIZONTAL_Pin | GREEN_HORIZONTAL_Pin, SET);

	// initialize for scan traffic led
	HAL_GPIO_WritePin(GPIOA, EN_VER1_Pin|EN_HORI1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, EN_VER2_Pin|EN_HORI2_Pin, GPIO_PIN_SET);

	//
	VERTICAL = RED;
	HORIZONTAL = GREEN;

	setTimer1(red_cycle,GetInterruptCycle());
	setTimer3(green_cycle,GetInterruptCycle());

	// 100: time scan ( for both traffic light and 7segment LED)
	setTimer2(1000,GetInterruptCycle());
	setTimer4(1000,GetInterruptCycle());

	// Turn on the 1st 7Segment LED, for scan LED
	Init7SEG();
	display_flag = 0;


}


void TrafficLight(){
	int vertical = getTimer1()*GetInterruptCycle()/1000;
	int horizontal = getTimer3()*GetInterruptCycle()/1000;

	update_7seg_buffer(vertical, horizontal);
	Scan4LEDs();

	switch(VERTICAL){
		case RED:{
			HAL_GPIO_WritePin(GPIOA, RED_VERTICAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_VER1_Pin, EN_VER2_Pin);
			HAL_GPIO_WritePin(GPIOA,YELLOW_VERTICAL_Pin | GREEN_VERTICAL_Pin , GPIO_PIN_SET);
			if(timer1_flag == 1){
				VERTICAL = GREEN;
				setTimer1(green_cycle, GetInterruptCycle());
			}
			break;
		}
		case GREEN:{
			HAL_GPIO_WritePin(GPIOA, GREEN_VERTICAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_VER1_Pin, EN_VER2_Pin);
			HAL_GPIO_WritePin(GPIOA,RED_VERTICAL_Pin | YELLOW_VERTICAL_Pin , GPIO_PIN_SET);
			if(timer1_flag == 1){
				VERTICAL = YELLOW;
				setTimer1(yellow_cycle, GetInterruptCycle());
			}
			break;
		}
		case YELLOW:{
			HAL_GPIO_WritePin(GPIOA, YELLOW_VERTICAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_VER1_Pin, EN_VER2_Pin);
			HAL_GPIO_WritePin(GPIOA,RED_VERTICAL_Pin | GREEN_VERTICAL_Pin , GPIO_PIN_SET);
			if(timer1_flag == 1){
				VERTICAL = RED;
				setTimer1(red_cycle, GetInterruptCycle());
			}
			break;
		}
		default:{
			break;
		}
	}

	switch(HORIZONTAL){
		case RED:{
			HAL_GPIO_WritePin(GPIOA, RED_HORIZONTAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_HORI1_Pin, EN_HORI2_Pin);
			HAL_GPIO_WritePin(GPIOA,YELLOW_HORIZONTAL_Pin|GREEN_HORIZONTAL_Pin , GPIO_PIN_SET);
			if(timer3_flag == 1){
				HORIZONTAL = GREEN;
				setTimer3(green_cycle,GetInterruptCycle());
			}
			break;
		}
		case GREEN:{
			HAL_GPIO_WritePin(GPIOA, GREEN_HORIZONTAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_HORI1_Pin, EN_HORI2_Pin);
			HAL_GPIO_WritePin(GPIOA,YELLOW_HORIZONTAL_Pin|RED_HORIZONTAL_Pin , GPIO_PIN_SET);
			if(timer3_flag == 1){
				HORIZONTAL = YELLOW;
				setTimer3(yellow_cycle,GetInterruptCycle());
			}
			break;
		}
		case YELLOW:{
			HAL_GPIO_WritePin(GPIOA, YELLOW_HORIZONTAL_Pin, GPIO_PIN_RESET);
			Scan2LEDs(EN_HORI1_Pin, EN_HORI2_Pin);
			HAL_GPIO_WritePin(GPIOA,RED_HORIZONTAL_Pin|GREEN_HORIZONTAL_Pin , GPIO_PIN_SET);
			if(timer3_flag == 1){
				HORIZONTAL = RED;
				setTimer3(red_cycle,GetInterruptCycle());
			}
			break;
		}
		default:{
			break;
		}
	}

}
