#include"uart.h"
#include<string.h>

int main() {
	enableUART1(1, 0, 0, 1, 5);
	while (1)
	{        
		char ReceivedChar;
		printf("HelloWorld");
		__delay_ms(250);
}