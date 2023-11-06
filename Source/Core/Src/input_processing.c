/*
 * input_processing.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */


#include "main.h"
#include "input_reading.h"
#include "7SEG.h"
#include "light_system.h"

/*
 * 	SAMPLE CODE
enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
enum ButtonState buttonState = BUTTON_RELEASED;

void fsm_for_input_processing(void){
	switch(buttonState){
	case BUTTON_RELEASED:
		if(is_button_pressed(0)){
			buttonState = BUTTON_PRESSED;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	case BUTTON_PRESSED:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		} else {
			if(is_button_pressed_1s(0)){
				buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
			}
		}
		break;
	case BUTTON_PRESSED_MORE_THAN_1_SECOND:
		if(!is_button_pressed(0)){
			buttonState = BUTTON_RELEASED;
		}
		//todo
		break;
	}
}
	SAMPLE CODE END HERE
*/


enum SystemState{
	MODE1,
	MODE2,
	MODE3,
	MODE4
};

enum SystemState mode = MODE1;
int start_flag = 0;

void fsm_for_input_processing(void){
	switch(mode){
	case MODE1:
	{
		// Normal mode
		if(start_flag == 1){
			InitTrafficLight();
			start_flag = 0;
		}

		TrafficLight();
		if(is_button_pressed(0) == 1){
			mode = MODE2;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	}
	case MODE2:{
		// Modify RED
		if(is_button_pressed(1) == 1){
			int temp = GetRedCycle()/1000;
			temp++;
			if(temp >99) temp = 0;
			SetRedCycle(temp*1000);
		}

		update_7seg_buffer(GetRedCycle()/1000, 2);
		Scan4LEDs();
		DisplayRedLight();
		if(is_button_pressed(2) == 1){
			if(GetRedCycle() != ( GetYellowCycle() + GetGreenCycle() ) ){
				SetGreenCycle(GetRedCycle() - GetYellowCycle());
			}
		}

		if(is_button_pressed(0) == 1){
			mode = MODE3;
		}
		break;
	}
	case MODE3:{
		// Modify Yellow(Amber)
		if(is_button_pressed(1) == 1){
			int temp = GetYellowCycle()/1000;
			temp++;
			if(temp > 99) temp =0;
			SetYellowCycle(temp*1000);
		}

		update_7seg_buffer(GetYellowCycle()/1000, 3);
		Scan4LEDs();
		DisplayYellowLight();

		if(is_button_pressed(2) == 1){
			if(GetRedCycle() != ( GetYellowCycle() + GetGreenCycle() ) ){
				SetGreenCycle(GetRedCycle() - GetYellowCycle());
			}
		}
		if(is_button_pressed(0) == 1){
			mode = MODE4;
		}
		break;
	}
	case MODE4:{
		// Modify Green
		if(is_button_pressed(1) == 1){
			int temp = GetGreenCycle()/1000;
			temp++;
			if( temp > 99 ) temp =0;
			SetGreenCycle(temp*1000);
		}

		update_7seg_buffer(GetGreenCycle()/1000, 4);
		Scan4LEDs();
		DisplayGreenLight();
		if(is_button_pressed(2) == 1){
			if(GetRedCycle() != ( GetGreenCycle() + GetYellowCycle() )){
				SetRedCycle( GetGreenCycle() + GetYellowCycle());
			}
		}

		if(is_button_pressed(0) == 1){
			mode = MODE1;
			start_flag = 1;
		}
		break;
	}
	default:{
		break;
	}
	}
}
