/*
 * std_types.h
 *
 *  Created on: Jun. 6, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_



typedef unsigned char 		  bool;
typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;


// Bool Values


#ifndef ENABLE
#define ENABLE        (1u)
#endif

#ifndef DISABLE
#define DISABLE       (0u)
#endif


#ifndef TRUE
#define TRUE        (1u)
#endif

#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef HIGH
#define HIGH        (1u)
#endif

#ifndef LOW
#define LOW         (0u)
#endif


#ifndef NULL
#define NULL (void *)0
#endif


#endif /* MCAL_STD_TYPES_H_ */
