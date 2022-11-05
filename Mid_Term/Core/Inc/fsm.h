/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_
#include "main.h"
#include "software_timer.h"
#include "display7SEG.h"
#include "button.h"
extern int Time_Edit;
void inscreases_time();
void descreases_time();
void fsm_simple_buttons_run ();
void fsm_Blinking_LED_for_Debugging();
//void fsm_AUTO_buttons_run();



#endif /* INC_FSM_H_ */
