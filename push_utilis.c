/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 21:11:56 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/02 21:57:41 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
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

int ft_is_sorted(t_stack *a){
	if(!a)
		return 0;
	while(a->next){
		if(a->value > a->next->value)
			return 0;
		a = a->next;
	}
	return 1;
}

void ft_sort_stack(t_stack **a, t_stack **b){
	int len; 
	len = ft_stack_size(*a);
	if(len <= 3)
		ft_sort_three(a);
	else if(len == 5 || len == 4)
		ft_sort_five(a, b);
}