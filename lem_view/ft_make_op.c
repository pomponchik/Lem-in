/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:58:25 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/20 18:15:14 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int		key_pressed(int keycode, void *param)
{
	t_visu	*visu;

	if (keycode == 53)
		exit(0);
	visu = (t_visu *)param;
	if (keycode == 49)
		perfom_operation(visu);
	return (0);
}

void	ft_make_op(void *win_ptr, t_visu *visu)
{
	mlx_hook(win_ptr, 17, 1L << 0, ft_close, visu);
	mlx_hook(win_ptr, 2, 1L << 0, key_pressed, visu);
}
