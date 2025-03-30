/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:48:46 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/30 02:54:31 by mohkhald         ###   ########.fr       */
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

// sa sb
void	sa_sb(t_stack **a, t_stack **b)
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

// rotate
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	end = *stack;
	while (end->next)
		end = end->next;
	end->next = tmp;
	tmp->next = NULL;
}

// rotate a
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

// rotate b
void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

// ra rb
void	ra_rb(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

// rotate reverse
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

// rot_rev a
void	rot_rev_a(t_stack **a)
{
	rot_rev(a);
	write(1, "rra\n", 4);
}

// rot_rev b
void	rot_rev_b(t_stack **b)
{
	rot_rev(b);
	write(1, "rrb\n", 4);
}

// rra_rrb
void	rra_rrb(t_stack **a, t_stack **b)
{
	rot_rev_a(a);
	rot_rev_b(b);
	write(1, "rrr\n", 4);
}
