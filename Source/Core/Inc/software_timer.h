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
extern int timer4_flag;

void setTimer1(int duration, int interrupt_cycle);
void setTimer2(int duration,int interrupt_cycle);
void setTimer3(int duration,int interrupt_cycle);
void setTimer4(int duration,int interrupt_cycle);

int getTimer1();
int getTimer3();
void timerRun();

int GetInterruptCycle();


#endif /* INC_SOFTWARE_TIMER_H_ */
