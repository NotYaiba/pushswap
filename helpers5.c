/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:27:34 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/06 20:40:21 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_first(t_data *data, int len)
{
	data->rf = 1;
	data->f_index = len - data->f_index + 1;
}

void	check_second(t_data *data, int len)
{
	data->s_index = len - data->s_index + 1;
	data->rs = 1;
}

void	push_half(int half, t_data *data)
{
	int	mid;
	int	len;

	mid = find_middle(data->a, data);
	while (half-- > 0)
	{
		data->rf = 0;
		data->rs = 0;
		len = stack_len(data->a);
		data->f_index = find_index_top(data->a, mid);
		data->s_index = find_index_bot(data->a, mid);
		if (data->f_index > (len / 2))
			check_first(data, len);
		else
			data->f_index -= 1;
		if (data->s_index > (len / 2))
			check_second(data, len);
		else
			data->s_index -= 1;
		if (data->f_index >= data->s_index)
			rotates_second(data, data->s_index);
		else if (data->f_index < data->s_index)
			rotates_first(data, data->f_index);
		execute_ya("pb", data);
	}
}

void	case4(t_data *data)
{
	addback(&(data->cmds), new_node2("sa"));
	addback(&(data->cmds), new_node2("ra"));
}

void	do_rrb(t_data *data)
{
	data->index = stack_len(data->b) - data->index + 1;
	while (data->index--)
		execute_ya("rrb", data);
}
