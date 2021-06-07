/*
 * common_macros.h
 *
 *  Created on: Jun. 6, 2021
 *      Author: Eslam Khaled Korany
 */

#ifndef MCAL_COMMON_MACROS_H_
#define MCAL_COMMON_MACROS_H_

#define SET_REG_VALUE(REG, VALUE) (REG = VALUE) //set a register with any value

#define SET_BIT(REG, BIT)         (REG = REG | (1 << BIT)) // set bit in a specific register

#define CLEAR_BIT(REG, BIT)       (REG = REG & (~(1 << BIT))) // clear bit from a specific register

// set any certain bit in any register with 0 or 1
#define SET_VALUE(REG, BIT, VALUE) \
    {                              \
        CLEAR_BIT(REG, BIT);       \
        REG |= (VALUE << BIT);     \
    }
#define TOGGLE_BIT(REG, BIT)   (REG = REG ^ (1 << BIT))          // toggle bit in a specific register
#define IS_BIT_SET(REG, BIT)   (REG & (1 << BIT))                // check if a bit is set or not
#define IS_BIT_CLEAR(REG, BIT) (!(REG & (1 << BIT)))             // check if a bit is cleared or not
#define ROL(REG, num)          ((REG << num) | (REG >> 8 - num)) // rotate a specific bit left with a defined number of rotations
#define ROR(REG, num)          ((REG >> num) | (REG << 8 - num)) // rotate a specific bit right with a defined number of rotations

// upper bits of a register are: 0 1 2 3
#define SET_UPPER(REG)         (REG |= 0x0F)
#define CLEAR_UPPER(REG)       (REG &= 0xF0)

// lower bits of a register are: 4 5 6 7
#define SET_LOWER(REG)         (REG |= 0xF0)
#define CLEAR_LOWER(REG)       (REG &= 0x0F)

#endif /* MCAL_COMMON_MACROS_H_ */
