#include"uart.h"
#include<string.h>

int main() {
	enableUART1(1, 0, 0, 1, 5);
	enableUART2(1, 0, 0, 1, 5);
	while (1) {
		char *buffer;
		while (U1STAbits.URXDA==1)
		{			
			*buffer = U1RXREG;
			printf("%c ",*buffer);
			__delay_ms(75);
			buffer++;
		}
	}

}

