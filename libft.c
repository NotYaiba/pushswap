/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:44:39 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/10 13:55:54 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_sstrlen(s));
}

int	ft_strcmp(const char *ss1, const char *ss2)
{
	size_t				i;
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)ss1;
	s2 = (unsigned char *)ss2;
	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	remove_leaks(t_data *data)
{
	ft_lstclear(&(data->a));
	data->a = NULL;
	ft_lstclear(&(data->p));
	ft_lstclear(&(data->cmds));
	ft_lstclear(&(data->b));
	ft_lstclear(&(data->chunkcopy));
	data->chunkcopy = NULL;
	data->b = NULL;
	free(data);
}

int	is_dup(char **tab, int index)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[index], tab[i]) == 0 && index != i)
			return (0);
		i++;
	}
	return (1);
}

int	tab_issorted(char **tab)
{
	int	i;

	i = 1;
	while (tab[i] && tab[i + 1])
	{
		if (ft_atoii(tab[i]) > ft_atoii(tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
