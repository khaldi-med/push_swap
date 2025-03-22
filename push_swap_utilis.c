/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:46 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/22 00:06:04 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap
void	swap(t_stack **stack)
{
	int	tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

// sb
void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

// sa
void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

// ss
void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

// push
void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

// push a
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

// push b
void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

// ra
void	rotate(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
}
