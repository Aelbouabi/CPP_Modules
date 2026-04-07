#include "phonebook.hpp"

int g_n;

void PhoneBook::get_one()
{
	std::string line;
	int i;
	for (int i = 1; i != 0; i = 1){
		std::cout << "➜ Enter index for DISPLAY or '0' (or non-digit character) to QUIT: ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit (1);
		std::istringstream is(line);
		is >> i;
		if ((!line.empty() && i <= g_n && i > 0 && line.size() == 1 && ft_isprint(line)) || i == 0)
			break ;
	}
	std::istringstream is(line);
	is >> i;
	if (i > 0 && i <= g_n)
	{
		std::cout << std::endl;
		std::cout << "➜  first name     : ";
		list[i - 1].get_f_name();
		std::cout << std::endl;
		std::cout << "➜  last name      : " ;
		list[i - 1].get_l_name();
		std::cout << std::endl;
		std::cout << "➜  nickname       : " ;
		list[i - 1].get_nickname();
		std::cout << std::endl;
		std::cout << "➜  phone number   : " ;
		list[i - 1].get_p_num();
		std::cout << std::endl;
		std::cout << "➜  darkest secret : " ;
		list[i - 1].get_d_s();
		std::cout << std::endl;
	}
}

void PhoneBook::get_list(){
	int j;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < g_n; i++){
		std::cout << "|" ;
		for (int k = 0; k < 9; k++)
			std::cout << " ";
		std::cout << i + 1;
		std::cout << "|";
		j = list[i].get_fi_name().size();
		if (j <= 10)
		{
			for (int k = j; k < 10; k++)
				std::cout << " ";
			std::cout << list[i].get_fi_name().substr(0, 10);
		}
		else
		{
			std::cout << list[i].get_fi_name().substr(0, 9);
			std::cout << ".";
		}
		std::cout << "|";
		j = list[i].get_la_name().size();
		if (j <= 10)
		{
			for (int k = j; k < 10; k++)
				std::cout << " ";
			std::cout << list[i].get_la_name().substr(0, 10);
		}
		else
		{
			std::cout << list[i].get_la_name().substr(0, 9);
			std::cout << ".";
		}
		std::cout << "|";
		j = list[i].get_nkname().size();
		if (j <= 10)
		{
			for (int k = j; k < 10; k++)
				std::cout << " ";
			std::cout << list[i].get_nkname().substr(0, 10);
		}
		else
		{
			std::cout << list[i].get_nkname().substr(0, 9);
			std::cout << ".";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void PhoneBook::set_list(Contact one){
	static int i;
	list[i] = one;
	if (g_n < 8)
		g_n++;
	i++;
	if (i == 8)
		i = 0;
}
