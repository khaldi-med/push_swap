/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:44:31 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/01 22:39:44 by mohkhald         ###   ########.fr       */
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

void	ft_parse_inp(char **s, t_stack **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (s[i])
	{
		split = ft_split(s[i], ' ');
		j = 0;
		while (split[j])
		{
			if ((ft_atoi(split[j]) < INT_MIN) || (ft_atoi(split[j]) > INT_MAX)
				|| (ft_duplicate(*a, ft_atoi(split[j]))
					|| ft_check_input(split[j])))
			{
				free_stack(split);
				ft_print_error(a);
			}
			ft_add_back(a, ft_atoi(split[j]));
			j++;
		}
		free_stack(split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*t;

	if (!av[1] || !av[1][0])
	{
		write(2, "Error!\n", 7);
		return (-1);
	}
	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		ft_parse_inp(av, &a);
		sort_three(&a);
	}
	t = a;
	while (t != NULL)
	{
		ft_printf("%d\n", t->value);
		t = t->next;
	}
	return (0);
}
