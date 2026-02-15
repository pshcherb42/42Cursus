/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:44:29 by pshcherb          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:17 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	pos_min(t_stack *a)
{
	int		pos;
	t_stack	*min;

	pos = 0;
	min = find_min(a);
	while (a)
	{
		if (a == min)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);
}

int	pos_max(t_stack *a)
{
	int		pos;
	t_stack	*max;

	pos = 0;
	max = find_max(a);
	while (a)
	{
		if (a == max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (0);
}
