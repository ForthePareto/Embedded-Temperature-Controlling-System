#include "LCD.h"

static void send_falling_edge(void);

void LCD_Init(void) {
    // user must wait 15 ms to start LCD after boot, if this fn is not the first fn after boot no delay needed
    // send command "33" 4-bit mode
    // send command "32" 4-bit mode
    // send command "28" 4-bit mode
    // send command "0E" disp on, cursor blinking (no wait)
    // send command "01" clear disp
    // wait 2 ms
    // send command "06" shift cursor right

    DIO_setPINDir(LCD_PORT, LCD_D4, 1);
    DIO_setPINDir(LCD_PORT, LCD_D5, 1);
    DIO_setPINDir(LCD_PORT, LCD_D6, 1);
    DIO_setPINDir(LCD_PORT, LCD_D7, 1);
    /*****************************/
    /* set LCD control pins as output pins in case of 4 bit LCD */
    DIO_setPINDir(LCD_PORT, LCD_E, 1);
    DIO_setPINDir(LCD_PORT, LCD_RS, 1);
    /*****************************/
    LCD_SendCommand(FOUR_BIT_MODE_I);        //enable 4 bit LCD Mode
    LCD_SendCommand(FOUR_BIT_MODE_II);       //enable 4 bit LCD Mode
    LCD_SendCommand(DISPLAY_ON_CURSOR_OFF);  // enable cursor and display on
    LCD_clearscreen();                       // CLR LCD screen
}

void LCD_SendCommand(uint8 cmnd) {
    // write data high nibble on Data pins
    // RS pin = 0 (write command)
    // R/W pin = 0 (write)
    // high-to-low pulse (450 ns wide) to E pin
    // wait 100 us

    // write data low nibble on Data pins
    // high-to-low pulse (450 ns wide) to E pin
    // wait 100 us

    uint8 HighNibb = (cmnd & 0xf0) >> 4;
    uint8 D01 = (HighNibb & 0x01);
    uint8 D02 = ((HighNibb >> 1) & 0x01);
    uint8 D03 = ((HighNibb >> 2) & 0x01);
    uint8 D04 = ((HighNibb >> 3) & 0x01);
    DIO_write(LCD_PORT, LCD_D4, D01);
    DIO_write(LCD_PORT, LCD_D5, D02);
    DIO_write(LCD_PORT, LCD_D6, D03);
    DIO_write(LCD_PORT, LCD_D7, D04);

    DIO_write(LCD_PORT, LCD_RS, 0);  //enable LCD to receive command
    send_falling_edge();             //send falling edge

    uint8 LowNibb = cmnd & 0x0f;
    D01 = (LowNibb & 0x01);
    D02 = ((LowNibb >> 1) & 0x01);
    D03 = ((LowNibb >> 2) & 0x01);
    D04 = ((LowNibb >> 3) & 0x01);
    DIO_write(LCD_PORT, LCD_D4, D01);
    DIO_write(LCD_PORT, LCD_D5, D02);
    DIO_write(LCD_PORT, LCD_D6, D03);
    DIO_write(LCD_PORT, LCD_D7, D04);
    send_falling_edge();
}

void LCD_DispChar(uint8 data) {
    // write data high nibble on Data pins
    // RS pin = 1 (write data)
    // R/W pin = 0 (write)
    // high-to-low pulse (450 ns wide) to E pin
    // wait 100 us

    // write data low nibble on Data pins
    // high-to-low pulse (450 ns wide) to E pin
    // wait 100 us

    uint8 HighNibb = (data & (uint8)0xf0) >> 4;
    uint8 D01 = (HighNibb & (uint8)0x01);
    uint8 D02 = ((HighNibb >> (uint8)1) & (uint8)0x01);
    uint8 D03 = ((HighNibb >> (uint8)2) & (uint8)0x01);
    uint8 D04 = ((HighNibb >> (uint8)3) & (uint8)0x01);
    DIO_write(LCD_PORT, LCD_D4, D01);
    DIO_write(LCD_PORT, LCD_D5, D02);
    DIO_write(LCD_PORT, LCD_D6, D03);
    DIO_write(LCD_PORT, LCD_D7, D04);

    DIO_write(LCD_PORT, LCD_RS, 1);  //enable LCD to receive data
    send_falling_edge();             //send falling edge

    uint8 LowNibb = data & (uint8)0x0f;
    D01 = (LowNibb & (uint8)0x01);
    D02 = ((LowNibb >> (uint8)1) & (uint8)0x01);
    D03 = ((LowNibb >> (uint8)2) & (uint8)0x01);
    D04 = ((LowNibb >> (uint8)3) & (uint8)0x01);
    DIO_write(LCD_PORT, LCD_D4, D01);
    DIO_write(LCD_PORT, LCD_D5, D02);
    DIO_write(LCD_PORT, LCD_D6, D03);
    DIO_write(LCD_PORT, LCD_D7, D04);
    send_falling_edge();
}

void LCD_Print(uint8* str) {
    while ((*str) != 0)  //keep in the loop until the end of the string
    {
        LCD_DispChar(*str);  // print the characters of the string

        // MISRA : we have a check so it doesn't go out of index
        str++;               
    }
}

void LCD_PrintString(uint8* str, uint8 len) {
    for (uint8 itr = 0; itr < len;itr++) //keep in the loop until the end of the string
    {
        // MISRA : we have a check so it doesn't go out of index
        LCD_DispChar(str[itr]);  // print the characters of the string
    }
}

void LCD_clearscreen(void) {
    LCD_SendCommand(CLR_SCREEN);  // clear the screen
    _delay_ms(2);
}

static void send_falling_edge(void) {
    /* to enable printing the sent character to LCD ,we should send send falling edge to the lcd*/
    DIO_write(LCD_PORT, LCD_E, 1);  // set enable pin to one
    _delay_us(1);                   //period of high
    DIO_write(LCD_PORT, LCD_E, 0);  // clear enable pin
}
