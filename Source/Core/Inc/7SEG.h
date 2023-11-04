/*
 * 7SEG.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_


int led_buffer[4];
void update_7seg_buffer(int vertical, int horizontal);
void init_7seg();
void display7SEG(int number);
void update_display(int* display_flag);

#endif /* INC_7SEG_H_ */
