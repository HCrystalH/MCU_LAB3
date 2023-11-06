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

void fsm_for_input_processing(void){
	switch(mode){
	case MODE1:
	{
		TrafficLight();
		if(is_button_pressed(0) == 1){
			mode = MODE2;
			//INCREASE VALUE OF PORT A BY ONE UNIT
		}
		break;
	}
	case MODE2:{
		update_7seg_buffer(GetRedCycle()/1000, 2);
		Scan4LEDs();
		DisplayRedLight();
		if(is_button_pressed(0) == 1){
			mode = MODE3;
		}
		break;
	}
	case MODE3:{
		update_7seg_buffer(GetYellowCycle(), 3);
		Scan4LEDs();
		DisplayYellowLight();
		if(is_button_pressed(0) == 1){
			mode = MODE4;
		}
		break;
	}
	case MODE4:{
		update_7seg_buffer(GetGreenCycle(), 4);
		Scan4LEDs();
		DisplayGreenLight();
		if(is_button_pressed(0) == 1){
			mode = MODE1;
		}
		break;
	}
	default:
		break;
	}
}
