/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:17:35 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/07 09:35:00 by mohkhald         ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_swap(t_stack **stack);
void				sb(t_stack **b);
void				sa(t_stack **a);
void				sa_sb(t_stack **a, t_stack **b);
void				ft_push(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				ft_rotate(t_stack **stack);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				ra_rb(t_stack **a, t_stack **b);
void				ft_rot_rev(t_stack **stack);
void				rot_rev_a(t_stack **a);
void				rot_rev_b(t_stack **b);
void				rra_rrb(t_stack **a, t_stack **b);
void				ft_sort_three(t_stack **a);
void				ft_sort_five(t_stack **a, t_stack **b);

void				ft_free_stack(char **split);
void				ft_print_error(t_stack **a);
void				ft_free_list(t_stack **stack);
void				ft_add_back(t_stack **stack, int n);
void				ft_sort_stack(t_stack **a, t_stack **b);
void				ft_set_index(t_stack **a);
void				ft_sort_stack_rang(t_stack **a, t_stack **b, int max);
void				ft_move_larg_to_a(t_stack **a, t_stack **b);
void				ft_process_number(char *num_str, t_stack **a, char **split);
void				ft_process_split(char **split, t_stack **a);
void				ft_parse_inp(char **s, t_stack **a);

int					ft_max_index(t_stack *stack);
int					ft_min_pos(t_stack *stack);
int					ft_duplicate(t_stack *stack, int n);
int					ft_check_input(char *s);
int					ft_stack_size(t_stack *stack);
int					ft_is_sorted(t_stack *a);
int					*ft_sort_arr(t_stack *stack, int size);
int					*ft_fill_arr(t_stack *stack, int size);
#endif
