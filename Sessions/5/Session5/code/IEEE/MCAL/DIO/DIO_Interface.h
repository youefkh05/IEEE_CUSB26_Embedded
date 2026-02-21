/*
 * DIO_Interface.h
 *
 *  Created on: Sep 27, 2024
 *      Author: b
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../LIB/Definition.h"

#include "../../LIB/StdType.h"
#include "DIO_Register.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include <avr/io.h>

void DIO_SelectDirectionForPin(u8 GroupName,u8 PinNumber,u8 DirectionState);
void DIO_SelectOutputValueForPin(u8 GroupName,u8 PinNumber,u8 OutputValue);
void  DIO_ReadInputValueForPin(u8 GrouName,u8 PinNumber, u8 *InputValue);


void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState);
void DIO_SelectOutputValueForGroup(u8 GroupName,u8 OutputValue);
void  DIO_ReadInputValueForGroup(u8 GrouName, u8 *InputValue);


void DIO_ControlInternalPullUpForPin(u8 GroupName,u8 PinNumber,u8 State);
void DIO_ToggelValueForGroup(u8 GroupName);
void DIO_ToggelValueForPin(u8 GroupName,u8 PinNumber);
void DIO_ControlInternalPullUpForPin(u8 group, u8 pin, u8 enable) ;




u8 DIO_ReadPin(u8 group, u8 pin) ;




#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
