/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   helpers3.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melkarmi <melkarmi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/29 16:20:20 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/29 16:20:22 by melkarmi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors(char **av, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (check_str(av[i]) == 0 || ft_atoii(av[i]) < (long long) \
		-2147483647 || ft_atoii(av[i]) > (long long)2147483647 \
		|| is_dup(av, i) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_sstrlen(str) != 1)
		i++;
	else if (str[i] == '-' && ft_sstrlen(str) == 1)
		return (0);
	while (str[i])
	{
		if (isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	find_max_val(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min_val(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	max = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (max > tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	find_max(t_stack *stack)
{
	t_stack	*tmp;
	int		cnt;
	int		max;

	cnt = 1;
	max = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (max < tmp->num)
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
