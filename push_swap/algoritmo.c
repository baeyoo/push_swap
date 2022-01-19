/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:25:03 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:25:04 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algoritmo(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int	sezione;
	int	check_testa;
	int	check_coda;

	sezione = inti / 5;
	check_testa = support[sezione];
	check_coda = support[sezione * 3 - 1];
	algoritmo_00(punt_a, punt_b, support, inti);
	algoritmo_0(punt_a, punt_b, support, inti);
	ritmo_uno(punt_a, punt_b, support, inti);
	algoritmo_1(punt_a, support, inti);
	ritmo_unico(punt_a, punt_b, inti, support);
	algoritmo_2(punt_a, support, inti);
	ritmo_unico(punt_a, punt_b, inti, support);
	algoritmo_3(punt_a, support, inti);
	ritmo_unico(punt_a, punt_b, inti, support);
	algoritmo_4(punt_a, support, inti);
	ritmo_unico(punt_a, punt_b, inti, support);
	algoritmo_5(punt_a, support, inti);
}

void	algoritmo_00(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	t_def	def;
	int		sezione;
	int		check_testa;
	int		check_coda;

	sezione = inti / 5;
	check_testa = support[sezione];
	check_coda = support[sezione * 3 - 1];
	while (ft_lstsize(punt_b->head) <= (sezione * 2 - 1))
	{
		update_define(punt_a, punt_b, &def);
		if (def.st <= check_coda && def.st >= check_testa)
			supp_algoritmo2(punt_a, punt_b, support, inti);
		else
			supp_algoritmo(punt_a, punt_b, support, inti);
	}
}

void	algoritmo_0(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int		sezione;
	int		ultimo_a;
	t_def	def;

	sezione = inti / 5;
	while (ft_lstsize(punt_b->head) <= (sezione * 4 - 1))
	{
		update_define(punt_a, punt_b, &def);
		ultimo_a = ft_last(punt_a->head);
		if (def.st < support[sezione * 4])
			supp_pb_rb(punt_a, punt_b, support, inti);
		else
			supp_sa_rra_ra(punt_a, punt_b, support, inti);
	}
}
