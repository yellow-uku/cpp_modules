#include <iostream>
#include <fstream>
#include <string.h>

typedef std::string string;

std::string replace_string(std::string &src, std::string &dst, std::string line, std::string replaced)
{
    std::string::size_type idx;
    std::string cut_line;

    idx = line.find(src);
	if (idx == std::string::npos)
		return (replaced + line);
    replaced += (line.substr(0, idx) + dst);
    cut_line = line.substr(idx + src.length());
    return (replace_string(src, dst, cut_line, replaced));
}

int main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "Wrong number of arguments\n";
	else
	{
		string s1, s2, fname1;
		
		fname1 = av[1];
		s1 = av[2];
		s2 = av[3];

		std::ifstream f_in(fname1);
		if (!f_in)
		{
			std::cout << "File can't be open for reading\n";
			exit(1);			
		}
		if (f_in.peek() == EOF)
		{
			std::cout << "File is empty\n";
			exit(1);			
		}

		string fname2 = fname1 + ".replace";
		std::ofstream f_out(fname2);
		if (!f_out)
		{
			std::cout << "File can't be open for writing\n";
			exit(1);
		}

		string line;
		while (std::getline(f_in, line))
		{
			string buffer = "";
			buffer += replace_string(s1, s2, line, "");
			f_out << buffer;
			if (!f_in.eof())
				f_out << "\n";
		}
	}
	return (0);
}