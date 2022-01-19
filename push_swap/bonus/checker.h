/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:19:58 by mobrycki          #+#    #+#             */
/*   Updated: 2021/05/29 12:24:32 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define	MAX 2147483647
# define	MIN -2147483648

typedef struct s_punt{
	int				couple;
	int				size;
	struct s_list	*head;
	struct s_list	*tail;
}				t_punt;

typedef struct s_list{
	int			 	numero;
	struct s_list	*next;
}				t_list;

//doppini
void	doppini(t_punt *punt_a);
int		ft_lstsize(t_list *lst);
//gnl
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strchr(char c, char *str);
char	*ft_support_get_n_line(char *total, char string[2]);
int		get_next_line(char **line, int fd, t_punt *a, t_punt *b);
//push
int		ft_isdigit(char *str);
long	ft_atoi(const char *str);
void	fill_listaa(t_list **lst, char *argv[], int a);
//push_two
long	conversione(char **str);
void	fill_lista(t_list **lst, int valore);
int		push(t_list **lst, char **str);
//utils
void	ft_free(t_punt *punt);
void	uscita(t_punt *punt);
char	*ft_strdup(char *str);
int		ft_strcomp(char c, char *str);
int		check_ordine(t_punt *puntatore, t_punt *punt);
//moves
void	rra(t_punt *puntatore);
void	rrb(t_punt *puntatore);
void	rr(t_punt *punt_a, t_punt *punt_b);
void	rrr(t_punt *punt_a, t_punt *punt_b);
//moves_2
void	sa(t_punt *puntatore);
void	sb(t_punt *puntatore);
void	ra(t_punt *puntatore);
void	rb(t_punt *puntatore);
void	ss(t_punt *punt_a, t_punt *punt_b);
//moves_3
void	pa(t_punt *punt_a, t_punt *punt_b);
void	pb(t_punt *punt_a, t_punt *punt_b);
//checker
int		main (int argc, char *argv[]);
int		ritorno(char *line, t_punt *puntatore_a, t_punt *puntatore_b);

#endif
