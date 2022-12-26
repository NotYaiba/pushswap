/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:21:05 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/10 14:58:35 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(av, ac) == 0 || ac == 1 || tab_issorted(av))
		return (0);
	data = malloc(sizeof(t_data));
	init_struct3(data);
	data->a = convert_input(ac, av);
	if (stack_len(data->a) == 2)
		sort_two(data);
	else if (stack_len(data->a) == 3)
		sort_three(data->a, data);
	else if (stack_len(data->a) == 4)
		sort_four(data);
	else if (stack_len(data->a) == 5)
		sort_five(data);
	else if (stack_len(data->a) <= 100)
		sort_more(data);
	else
		find_chunk(data);
	optimize(data);
	remove_leaks(data);
	return (0);
}

void	sort_two(t_data *data)
{
	if (is_sorted(data->a) == 0)
		execute_ya("sa", data);
}

void	clear_struct(t_data *data)
{
	print_list2(data->p);
	ft_lstclear(&data->p);
	ft_lstclear(&(data->cmds));
}

void	optimize(t_data *data)
{
	t_stack	*tmp2;

	tmp2 = data->cmds;
	while (tmp2)
	{
		if ((tmp2)->next && ((!ft_strcmp((tmp2)->content, "ra") && \
		!ft_strcmp((tmp2)->next->content, "rb")) || (!ft_strcmp((tmp2) \
		->content, "rb") && !ft_strcmp((tmp2)->next->content, "ra"))))
		{
			addback(&data->p, new_node2("rr"));
			(tmp2) = (tmp2)->next;
		}
		else if ((tmp2)->next && ((!ft_strcmp((tmp2)->content, "rra") \
		&& !ft_strcmp((tmp2)->next->content, "rrb")) || (!ft_strcmp((tmp2) \
		->content, "rrb") && !ft_strcmp((tmp2)->next->content, "rra"))))
		{
			addback(&data->p, new_node2("rrr"));
			(tmp2) = (tmp2)->next;
		}
		else
			addback(&data->p, new_node2((tmp2)->content));
		(tmp2) = (tmp2)->next;
	}
	clear_struct(data);
}
