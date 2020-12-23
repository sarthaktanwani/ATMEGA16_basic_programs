#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
void slave_spi_init();
void rx();
int main()
{
  
  slave_spi_init();
   while(1)
  {
	 rx();
  }

}
void slave_spi_init()
{
  DDRA=0xff; 
  DDRB=DDRB | (1<<6);//Input
  SPCR=SPCR|(1<<SPE)|(1<<DORD);

}
void rx()
{
	  while( (SPSR&(1<<SPIF))==0);
	  PORTA=SPDR;
	
}
