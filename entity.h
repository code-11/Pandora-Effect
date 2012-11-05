#include <stdio.h>
class entity
{
	public:
      entity(char Val);
      entity();
		char get_val();
	private:
		char val;
};

entity::entity(){}
entity::entity(char Val){
	val=Val;
}
char entity::get_val(){
	return val;	
}
