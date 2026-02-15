/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:11:01 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/03 17:49:04 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	init_stack(&a, argv + 1);
	if (a && ft_checksorted(a))
	{
		if (ft_stacksize(a) <= 5)
			ft_sort_small(&a, &b);
		else
		{
			ft_sort(&a, &b);
		}
	}
	ft_free_stack(&a);
	return (0);
}
