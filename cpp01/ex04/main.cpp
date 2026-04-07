#include <iostream>
#include <fstream>

int main(int ac, char **av) {
    
    if (ac == 4)
    {
        std::ifstream inFile(av[1]);
        if (!inFile.is_open())
        {
            std::cerr << "File doesn't exist !" << std::endl;
            return(1);
        }
        std::string line;
        std::getline(inFile,line, '\0');
        inFile.close();
        std::string re;  
        size_t pos = 0;  
        std::string s = av[1];
        std::string s1;
        if (!av[2][0])
            s1 = "\a";
        else
            s1 = av[2];
        std::string s2 = av[3];
        while (pos < line.length()) {
            size_t f = line.find(s1, pos);
            if (f != std::string::npos) {
                re += line.substr(pos, f - pos);
                re += s2;
                pos = f + s1.length();
            } else {
                re += line.substr(pos);
                break;
            }
        }
        std::string f_replace = s + ".replace";
        std::ofstream outfile(f_replace.c_str());
        if (outfile.is_open())
        {
            outfile << re;
            outfile.close();
        }
        else
            std::cerr << "Error opening file !" << std::endl;
    }
    else
        std::cerr << "Error parameters <filename> and two strings, s1 and s2 !" << std::endl;
    return 0;
}
