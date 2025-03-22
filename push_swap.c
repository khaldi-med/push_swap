/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:44:31 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/22 01:22:27 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_args(char **split)
{
	int	i;

	i = 0;
	if (!split || !(*split))
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_list(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	ft_print_error(t_stack **a)
{
	write(2, "Error!\n", 7);
	free_list(a);
	exit(1);
}

int	dup_num(t_stack *stack, int n)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_input(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (s[i] == '+' || s[i] == '-')
			return (1);
		else if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

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
				|| (dup_num(*a, ft_atoi(split[j])) || ft_check_input(split[j])))
			{
				free_args(split);
				ft_print_error(a);
			}
			ft_add_back(a, ft_atoi(split[j]));
			j++;
		}
		free_args(split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		ft_parse_inp(av, &a);
	}
	while (a != NULL)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}
