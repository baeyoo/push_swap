/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:23:38 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:23:40 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
