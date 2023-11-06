/*
 * input_reading.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */
#include "main.h"

/*
 *  Define constants buffers and button_reading function
 */

//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       3
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 100 time
#define DURATION_FOR_AUTO_INCREASING	   100
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED};
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer0[N0_OF_BUTTONS]={BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS]={BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS]={BUTTON_IS_RELEASED};
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS]={BUTTON_IS_RELEASED};
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
int hold_counter = 0;
uint16_t buttonArray[N0_OF_BUTTONS] = {BUTTON1_Pin,BUTTON2_Pin,BUTTON3_Pin};

void button_reading(void){
	/* Sample code*/
//	for(char i = 0; i < N0_OF_BUTTONS; i ++){
//		debounceButtonBuffer2[i] =debounceButtonBuffer1[i];
//		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
//		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
//			buttonBuffer[i] = debounceButtonBuffer1[i];
//			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
//			//if a button is pressed, we start counting
//				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
//					counterForButtonPress1s[i]++;
//				} else {
//				//the flag is turned on when 1 second has passed
//				//since the button is pressed.
//					flagForButtonPress1s[i] = 1;
//					//todo
//				}
//			} else {
//				counterForButtonPress1s[i] = 0;
//				flagForButtonPress1s[i] = 0;
//			}
//	}
	/* Sample code end here */

	for (int i=0; i< N0_OF_BUTTONS; i++){
		// 3 button buffer for debouncing
		debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = HAL_GPIO_ReadPin(GPIOB, buttonArray[i]);

		//If a button is pressed, start counting
		if( (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) && (debounceButtonBuffer0[i] == debounceButtonBuffer1[i]) ){
			//Processing for pressing and releasing
			if(debounceButtonBuffer3[i] != debounceButtonBuffer2[i]){
				debounceButtonBuffer3[i] = debounceButtonBuffer2[i];

				if(debounceButtonBuffer2[i] == BUTTON_IS_PRESSED){
					buttonBuffer[i] = BUTTON_IS_PRESSED;
					counterForButtonPress1s[i] = 0;
				}
			}
			//Processing for pressing and holding
			else{
				counterForButtonPress1s[i]++;
				if(counterForButtonPress1s[i] >= DURATION_FOR_AUTO_INCREASING){
					flagForButtonPress1s[i] = 1;
					counterForButtonPress1s[i] =0;
					hold_counter++;
				}
			}
		}
	}
}

//Checking a button is pressed or not
int is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;

	if(buttonBuffer[index] == BUTTON_IS_PRESSED){
		buttonBuffer[index] = BUTTON_IS_RELEASED;
		return 1;
	}else if(buttonBuffer[index] != BUTTON_IS_PRESSED){
		return 0;
	}
}

//Checking a button is pressed more than a second or not
unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}
