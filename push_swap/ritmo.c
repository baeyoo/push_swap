/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ritmo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:29:04 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:29:08 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ritmo_tres(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi)
{
	t_def	def;

	update_define(punt_a, punt_b, &def);
	if (def.st_b == support[nozi->nodi + nozi->intero])
	{
		pa(punt_a, punt_b);
		nozi->intero--;
		return (1);
	}
	else if (punt_b->head->numero == support[nozi->inter])
	{
		pa(punt_a, punt_b);
		nozi->inter++;
		if (!((def.end_b > def.st_b && def.end_b < def.nd_b)
				|| (def.end_b == support[nozi->nodi + nozi->intero]))
			&& !((def.nd_b < def.st_b && def.st_b < def.rd_b)
				|| (def.end_b < def.nd_b && def.nd_b < def.st_b))
			&& (def.st_b != support[nozi->intero] && def.st_b
				!= support[nozi->inter]))
			rr(punt_a, punt_b);
		else
			ra(punt_a);
		return (1);
	}
	return (0);
}

void	ritmo_terzo(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi)
{
	t_def	def;

	while (ft_lstsize(punt_a->head) < (nozi->inti - (nozi->sezione * 4)))
	{
		update_define(punt_a, punt_b, &def);
		if (ritmo_tres(punt_a, punt_b, support, nozi) == 0)
		{
			if ((def.end_b > def.st_b && def.end_b < def.nd_b)
				|| (def.end_b == support[nozi->nodi + nozi->intero]))
				rrb(punt_b);
			else if ((def.nd_b < def.st_b && def.st_b < def.rd_b)
				|| (def.end_b < def.nd_b && def.nd_b < def.st_b))
				sb(punt_b);
			else
			{
				if (ft_nodi(punt_b->head, support[nozi->nodi + nozi->intero],
						support[nozi->inter]) < (ft_lstsize(punt_b->head) / 2))
					rb(punt_b);
				else
					rrb(punt_b);
			}
		}	
	}
}

void	ritmo_dos(t_punt *punt_a, int *support, t_nozi *nozi)
{
	if ((ft_nodi(punt_a->head, support[nozi->nodi + nozi->intero],
				support[nozi->nodi + nozi->intero]))
		> (ft_lstsize(punt_a->head) / 2))
		rra(punt_a);
	else
		ra(punt_a);
}

void	ritmo_secon(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi)
{
	t_def	def;

	if ((nozi->inti - (nozi->sezione * 4)) % 3 != 0)
		nozi->intero++;
	while (check_ordine(punt_a) != 1)
	{
		update_define(punt_a, punt_b, &def);
		if (def.st == support[nozi->nodi + nozi->intero])
		{
			pb(punt_a, punt_b);
			nozi->intero++;
		}
		else if ((def.end > def.st && def.end < def.nd)
			|| (def.end == support[nozi->nodi + nozi->intero]))
			rra(punt_a);
		else if (((def.nd < def.st && def.st < def.rd)
				&& (def.st > nozi->check && def.nd > nozi->check
					&& def.rd > nozi->check))
			|| ((def.end < def.nd && def.nd < def.st) && (def.st > nozi->check
					&& def.nd > nozi->check && def.end > nozi->check)))
			sa(punt_a);
		else
			ritmo_dos(punt_a, support, nozi);
	}
}

void	ritmo_primo(t_punt *punt_a, t_punt *punt_b, t_nozi *nozi)
{
	t_def	def;

	while ((ft_lstsize(punt_b->head) <= (nozi->nodi + nozi->intero)
			&& (nozi->inti - (nozi->sezione * 4)) % 3 != 0)
		|| (ft_lstsize(punt_b->head) < (nozi->nodi + nozi->intero)
			&& (nozi->inti - (nozi->sezione * 4)) % 3 == 0))
	{
		update_define(punt_a, punt_b, &def);
		if ((def.st <= nozi->check && (nozi->inti - (nozi->sezione * 4)) % 3
				!= 0) || (def.st < nozi->check && (nozi->inti - (nozi->sezione
						* 4)) % 3 == 0))
			pb(punt_a, punt_b);
		else
		{
			if ((def.nd < def.st && def.st < def.rd)
				|| (def.end < def.nd && def.nd < def.st))
				sa(punt_a);
			else if (def.end < nozi->check
				&& (def.st < def.nd && def.end < def.st))
				rra(punt_a);
			else
				ra(punt_a);
		}
	}
}
