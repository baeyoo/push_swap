/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:28:52 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:28:55 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*filler(t_list *lst, int a)
{
	int	i;
	int	*support;

	support = (int *)malloc(sizeof(int) * (a));
	i = 0;
	while (lst)
	{
		support[i] = lst->numero;
		lst = lst->next;
		i++;
	}
	quicksort(support, 0, a - 1);
	return (support);
}

void	uscita1(t_punt *punt, int *support)
{
	write(1, "Error\n", 6);
	ft_free(punt);
	free(support);
	exit (0);
}

void	uscita(t_punt *punt)
{
	write(1, "Error\n", 6);
	ft_free(punt);
	exit (0);
}

long	conversione(char **str)
{
	long	negativo;
	long	intero;

	intero = 0;
	negativo = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			negativo = -1;
		(*str)++;
		if (ft_strcomp(**str, "0123456789") == 0)
			return (2147483648);
	}
	while ('0' <= **str && **str <= '9')
	{
		intero = (intero * 10) + **str - 48;
		(*str)++;
	}
	intero *= negativo;
	return (intero);
}

int	push_two(t_list **lst, char **str, int **support)
{
	t_punt	punt;
	long	intero;
	int		a;

	a = 0;
	while (**str != 0)
	{
		punt.head = *lst;
		intero = 0;
		while (**str == ' ' && **str != 0)
			(*str)++;
		if (**str == 0)
			break ;
		intero = conversione(str);
		if (intero > MAX || intero < MIN)
			uscita(&punt);
		fill_lista(lst, intero);
		a++;
		if (**str != 32 && **str != 0)
			return (-1);
	}
	if (a > 0)
		*support = filler(*lst, a);
	return (a);
}
