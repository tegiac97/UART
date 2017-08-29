#include"uart.h"
#include<string.h>

char receivedChar;

int main() {
	enableUART1(1, 0, 0, 1, 5);
	enableUART2(1, 0, 0, 1, 5);
	U1STAbits.URXISEL = 00;	//  ngat xay ra khi nhan duoc mot ky tu
	//__delay_ms(100);	
//	receivedChar = U1RXREG;
	IEC0bits.U1RXIE = 1; // bat ngat nhan ky tu
	while (1)
	{

	}
}

void __attribute__((__interrupt__, __auto_psv__)) _U1RXInterrupt(void) {
	receivedChar = U1RXREG;

	IFS0bits.U1RXIF = 0; // xoa co ngat
	puts(receivedChar);
}

