/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doppini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:20:29 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:21:33 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	check_array(t_punt *punt_a, int *support, int a)
{
	int	i;

	i = 0;
	while (i < (a - 1))
	{
		if (support[i + 1] == support[i])
		{
			ft_free(punt_a);
			free(support);
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
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

void	doppini(t_punt *punt_a)
{
	int		i;
	int		*support;
	t_list	*list;

	support = NULL;
	list = punt_a->head;
	if (list)
	{
		i = ft_lstsize(list);
		support = (int *)malloc(sizeof(int) * (i));
		i = 0;
		while (list)
		{
			support[i] = list->numero;
			i++;
			list = list->next;
		}
		list = punt_a->head;
		quicksort(support, 0, (ft_lstsize(list) - 1));
		check_array(punt_a, support, ft_lstsize(list));
	}
	free(support);
}
