#include<p30F6010A.h>
#include<xc.h>
#include<stdio.h>
#include<libpic30.h>
#include<stdio.h>


/*enableUART1(Stop Bit, Parity Data, auto baudrata, enable tranfer, baudrate, interrupt, flag interrupt received)
- stop bit:				 Stop selection bit:		1 = 2 stops bit
													0 = 1 stop bit
- parity data			parity and data bit			11 = 9-bit data, no parity
													10 = 8-bit data, odd parity
													01 = 8-bit data, even parity
													00 = 8-bit data, no parity
- autobaud				 Auto Baud Enable bit		1 = Input to Capture module from UxRX pin
													0 = Input to Capture module from
- baudrate				Baudrate Value
- tranfer				 Transmit Enable bit		1 = UART transmitter enabled, UxTX pin controlled by UART (if UARTEN = 1)
													0 = UART transmitter disabled, any pending transmission is aborted and buffer is reset. UxTX pin controlled by PORT
- interruptRX			interrupt received bit		11 =Interrupt flag bit is set when Receive Buffer is full (i.e., has 4 data characters)
													10 =Interrupt flag bit is set when Receive Buffer is 3/4 full (i.e., has 3 data characters)
													0x =Interrupt flag bit is set when a character is received
- flagRX				flag interrupt RX bit		*/

void enableUART1(short int stopBit, short int parityData, short int autoBaud, short int baud_rate, short int transfer, short int interruptRX, short int flagInterruptRX) {
	U1MODEbits.STSEL = stopBit;
	U1MODEbits.PDSEL = parityData;
	U1MODEbits.ABAUD = autoBaud;
	U1STAbits.UTXEN = transfer;
	U1BRG = baud_rate;
	U1STAbits.URXISEL = interruptRX;			//// Interrupt after one RX character is received
	IEC0bits.U1RXIE = flagInterruptRX;			// bat ngat nhan ky tu
	U1MODEbits.UARTEN = 1;
}

//void enableUART2(short int stopBit, short int parityData, short int autoBaud, short int transfer, short int baud_rate, short int interrupt, short int flagInterrupt) {
//	
//	U2MODEbits.STSEL = stopBit;
//	U2MODEbits.PDSEL = parityData;
//	U2MODEbits.ABAUD = autoBaud;
//	U2STAbits.UTXEN = transfer;
//	U2BRG = baud_rate;
//	U2STAbits.URXISEL = 0;
//	IEC1bits.U2RXIE = 1;				// bat ngat nhan ky tu
//	U2MODEbits.UARTEN = 1;
//}


//char receivedChar;
//char receivedString[33], buf[33];
//int i = 0, t = 0;
//int sign;

//
//void printString() {
//	while (1) {
//		if (sign == 1) {
//			printf("%s ", buf);
//			memset(buf, 0, sizeof(buf));
//			i = 0;
//			sign = 0;
//		}
//	}
//}
//
//void __attribute__((__interrupt__, __auto_psv__)) _U1RXInterrupt() {	// Moi khi RXREG nhan 1 ki tu thi nhay vao trong ham nay
//	receivedChar = U1RXREG;
//	if (receivedChar != 'c') {
//		receivedString[i] = receivedChar;
//		IFS0bits.U1RXIF = 0; // xoa co ngat
//		i++;
//	}
//	else {
//			sign = 1;				//Neu sign=1 thi dung viec nhan them ki tu tu uart	
//			
//			for (t = 0; t < i; t++)
//			{
//				buf[t] = receivedString[t];		//va chuyen cac ki tu tu chuoi s sang buf
//			}
//			memset(receivedString, 0, sizeof(receivedString));
//	}
//}