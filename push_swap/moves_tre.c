/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_tre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:27:21 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:27:23 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_punt *punt_a, t_punt *punt_b)
{
	t_list	*pushante;

	pushante = punt_b->head;
	if (pushante)
	{
		punt_b->head = pushante->next;
		pushante->next = punt_a->head;
		punt_a->head = pushante;
	}
	write(1, "pa\n", 3);
}

void	pb(t_punt *punt_a, t_punt *punt_b)
{
	t_list	*pushante;

	pushante = punt_a->head;
	if (pushante)
	{
		punt_a->head = pushante->next;
		pushante->next = punt_b->head;
		punt_b->head = pushante;
	}
	write(1, "pb\n", 3);
}
