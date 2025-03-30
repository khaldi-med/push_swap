/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:14 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/30 02:57:08 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		if (second->value < third->value)
			sa(a);
		else
		{
			sa(a);
			rot_rev_a(a);
		}
	}
	if (second->value > first->value && second->value > third->value)
	{
		if (first->value > third->value)
			rot_rev_a(a);
		else
		{
			rot_rev_a(a);
			sa(a);
		}
	}
	if (third->value > second->value && third->value > first->value)
	{
	}
}
