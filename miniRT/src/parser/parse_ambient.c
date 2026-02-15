/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:49:06 by pshcherb          #+#    #+#             */
/*   Updated: 2025/08/23 21:34:14 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/miniRT.h"
#include "../../includes/math_utils.h"

int	handle_ambient(char **tokens, t_scene *scene)
{
	double	ratio;
	t_color	color;

	if (get_ambient_count(0) > 1)
	{
		ft_printf("Error: Multiple ambient lights detected\n");
		return (0);
	}
	if (!validate_ambient_params(tokens, &ratio, &color))
		return (0);
	scene->ambient.ratio = ratio;
	scene->ambient.color = color;
	return (1);
}
