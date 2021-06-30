#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

int				main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::fstream	file;
		std::string		buf;
		std::fstream	res;
		std::string		re_file(argv[1]);
		std::string::size_type pos = 0;
		std::string s1(argv[2]);
		std::string s2(argv[3]);

		re_file.append(".replace");
		res.open(re_file, std::ios::out);
		file.open(argv[1], std::ios::in);
		while (getline(file, buf))
		{
			pos = 0;
			while ((pos = buf.find(s1, pos)) != std::string::npos)
			{
				buf = buf.replace(pos, s1.size(), s2);
				pos += s2.size();
			}
			res << buf << std::endl;
		}
		res.close();
		file.close();
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}