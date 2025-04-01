/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:04:48 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/01 23:14:32 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_rev(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	end = *stack;
	while (end->next)
		end = end->next;
	tmp = end->next;
	end->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rot_rev_a(t_stack **a)
{
	rot_rev(a);
	write(1, "rra\n", 4);
}

void	rot_rev_b(t_stack **b)
{
	rot_rev(b);
	write(1, "rrb\n", 4);
}

void	rra_rrb(t_stack **a, t_stack **b)
{
	rot_rev_a(a);
	rot_rev_b(b);
	write(1, "rrr\n", 4);
}
