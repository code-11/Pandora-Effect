#include <stdio.h>
#include "biome.h"
int main()
{
		char* list[]={"12345","23456","34567","45678","56789"};
		feature random=feature(1,2,5,5,list);
		feature random2=feature(1,2,5,5,list);
		feature feature_list[]={random,random2};
		printf("%s\n",random.get_form()[1]);
		biome test=biome("Random",feature_list);
		printf("%s\n",test.get_name());
		printf("%s\n",test.get_feature_list()[1].get_form()[1]);
}