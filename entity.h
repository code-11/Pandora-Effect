#include <stdio.h>
class entity
{
	public:
      entity(char Val);
      entity();
		char get_val();
		void set_val(char c);
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
void entity::set_val(char c){
	val=c;
}
