#include "push_swap.h"

void	supp_algoritmo2(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int		sezione;
	int		check_testa;
	int		check_coda;
	t_def	def;

	sezione = inti / 5;
	check_testa = support[sezione];
	check_coda = support[sezione * 3 - 1];
	update_define(punt_a, punt_b, &def);
	if (def.st <= check_coda && def.st >= check_testa)
	{
		pb(punt_a, punt_b);
		update_define(punt_a, punt_b, &def);
		if (def.st_b > check_testa && def.st_b < support[sezione * 2 - 1])
			rb(punt_b);
	}
}

void	supp_algoritmo(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int		ultimo_a;
	int		sezione;
	int		check_testa;
	t_def	def;

	sezione = inti / 5;
	check_testa = support[sezione];
	ultimo_a = ft_last(punt_a->head);
	update_define(punt_a, punt_b, &def);
	if ((def.nd < def.st && def.st < def.rd)
		|| (ultimo_a < def.nd && def.nd < def.st))
		sa(punt_a);
	else if (ultimo_a > check_testa && ultimo_a < support[sezione * 2 - 1]
		&& (def.st < def.nd && ultimo_a < def.st))
		rra(punt_a);
	else
		ra(punt_a);
}

void	supp_pb_rb(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int		sezione;
	int		check_testa;
	t_def	def;

	sezione = inti / 5;
	check_testa = support[sezione];
	pb(punt_a, punt_b);
	update_define(punt_a, punt_b, &def);
	if (def.st_b < check_testa)
		rb(punt_b);
}

void	supp_sa_rra_ra(t_punt *punt_a, t_punt *punt_b, int *support, int inti)
{
	int		ultimo_a;
	int		sezione;
	int		check_testa;
	t_def	def;

	sezione = inti / 5;
	check_testa = support[sezione];
	ultimo_a = ft_last(punt_a->head);
	update_define(punt_a, punt_b, &def);
	if ((def.nd < def.st && def.st < def.rd)
		|| (ultimo_a < def.nd && def.nd < def.st))
		sa(punt_a);
	else if (ultimo_a < check_testa && (def.st < def.nd && ultimo_a < def.st))
		rra(punt_a);
	else
		ra(punt_a);
}
