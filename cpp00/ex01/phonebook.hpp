#include "contact.hpp"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

class PhoneBook {
	private:
		Contact list[8];
	public:
		void get_list();
		void get_one();
		void set_list(Contact one);
};

int ft_isprint(std::string line);
