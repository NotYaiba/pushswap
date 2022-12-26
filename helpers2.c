/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   helpers2.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: melkarmi <melkarmi@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/29 16:20:11 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/29 16:24:31 by melkarmi		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	r;
	int				a;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		r = n * -1;
	}
	else
		r = n;
	if (r >= 10)
		ft_putnbr_fd(r / 10, fd);
	a = r % 10 + 48;
	ft_putchar_fd(a, fd);
}

int	isdigit(int cc)
{
	if (cc >= 48 && cc <= 57)
		return (1);
	return (0);
}

long long	ft_atoii(const char *s)
{
	char		*str;
	 long long	x;
	 long long	n;

	str = (char *)s;
	x = 0;
	n = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
		*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (x < 0 && n < 0)
			return (0);
		if (x < 0 && n > 0)
			return (-1);
		x = x * 10 + (*str - 48);
		str++;
	}
	return (x * n);
}
