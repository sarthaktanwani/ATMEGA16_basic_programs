//MAin 
/*
#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
void main()
{
 DDRA=DDRA|(1<<0);
  while(1)
  {
	  PORTA=PORTA | (1<<0);
	  delay();
	  PORTA=PORTA &~ (1<<0);
	  delay();
  }
}
void delay()
{
  TCNT0=0;
  TCCR0=0b00000001;
  while( (TIFR&(1<<TOV0)) ==0);//wait here till TOV0 is 0
  TIFR=TIFR|(1<<TOV0);
}
*/


/*
#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
void main()
{
 DDRA=DDRA|(1<<0);
  while(1)
  {
	  PORTA=PORTA | (1<<0);
	  delay();
	  PORTA=PORTA &~ (1<<0);
	  delay();
  }
}
void delay()
{
  TCNT0=0;
  TCCR0=0b000000010;//8uS
  while( (TIFR&(1<<TOV0)) ==0);//wait here till TOV0 is 0
  TIFR=TIFR|(1<<TOV0);
}
*/


#define F_CPU 1000000UL
#include<avr/io.h>
void delay();
void main()
{
 DDRA=DDRA|(1<<0);
  while(1)
  {
	  PORTA=PORTA | (1<<0);
	  delay();
	  PORTA=PORTA &~ (1<<0);
	  delay();
  }
}
void delay()
{
  TCNT0=0;
  TCCR0=0b000000101;//1024uS
  while( (TIFR&(1<<TOV0)) ==0);//wait here till TOV0 is 0
  TIFR=TIFR|(1<<TOV0);
}
