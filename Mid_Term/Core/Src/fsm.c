/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Hoang Tri
 */

#include "fsm.h"
#include "software_timer.h"
#define TIME_BLINKING               250
#define TIME_AUTO_INCREASES         100          // adjust times to flexible with frequency.

enum ButtonMode {MODE_1,MODE_2,AUTO_MODE_1,AUTO_MODE_2} ;
enum ButtonMode button_mode = MODE_1 ;           // button mode of first state.

int Time_Edit = 0;
int Timer_Edit2=9;

void fsm_simple_buttons_run()
{
	switch(button_mode)
	{
	  case MODE_1:  // INIT_MODE;
		  if(timer1_flag==1)
		  {
			  button_mode=AUTO_MODE_1;
			  setTimer1(400);
			  break;
		  }
		  if(isButton1Pressed())   // RESET
		  {
			  Time_Edit = 0;
			  display7SEG(0);
			  button_mode=MODE_2;
			  break;
		  }
		  display7SEG(0);
	  break;
	 case MODE_2:
		  if (isButton2Pressed())
		  {
			  Time_Edit++;
			  if(Time_Edit>9)
			  {
				  Time_Edit=0;
			  }
			  display7SEG(Time_Edit);
		  }
		 if(isButton3Pressed())
		  {
			  Time_Edit--;
			  if(Time_Edit < 0)
			  {
				  Time_Edit=9;
			  }
			  display7SEG(Time_Edit);
		  }
		 if(isButton1Pressed()==1 && flag_change_state_button1==1)
		  {
			  Time_Edit = 0;
			  display7SEG(0);
			  button_mode=MODE_1;
			  break;
		  }
		  if(isButton1Pressed()==1 && flag_change_state_button1==0)
		  {
			  Time_Edit = 0;
			  display7SEG(0);
		  }
	  break;
	 case AUTO_MODE_1:
	        	if(timer2_flag==1)
	        	{
	        		display7SEG(Timer_Edit2);
	        		Timer_Edit2--;
	        		setTimer2(100);
	        		if(Timer_Edit2<0)
	        		{
	        			button_mode=MODE_1;
	        			break;
	        		}
	        	}
	        	if(isButton2Pressed())
	        	{
	        		button_mode=MODE_2;
	        		Time_Edit=Timer_Edit2;
	        		Timer_Edit2=9;
	        		break;
	        	}
	        	if(isButton3Pressed())
	        	{
	        		button_mode=MODE_2;
	        		Time_Edit=Timer_Edit2;
	        		Timer_Edit2=9;
	        		break;
	        	}
	  default:
	  break;
	}
}
void fsm_Blinking_LED_for_Debugging()
{
	switch(button_mode)
	{
	case MODE_1:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
	break;
	case MODE_2:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
	break;
	case AUTO_MODE_1:
       if(timer3_flag==1)
       {
    	   HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
    	   setTimer3(100);
       }

	break;
	default:
	break;
	}
}

void inscreases_time()
{
	Time_Edit++;
	if(Time_Edit >= 9)              // start at 0;
	{
		Time_Edit = 0;
	}
}
void descreases_time()
{
		Time_Edit--;
		if(Time_Edit <= 0)              // start at 0;
		{
			Time_Edit = 0;
		}
}


