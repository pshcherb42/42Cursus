/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:26:33 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/01 20:12:09 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_checksorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->nbr < a->next->nbr)
			a = a->next;
		else
			return (1);
	}
	return (0);
}
