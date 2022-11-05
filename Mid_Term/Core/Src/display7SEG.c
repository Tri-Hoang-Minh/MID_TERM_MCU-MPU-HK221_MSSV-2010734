/*
 * display7SEG.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Hoang Tri
 */

#include "display7SEG.h"
void display7SEG(int num)
{
	switch(num)
	{
	    case 0:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);     //a
	    	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);     //b
	        HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	    	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);     //g
	    break;
	    case 1:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);      //a
	 	  	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);     //b
	 	  	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);     //g
	    break;
	    case 2:

	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);     //c
	 	  	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	 	  	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 3:
	        HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	        HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	     	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	     	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	     	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	        HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 4:
	    	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);          //a
	    	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	    	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	    	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	    	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	        HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 5:
	    	 HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	    	 HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	    	 HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	 HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	 HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	    	 HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	    	 HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 6:
	    	 HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	    	 HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	    	 HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	    	 HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	    	 HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	    	 HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	    	 HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 7:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);    //g
	    break;
	    case 8:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 0);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    case 9:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 0);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 0);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 0);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 0);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 0);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 0);    //g
	    break;
	    default:
	          HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, 1);          //a
	 	  	  HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, 1);      //b
	 	  	  HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, 1);     //c
	 	  	  HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, 1);     //d
	 	  	  HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, 1);     //e
	 	  	  HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, 1);     //f
	 	  	  HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, 1);    //g
	    break;
	}
}
