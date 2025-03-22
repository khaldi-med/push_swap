/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:17:35 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/22 02:56:16 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// operation functions

void				swap(t_stack **stack);
void				sb(t_stack **b);
void				sa(t_stack **a);
void				sa_sb(t_stack **a, t_stack **b);
void				push(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				ra_rb(t_stack **a, t_stack **b);
void				rot_rev(t_stack **stack);
void				rot_rev_a(t_stack **a);
void				rot_rev_b(t_stack **b);
void				rra_rrb(t_stack **a, t_stack **b);
#endif
