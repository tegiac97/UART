
#pragma once
#pragma config FOSFPR = HS             // Oscillator (Internal Fast RC (No change to Primary Osc Mode bits))
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)

// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)

// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_ON          // PBOR Enable (Enabled)
#pragma config LPOL = PWMxL_ACT_HI      // Low-side PWM Output Polarity (Active High)
#pragma config HPOL = PWMxH_ACT_HI      // High-side PWM Output Polarity (Active High)
#pragma config PWMPIN = RST_IOPIN       // PWM Output Pin Reset (Control with PORT/TRIS regs)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enable)

// FBS
#pragma config BWRP = WR_PROTECT_BOOT_OFF// Boot Segment Program Memory Write Protect (Boot Segment Program Memory may be written)
#pragma config BSS = NO_BOOT_CODE       // Boot Segment Program Flash Memory Code Protection (No Boot Segment)
#pragma config EBS = NO_BOOT_EEPROM     // Boot Segment Data EEPROM Protection (No Boot EEPROM)
#pragma config RBS = NO_BOOT_RAM        // Boot Segment Data RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WR_PROT_SEC_OFF   // Secure Segment Program Write Protect (Disabled)
#pragma config SSS = NO_SEC_CODE        // Secure Segment Program Flash Memory Code Protection (No Secure Segment)
#pragma config ESS = NO_SEC_EEPROM      // Secure Segment Data EEPROM Protection (No Segment Data EEPROM)
#pragma config RSS = NO_SEC_RAM         // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = GSS_OFF            // General Segment Code Protection (Disabled)

// FICD
#pragma config ICS = ICS_PGD            // Comm Channel Select (Use PGC/EMUC and PGD/EMUD)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define FCY 2000000UL
#include<p30F6010A.h>
#include<xc.h>
#include<stdio.h>
#include<libpic30.h>
#include<stdio.h>
#include"uart.h"
char receivedChar;
char s[20],buf[20];
int i = 0, sign = 0,t=0;

int main() {
	enableUART1(1, 0, 0, 1, 12);
	IEC0bits.U1RXIE = 1; // bat ngat nhan ky tu
	while (1)
	{
		if (sign==1)
		{
			printf("%s  ", buf);
			memset(buf, 0, sizeof(buf));
			sign = 0; 
			i = 0;
		}
		else
		{	
		}
	}
}

void __attribute__((__interrupt__, __auto_psv__)) _U1RXInterrupt(void) {
	receivedChar = U1RXREG;
	if(receivedChar != 'c')
	{
		s[i] = receivedChar;
		IFS0bits.U1RXIF = 0; // xoa co ngat
		i++;
	}
	else
	{
		sign = 1;
		for ( t = 0; t < i; t++)
		{
			buf[t] = s[t];
		}
	}	
}
