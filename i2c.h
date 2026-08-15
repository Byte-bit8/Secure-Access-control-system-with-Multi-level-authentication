/*---------------------------------------------------------
 * File Name    : i2c.h
 * Description  : I2C Function Prototypes
 *---------------------------------------------------------*/

#ifndef _I2C_H_                      // Start of conditional compilation
#define _I2C_H_                      // Define header guard


#include "types.h"                  // User defined data types

#ifndef I2C_H
#define I2C_H

// Memory-Mapped Register Definitions (I2C0 Base)
#define I2CONSET   (*((volatile unsigned char *) 0xE001C000))
#define I2CONCLR   (*((volatile unsigned char *) 0xE001C018))

// Bit Positions (matching your bit-shifting usage: 1 << BIT)
#define STA        5   // Start flag bit position
#define SI         3   // Interrupt flag bit position
#define SIC        3   // Interrupt clear bit position

#endif // I2C_H
// Pin Connect Block Register
#define PINSEL0    (*((volatile unsigned long *) 0xE002C000))

// I2C0 Peripheral Registers (Base: 0xE001C000)
#define I2DAT      (*((volatile unsigned char *)  0xE001C008))
#define I2SCLH     (*((volatile unsigned short *) 0xE001C010))
#define I2SCLL     (*((volatile unsigned short *) 0xE001C014))
void init_i2c(void);                // Initialize I2C peripheral

void i2c_start(void);               // Generate I2C start condition

void i2c_stop(void);                // Generate I2C stop condition

void i2c_restart(void);             // Generate I2C repeated start

void i2c_write(u8 sdat);            // Write data byte on I2C bus

u8 i2c_mack(void);                  // Read byte with ACK

u8 i2c_nack(void);                  // Read byte with NACK


#endif                              // End of conditional compilation