/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:37:49 by pshcherb          #+#    #+#             */
/*   Updated: 2024/10/04 12:39:48 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int	ft_puthex(unsigned long long num, char format);
int	ft_putptr(void *pt);
int	ft_putunsigned(unsigned int n);

#endif
