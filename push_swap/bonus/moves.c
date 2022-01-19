/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:23:19 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:23:21 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_punt *puntatore)
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

void	rrb(t_punt *puntatore)
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

void	rr(t_punt *punt_a, t_punt *punt_b)
{
	ra(punt_a);
	rb(punt_b);
}

void	rrr(t_punt *punt_a, t_punt *punt_b)
{
	rra(punt_a);
	rrb(punt_b);
}
