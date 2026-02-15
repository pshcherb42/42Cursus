/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:13:43 by pshcherb          #+#    #+#             */
/*   Updated: 2025/01/28 19:19:51 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	max_bits(t_stack *a)
{
	int	max_value;
	int	bits;

	if (!a)
		return (0);
	max_value = a->nbr;
	bits = 0;
	while (a)
	{
		if (a->nbr > max_value)
			max_value = a->nbr;
		a = a->next;
	}
	while (max_value > 0)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}
