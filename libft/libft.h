/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 13:31:35 by almarsel          #+#    #+#             */
/*   Updated: 2021/07/15 09:46:01 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int		data;
	int		rank;
	struct s_list	*next;
}				t_list;
void		ft_putchar(char c);
void		ft_putstr(char *str);
int		ft_isdigit(char c);
long long	ft_atoll(const char *str);
int		ft_strcmp(char *str0, char *str1);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(int));
int		ft_lstget_min(t_list *lst);
int		ft_lstget_max(t_list *lst);
void		ft_lstswap(t_list *lst0, t_list *lst1);
#endif
