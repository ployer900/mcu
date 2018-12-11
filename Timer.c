#include<8052.h>
unsigned int i;

void main() {
	i = 0;
	EA = 1;
	ET0 = 1;
	TMOD = 0x01;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	TR0 = 1;
	TF0 = 0;
	P0 = 0xff;
	while(1) {
/* 		while(TF0 == 1) {
			TF0 = 0;
			P0 = ~P0;
			TH0 = (65536 - 50000) / 256;
			TL0 = (65536 - 50000) % 256;
		} */
	}
}

void Timer0(void) __interrupt 1 {
	i++;
	if (i == 20) {
		i = 0;
		P0 = ~P0;
	}
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
}