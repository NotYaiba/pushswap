/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:38:35 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/10 14:50:26 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	printret(t_data *data)
{
	if (is_sorted(data->a) == 0)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	remove_leaks(data);
}

int	check_line(char *line)
{
	if (!ft_strcmp(line, "sa"))
		return (1);
	else if (!ft_strcmp(line, "sb"))
		return (1);
	else if (!ft_strcmp(line, "ss"))
		return (1);
	else if (!ft_strcmp(line, "pa"))
		return (1);
	else if (!ft_strcmp(line, "pb"))
		return (1);
	else if (!ft_strcmp(line, "ra"))
		return (1);
	else if (!ft_strcmp(line, "rb"))
		return (1);
	else if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || \
	!ft_strcmp(line, "rrr") || !ft_strcmp(line, "rr"))
		return (1);
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}

int	checker(t_data *data, int ac)
{
	char	*line;
	int		i;

	while (1)
	{
		i = get_next_line(0, &line);
		if (i > 0 && check_line(line) == 0)
		{
			free(line);
			remove_leaks(data);
			return (0);
		}
		exec_inst(line, data);
		free(line);
		if (i == 0)
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (check_errors(av, ac) == 0 || ac <= 2 )
		return (0);
	data = malloc(sizeof(t_data));
	init_struct3(data);
	data->a = convert_input(ac, av);
	if (checker(data, ac) == 1)
		printret(data);
	return (0);
}
