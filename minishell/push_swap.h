/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:41:24 by pshcherb          #+#    #+#             */
/*   Updated: 2025/02/03 19:05:25 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		error_syntax(char *str);
int		error_dups(t_stack *a, int nbr);
void	free_error(t_stack **a);
int		append_nbr(t_stack **a, int nbr);
void	init_stack(t_stack **a, char **argv);
long	ft_atoi2(const char *str);
void	ft_free_stack(t_stack **a);
void	pb(t_stack **b, t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sa(t_stack **a);
void	push(t_stack **dest, t_stack **src);
int		ft_checksorted(t_stack *a);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_sort_small(t_stack **a, t_stack **b);
int		ft_stacksize(t_stack *lst);
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);
void	put_max_top(t_stack **a);
void	put_min_top(t_stack **a);
int		pos_max(t_stack *a);
int		pos_min(t_stack *a);
int		get_max_bits(int max_num);
t_stack	*find_last_node(t_stack *a);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	make_index(t_stack **a, int size);
int		max_bits(t_stack *a);
int		main(int argc, char **argv);
void	print_stack(t_stack *stack);

#endif
