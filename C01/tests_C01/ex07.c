#include <stdio.h>
#include "../ex07/ft_rev_int_tab.c"

int	main(void)
{
	int		tab[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		scanf("%d", &tab[i]);
		i++;
	}
	ft_rev_int_tab(tab, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d : ", tab[i]);
		i++;
	}
}
