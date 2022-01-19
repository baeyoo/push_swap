/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:29:50 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:29:52 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_last(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (lst)
	{
		while (last->next)
			last = last->next;
	}
	return (last->numero);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	supp_quick(int *a, int primo, int ultimo)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	pivot = primo;
	i = primo;
	j = ultimo;
	while (i < j)
	{
		while (a[i] <= a[pivot] && i < ultimo)
			i++;
		while (a[j] > a[pivot])
			j--;
		if (i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	return (j);
}

void	quicksort(int *a, int primo, int ultimo)
{
	int	j;
	int	pivot;
	int	temp;

	if (primo < ultimo)
	{
		pivot = primo;
		j = supp_quick(a, primo, ultimo);
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		quicksort(a, primo, j - 1);
		quicksort(a, j + 1, ultimo);
	}
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
