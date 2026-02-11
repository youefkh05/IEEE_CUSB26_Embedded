/*
 * traffic_light.h
 *
 * Created: 10/02/2026 21:05:57
 *  Author: maria
 */ 


#ifndef TRAFFIC_LIGHT_H_
#define TRAFFIC_LIGHT_H_

#define TRAFFIC_RED_PIN     PIN0_ID
#define TRAFFIC_YELLOW_PIN  PIN1_ID
#define TRAFFIC_GREEN_PIN   PIN2_ID

#define TRAFFIC_PORT        PORTA_ID

typedef enum
{
    RED,
    YELLOW,
    GREEN
}TrafficLight_Color;


void TrafficLight_init(void);

void TrafficLight_ON(TrafficLight_Color color);

void TrafficLight_OFF(TrafficLight_Color color);

void TrafficLight_turnOffAll(void);


#endif /* TRAFFIC_LIGHT_H_ */