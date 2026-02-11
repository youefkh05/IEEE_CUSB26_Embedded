/*
 * BIT_MATH.h
 *
 * Created: 10/02/2026 20:54:45
 *  Author: maria
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )

#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )



#endif /* BIT_MATH_H_ */