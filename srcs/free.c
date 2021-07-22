#include "../includes/pipex.h"

void	free_splits(char **chain, int i)
{
	while (--i >= 0)
		free(chain[i]);
	free(chain);
}

int	number_of_split(char **splitresult)
{
	int	i;

	i = 0;
	if (!splitresult)
		return (0);
	while (splitresult[i])
		i++;
	return (i);
}

void	free_two_splits(char **chain1, char **chain2)
{
	int	i1;
	int	i2;

	i1 = number_of_split(chain1);
	i2 = number_of_split(chain2);
	while (--i1 >= 0)
		free(chain1[i1]);
	free(chain1);
	while (--i2 >= 0)
		free(chain2[i2]);
	free(chain2);
}
