/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 22:19:54 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/01 22:35:44 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(t_stack **a)
{
	write(2, "Error!\n", 7);
	free_list(a);
	exit(1);
}

int	ft_duplicate(t_stack *stack, int n)
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
