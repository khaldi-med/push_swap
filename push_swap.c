/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:44:31 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/05 00:43:15 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
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
	// write(2, "teste 4\n", 8);
	if ((ft_atoi(num_str) < INT_MIN) || (ft_atoi(num_str) > INT_MAX)
		|| (ft_duplicate(*a, ft_atoi(num_str)) || ft_check_input(num_str)))
	{
		ft_free_stack(split);
		ft_print_error(a);
	}
	ft_add_back(a, ft_atoi(num_str));
}

void	ft_process_split(char **split, t_stack **a)
{
	int	j;

	j = 0;
	while (*split[j] && ((*split[j] >= 9 && *split[j] <= 13)
			|| *split[j] == ' '))
		j++;
	while (split[j])
	{
		// write(2, "teste 3\n", 8);
		ft_process_number(split[j], a, split);
		j++;
	}
}

void	ft_parse_inp(char **s, t_stack **a)
{
	int		i;
	char	**split;

	i = 1;
	while (s[i])
	{
		// write(2, "teste\n", 6);
		if (!s || !s[i] || *s[i] == '\0')
		{
			write(2, "Error\n", 6);
			ft_free_list(a);
			exit(1);
		}
		// write(2, "teste 2\n", 8);
		split = ft_split(s[i], ' ');
		ft_process_split(split, a);
		ft_free_stack(split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	if (ac > 1)
		ft_parse_inp(av, &a);
	if (a && !ft_is_sorted(a))
	{
		ft_sort_stack(&a, &b);
		ft_move_larg_to_a(&a, &b);
		ft_free_list(&a);
		ft_free_list(&b);
	}
	else if (a)
		ft_free_list(&a);
	return (0);
}
