/*
 * 7SEG.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#include "7SEG.h"
#include "main.h"

int led_buffer[4] = {0,0,0,0};
void display7SEG(int number){
	int a[10][7] = {
		{0, 0, 0, 0, 0, 0, 1}, 	//0
		{1, 0, 0, 1, 1, 1, 1},  //1
		{0, 0, 1, 0, 0, 1, 0},  //2
		{0, 0, 0, 0, 1, 1, 0},  //3
		{1, 0, 0, 1, 1, 0, 0},	//4
		{0, 1, 0, 0, 1, 0, 0},  //5
		{0, 1, 0, 0, 0, 0, 0}, 	//6
		{0, 0, 0, 1, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0}, 	//8
		{0, 0, 0, 0, 1, 0, 0}   //9
	};
	HAL_GPIO_WritePin(GPIOB, seg_a_Pin, a[number][0]);
	HAL_GPIO_WritePin(GPIOB, seg_b_Pin, a[number][1]);
	HAL_GPIO_WritePin(GPIOB, seg_c_Pin, a[number][2]);
	HAL_GPIO_WritePin(GPIOB, seg_d_Pin, a[number][3]);
	HAL_GPIO_WritePin(GPIOB, seg_e_Pin, a[number][4]);
	HAL_GPIO_WritePin(GPIOB, seg_f_Pin, a[number][5]);
	HAL_GPIO_WritePin(GPIOB, seg_g_Pin, a[number][6]);

}

void update_display(int* display_flag){
	switch (*display_flag){
		case 0:{
			(*display_flag)++;
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI2_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[1]);
			break;
		}
		case 1:{
			(*display_flag)++;
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI2_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[2]);
			break;
		}
		case 2:{
			(*display_flag)++;
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI2_Pin, GPIO_PIN_RESET);
			display7SEG(led_buffer[3]);
			break;
		}
		case 3:{
			(*display_flag) = 0;
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI2_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[0]);
			break;
		}
		default:{
			break;
		}
	}
}

void Init7SEG(){
	HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, EN_7SEG_VER2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, EN_7SEG_HORI2_Pin, GPIO_PIN_SET);
	display7SEG(led_buffer[0]);
}

void update_7seg_buffer(int vertical, int horizontal){
	led_buffer[0] = (int)vertical/10;
	led_buffer[1] = vertical%10;
	led_buffer[2] = (int)horizontal/10;
	led_buffer[3] = horizontal%10;
	if(led_buffer[3] <= 0){
		led_buffer[3] = 0;
		led_buffer[2]--;
	}
	if(led_buffer[2] <= 0){
		led_buffer[2] = 0;
	}
	if(led_buffer[1] <= 0){
		led_buffer[0]--;
		led_buffer[1] = 0;
	}
	if(led_buffer[0] <= 0){
		led_buffer[0] = 0;
	}
}

