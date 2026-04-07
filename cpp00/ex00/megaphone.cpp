#include <iostream>

int main(int ac, char **av)
{
	std::string st;
	if (ac > 1)
	{
		for (int i = 1; i < ac ; i++)
		{
			st = av[i];
			for (int j = 0; st[j] ; j++)
				st[j] = std::toupper(st[j]);
			std::cout << st;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
