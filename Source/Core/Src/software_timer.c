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
int timer4_counter =0;

int timer1_flag =0;
int timer2_flag =0;
int timer3_flag =0;
int timer4_flag =0;

void setTimer1(int duration,int interrupt_cycle){
	timer1_counter = duration/interrupt_cycle;
	timer1_flag =0;
}

void setTimer2(int duration,int interrupt_cycle){
	timer2_counter = duration/interrupt_cycle;
	timer2_flag = 0;
}

void setTimer3(int duration,int interrupt_cycle){
	timer3_counter = duration/interrupt_cycle;
	timer3_flag = 0;
}

void setTimer4(int duration,int interrupt_cycle){
	timer4_counter = duration/interrupt_cycle;
	timer4_flag = 0;
}

int getTimer1(){
	return timer1_counter;
}

int getTimer3(){
	return timer1_counter;
}

void timerRun(){
	timer1_counter--;	// for led cycle (vertical)
	timer2_counter--;	// for scan LEDs
	timer3_counter--;	// for led cycle (vertical)
	timer4_counter--;	// for scan 7segment LEDs

	if(timer1_counter <=0){
		timer1_flag =1;
	}
	if(timer2_counter <=0){
		timer2_flag =1;
	}
	if(timer3_counter <=0){
		timer3_flag =1;
	}
	if(timer4_counter <=0){
		timer4_flag =1;
	}
}


