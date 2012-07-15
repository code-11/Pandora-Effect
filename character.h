#include <string.h>
class character
{
	public:
	      character(int Name);//nondefault constructor
			int getName();
			int Name;
};
character::character(int name)
{
    Name=name;
}
int character::getName()
{
	return Name;
}
