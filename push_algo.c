/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:14 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/02 01:34:25 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	sort_three(t_stack **a)
{
	int	n2;
	int	n3;

	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if ((*a)->value > n2 && n2 > n3)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->value > n2 && (*a)->value > n3)
		ra(a);
	else if (n2 > (*a)->value && n2 > n3)
	{
		if ((*a)->value < n3)
			rot_rev_a(a);
		else
		{
			rot_rev_a(a);
			sa(a);
		}
	}
	else if (n3 > (*a)->value && n3 > n2 && n2 > (*a)->value)
		sa(a);
}
