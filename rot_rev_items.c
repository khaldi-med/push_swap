/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 23:04:48 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/03 01:15:43 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_rev(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	end = NULL;
	while (tmp->next)
	{
		end = tmp;
		tmp = tmp->next;
	}
	tmp->next = *stack;
	end->next = NULL;
	*stack = tmp;
}

void	rot_rev_a(t_stack **a)
{
	ft_rot_rev(a);
	write(1, "rra\n", 4);
}

void	rot_rev_b(t_stack **b)
{
	ft_rot_rev(b);
	write(1, "rrb\n", 4);
}

void	rra_rrb(t_stack **a, t_stack **b)
{
	rot_rev_a(a);
	rot_rev_b(b);
	write(1, "rrr\n", 4);
}
