#include "push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, char **split)
{
	if (stack_a)
		ft_stack_clear(stack_a);
	if (stack_b)
		ft_stack_clear(stack_b);
	if (split)
		free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

int	add_number_to_stack(char *str, t_stack **stack_a, char **split)
{
	int		error;
	int		num;
	t_stack	*new;

	error = 0;
	num = ft_atoi_check(str, &error);
	if (error)
	{
		free_split(split);
		return (0);
	}
	new = ft_stack_new(num);
	if (!new)
		ft_error(stack_a, NULL, split);
	ft_stack_add_back(stack_a, new);
	return (1);
}

int	parse_and_add_numbers(char *arg, t_stack **stack_a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!add_number_to_stack(split[j], stack_a, split))
			return (0);
		j++;
	}
	free_split(split);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_and_add_numbers(argv[i], stack_a))
			return (0);
		i++;
	}
	return (1);
}

// int	parse_args(int argc, char **argv, t_stack **stack_a)
// {
// 	int		i;
// 	char	**split;
// 	int		j;
// 	int		error;
// 	int		num;
// 	t_stack	*new;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		split = ft_split(argv[i], ' '); // Split each argument
// 		if (!split)
// 			return (0);
// 		j = 0;
// 		while (split[j])
// 		{
// 			error = 0;
// 			num = ft_atoi_check(split[j], &error);
// 			if (error)
// 			{
// 				free_split(split);
// 				return (0);
// 			}
// 			new = ft_stack_new(num);
// 			if (!new)
// 			{
// 				ft_error(stack_a, NULL, split);
// 			}
// 			ft_stack_add_back(stack_a, new);
// 			j++;
// 		}
// 		free_split(split);
// 		i++;
// 	}
// 	return (1);
// }




// int	parse_single_arg(char *arg, t_stack **stack_a)
// {
// 	char	**split;
// 	int		i;
// 	int		error;
// 	int		num;
// 	t_stack	*new;

// 	split = ft_split(arg, ' ');
// 	if (!split)
// 		return (0);
// 	i = 0;
// 	while (split[i])
// 	{
// 		error = 0;
// 		num = ft_atoi_check(split[i], &error);
// 		if (error)
// 		{
// 			free_split(split);
// 			return (0);
// 		}
// 		new = ft_stack_new(num);
// 		if (!new)
// 			ft_error(stack_a, NULL, split);
// 		ft_stack_add_back(stack_a, new);
// 		i++;
// 	}
// 	free_split(split);
// 	return (1);
// }

// int	parse_args(int argc, char **argv, t_stack **stack_a)
// {
// 	int		i;
// 	int		num;
// 	int		error;
// 	t_stack	*new;

// 	if (argc == 2)
// 		return (parse_single_arg(argv[1], stack_a));
// 	i = 1;
// 	while (i < argc)
// 	{
// 		error = 0;
// 		num = ft_atoi_check(argv[i], &error);
// 		if (error)
// 			return (0);
// 		new = ft_stack_new(num);
// 		if (!new)
// 			return (0);
// 		ft_stack_add_back(stack_a, new);
// 		i++;
// 	}
// 	return (1);
// }