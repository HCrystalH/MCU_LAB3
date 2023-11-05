/*
 * light_system.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Admin
 */

#ifndef INC_LIGHT_SYSTEM_H_
#define INC_LIGHT_SYSTEM_H_

#define INIT_RED	5000	// Initialize Red LEDs cycle
#define INIT_YELLOW	2000	// Initialize Yellow LEDs cycle
#define INIT_GREEN	3000	// Initialize Green LEDs cycle

void SetRedCycle(int duration);
void SetYellowCycle(int duration);
void SetGreenCycle(int duration);

int GetRedCycle();
int GetYellowCycle();
int GetGreenCycle();

void traffic_light();
void init_traffic_light();

void DisplayRedLight();
void DisplayYellowLight();
void DisplayGreenLight();

void Scan4LEDs();
void Scan2LEDs(uint16_t led1, uint16_t led2);


#endif /* INC_LIGHT_SYSTEM_H_ */
