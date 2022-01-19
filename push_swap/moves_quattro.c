/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_quattro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:26:39 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:27:14 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb2(t_punt *puntatore)
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

void	ra2(t_punt *puntatore)
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

void	rb2(t_punt *puntatore)
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

void	rrb2(t_punt *puntatore)
{
	t_list	*list_b;
	t_list	*primo;
	t_list	*penultimo;

	list_b = puntatore->head;
	if (list_b && list_b->next)
	{
		primo = list_b;
		while (list_b->next->next)
			list_b = list_b->next;
		penultimo = list_b;
		list_b = list_b->next;
		penultimo->next = NULL;
		list_b->next = primo;
		puntatore->head = list_b;
	}
}

void	rra2(t_punt *puntatore)
{
	t_list	*list_a;
	t_list	*primo;
	t_list	*penultimo;

	list_a = puntatore->head;
	if (list_a && list_a->next)
	{
		primo = list_a;
		while (list_a->next->next)
			list_a = list_a->next;
		penultimo = list_a;
		list_a = list_a->next;
		penultimo->next = NULL;
		list_a->next = primo;
		puntatore->head = list_a;
	}
}
