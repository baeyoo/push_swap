/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:27:48 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:27:49 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_segnalone(t_list *list_a, t_segna *segnalino)
{
	while (list_a)
	{
		if (list_a->numero < segnalino->low)
		{
			if (list_a->numero < segnalino->lower)
			{
				segnalino->low = segnalino->lower;
				segnalino->lower = list_a->numero;
			}
			else
				segnalino->low = list_a->numero;
		}
		list_a = list_a->next;
	}
}

void	fill_segnalino(t_punt *punt_a, t_segna *segnalino)
{
	t_list	*list_a;

	list_a = punt_a->head;
	segnalino->lower = list_a->numero;
	if (list_a->next->numero < segnalino->lower)
	{
		segnalino->lower = list_a->next->numero;
		segnalino->low = list_a->numero;
	}
	else
		segnalino->low = list_a->next->numero;
	list_a = list_a->next->next;
	fill_segnalone(list_a, segnalino);
}

void	segnaletto(t_punt *punt_a, t_punt *punt_b, t_segna segnalino)
{
	while (punt_a->head && segnalino.cont < 2)
	{
		if (punt_a->head->numero == segnalino.lower
			|| punt_a->head->numero == segnalino.low)
		{
			pb(punt_a, punt_b);
			segnalino.cont++;
		}
		else
			ra(punt_a);
	}
}

int	pushfive(t_punt *punt_a, t_punt *punt_b)
{
	t_segna	segnalino;

	segnalino.cont = 0;
	if (check_ordine(punt_a) == 0)
	{
		fill_segnalino(punt_a, &segnalino);
		segnaletto(punt_a, punt_b, segnalino);
		if (check_ordine(punt_b) == 1)
			sb(punt_b);
		pushtree(punt_a);
		pa(punt_a, punt_b);
		pa(punt_a, punt_b);
	}
	return (0);
}

void	ft_free(t_punt *punt)
{
	t_list	*list_a;
	t_list	*temp;

	list_a = punt->head;
	if (list_a)
	{
		while (list_a->next)
		{
			temp = list_a;
			list_a = list_a->next;
			free(temp);
		}
	}
	free(list_a);
}
