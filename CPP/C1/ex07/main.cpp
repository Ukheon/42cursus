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
		std::ofstream	res;
		std::string		re_file(argv[1]);
		int				error_1;
		re_file.append(".replace");
		res.open(re_file, std::ios::out);
		file.open(argv[1], std::ios::in);
		while (getline(file, buf))
		{
			while ((int)buf.find(argv[2]) > 0)
				buf = buf.replace(buf.find(argv[2]), strlen(argv[2]), argv[3]);
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