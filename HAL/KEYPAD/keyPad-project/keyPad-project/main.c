
#include <avr/io.h>
#include <util/delay.h>

#define KEY_PRT PORTC
#define KEY_DDR DDRC
#define KEY_PIN PINC

unsigned char keypad[4][3] ={'1','2','3',
								'4','5','6',
								'7','8','9',
								'*','0','#'};
								

int main(void)
{
	
	unsigned char colLoc,rowLoc;
	
	DDRD = 0xFF;
	KEY_DDR = 0xF0;
	KEY_PRT = 0xFF;
	
	
    while(1)
    {
    
		do{
			// Ground all rows
			KEY_PRT &= 0x07;	
			// Read columns			
			colLoc = (KEY_PIN & 0x07);
			
		} while(colLoc != 0x0F); //check till all keys R' released
		
		do{
			do{
				_delay_ms(20);
				colLoc = (KEY_PIN & 0x07);
				
			}while(colLoc == 0x07); // keep checking for key press
			
			_delay_ms(20); // wait till btn is in stable state
			colLoc = (KEY_PIN & 0x07);
		
		
		}while(colLoc == 0x07);
		
		
		while (1)
		{
			//ground row 0 (11100111)
			KEY_PRT = 0xE7; 
			colLoc = (KEY_PIN & 0x07);
			
			if(colLoc != 0x07){ 
				rowLoc = 0;
				break;
			}
			//ground row 1 (11010111)
			KEY_PRT = 0xD7;
			colLoc = (KEY_PIN & 0x07);
			
			if(colLoc != 0x07){
				rowLoc = 1;
				break;
			}
			
			//ground row 2 (10110111)
			KEY_PRT = 0xB7;
			colLoc = (KEY_PIN & 0x07);
			
			if(colLoc != 0x07){
				rowLoc = 2;
				break;
			}
			
			//ground row 3 (01110111)
			KEY_PRT = 0x77;
			colLoc = (KEY_PIN & 0x07);
			rowLoc = 3;
			break;
			
		}
		
		
		if(colLoc == 0x06)
			PORTD = (keypad[rowLoc][0]);
		else if(colLoc == 0x05)
				PORTD = (keypad[rowLoc][1]);
		else
			PORTD = (keypad[rowLoc][2]);
		
	}
	
	return 0;
		
}
