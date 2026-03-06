/*
 * traffic_light.c
 *
 * Created: 10/02/2026 21:06:16
 *  Author: maria
 */ 

#include "../LIB/STD_TYPES.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/GPIO.h"

#include "traffic_light.h"

void TrafficLight_init(void)
{
	GPIO_setupPinDirection(TRAFFIC_PORT, TRAFFIC_RED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(TRAFFIC_PORT, TRAFFIC_YELLOW_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(TRAFFIC_PORT, TRAFFIC_GREEN_PIN, PIN_OUTPUT);
	
	TrafficLight_turnOffAll();
}


void TrafficLight_ON(TrafficLight_Color color)
{
	TrafficLight_turnOffAll();
	
	   switch(color)
	   {
		   case RED:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_RED_PIN, LOGIC_HIGH);
		   break;
		   case YELLOW:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_YELLOW_PIN, LOGIC_HIGH);
		   break;
		   case GREEN:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_GREEN_PIN, LOGIC_HIGH);
		   break;
		   default:
            // Do nothing
            break;
        }
}

void TrafficLight_OFF(TrafficLight_Color color)
{
	TrafficLight_turnOffAll();
	
	   switch(color)
	   {
		   case RED:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_RED_PIN, LOGIC_LOW);
		   break;
		   case YELLOW:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_YELLOW_PIN, LOGIC_LOW);
		   break;
		   case GREEN:
		   GPIO_writePin(TRAFFIC_PORT, TRAFFIC_GREEN_PIN, LOGIC_LOW);
		   break;
		   default:
            // Do nothing
            break;
        }
}
			
void TrafficLight_turnOffAll(void)
{
	GPIO_writePin(TRAFFIC_PORT, TRAFFIC_RED_PIN, LOGIC_LOW);
	GPIO_writePin(TRAFFIC_PORT, TRAFFIC_YELLOW_PIN, LOGIC_LOW);
	GPIO_writePin(TRAFFIC_PORT, TRAFFIC_GREEN_PIN, LOGIC_LOW);
}
