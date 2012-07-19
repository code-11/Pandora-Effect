//#include <string.h>
#include <string>

class character
{
	public:
	      character(std::string Name);//nondefault constructor
			std::string getName();
			std::string Name;
};
character::character(std::string name)
{
    Name=name;
}
std::string character::getName()
{
	return Name;
}
