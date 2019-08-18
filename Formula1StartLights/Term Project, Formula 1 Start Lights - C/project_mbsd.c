#include <89c51rd2.h>

void init_timer(); //timer initialize islemini gerceklestiren method.
void init_interrupt(); ///interrupt initialize islemini gerceklestiren method.
void delay(unsigned int); //ledlerin belli zaman araliklarinda yanmasini saglayan gecikme methodu.

void main()
{	
	init_timer();
	init_interrupt();
	
	while(1)
	{
		while(P1)
		{
			P1=0x01; //2^0 = 1 ~ Sadece P1.0'a bagli ledi yakar.
			delay(500);
			P1=0x03; //2^0 + 2^1 = 3 ~ P1.0 ve P1.1 portlarina bagli ledleri birlikte yakar.
			delay(500);
			P1=0x07; //2^0 + 2^1 + 2^2 = 7 ~ P1.0, P1.1 ve P1.2 portlarina bagli ledleri birlikte yakar.
			delay(500);
			P1=0x0F; //2^0 + 2^1 + 2^2 + 2^3 = 15 = 0F ~ P1.0, P1.1, P1.2 ve P1.3 portlarina bagli ledleri birlikte yakar.
			delay(500);
			P1=0x1F; //2^0 + 2^1 + 2^2 + 2^3 + 2^4 = 31 = 1F ~ P1.0, P1.1, P1.2, P1.3 ve P1.4 portlarina bagli ledleri birlikte yakar.
			delay(500);
			P1=0x00; //Tum ledleri ayni anda sondurur.
		}
	}
}

void init_timer()
{
	TMOD = 0x32;	//0011 0010
	TH0 = TL0 = 256-250;	//0.25 ms
}

void init_interrupt()
{
	IT0 = 1;
	EX0 = 1;
	EA = 1;
}

void delay(unsigned int ms)
{	
  int i;
  for (i=0;i<=4*ms;i++)
	{
		TR0=1;
		while(!TF0);
		TF0=0;
	}		 
}