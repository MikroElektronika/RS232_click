/*
Example for RS232 Click

    Date          : maj 2018.
    Author        : Katarina Perendic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Intializes UART module
- Application Initialization - Driver intialization
- Application Task - (code snippet) - Checks if new data byte have received in rx buffer (ready for reading),
  and if ready than reads one byte from rx buffer. In second case aplication task writes
  message data via UART.

*/

#include "Click_RS232_types.h"
#include "Click_RS232_config.h"

const uint8_t MESSAGE_DATA[9] = { 'M', 'i', 'k', 'r', 'o', 'E', 13, 10, 0 };

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_uartInit( _MIKROBUS1, &_RS232_UART_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    Delay_ms( 100 );
}

void applicationInit()
{
    rs232_uartDriverInit( (T_RS232_P)&_MIKROBUS1_GPIO, (T_RS232_P)&_MIKROBUS1_UART );
    mikrobus_logWrite( "Initialized", _LOG_LINE );
    Delay_ms( 100 );
}

void applicationTask()
{
    char tmp;
    uint8_t rdyFlag;

// RECEIVER - UART polling 

    rdyFlag = rs232_byteReady();

    if (1 == rdyFlag)
    {
        tmp = rs232_readByte();
        mikrobus_logWrite( &tmp, _LOG_BYTE );
    }

// TRANSMITER - TX each 2 sec

/*
    for (tmp = 0; tmp < 9; tmp++)
    {
        rs232_writeByte( MESSAGE_DATA[tmp] );
        mikrobus_logWrite( "MESSAGE SENT", _LOG_LINE );
    }
    Delay_ms(2000);
*/

}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}