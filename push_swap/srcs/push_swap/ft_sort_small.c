/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:40:41 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/03 17:27:10 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*max;

	if (!a || !*a)
		return ;
	max = find_max(*a);
	if ((*a)->nbr == max->nbr)
		ra(a);
	else if ((*a)->next->nbr == max->nbr)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	put_min_top(a);
	pb(b, a);
	ft_sort_three(a);
	pa(a, b);
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	put_min_top(a);
	pb(b, a);
	put_min_top(a);
	pb(b, a);
	ft_sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
	}
	else if (ft_stacksize(*a) == 3)
		ft_sort_three(a);
	else if (ft_stacksize(*a) == 4)
		ft_sort_four(a, b);
	else if (ft_stacksize(*a) == 5)
		ft_sort_five(a, b);
}
