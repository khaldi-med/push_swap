/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:14 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/02 21:59:12 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_larg_node(t_stack *stack)
{
	t_stack	*node;

	if (!stack)
		return (NULL);
	node = stack;
	while (stack)
	{
		if (stack->value > node->value)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*larg_node;

	larg_node = ft_larg_node(*a);
	if (larg_node == *a)
		ra(a);
	else if (larg_node == (*a)->next)
		rot_rev_a(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
