/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:24:56 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:24:58 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_define(t_punt *punt_a, t_punt *punt_b, t_def *def)
{
	if (punt_a->head)
		def->st = punt_a->head->numero;
	if (punt_a->head && punt_a->head->next)
		def->nd = punt_a->head->next->numero;
	if (punt_a->head && punt_a->head->next && punt_a->head->next->next)
		def->rd = punt_a->head->next->next->numero;
	if (punt_b->head)
		def->st_b = punt_b->head->numero;
	if (punt_b->head && punt_b->head->next)
		def->nd_b = punt_b->head->next->numero;
	if (punt_b->head && punt_b->head->next && punt_b->head->next->next)
		def->rd_b = punt_b->head->next->next->numero;
	if (punt_a->head)
		def->end = ft_last(punt_a->head);
	if (punt_b->head)
		def->end_b = ft_last(punt_b->head);
}

void	algo3(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi)
{
	t_def	def;

	while (punt_b->head)
	{
		update_define(punt_a, punt_b, &def);
		if (punt_b->head->numero == support[nozi->intero])
		{
			pa(punt_a, punt_b);
			nozi->intero--;
		}
		else if ((def.end_b > def.st_b && def.end_b < def.nd_b)
			|| (def.end_b == support[nozi->intero]))
			rrb(punt_b);
		else if ((def.nd_b < def.st_b && def.st_b < def.rd_b)
			|| (def.end_b < def.nd_b && def.nd_b < def.st_b))
			sb(punt_b);
		else
			rb(punt_b);
	}
}

void	algo2(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi)
{
	t_def	def;

	while (check_ordine(punt_a) != 1)
	{
		update_define(punt_a, punt_b, &def);
		if (def.st == support[nozi->intero])
		{
			pb(punt_a, punt_b);
			nozi->intero++;
		}
		else if ((def.end > def.st && def.end < def.nd)
			|| (def.end == support[nozi->intero]))
			rra(punt_a);
		else if (((def.nd < def.st && def.st < def.rd) && (def.st > nozi->check
					&& def.nd > nozi->check && def.rd > nozi->check)) || ((
					def.end < def.nd && def.nd < def.st) && (def.st
					> nozi->check && def.nd > nozi->check && def.end
					> nozi->check)))
			sa(punt_a);
		else
			ra(punt_a);
	}
}

void	algo1(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	t_def	def;
	int		intero;
	int		check;

	intero = (inti / 2);
	check = support[intero];
	while ((ft_lstsize(punt_b->head) <= intero && inti % 2 == 1)
		|| (ft_lstsize(punt_b->head) < intero && inti % 2 == 0))
	{
		update_define(punt_a, punt_b, &def);
		if ((def.st <= check && inti % 2 == 1)
			|| (def.st < check && inti % 2 == 0))
			pb(punt_a, punt_b);
		else
		{
			if ((def.nd < def.st && def.st < def.rd)
				|| (def.end < def.nd && def.nd < def.st))
				sa(punt_a);
			ra(punt_a);
		}
	}
}

void	algo(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	t_nozi	nozi;
	int		intero;
	int		check;

	nozi.inti = inti;
	nozi.intero = (inti / 2);
	intero = (inti / 2);
	check = support[intero];
	nozi.check = check;
	algo1(punt_a, punt_b, support, inti);
	if (inti % 2 == 1)
		nozi.intero++;
	algo2(punt_a, punt_b, support, &nozi);
	nozi.intero--;
	algo3(punt_a, punt_b, support, &nozi);
}
