/*
 * Nom: TP2Probleme2
 * Auteur: Tristan Philis (1906402)
 */


#include <avr/io.h> 
#define F_CPU 8000000
#include <avr/delay.h>

int main()
{
  DDRA = 0xff; // PORT A est en mode sortie
  DDRB = 0xff; // PORT B est en mode sortie
  DDRC = 0xff; // PORT C est en mode sortie
  DDRD = 0; // PORT D est en mode entree

                          
bool buttonPushed = false;
unsigned long compteur = 0;
int Z=1;

  for(;;)  
  {
  	if(PIND & 0x04){
		_delay_ms(20);
		if ((PIND & 0x04) && buttonPushed==false){
		compteur++;
		buttonPushed = true;
		}  
	 }else{
		 buttonPushed =false;
	 }
	 
	
	
	
	switch (compteur) {
		case 0: Z=0;
			break;
		case 1: Z=1;
			break;
		case 2: Z=2;
			break;
		case 3: Z=3;
			break;
		case 4: Z=4;
			break;
		case 5: Z=5;
			break;
		default: Z=0;
	}
	
	if(Z==0){
		PORTA=0x02;
		}
	else if(Z==1){
		if (PIND & 0x04){
			
			PORTA = 0x02;
		    _delay_ms(10);
		    PORTA = 0x01;
		    _delay_ms(10);
			} else{
				compteur=2;
				}
		} 
	else if(Z==2){
		PORTA=0x01;
		} 
	else if(Z==3){
		if(PIND & 0x04){
			PORTA=0x02;
			} else{
				compteur=4;
			}
		}
	else if(Z==4){
		PORTA=0;
		} 
	else if(Z==5){
		if(PIND & 0x04){
			PORTA=0x01;
			}else{
				compteur=0;
				}
		} 
	else {
		compteur=0;
			}
	
	
  }

  return 0; 
}
