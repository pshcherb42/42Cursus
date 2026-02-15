/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:03:28 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/03 15:50:59 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	append_nbr(t_stack **a, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!a)
		return (1);
	node = malloc(sizeof(t_stack));
	if (!node)
		return (1);
	node->next = NULL;
	node->nbr = nbr;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
	return (0);
}

void	init_stack(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_error(a);
		nbr = ft_atoi2(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a);
		if (error_dups(*a, nbr))
			free_error(a);
		if (append_nbr(a, (int)nbr))
			free_error(a);
		i++;
	}
}
