/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:14 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/02 21:38:24 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
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
