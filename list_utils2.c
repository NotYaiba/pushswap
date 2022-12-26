/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:43:48 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/07 11:38:15 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_inst(char *line, t_data *data)
{
	if (!ft_strcmp(line, "sa"))
		sa(data);
	else if (!ft_strcmp(line, "sb"))
		sb(data);
	else if (!ft_strcmp(line, "ss"))
		ss(data);
	else if (!ft_strcmp(line, "pa"))
		pa(data);
	else if (!ft_strcmp(line, "pb"))
		pb(data);
	else if (!ft_strcmp(line, "ra"))
		ra(data);
	else if (!ft_strcmp(line, "rb"))
		rb(data);
	else if (!ft_strcmp(line, "rr"))
		rr(data);
	else if (!ft_strcmp(line, "rra"))
		rra(data);
	else if (!ft_strcmp(line, "rrb"))
		rrb(data);
	else if (!ft_strcmp(line, "rrr"))
		rrr(data);
}

void	sort_linked(t_stack **start)
{
	t_stack	*tmp;
	int		swapped;

	if (start == NULL)
		return ;
	swapped = 1;
	while (1)
	{
		swapped = 0;
		tmp = *start;
		while (tmp)
		{
			if (tmp->next && tmp->num > tmp->next->num)
			{	
				swap(tmp, tmp->next);
				swapped = 1;
			}
			tmp = tmp->next;
		}
		if (swapped == 0)
			break ;
	}
}

void	swap(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->num;
	a->num = b->num;
	b->num = temp;
}

t_stack	*copy_linkedlist(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	if (!stack)
		return (NULL);
	tmp2 = stack;
	while (tmp2)
	{
		addback(&tmp, new_node(tmp2->num));
		tmp2 = tmp2->next;
	}
	return (tmp);
}

int	find_middle(t_stack *stack, t_data *data)
{
	t_stack	*tmp;
	t_stack	*first;
	int		i;
	int		val;

	tmp = copy_linkedlist(stack);
	sort_linked(&tmp);
	first = tmp;
	i = 1;
	while (tmp)
	{
		if (i == ((stack_len(data->a) / 2) + 1))
		{
			val = tmp->num;
			ft_lstclear(&first);
			return (val);
		}
		i++;
		tmp = tmp->next;
	}
	ft_lstclear(&first);
	return (0);
}
