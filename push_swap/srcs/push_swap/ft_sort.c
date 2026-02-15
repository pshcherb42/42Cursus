/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:35:59 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/03 17:12:49 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

void	make_index(t_stack **a, int size)
{
	t_stack	*min;
	t_stack	*max;
	int		i;

	i = 0;
	while (i < size)
	{
		min = find_min(*a);
		min->nbr = INT_MAX - (1 + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		max = find_max(*a);
		max->nbr = i;
		i++;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bit_pos;
	int	i;

	size = ft_stacksize(*a);
	make_index(a, size);
	bit_pos = 0;
	while (ft_checksorted(*a))
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->nbr >> bit_pos) & 1)
				ra(a);
			else
				pb(b, a);
			i++;
		}
		while (ft_stacksize(*b) > 0)
			pa(a, b);
		bit_pos++;
	}
}
