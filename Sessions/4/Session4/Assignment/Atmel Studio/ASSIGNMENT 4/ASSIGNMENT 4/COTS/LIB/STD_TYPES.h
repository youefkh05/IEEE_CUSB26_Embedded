/*
 * STD_TYPES.h
 *
 * Created: 10/02/2026 20:53:43
 *  Author: maria
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       0
#endif
#ifndef TRUE
#define TRUE        1
#endif

#define LOGIC_HIGH        1
#define LOGIC_LOW         0

#define NULL_PTR    ((void*)0)

typedef unsigned char            u8 ;       
typedef unsigned short int       u16;       
typedef unsigned long int        u32; 
typedef unsigned long long int   u64;    
   
typedef signed char              s8 ;      
typedef signed short int         s16;      
typedef signed long int          s32;      
typedef signed long long         s64;   
   
typedef float                    f32;
typedef double                   f64;



#endif /* STD_TYPES_H_ */