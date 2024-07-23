/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotom <arakotom@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:28:35  by arakotom          #+#    #+#             */
/*   Updated: 2024/07/23 19:42:57 by arakotom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_stack
{
	int				val;
	int				index;
	int				push_cost;
	int				above_med;
	int				best_node;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				ft_free_stack(t_stack **stack);
t_stack				*new_node(int nbr);
t_stack				*last_node(t_stack **stack);
t_stack				*max_node(t_stack *stack);
t_stack				*min_node(t_stack *stack);
t_stack				*best_node(t_stack *stack);
int					stack_len(t_stack *stack);
int					is_stack_sorted(t_stack **stack);
void				add_stack(t_stack **stack, int nbr);
void				set_curr_index(t_stack **stack);
void				print_stack(t_stack **stack, char name, int free_stack);
int					syntax_error(char *nbr);
int					range_error(long nbr);
int					duplicate_error(t_stack **stack, int nbr);
void				error_exit(t_stack **stack, char **str, int free_str);
void				init_sort(t_stack **a, t_stack **b);
void				init_a(t_stack **stack, char **argv, int free_argv);
void				init_stack_a(t_stack **a, t_stack **b);
void				init_stack_b(t_stack **a, t_stack **b);
void				move_to_top(t_stack **stack, char name, t_stack *top_node);
void				move_a_to_b(t_stack **a, t_stack **b);
void				move_min_to_top(t_stack **stack, char name);
void				move_b_to_a(t_stack **a, t_stack **b);
#endif