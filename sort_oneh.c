/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_oneh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:58:08 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/06 19:40:49 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(t_data *data)
{
	int	i;
	int	half;

	i = 0;
	half = stack_len(data->a) / 2 ;
	push_half(half, data);
	while (data->b)
		move_to_top2(&i, data);
	while (i--)
		 execute_ya("ra", data);
	move_to_b(find_min_val(data->a), data);
	i = 0;
	while (data->b)
		move_to_top2(&i, data);
	while (i--)
		execute_ya("ra", data);
}

int	find_index_top(t_stack *stack, int max)
{
	t_stack	*tmp;
	int		cnt;

	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			return (cnt);
		tmp = tmp->next;
		cnt++;
	}
	return (0);
}

int	find_index_bot(t_stack *stack, int max)
{
	t_stack	*tmp;
	int		cnt;

	cnt = 1;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			max = tmp->num;
		cnt++;
		tmp = tmp->next;
	}
	tmp = stack;
	cnt = 1;
	while (tmp)
	{
		if (max == tmp->num)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		cnt;
	int		max;

	cnt = 1;
	max = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (max == tmp->num)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
