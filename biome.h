#include "feature.h"
class biome
{
	private:
		char* name;
		feature* feature_list;
	public:
		biome(){}
		biome(char* Name, feature* List){
			name=Name;
			feature_list=List;
		}	
		char* get_name(){
			return name;
		}
		feature* get_feature_list(){
			return feature_list;
		}

};