/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:12:47 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/06 15:15:41 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	execute_ya(char *str, t_data *data)
{
	addback(&data->cmds, new_node2(str));
	exec_inst(str, data);
}

void	sort_five(t_data *data)
{
	push_half(2, data);
	sort_three(data->a, data);
	if (is_sorted(data->b) == 1)
		execute_ya("sb", data);
	execute_ya("pa", data);
	execute_ya("pa", data);
}

void	rotates_second(t_data *data, int s_index)
{
	if (data->rs == 1)
	{
		while (s_index-- > 0)
			execute_ya("rra", data);
	}
	else
	{
		while (s_index-- > 0)
			execute_ya("ra", data);
	}
}

void	rotates_first(t_data *data, int f_index)
{
	if (data->rf == 1)
	{
		while (f_index-- > 0)
			execute_ya("rra", data);
	}
	else
	{
		while (f_index-- > 0)
			execute_ya("ra", data);
	}
}
