#include <iostream>

class Contact {
	private:
		std::string f_name;
		std::string l_name;
		std::string nickname;
		std::string p_num;
		std::string d_s;
	public:
		std::string get_fi_name();
		std::string get_la_name();
		std::string get_nkname();
		void get_f_name();
		void get_l_name();
		void get_nickname();
		void get_p_num();
		void get_d_s();
		void set_f_name(std::string name);
		void set_l_name(std::string ln);
		void set_nickname(std::string nn);
		void set_p_num(std::string pn);
		void set_d_s(std::string ds);
};