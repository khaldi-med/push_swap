/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 01:03:11 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/03 01:03:16 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_pos(t_stack *stack)
{
	int		min_val;
	int		min_pos;
	int		curr_pos;
	t_stack	*tmp;

	min_val = stack->value;
	min_pos = 0;
	curr_pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = curr_pos;
		}
		tmp = tmp->next;
		curr_pos++;
	}
	return (min_pos);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;
	int	pushed;

	pushed = 0;
	size = ft_stack_size(*a);
	if (size <= 3)
		return (ft_sort_three(a));
	while (size - pushed > 3)
	{
		min_pos = ft_min_pos(*a);
		while (min_pos > 0)
		{
			if (min_pos <= size / 2)
				ra(a);
			else
				rot_rev_a(a);
			min_pos = ft_min_pos(*a);
		}
		pb(b, a);
		pushed++;
	}
	ft_sort_three(a);
	while (*b)
		pa(a, b);
}
