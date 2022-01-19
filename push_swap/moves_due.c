/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_due.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:26:28 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:26:30 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_punt *punt_a, t_punt *punt_b)
{
	ra2(punt_a);
	rb2(punt_b);
	write(1, "rr\n", 3);
}

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	rrr(t_punt *punt_a, t_punt *punt_b)
{
	rra2(punt_a);
	rrb2(punt_b);
	write(1, "rrr\n", 4);
}

void	sa2(t_punt *puntatore)
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
