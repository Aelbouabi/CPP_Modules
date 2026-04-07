#include "phonebook.hpp"

int ft_digit(std::string line)
{
	for (int i = 0 ; i < (int)line.size() ; i++) {
        if (std::isdigit(line[i]))
            continue ;
		return 0;
    }
    return 1;
}

int ft_isprint(std::string line)
{
	for (int i = 0; i < (int)line.size() ; i++)
	{
		if (std::isprint(line[i]))
			continue ;
		return (0);
	}
	return (1);
}

int is_all_sp(std::string line)
{
	int cp = 0;
	for (int i = 0 ; i < (int)line.size() ; i++)
	{
		if (std::isspace(line[i]))
			cp++;
	}
	if (cp == (int)line.size())
		return 1;
	return 0;
}

int main ()
{
    PhoneBook book;
	for (int i = 1; i != 0; i = 1)
	{
		Contact		con;
		std::string	line;
		std::cout << "➜  what you wanna do ADD or SEARCH or EXIT :" << std::endl;
		std::cout << "➜  ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			exit (1);
		if (line == "ADD")
		{
			for (int i = 1; i != 0; i = 1){
				std::cout << "➜  add first name     : ";
				std::getline(std::cin, line);
				if (!line.empty() && ft_isprint(line) && !is_all_sp(line))
					break ;
				if (std::cin.eof())
					exit (1);
			}
			con.set_f_name(line);
			for (int i = 1; i != 0; i = 1){
				std::cout << "➜  add last name      : ";
				std::getline(std::cin, line);
				if (!line.empty() && ft_isprint(line) && !is_all_sp(line))
					break ;
				if (std::cin.eof())
					exit (1);
			}
			con.set_l_name(line);
			for (int i = 1; i != 0; i = 1){
				std::cout << "➜  add nickname       : ";
				std::getline(std::cin, line);
				if (!line.empty() && ft_isprint(line) && !is_all_sp(line))
					break ;
				if (std::cin.eof())
					exit (1);
			}
			con.set_nickname(line);
			for (int i = 1; i != 0; i = 1){
				std::cout << "➜  add phone number   : ";
				std::getline(std::cin, line);
				if (!line.empty() && ft_isprint(line) && !is_all_sp(line) && ft_digit(line))
					break ;
				if (std::cin.eof())
					exit (1);
			}
			con.set_p_num(line);
			for (int i = 1; i != 0; i = 1){
				std::cout << "➜  add darkest secret : ";
				std::getline(std::cin, line);
				if (!line.empty() && ft_isprint(line) && !is_all_sp(line))
					break ;
				if (std::cin.eof())
					exit (1);
			}
			con.set_d_s(line);
            book.set_list(con);
		}
        if (line == "SEARCH")
        {
			book.get_list();
			book.get_one();
        }
		if (line == "EXIT")
			break ;
	}
	return(0);
}