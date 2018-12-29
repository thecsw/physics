#include <iostream>

class Apple {
    public:
	int stones;

	Apple operator+(Apple sa)
	{
		Apple na;
		na.stones = this->stones + sa.stones;
		return na;
	}
};

Apple& operator-(Apple& sa, Apple& oa)
{
	Apple na;
	na.stones = sa.stones - oa.stones;
	return na;
}

/*
void operator>>(std::ostream& out, std::string v)
{
	std::cout << v;
}
*/

int main(void)
{
	std::ostream &coucou = std::cout;

	coucou << "Sandy";

	Apple fa;
	Apple fs;
	fa.stones = 10;
	fs.stones = 32;
	Apple new_apple = fa - fs;
	coucou << new_apple.stones;
	coucou << (fa + fs + fa + fa).stones;

	//std::cout >> "eoaeao";

	return 0;
}
