#include <iostream>

int         main(int argc, char *argv[])
{
    char    c;
    int     i;
    int     j;

    i = 0;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                argv[i][j] = toupper(argv[i][j]);
                j++;
            }
            std::cout << argv[i];
            i++;
        }
        std::cout << std::endl;
    }
    return (0);
}