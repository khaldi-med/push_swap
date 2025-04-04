/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:46 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/03 01:01:50 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	ft_push(b, a);
	write(1, "pb\n", 3);
}
