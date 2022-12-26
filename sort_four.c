/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:58:27 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/10 13:56:22 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index3(t_data *data)
{
	execute_ya("rra", data);
	execute_ya("rra", data);
	execute_ya("pb", data);
	if (is_sorted(data->a) == 0)
		sort_three(data->a, data);
	execute_ya("pa", data);
}

static void	index4(t_data *data)
{
	execute_ya("rra", data);
	if (is_sorted(data->a) == 0)
		sort_three(data->a, data);
	execute_ya("pa", data);
}

void	sort_four(t_data *data)
{
	if (find_min(data->a) == 1)
	{
		execute_ya("pb", data);
		if (is_sorted(data->a) == 0)
			sort_three(data->a, data);
		execute_ya("pa", data);
	}
	else if (find_min(data->a) == 2)
	{
		execute_ya("sa", data);
		execute_ya("pb", data);
		if (is_sorted(data->a) == 0)
			sort_three(data->a, data);
		execute_ya("pa", data);
	}
	else if (find_min(data->a) == 3)
		index3(data);
	else if (find_min(data->a) == 4)
		index4(data);
}
