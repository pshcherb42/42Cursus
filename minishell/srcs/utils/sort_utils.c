/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:57:09 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/01 17:59:43 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	min = stack;
	tmp = stack;
	if (!stack)
		return (NULL);
	while (tmp)
	{
		if (tmp->nbr < min->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nbr > max->nbr)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	put_min_top(t_stack **a)
{
	int	size;

	size = ft_stacksize(*a);
	while (pos_min(*a))
	{
		if (pos_min(*a) <= (size / 2))
			ra(a);
		else
			rra(a);
	}
}

void	put_max_top(t_stack **a)
{
	int	size;

	size = ft_stacksize(*a);
	while (pos_max(*a))
	{
		if (pos_max(*a) < (size / 2))
			ra(a);
		else
			rra(a);
	}
}

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*a = second;
	ft_printf("sa\n");
}
