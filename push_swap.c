/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:44:31 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/05 01:37:00 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		ft_print_error(stack);
	}
	new->value = n;
	new->next = NULL;
	tmp = *stack;
	if (!*stack)
		*stack = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_process_number(char *num_str, t_stack **a, char **split)
{
	long	num;

	if (!num_str || ft_check_input(num_str))
	{
		ft_free_stack(split);
		ft_print_error(a);
	}
	num = ft_atoi(num_str);
	if (num < INT_MIN || num > INT_MAX || ft_duplicate(*a, num))
	{
		ft_free_stack(split);
		ft_print_error(a);
	}
	ft_add_back(a, num);
}

void	ft_process_split(char **split, t_stack **a)
{
	int	j;

	j = 0;
	if (!split[0])
	{
		ft_free_stack(split);
		ft_print_error(a);
	}
	while (split[j])
	{
		ft_process_number(split[j], a, split);
		j++;
	}
}

void	ft_parse_inp(char **s, t_stack **a)
{
	int		i;
	char	**split;

	i = 1;
	if (s)
		while (s[i])
		{
			if (!s[i] || *s[i] == '\0')
				ft_print_error(a);
			split = ft_split(s[i], ' ');
			if (!split)
				ft_print_error(a);
			ft_process_split(split, a);
			ft_free_stack(split);
			i++;
		}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	if (ac > 1)
		ft_parse_inp(av, &a);
	if (a && !ft_is_sorted(a))
	{
		size = ft_stack_size(a);
		if (size <= 3)
			ft_sort_three(&a);
		else if (size <= 5)
			ft_sort_five(&a, &b);
		else
		{
			ft_set_index(&a);
			ft_sort_stack_rang(&a, &b, size <= 100 ? 15 : 30);
			ft_move_larg_to_a(&a, &b);
		}
	}
	ft_free_list(&a);
	ft_free_list(&b);
	return (0);
}
