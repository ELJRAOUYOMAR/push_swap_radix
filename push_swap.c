#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a, 1);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 10)
		sort_small_stack(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

void print_stack(t_stack *stack)
{
    t_stack *tmp = stack;

    printf("[");
    while (tmp)
    {
        printf("%d", tmp->value);
        if (tmp->next) // Print a comma if there's a next element
            printf(", ");
        tmp = tmp->next;
    }
    printf("]\n");
}
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &stack_a))
	{
		ft_stack_clear(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_duplicates(stack_a))
	{
		ft_stack_clear(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	index_stack(&stack_a);
	sort_stack(&stack_a, &stack_b);
	print_stack(stack_a);
	ft_stack_clear(&stack_a);
	return (0);
}