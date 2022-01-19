/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ritmo_supp_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:29:39 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:29:41 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_capo_coda(int inti, t_punt *punt_b, int *capo, int *coda)
{
	int		sezione;
	int		elle;

	elle = ft_lstsize(punt_b->head);
	sezione = inti / 5;
	if (elle > (sezione * 3) && elle <= (sezione * 4))
	{
		*capo = (inti / 5) * 3;
		*coda = ((inti / 5) * 4 - 1);
	}
	else if (elle > (sezione * 2) && elle <= (sezione * 3))
	{
		*capo = (inti / 5) * 2;
		*coda = ((inti / 5) * 3 - 1);
	}
	else if (elle > (sezione) && elle <= (sezione * 2))
	{
		*capo = (inti / 5);
		*coda = ((inti / 5) * 2 - 1);
	}
	else
	{
		*capo = 0;
		*coda = (inti / 5 - 1);
	}
}

void	ritmo_supp2(t_punt *punt_a, t_punt *punt_b, int capo, int coda)
{
	t_def	def;

	update_define(punt_a, punt_b, &def);
	pa(punt_a, punt_b);
	capo++;
	if (ft_nodi(punt_b->head, capo, coda)
		< (ft_lstsize(punt_b->head) / 2)
		&& (def.st_b != capo && def.st_b != coda))
	{
		ra(punt_a);
		rb(punt_b);
	}
	else
		ra(punt_a);
}

void	ritmo_supp3(t_punt *punt_a, t_punt *punt_b, int capo, int coda)
{
	int		nodi;
	t_def	def;

	update_define(punt_a, punt_b, &def);
	nodi = ft_nodi(punt_b->head, capo, coda);
	if (nodi < (ft_lstsize(punt_b->head) / 2))
	{
		while (def.st_b != capo && def.st_b != coda)
		{
			rb(punt_b);
			update_define(punt_a, punt_b, &def);
		}
	}
	else
	{
		while (def.st_b != capo && def.st_b != coda)
		{
			rrb(punt_b);
			update_define(punt_a, punt_b, &def);
		}
	}
}

void	ritmo_unico(t_punt *punt_a, t_punt *punt_b, int inti, int *support)
{
	int		capo;
	int		coda;
	t_def	def;

	init_capo_coda(inti, punt_b, &capo, &coda);
	while (capo <= coda)
	{
		update_define(punt_a, punt_b, &def);
		if (def.st_b == support[coda])
		{
			pa(punt_a, punt_b);
			coda--;
		}
		else if (def.st_b == support[capo])
		{
			ritmo_supp2(punt_a, punt_b, support[capo], support[coda]);
			capo++;
		}
		else
			ritmo_supp3(punt_a, punt_b, support[capo], support[coda]);
	}
}

void	ritmo_uno(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	t_nozi	nozi;

	nozi.nodi = ft_lstsize(punt_b->head);
	nozi.sezione = inti / 5;
	nozi.intero = (inti - (nozi.sezione * 4)) / 3;
	nozi.intero = (inti - (nozi.sezione * 4)) - nozi.intero;
	nozi.check = support[nozi.nodi + nozi.intero];
	nozi.inti = inti;
	ritmo_primo(punt_a, punt_b, &nozi);
	ritmo_secon(punt_a, punt_b, support, &nozi);
	nozi.intero--;
	nozi.inter = nozi.sezione * 4;
	ritmo_terzo(punt_a, punt_b, support, &nozi);
}
