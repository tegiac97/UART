#include"uart.h"
#include<string.h>

int main() {
	enableUART1(1, 0, 0, 1, 5);
	while (1)
	{
		char ReceivedChar;
		__C30_UART = 1;
		fflush(stdin);
		ReceivedChar = U1RXREG;
		__C30_UART = 2;
		printf("%c", ReceivedChar);
	}
}