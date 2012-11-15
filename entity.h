#include <stdio.h>
#include "unit.h"


class entity
{
	public:
		entity(char Val){
			val=Val;
			being=' ';//NULL;
		}

		entity(){
			being=' ';//NULL;
		}

		char get_val(){ //get a character to print to the map
			char to_return;
			if (being.get_type()==' '){//NULL){ //if there no unit on the square, print the terrain char
				to_return=val;
			}else{  //otherwise, print the unit
				to_return=being.get_type();
			}
			return to_return;	
		}

		void set_val(char c){
			val=c;
		}

		unit get_unit(){
			return being;
		}

		void set_unit(unit Being){
			being=Being;
		}

	private:
		
		char val; //what gets output to screen

		unit being;
};
