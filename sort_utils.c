#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	index_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;
	int		min;
	int		index;

	if (!stack || !*stack)
		return ;
	current = *stack;
	index = 0;
	while (current)
	{
		min = INT_MAX;
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value < min && tmp->index == 0)
				min = tmp->value;
			tmp = tmp->next;
		}
		tmp = *stack;
		while (tmp)
		{
			if (tmp->value == min && tmp->index == 0)
				tmp->index = ++index;
			tmp = tmp->next;
		}
		current = current->next;
	}
}

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (ft_stack_size(*stack_a) < 3)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

int	find_smallest_index_position(t_stack *stack)
{
	int		min_index;
	int		pos;
	int		min_pos;
	t_stack	*tmp;

	if (!stack)
		return (0);
	min_index = INT_MAX;
	pos = 0;
	min_pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

void	sort_small_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	size;

	size = ft_stack_size(*stack_a);
	while (ft_stack_size(*stack_a) > 3)
	{
		min_pos = find_smallest_index_position(*stack_a);
		if (min_pos <= ft_stack_size(*stack_a) / 2)
		{
			while (min_pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			while (min_pos++ < ft_stack_size(*stack_a))
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
	}
	sort_3(stack_a);
	while (ft_stack_size(*stack_b) > 0)
		pa(stack_a, stack_b, 1);
}