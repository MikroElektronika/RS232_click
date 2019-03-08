/*
    __rs232_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rs232_driver.h
@brief    RS232 Driver
@mainpage RS232 Click
@{

@image html sch.jpg

@}

@defgroup   RS232
@brief      RS232 Click Driver
@{

| Global Library Prefix | **RS232** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **maj 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RS232_H_
#define _RS232_H_

/** 
 * @macro T_RS232_P
 * @brief Driver Abstract type 
 */
#define T_RS232_P    const uint8_t*

/** @defgroup RS232_COMPILE Compilation Config */              /** @{ */

//  #define   __RS232_DRV_SPI__                            /**<     @macro __RS232_DRV_SPI__  @brief SPI driver selector */
//  #define   __RS232_DRV_I2C__                            /**<     @macro __RS232_DRV_I2C__  @brief I2C driver selector */                                          
  #define   __RS232_DRV_UART__                           /**<     @macro __RS232_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RS232_VAR Variables */                           /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RS232_INIT Driver Initialization */              /** @{ */

#ifdef   __RS232_DRV_SPI__
void rs232_spiDriverInit(T_RS232_P gpioObj, T_RS232_P spiObj);
#endif
#ifdef   __RS232_DRV_I2C__
void rs232_i2cDriverInit(T_RS232_P gpioObj, T_RS232_P i2cObj, uint8_t slave);
#endif
#ifdef   __RS232_DRV_UART__
void rs232_uartDriverInit(T_RS232_P gpioObj, T_RS232_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup RS232_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Write Single Byte
 *
 * @param[in] input 
 *
 * Writes sinle byte.
 */
void rs232_writeByte(uint8_t input);

/**
 * @brief Read Single Byte
 *
 * @return received byte
 *
 * Read received byte.
 */
uint8_t rs232_readByte();

/**
 * @brief Check for new byte received
 *
 * @retval 0 - no new data / 1 - data ready
 *
 * Checks is there a new byte received.
 */
uint8_t rs232_byteReady();

uint8_t rs232_getCTS();

void rs232_setRTS(uint8_t state);

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RS232_STM.c
    @example Click_RS232_TIVA.c
    @example Click_RS232_CEC.c
    @example Click_RS232_KINETIS.c
    @example Click_RS232_MSP.c
    @example Click_RS232_PIC.c
    @example Click_RS232_PIC32.c
    @example Click_RS232_DSPIC.c
    @example Click_RS232_AVR.c
    @example Click_RS232_FT90x.c
    @example Click_RS232_STM.mbas
    @example Click_RS232_TIVA.mbas
    @example Click_RS232_CEC.mbas
    @example Click_RS232_KINETIS.mbas
    @example Click_RS232_MSP.mbas
    @example Click_RS232_PIC.mbas
    @example Click_RS232_PIC32.mbas
    @example Click_RS232_DSPIC.mbas
    @example Click_RS232_AVR.mbas
    @example Click_RS232_FT90x.mbas
    @example Click_RS232_STM.mpas
    @example Click_RS232_TIVA.mpas
    @example Click_RS232_CEC.mpas
    @example Click_RS232_KINETIS.mpas
    @example Click_RS232_MSP.mpas
    @example Click_RS232_PIC.mpas
    @example Click_RS232_PIC32.mpas
    @example Click_RS232_DSPIC.mpas
    @example Click_RS232_AVR.mpas
    @example Click_RS232_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rs232_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */