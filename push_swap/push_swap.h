/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:28:20 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:28:22 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define	MAX 2147483647
# define	MIN -2147483648

typedef struct s_nozi{
	int		inter;
	int		intero;
	int		inti;
	int		check;
	int		nodi;
	int		sezione;
}				t_nozi;

typedef struct s_def{
	int		st;
	int		nd;
	int		rd;
	int		end;
	int		st_b;
	int		nd_b;
	int		rd_b;
	int		end_b;
}				t_def;

typedef struct s_define{
	int		primo;
	int		secondo;
	int		terzo;
	int		primo_b;
	int		secondo_b;
	int		terzo_b;
}				t_define;

typedef struct s_segna{
	int		low;
	int		lower;
	int		cont;
}				t_segna;

typedef struct s_list{
	int			 	numero;
	struct s_list	*next;
}				t_list;

typedef struct s_punt{
	int				couple;
	int				size;
	struct s_list	*head;
	struct s_list	*tail;
}				t_punt;

//algoritmo
void	algoritmo(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	ritmo_uno(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	ritmo_due(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	ritmo_tre(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	ritmo_quattro(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	ritmo_cinque(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	algoritmo_00(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	algoritmo_0(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
//algoritmo_continue
void	algoritmo_1(t_punt *punt_a, int *support, int inti);
void	algoritmo_2(t_punt *punt_a, int *support, int inti);
void	algoritmo_3(t_punt *punt_a, int *support, int inti);
void	algoritmo_4(t_punt *punt_a, int *support, int inti);
void	algoritmo_5(t_punt *punt_a, int *support, int inti);
//supp_algoritmo
void	supp_algoritmo(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	supp_algoritmo2(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	supp_pb_rb(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	supp_sa_rra_ra(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
//ritmo
void	ritmo(t_punt *punt_a, t_punt *punt_b, int *support, int intero);
void	ritmo_unico(t_punt *punt_a, t_punt *punt_b, int inti, int *support);
int		ritmo_tres(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi);
void	ritmo_terzo(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi);
void	ritmo_dos(t_punt *punt_a, int *support, t_nozi *nozi);
void	ritmo_secon(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi);
void	ritmo_primo(t_punt *punt_a, t_punt *punt_b, t_nozi *nozi);
void	ritmo_uno(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
//algo
void	update_define(t_punt *punt_a, t_punt *punt_b, t_def *def);
void	algo1(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
void	algo2(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi);
void	algo3(t_punt *punt_a, t_punt *punt_b, int *support, t_nozi *nozi);
void	algo(t_punt *punt_a, t_punt *punt_b, int *support, int inti);
//five
int		pushfive(t_punt *punt_a, t_punt *punt_b);
void	fill_segnalino(t_punt *punt_a, t_segna *segnalino);
//tree
int		pos_max_three(t_list *lst);
int		pos_min_three(t_list *lst);
int		pushtree(t_punt *puntatore);
void	mossa_tre(t_punt *punt_a);
//moves_quattro
void	sb2(t_punt *puntatore);
void	ra2(t_punt *puntatore);
void	rb2(t_punt *puntatore);
void	rra2(t_punt *puntatore);
void	rrb2(t_punt *puntatore);
//moves_tre
void	pa(t_punt *punt_a, t_punt *punt_b);
void	pb(t_punt *punt_a, t_punt *punt_b);
//moves_due
void	rr(t_punt *punt_a, t_punt *punt_b);
void	rra(t_punt *puntatore);
void	rrb(t_punt *puntatore);
void	rrr(t_punt *punt_a, t_punt *punt_b);
void	sa2(t_punt *puntatore);
//moves
void	sa(t_punt *puntatore);
void	sb(t_punt *puntatore);
void	ss(t_punt *punt_a, t_punt *punt_b);
void	ra(t_punt *puntatore);
void	rb(t_punt *puntatore);
//two
void	uscita(t_punt *punt);
void	uscita1(t_punt *punt, int *support);
int		*filler(t_list *lst, int a);
int		push_two(t_list **lst, char **str, int **support);
//utils_due
int		ft_nodi(t_list *list_b, int intero, int inter);
int		check_ordine(t_punt *puntatore);
int		consecutive(int *support, int a, int b);
int		ft_strcomp(char c, char *str);
//utils
int		ft_isdigit(char *str);
long	ft_atoi(const char *str);
void	quicksort(int *a, int primo, int ultimo);
int		ft_last(t_list *lst);
int		ft_lstsize(t_list *lst);
//main
void	fill_list(t_list **lst, int valore);
void	fill_lista(t_list **lst, int valore);
void	fill_array(t_list **lst, char *argv[], int *support, int a);
int		main(int argc, char *argv[]);
int		switch_(t_punt *puntatore_a, t_punt *puntatore_b, int *support, int a);
void	main_dos(t_punt *puntatore_a, t_punt *puntatore_b, int *support, int a);

void	ft_free(t_punt *punt);

#endif
