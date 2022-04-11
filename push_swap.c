#include "push_swap.h"

/*
**		ft_sort - Распределяет стек в нужную функцию,
** 		распределение зависит от количества элементов(чисел) в стеке.
**			༺༻
**		Состояние:	✓
**		Нормы:		✓
**			༺༻
*/

void	ft_sort(t_stacks *stacks)
{
	if (stacks->count_a <= 3)
		ft_sort_3_element(stacks);
	else if (stacks->count_a <= 5)
		ft_sort_5_element(stacks);
	else
		ft_global_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_data		*new;
	t_stacks	*stacks;

	if (argc < 2)
		exit(1);
	new = (t_data *)malloc(sizeof(t_data));
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!new || !stacks)
		exit(1);
	ft_null(stacks, new);
	if (ft_validation(argc, argv))
	{
		ft_array_separation(argc, argv, new);
		ft_duplicate_check(new, stacks);
		if (ft_is_sorted(new))
		{
			ft_init_stack(new, stacks);
			ft_sort(stacks);
			ft_free_stack(stacks);
		}
	}
	free(new);
	free(stacks);
	return (0);
}
