/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Hoang Tri
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"
/* void subKeyProccess(int index);
void button_reading(void);
int is_button1_Press();
int is_button2_Press();
int is_button3_Press();
unsigned char is_button_pressed_1s ();  */

#define NORMAL_STATE GPIO_PIN_SET  // 1: High
#define PRESSED_STATE GPIO_PIN_RESET //0: LOW, khi nhan o pull up

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int TimerForKeyPress_1; // setTimer();
extern int TimerForKeyPress_2; // setTimer();
extern int TimerForKeyPress_3; // setTimer();

extern int flag_change_state_button1;
extern int flag_change_state_button2;
extern int flag_change_state_button3;

void getKeyInput();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

#endif /* INC_BUTTON_H_ */
