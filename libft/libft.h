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

typedef	struct	s_stack
{
	struct	s_list	*first;
}				t_stack;

typedef struct	s_list
{
	int		content;
	int		rank;
	struct s_list	*next;
}				t_list;
int		ft_atoi(const char *str);
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
#endif
