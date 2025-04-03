/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohkhald <mohkhald@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 05:42:52 by mohkhald          #+#    #+#             */
/*   Updated: 2025/04/03 05:43:02 by mohkhald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_fill_arr(t_stack *stack, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	*ft_sort_arr(t_stack *stack, int size)
{
	int	*arr;
	int	*tmp;
	int	i;
	int	j;

	i = 0;
	arr = ft_fill_arr(stack, size);
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	ft_set_index(t_stack **a)
{
	int		i;
	int		len;
	int		*arr;
	t_stack	*tmp;

	tmp = (*a);
	len = ft_stack_size(*a);
	arr = ft_sort_stack(*a, len);
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == tmp->data)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
	arr = NULL;
}

void	ft_sort_stack(t_stack **a, t_stack **b, int max)
{
	int	min;

	min = 0;
	while (*a)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb(a, b);
			min++;
			max++;
		}
		else if ((*a)->index < min)
		{
			pb(a, b);
			rb(b);
			min++;
			max++;
		}
		else
			ra(a);
	}
}

void	ft_move_larg_to_a(t_stack **a, t_stack **b)
{
	int	index;
	int	size;

	while (*b)
	{
		index = ft_max_index(*b);
		size = ft_stack_size(*b) / 2;
		if (index == 0)
			pa(a, b);
		else if (index > size)
			rrb(b);
		else if (index <= size)
			rb(b);
	}
}
