/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Hoang Tri
 */
#include "button.h"

/*#define NO_OF_BUTTONS		3                             // 2 buttons
#define DURATION_FOR_AUTO_INCREASING	254

#define BUTTON_IS_PRESSED           GPIO_PIN_RESET   //0
#define BUTTON_IS_RELEASED          GPIO_PIN_SET     //1
#define NORMAL_STATE                GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS]={NORMAL_STATE};
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS]={NORMAL_STATE};
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS]={NORMAL_STATE};
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS]={0};
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS]={0};
//int buffer_flag[NO_OF_BUTTONS]={0};

//int button1_State = 0;
//int button3_State = 0;
//int button2_State = 0;


//int button1_flag=0;
// int button2_flag=0;
void subKeyProccess(int index)
{
	flagForButtonPress1s[index]=1;
}

void button_reading(void)
{
	for(int i = 0; i < NO_OF_BUTTONS; i++){
			debounceButtonBuffer0[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = debounceButtonBuffer2[i];
	switch(i)
		{
			case 0:
				debounceButtonBuffer2[i]=HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
			break;
			case 1:
				debounceButtonBuffer2[i]=HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			break;
			case 2:
				debounceButtonBuffer2[i]=HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
			default:
				debounceButtonBuffer2[i]=BUTTON_IS_RELEASED;
            break;
		}
			if((debounceButtonBuffer0[i] == debounceButtonBuffer1[i]) &&(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]))
			{
				if(buttonBuffer[i]!=debounceButtonBuffer2[i])
				{
					buttonBuffer[i]=debounceButtonBuffer2[i];
					if(buttonBuffer[i]==BUTTON_IS_PRESSED)
					{
					       counterForButtonPress1s[i]=DURATION_FOR_AUTO_INCREASING;
					       subKeyProccess(i);

					}
				}
				else
				{
					 counterForButtonPress1s[i]--;
					 if(counterForButtonPress1s[i]==0)
					 {
						 if(buttonBuffer[i]==BUTTON_IS_PRESSED)
						 {
							  counterForButtonPress1s[i]=DURATION_FOR_AUTO_INCREASING;
	                          subKeyProccess(i);
						 }
					 }
				}
			}
	}
}
unsigned char is_button1_Press()
{
	//if( index >= NO_OF_BUTTONS ) return 0;
	return (buttonBuffer[0] == BUTTON_IS_PRESSED );
}
unsigned char is_button2_Press()
{
	//if( index >= NO_OF_BUTTONS ) return 0;
	return (buttonBuffer[1] == BUTTON_IS_PRESSED );
}
unsigned char is_button3_Press()
{
	//if( index >= NO_OF_BUTTONS ) return 0;
	return (buttonBuffer[2] == BUTTON_IS_PRESSED );
}
unsigned char is_button_pressed_1s ( unsigned char index )
{
	//if( index>=NO_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);

} */


/*#define NO_OF_BUTTONS		1
#define DURATION_FOR_AUTO_INCREASING	254

#define BUTTON_IS_PRESSED           GPIO_PIN_RESET   //0
#define BUTTON_IS_RELEASED          GPIO_PIN_SET     //1

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

int button1_State = 0;
int button3_State = 0;
int button2_State = 0;

void button_reading(void)
{
	for(int i = 0; i < NO_OF_BUTTONS; i++){
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			{
				buttonBuffer[i] = debounceButtonBuffer1[i];
			}
			if(buttonBuffer[i] ==  BUTTON_IS_PRESSED )
			{
				if(counterForButtonPress1s[i]< DURATION_FOR_AUTO_INCREASING)
				{
					counterForButtonPress1s[i]++;
				}
				else
				{
					flagForButtonPress1s[i] = 1;
				}
			}
			else
			{
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
}

GPIO_PinState get_button2_value()
{
	return buttonBuffer[0];
}

unsigned char is_button_pressed_1s()
{
	return flagForButtonPress1s[0];
}

int is_button1_Press(){
	if(HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin)==BUTTON_IS_PRESSED)
	{
		button1_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button1_State = 0;
		return 1;
	}
	return 0;
}
int is_button2_Press()
{
	if(HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin)==BUTTON_IS_PRESSED)
	{
		button2_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button2_State = 0;
		return 1;
	}
	return 0;
}
int is_button3_Press()
{
	if(HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin)==BUTTON_IS_PRESSED)
	{
		button3_State = 1;
		return 0;
	}
	if(button1_State == 1)
	{
		button3_State = 0;
		return 1;
	}
	return 0;
}
*/




int button1_flag= 0;
int button2_flag=0;
int button3_flag=0;
int KeyReg0= NORMAL_STATE;  // 1
int KeyReg1= NORMAL_STATE;  // 1
int KeyReg2= NORMAL_STATE;  // 1
int KeyReg3= NORMAL_STATE;  // 1
int TimerForKeyPress_1=0; // setTimer();
int TimerForKeyPress_2=0; // setTimer();
int TimerForKeyPress_3=0; // setTimer();

int KeyReg4= NORMAL_STATE;  // 1
int KeyReg5= NORMAL_STATE;  // 1
int KeyReg6= NORMAL_STATE;  // 1
int KeyReg7= NORMAL_STATE;  // 1


int KeyReg8= NORMAL_STATE;  // 1
int KeyReg9= NORMAL_STATE;  // 1
int KeyReg10= NORMAL_STATE;  // 1
int KeyReg11= NORMAL_STATE;  // 1


int flag_change_state_button1=0;
int flag_change_state_button2= 0;
int flag_change_state_button3= 0;


int isButton1Pressed()
{
	 if(button1_flag==1)
	 {
		 button1_flag=0;
		 return 1;
	 }
	 return 0;
}
int isButton2Pressed()
{
	 if(button2_flag==1)
	 {
		 button2_flag=0;
		 return 1;
	 }
	 return 0;
}
int isButton3Pressed()
{
	 if(button3_flag==1)
	 {
		 button3_flag=0;
		 return 1;
	 }
	 return 0;
}
void subKeyProcess1()
{
	button1_flag=1;
}
void subKeyProcess2()
{
	button2_flag=1;
}
void subKeyProcess3()
{
	button3_flag=1;
}
void getKeyInput()
{
   KeyReg0=KeyReg1;
   KeyReg1=KeyReg2;
   KeyReg2=HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
   if((KeyReg0==KeyReg1) && (KeyReg1==KeyReg2))
   {
         if(KeyReg3 != KeyReg2)  // Nhan tha
         {
        	 KeyReg3 = KeyReg2;
        	 if(KeyReg2==PRESSED_STATE)
        	 {
        		    //TODO
          		 if(flag_change_state_button1==0)
          		 {
              		 subKeyProcess1();
              		 TimerForKeyPress_1=300;
          		 }
          		 else if(flag_change_state_button1==1)
          		 {
          			subKeyProcess1();
          			TimerForKeyPress_1=100;
          		 }

        	 }
        	 else
        	 {
        		 flag_change_state_button1=0;
        		 TimerForKeyPress_1=300;
        	 }
         }
         else
         {
        	 TimerForKeyPress_1--;
        	 if(TimerForKeyPress_1==0)
        	 {
        		 KeyReg3=NORMAL_STATE;  // 1
        		 TimerForKeyPress_1=100;
        		 flag_change_state_button1=1;
        	 }
         }
   }
   // 4,5,6,7
     KeyReg4=KeyReg5;   // NORMAL_STATE  //1
     KeyReg5=KeyReg6;   // NORMAL_STATE  //1
     KeyReg6=HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin); // state1= 1= normal
     if((KeyReg4==KeyReg5) && (KeyReg5==KeyReg6))  // NORMAL
     {
           if(KeyReg7 != KeyReg6)  // Nhan tha
           {
          	 KeyReg7 = KeyReg6;  // KeyReg3 = NORMAL
          	 if(KeyReg6==PRESSED_STATE)   // PRESSED_STATE = 0: LED_ON
          	 {
          		    //TODO
          		 if(flag_change_state_button2==0)
          		 {
              		 subKeyProcess2();
              		 TimerForKeyPress_2=300;
          		 }
          		 else if(flag_change_state_button2==1)
          		 {
          			subKeyProcess2();
          			TimerForKeyPress_2=100;
          		 }
          	 }
          	 else
          	 {
          		flag_change_state_button2=0;
          		TimerForKeyPress_2=300;

          	 }
           }
           else  // KeyREg3= KeyReg2
           {
          	 TimerForKeyPress_2--;
          	 if(TimerForKeyPress_2==0)
          	 {
          		 KeyReg7=NORMAL_STATE;  // 1
          		 TimerForKeyPress_2=100;
          		 flag_change_state_button2 =1;
          	 }
           }
     }
          KeyReg8=KeyReg9;   // NORMAL_STATE  //1
          KeyReg9=KeyReg10;   // NORMAL_STATE  //1
          KeyReg10=HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin); // state1= 1= normal
          if((KeyReg8==KeyReg9) && (KeyReg9==KeyReg10))  // NORMAL
          {
                if(KeyReg11 != KeyReg10)  // Nhan tha
                {
               	 KeyReg11 = KeyReg10;  // KeyReg3 = NORMAL
               	 if(KeyReg10==PRESSED_STATE)   // PRESSED_STATE = 0: LED_ON
               	 {
               		    //TODO
              		 if(flag_change_state_button3==0)
              		 {
                  		 subKeyProcess3();
                  		 TimerForKeyPress_3=300;
              		 }
              		 else if(flag_change_state_button3==1)
              		 {
              			subKeyProcess3();
              			TimerForKeyPress_3=100;
              		 }
               	 }
               	 else
               	 {
               		TimerForKeyPress_3=300;
               		flag_change_state_button3=0;
               	 }
                }
                else   // KeyREg3= KeyReg2
                {
               	  TimerForKeyPress_3--;
               	 if(TimerForKeyPress_3 == 0)
               	 {
               		 KeyReg11=NORMAL_STATE;  // 1
               		 TimerForKeyPress_3=100;
               		flag_change_state_button3 =1;
               	 }
                }
          }
}


