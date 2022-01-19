/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:23:29 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:23:31 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_punt *puntatore)
{
	t_list	*list_a;
	int		tmp;

	list_a = puntatore->head;
	if (list_a && list_a->next)
	{
		tmp = list_a->numero;
		list_a->numero = list_a->next->numero;
		list_a->next->numero = tmp;
	}
}

void	sb(t_punt *puntatore)
{
	t_list	*list_b;
	int		tmp;

	list_b = puntatore->head;
	if (list_b && list_b->next)
	{
		tmp = list_b->numero;
		list_b->numero = list_b->next->numero;
		list_b->next->numero = tmp;
	}
}

void	ra(t_punt *puntatore)
{
	t_list	*primo;
	t_list	*secondo;
	t_list	*ultimo;
	t_list	*list_a;

	list_a = puntatore->head;
	if (list_a && list_a->next)
	{
		primo = list_a;
		secondo = list_a->next;
		while (list_a->next)
			list_a = list_a->next;
		ultimo = list_a;
		ultimo->next = primo;
		primo->next = NULL;
		puntatore->head = secondo;
	}
}

void	rb(t_punt *puntatore)
{
	t_list	*primo;
	t_list	*secondo;
	t_list	*ultimo;
	t_list	*list_b;

	list_b = puntatore->head;
	if (list_b && list_b->next)
	{
		primo = list_b;
		secondo = list_b->next;
		while (list_b->next)
			list_b = list_b->next;
		ultimo = list_b;
		ultimo->next = primo;
		primo->next = NULL;
		puntatore->head = secondo;
	}
}

void	ss(t_punt *punt_a, t_punt *punt_b)
{
	sa(punt_a);
	sb(punt_b);
}
