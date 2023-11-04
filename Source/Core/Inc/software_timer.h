/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer1(int duration, int interrupt_cycle);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();

void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef* htim);

#endif /* INC_SOFTWARE_TIMER_H_ */
