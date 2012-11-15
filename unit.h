#ifndef UNIT_SEEN

#define UNIT_SEEN

class unit
{
	public:
		unit(){}
		unit(char Type){
			type=Type;
		}
		void ai(){}
		char get_type(){
			return type;
		}
		void set_type(char Type){
			type=Type;
		}
	private:
		int hp;
		int atk;
		int def;
		char type;
};

#endif /* !UNITSEEN */