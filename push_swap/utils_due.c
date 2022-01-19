/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_due.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:29:57 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:29:58 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_nodi(t_list *list_b, int intero, int inter)
{
	t_list	*list;
	int		nodo;

	nodo = 1;
	if (!list_b)
		return (0);
	list = list_b;
	while (list && list->numero != intero && list->numero != inter)
	{
		list = list->next;
		nodo++;
	}
	return (nodo);
}

int	check_ordine(t_punt *puntatore)
{
	t_list	*lst;
	int		controllo;

	lst = puntatore->head;
	controllo = lst->numero;
	while (lst->next)
	{
		if (controllo > lst->next->numero)
			return (0);
		lst = lst->next;
		controllo = lst->numero;
	}
	return (1);
}

int	consecutive(int *support, int a, int b)
{
	int	i;

	i = 0;
	while (support[i] != a)
		i++;
	if (support[i + 1] == b || support[i - 1] == b)
		return (1);
	return (0);
}

int	ft_strcomp(char c, char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret + 1);
		ret++;
	}
	return (0);
}
