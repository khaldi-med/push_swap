/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:44:31 by mohkhald          #+#    #+#             */
/*   Updated: 2025/03/21 00:35:59 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_args(char **split)
{
	int	i;

	i = 0;
	if (!split)
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

void	ft_error(t_stack **a)
{
	write(2, "Error!\n", 7);
	if (a != NULL)
		free_list(a);
	exit(1);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
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
		if (ft_check(s[i]) == 1)
			ft_error(a);
		split = ft_split(s[i], ' ');
		j = 0;
		while (split[j])
			ft_add_back(a, ft_atoi(split[j++]));
		if (split)
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
	return (0);
}
