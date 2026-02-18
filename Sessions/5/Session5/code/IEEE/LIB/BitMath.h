/*
 * BitMath.h
 *
 *  Created on: Sep 27, 2024
 *      Author: b
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_


#define SetBit(Reg,No)   ((Reg)|=(1<<No))
#define ClrBit(Reg,No)   ((Reg)&=~(1<<No))
#define TogBit(Reg,No)   ((Reg)^=(1<<No))
#define GetBit(Reg,No)   (((Reg)>>(No))&(0x01))



#endif /* LIB_BITMATH_H_ */
