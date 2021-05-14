#include "../../include/checker.h"

int				argv_check(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '0' && str[1] == '0')
			return (1);
		if (str[0] == '-')
			continue ;
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (1);
	}
	return (0);
}
