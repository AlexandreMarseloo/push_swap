#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>

//file push_swap.c

void	ft_sort(t_list **stack_a, t_list **stack_b);
void	sort_little_stack(t_list **stack_a);
void	sort_medium_stack(t_list **stack_a, t_list **stack_b);

//file operation.c

void	ft_push(t_list **src, t_list **dst, char *str);
void	ft_swap(t_list **stack, char *str);
void	ft_rotate(t_list **stack, char *str);
void	ft_rev_rotate(t_list **stack, char *str);

//file utils.c

void	ft_exit(int code, t_list **stack_a, t_list **stack_b);
void	parse_arg(char **av, int ac, t_list **stack_a);
int	is_sorted(t_list *stack);
void	ft_split_stack(t_list **stack_a, t_list **stack_b);

//file tests.c

int	is_number(char *arg);
int	is_int(long long nb);
int	has_doublon(t_list *stack);
int	is_closer_to_top(t_list *lst, int n);

//file radix_sort.c

void	sort_big_stack(t_list **stack_a, t_list **stack_b);
void	ft_bubble_sort(int *tab, int size);
void	ft_fill_tab(int	*tab, t_list **stack_a);
void	ft_sort_rank(t_list **stack_a, int size);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b,  int max_bits, int size);
#endif
