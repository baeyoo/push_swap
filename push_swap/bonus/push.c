/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:23:52 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:23:54 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_strcomp(str[i], "0123456789+-") == 0)
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	i;
	long	n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] < '0' || str[i + 1] > '9')
			return (2147483648);
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}

void	fill_listaa(t_list **lst, char *argv[], int a)
{
	int		i;
	long	intero;
	t_punt	punt;

	i = 1;
	punt.head = *lst;
	while (i <= a)
	{
		if (ft_isdigit(argv[i]) == 0)
			uscita(&punt);
		intero = ft_atoi(argv[i]);
		if (intero > MAX || intero < MIN)
			uscita(&punt);
		fill_lista(lst, intero);
		i++;
	}
}
