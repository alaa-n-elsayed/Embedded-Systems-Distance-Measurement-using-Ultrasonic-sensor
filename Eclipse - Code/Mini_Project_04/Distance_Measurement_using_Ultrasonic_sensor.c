 /*********************************************************************************
 *
 * [File Name]: Distance_Measurement_using_Ultrasonic_sensor.c
 *
 * [Author]: Alaa Elsayed
 *
 * [Date Created]: 23 / 10 / 2021
 *
 * [Description]: System to measure the distance using ultrasonic sensor HC-SR04
 *
 *********************************************************************************/

#include <avr/io.h>
#include <util/delay.h> /* To use delay function */
#include "lcd.h"
#include "ultrasonic.h"

/* function main begins program execution */
int main(void)
{
	/********** Initialization Code **********/

	uint16 Distance; /* Variable to store the distance to be displayed on the screen */

	SREG = ( 1 << 7 ); /* Enable global interrupts to generate one using ICU */

	LCD_init(); /* Initialize LCD to represent the distance */
	Ultrasonic_init(); /* Initialize Ultrasonic to get the distance */

	LCD_displayString("Distance =    cm"); /* Display the standard message for representing distance value */


	/* Super loop */
	for(;;)
	{
		/********** Application Code **********/

		/* 1. Call Ultrasonic readDistance function to measure the distance
		 * 2. Store the value sent from the function in a variable to be represented
		 */
		Distance = Ultrasonic_readDistance();

		LCD_moveCursor(0, 11); /* Move the cursor to the suitable place for representing the distance */

		/* Represent the distance on LCD */
		if( Distance >= 100 )
		{
			LCD_intgerToString(Distance);
		}
		else
		{
			LCD_intgerToString(Distance);

			/* In case the distance is two, or one number
			 * Print a space after the value to overwrite the previous digit in this location if existed
			 */
			LCD_displayCharacter(' ');
		}

	} /* End super loop */
} /* End function main */
