/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:48:04 by qumiraud          #+#    #+#             */
/*   Updated: 2025/02/04 19:02:05 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bestmove_in_top_b_big(t_stack **stack_b, t_stack **stack_a, int *move)
{
	t_stack	*nav;
	int		i;
	int	size_a;
	int	size_b;


	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	i = 0;
	nav = (*stack_b);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if ((*move) > size_a / 2)
		(*move) = size_a - (*move);
	if (i > size_b / 2 )
	{
		i = size_b - i;
		while ((*move) > 0 && i > 0)
		{
			reverse_rotate_rotate(stack_a, stack_b);
			(*move)--;
			i--;
		}
		while (i > 0)
		{
			reverse_rotate_b(stack_b);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			rotate_b(stack_b);
			i--;
		}
	}

}
void	bestmove_in_top_b_little(t_stack **stack_b, t_stack **stack_a, int *move)
{
	t_stack	*nav;
	int		i;

	i = 0;
	nav = (*stack_b);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}

	if (i > ft_stacksize(*stack_b)/2)
	{
		i = ft_stacksize(*stack_b) - i;
		while ((*move) > 0 && i > 0)
		{
			rotate_rotate(stack_b, stack_a);
			(*move)--;
			i--;
		}
		while ((*stack_b)->bestmove != 1)
			rotate_b(stack_b);
	}
	while (i > 0)
	{
		rotate_b(stack_b);
		i--;
	}
}

void	bestmove_in_top_a_big(t_stack **stack_a, t_stack **stack_b, int *move)
{
	t_stack	*nav;
	int		i;
	int		size_a;
	int		size_b;

	i = 0;
	nav = (*stack_a);
	//printf ("coucou\n");
	
	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);

	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	//printf("coucou, i = %d et move = %d\n", i, (*move));
	if ((*move) > size_b/2)
		(*move) = size_b - (*move);
	if (i > size_a/2 )
	{
		i = size_a - i;
		while ((*move) > 0 && i > 0)
		{
			reverse_rotate_rotate(stack_a, stack_b);
			(*move)--;
			i--;
		}
		while (i > 0)
		{
			reverse_rotate_a(stack_a);
			i--;
		}
	}
	else if (i <= size_a/2)
	{
		while (i > 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
}
void	bestmove_in_top_a_little(t_stack **stack_a, t_stack **stack_b, int *move)
{
	t_stack	*nav;
	int		i;
	int	size_a = ft_stacksize(*stack_a);
	int	size_b = ft_stacksize(*stack_b);

	i = 0;
	nav = (*stack_a);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if ((*move) <= size_b/2)
	{
		while ((*move) > 0 && i > 0)
		{
			rotate_rotate(stack_a,stack_b);
			(*move)--;
			i--;
		}
	}
	// rotation pour les pb
	while (i > 0)
	{
		// write (1, "asd\n",4);
		if(i < size_a/2)
			rotate_a(stack_a);
		else
		{
			i = size_a - i;
			while (i > 0)
			{
				reverse_rotate_a(stack_a);
				i--;
			}
			break;
		}
		i--;
	}
}

void	reset_bestmove(t_stack **stack)
{
	t_stack	*nav;

	nav = (*stack);
	while (nav)
	{
		if (nav->bestmove == 1)
			nav->bestmove = 0;
		if (nav->proxi == 1)
			nav->proxi = 0;
		nav = nav->next;
	}

}
void	search_proxi(int ref, t_stack *stack)
{
	t_stack		*nav;
	t_stack		*reset;
	int			near;

	reset = NULL;
	near = -2147483648;
	nav = stack;
	nav->proxi = 0;

	while (nav)
	{

		if (nav->nbr < ref && nav->nbr > near)
		{
			if (reset)
				reset->proxi = 0;
			near = nav->nbr;
			nav->proxi = 1;
			reset = nav;
		}
		nav = nav->next;
	}
}

void	search_proxi_for_return(int ref, t_stack *stack)
{
	t_stack		*nav;
	t_stack		*reset;
	int			near;

	reset = NULL;
	near = 2147483647;
	nav = stack;
	nav->proxi = 0;

	while (nav)
	{

		if (nav->nbr > ref && nav->nbr < near)
		{
			if (reset)
				reset->proxi = 0;
			near = nav->nbr;
			nav->proxi = 1;
			reset = nav;
		}
		nav = nav->next;
	}
}

int	ft_cheapest_move(t_stack **stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		size_b;
	int		k;

	int	min_b;
	int	max_b;

	t_stack	*nav_a;
	t_stack	*nav_b;
	t_stack	*reset;

	k = 0;
	nav_a = (*stack_a);
	nav_b = stack_b;
	reset = NULL;
	size_b = ft_stacksize(nav_b);
	min_b = ft_find_min(stack_b);
	max_b = ft_find_max(stack_b);
	i = 0;
	j = size_b + ft_stacksize(nav_a) * 2;
	while (nav_a && k <= size_b / 4)
	{
		i = 0;
		nav_b = stack_b;
		while (nav_b)
		{
			search_proxi(nav_a->nbr, stack_b);
			if (nav_a->nbr > nav_b->nbr  && nav_a->nbr > min_b && nav_b->proxi == 1)
				break;
			else if (nav_a->nbr > max_b && nav_b->nbr == max_b)
				break;
			else if (nav_a->nbr < min_b && nav_b->nbr == max_b)
				break;
			i++;
			nav_b = nav_b->next;
		}
		nav_b->proxi = 0;
		if ( i < j)
		{
			j = i;
			if (reset)
				reset->bestmove = 0;
			nav_a->bestmove = 1;
			reset = nav_a;
			if (j <= 2)
				return (j);
		}
		nav_a = nav_a->next;
		k++;
	}
	return (j);
}

int	ft_cheapest_move_for_return(t_stack **stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		size_b;
	int		k;

	int	min_b;


	t_stack	*nav_a;
	t_stack	*nav_b;
	t_stack	*reset;

	k = 0;
	nav_a = (*stack_a);
	nav_b = stack_b;
	reset = NULL;
	size_b = ft_stacksize(nav_b);
	i = 0;
	j = size_b + ft_stacksize(nav_a) * 2;

	min_b = ft_find_min(stack_b);

	while (nav_a && k <= size_b / 4)
	{
		i = 0;
		nav_b = stack_b;
		while (nav_b)
		{
			search_proxi_for_return(nav_a->nbr, stack_b);
			if (nav_a->nbr < nav_b->nbr  && nav_a->nbr > min_b && nav_b->proxi == 1)
				break;
			else if (nav_a->nbr > ft_find_max(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
				break;
			else if (nav_a->nbr < min_b && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
				break;
			i++;
			nav_b = nav_b->next;
		}
		nav_b->proxi = 0;
		if ( i < j)
		{
			j = i;
			if (reset)
				reset->bestmove = 0;
			nav_a->bestmove = 1;
			reset = nav_a;
			if (j <= 2)
				return (j);
		}
		nav_a = nav_a->next;
		k++;
	}
	return (j);
}

int	min_posi(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a && stack_a->nbr != ft_find_min(stack_a))
	{
		i++;
		stack_a = stack_a->next;
	}
	if (i > ft_stacksize(stack_a)/2)
		return (1);
	else
		return (0);
}

void	ft_over_five(t_stack **stack_a, int size_a)
{
	t_stack	*stack_b;
	int		size_b;
	int		move;

	move = 0;
	stack_b = NULL;
	//********************** go_stack_b **************************************//
	push_b(stack_a, &stack_b);
	push_b(stack_a, &stack_b);
	size_a = size_a - 2;
	while (--size_a >= 3)
	{
		size_b = ft_stacksize(stack_b);
		move =ft_cheapest_move(stack_a, stack_b);
		if (move <= size_b/2)
		{
			bestmove_in_top_a_little(stack_a, &stack_b, &move);
			while (move > 0 )
			{
					rotate_b(&stack_b);
					move --;
			}
		}
		else
		{
			bestmove_in_top_a_big(stack_a, &stack_b, &move);
			while (move > 0)
			{
				reverse_rotate_b(&stack_b);
				move --;
			}
		}
		push_b(stack_a, &stack_b);
	}
	//********************** go_stack_b **************************************//
	ft_for_three(stack_a, ft_stacklast(*stack_a));
	reset_bestmove(&stack_b);
	//?*********************? go_ stack_a ?************************************?//

	while (ft_stacksize(stack_b) > 0)
	{
		size_a = ft_stacksize(*stack_a);
		move = ft_cheapest_move_for_return(&stack_b, (*stack_a));
		//ft_printstack((*stack_a), stack_b);

		//printf("after cheapestmove move value: %d\n", move);
		if (move <= size_a/2)
		{
			bestmove_in_top_b_little(&stack_b, stack_a, &move);
			while (move > 0 )
			{
					rotate_a(stack_a);
					move --;
			}
		}
		else
		{
			move = size_a - (move);
			//printf("after le after move value: %d\n", move);
			bestmove_in_top_b_big(&stack_b, stack_a, &move);
			while (move > 0)
			{
				reverse_rotate_a(stack_a);
				move --;
			}
		}
		push_a(stack_a, &stack_b);
	}

	if (min_posi(*stack_a) == 0)
	{
		while ((*stack_a)->nbr != ft_find_min((*stack_a)))
		{
			rotate_a(stack_a);
		}
	}
	else
	{
		while ((*stack_a)->nbr != ft_find_min((*stack_a)))
			reverse_rotate_a(stack_a);
	}
	//?*********************? go_stack_a ?************************************?//
	
	
	
	// if (!ft_good_order(*stack_a))
	// {
	// 	ft_over_five(stack_a, ft_stacksize(*stack_a));
	// }
	return;
}






// void	bestmove_in_top_b_big(t_stack **stack_b, t_stack **stack_a, int *move)
// {
// 	t_stack	*nav;
// 	int		i;

// 	i = 0;
// 	nav = (*stack_b);
// 	while (nav->bestmove != 1)
// 	{
// 		i++;
// 		nav = nav->next;
// 	}
// 	if ((*move) > ft_stacksize(*stack_a)/2)
// 		(*move) = ft_stacksize(*stack_a) - (*move);
// 	if (i > ft_stacksize(*stack_b)/2 )
// 	{
// 		i = ft_stacksize(*stack_b) - i;
// 		while ((*move) > 0 && i > 0)
// 		{
// 			reverse_rotate_rotate(stack_a, stack_b);
// 			(*move)--;
// 			i--;
// 		}
// 		while (i > 0)
// 		{
// 			reverse_rotate_b(stack_b);
// 			i--;
// 		}
// 	}
// 	else if (i <= ft_stacksize(*stack_b)/2)
// 	{
// 		while (i > 0)
// 		{
// 			rotate_b(stack_b);
// 			i--;
// 		}
// 	}

// }
// void	bestmove_in_top_b_little(t_stack **stack_b, t_stack **stack_a, int *move)
// {
// 	t_stack	*nav;
// 	int		i;

// 	i = 0;
// 	nav = (*stack_b);
// 	while (nav->bestmove != 1)
// 	{
// 		i++;
// 		nav = nav->next;
// 	}

// 	if (i > ft_stacksize(*stack_b)/2)
// 	{
// 		i = ft_stacksize(*stack_b) - i;
// 		while ((*move) > 0 && i > 0)
// 		{
// 			rotate_rotate(stack_b, stack_a);
// 			(*move)--;
// 			i--;
// 		}
// 		while ((*stack_b)->bestmove != 1)
// 			rotate_b(stack_b);
// 	}
// 	while (i > 0)
// 	{
// 		rotate_b(stack_b);
// 		i--;
// 	}
// }

// void	bestmove_in_top_a_big(t_stack **stack_a, t_stack **stack_b, int *move)
// {
// 	t_stack	*nav;
// 	int		i;

// 	i = 0;
// 	nav = (*stack_a);
// 	//printf ("coucou\n");
// 	while (nav->bestmove != 1)
// 	{
// 		i++;
// 		nav = nav->next;
// 	}
// 	//printf("coucou, i = %d et move = %d\n", i, (*move));
// 	if ((*move) > ft_stacksize(*stack_b)/2)
// 		(*move) = ft_stacksize(*stack_b) - (*move);
// 	if (i > ft_stacksize(*stack_a)/2 )
// 	{
// 		i = ft_stacksize(*stack_a) - i;
// 		while ((*move) > 0 && i > 0)
// 		{
// 			reverse_rotate_rotate(stack_a, stack_b);
// 			(*move)--;
// 			i--;
// 		}
// 		while (i > 0)
// 		{
// 			reverse_rotate_a(stack_a);
// 			i--;
// 		}
// 	}
// 	else if (i <= ft_stacksize(*stack_a)/2)
// 	{
// 		while (i > 0)
// 		{
// 			rotate_a(stack_a);
// 			i--;
// 		}
// 	}
// }
// void	bestmove_in_top_a_little(t_stack **stack_a, t_stack **stack_b, int *move)
// {
// 	t_stack	*nav;
// 	int		i;

// 	i = 0;
// 	nav = (*stack_a);
// 	while (nav->bestmove != 1)
// 	{
// 		i++;
// 		nav = nav->next;
// 	}
// 	if ((*move) <= ft_stacksize(*stack_b)/2)
// 	{
// 		while ((*move) > 0 && i > 0)
// 		{
// 			rotate_rotate(stack_a,stack_b);
// 			(*move)--;
// 			i--;
// 		}
// 	}
// 	// rotation pour les pb
// 	while (i > 0)
// 	{
// 		// write (1, "asd\n",4);
// 		if(i < ft_stacksize(*stack_a)/2)
// 			rotate_a(stack_a);
// 		else
// 		{
// 			i = ft_stacksize(*stack_a) - i;
// 			while (i > 0)
// 			{
// 				reverse_rotate_a(stack_a);
// 				i--;
// 			}
// 		}
// 		i--;
// 	}
// }

// void	reset_bestmove(t_stack **stack)
// {
// 	t_stack	*nav;

// 	nav = (*stack);
// 	while (nav)
// 	{
// 		if (nav->bestmove == 1)
// 			nav->bestmove = 0;
// 		if (nav->proxi == 1)
// 			nav->proxi = 0;
// 		nav = nav->next;
// 	}

// }
// void	search_proxi(int ref, t_stack *stack)
// {
// 	t_stack		*nav;
// 	t_stack		*reset;
// 	int			near;

// 	reset = NULL;
// 	near = -2147483648;
// 	nav = stack;
// 	nav->proxi = 0;

// 	while (nav)
// 	{

// 		if (nav->nbr < ref && nav->nbr > near)
// 		{
// 			if (reset)
// 				reset->proxi = 0;
// 			near = nav->nbr;
// 			nav->proxi = 1;
// 			reset = nav;
// 		}
// 		nav = nav->next;
// 	}
// }

// void	search_proxi_for_return(int ref, t_stack *stack)
// {
// 	t_stack		*nav;
// 	t_stack		*reset;
// 	int			near;

// 	reset = NULL;
// 	near = 2147483647;
// 	nav = stack;
// 	nav->proxi = 0;

// 	while (nav)
// 	{

// 		if (nav->nbr > ref && nav->nbr < near)
// 		{
// 			if (reset)
// 				reset->proxi = 0;
// 			near = nav->nbr;
// 			nav->proxi = 1;
// 			reset = nav;
// 		}
// 		nav = nav->next;
// 	}
// }

// int	ft_cheapest_move(t_stack **stack_a, t_stack *stack_b)
// {
// 	int		i;
// 	int		j;
// 	int		size_b;
// 	int		k;

// 	t_stack	*nav_a;
// 	t_stack	*nav_b;
// 	t_stack	*reset;

// 	k = 0;
// 	nav_a = (*stack_a);
// 	nav_b = stack_b;
// 	reset = NULL;
// 	size_b = ft_stacksize(nav_b);
// 	i = 0;
// 	j = size_b + ft_stacksize(nav_a) * 2;
// 	while (nav_a && k <= size_b / 4)
// 	{
// 		i = 0;
// 		nav_b = stack_b;
// 		while (nav_b)
// 		{
// 			search_proxi(nav_a->nbr, stack_b);
// 			if (nav_a->nbr > nav_b->nbr  && nav_a->nbr > ft_find_min(nav_b) && nav_b->proxi == 1)
// 				break;
// 			else if (nav_a->nbr > ft_find_max(nav_b) && nav_b->nbr == ft_find_max(nav_b))
// 				break;
// 			else if (nav_a->nbr < ft_find_min(nav_b) && nav_b->nbr == ft_find_max(nav_b))
// 				break;
// 			i++;
// 			nav_b = nav_b->next;
// 		}
// 		nav_b->proxi = 0;
// 		if ( i < j)
// 		{
// 			j = i;
// 			if (reset)
// 				reset->bestmove = 0;
// 			nav_a->bestmove = 1;
// 			reset = nav_a;
// 			if (j <= 2)
// 				return (j);
// 		}
// 		nav_a = nav_a->next;
// 		k++;
// 	}
// 	return (j);
// }

// int	ft_cheapest_move_for_return(t_stack **stack_a, t_stack *stack_b)
// {
// 	int		i;
// 	int		j;
// 	int		size_b;
// 	int		k;

// 	t_stack	*nav_a;
// 	t_stack	*nav_b;
// 	t_stack	*reset;

// 	k = 0;
// 	nav_a = (*stack_a);
// 	nav_b = stack_b;
// 	reset = NULL;
// 	size_b = ft_stacksize(nav_b);
// 	i = 0;
// 	j = size_b + ft_stacksize(nav_a) * 2;
// 	while (nav_a && k <= size_b / 4)
// 	{
// 		i = 0;
// 		nav_b = stack_b;
// 		while (nav_b)
// 		{
// 			search_proxi_for_return(nav_a->nbr, stack_b);
// 			if (nav_a->nbr < nav_b->nbr  && nav_a->nbr > ft_find_min(nav_b) && nav_b->proxi == 1)
// 				break;
// 			else if (nav_a->nbr > ft_find_max(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
// 				break;
// 			else if (nav_a->nbr < ft_find_min(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
// 				break;
// 			i++;
// 			nav_b = nav_b->next;
// 		}
// 		nav_b->proxi = 0;
// 		if ( i < j)
// 		{
// 			j = i;
// 			if (reset)
// 				reset->bestmove = 0;
// 			nav_a->bestmove = 1;
// 			reset = nav_a;
// 			if (j <= 2)
// 				return (j);
// 		}
// 		nav_a = nav_a->next;
// 		k++;
// 	}
// 	return (j);
// }

// int	min_posi(t_stack *stack_a)
// {
// 	int	i;

// 	i = 0;
// 	while (stack_a && stack_a->nbr != ft_find_min(stack_a))
// 	{
// 		i++;
// 		stack_a = stack_a->next;
// 	}
// 	if (i > ft_stacksize(stack_a)/2)
// 		return (1);
// 	else
// 		return (0);
// }

// void	ft_over_five(t_stack **stack_a, int size_a)
// {
// 	t_stack	*stack_b;
// 	int		size_b;
// 	int		move;

// 	move = 0;
// 	stack_b = NULL;
// 	//********************** go_stack_b **************************************//
// 	push_b(stack_a, &stack_b);
// 	push_b(stack_a, &stack_b);
// 	size_a = size_a - 2;
// 	while (--size_a >= 3)
// 	{
// 		size_b = ft_stacksize(stack_b);
// 		move =ft_cheapest_move(stack_a, stack_b);
// 		if (move <= size_b/2)
// 		{
// 			bestmove_in_top_a_little(stack_a, &stack_b, &move);
// 			while (move > 0 )
// 			{
// 					rotate_b(&stack_b);
// 					move --;
// 			}
// 		}
// 		else
// 		{
// 			bestmove_in_top_a_big(stack_a, &stack_b, &move);
// 			while (move > 0)
// 			{
// 				reverse_rotate_b(&stack_b);
// 				move --;
// 			}
// 		}
// 		push_b(stack_a, &stack_b);
// 	}
// 	//********************** go_stack_b **************************************//
// 	ft_for_three(stack_a, ft_stacklast(*stack_a));
// 	reset_bestmove(&stack_b);
// 	//?*********************? go_ stack_a ?************************************?//

// 	while (ft_stacksize(stack_b) > 0)
// 	{
// 		size_a = ft_stacksize(*stack_a);
// 		move = ft_cheapest_move_for_return(&stack_b, (*stack_a));
// 		//ft_printstack((*stack_a), stack_b);

// 		//printf("after cheapestmove move value: %d\n", move);
// 		if (move <= size_a/2)
// 		{
// 			bestmove_in_top_b_little(&stack_b, stack_a, &move);
// 			while (move > 0 )
// 			{
// 					rotate_a(stack_a);
// 					move --;
// 			}
// 		}
// 		else
// 		{
// 			move = size_a - (move);
// 			//printf("after le after move value: %d\n", move);
// 			bestmove_in_top_b_big(&stack_b, stack_a, &move);
// 			while (move > 0)
// 			{
// 				reverse_rotate_a(stack_a);
// 				move --;
// 			}
// 		}
// 		push_a(stack_a, &stack_b);
// 	}

// 	if (min_posi(*stack_a) == 0)
// 	{
// 		while ((*stack_a)->nbr != ft_find_min((*stack_a)))
// 		{
// 			rotate_a(stack_a);
// 		}
// 	}
// 	else
// 	{
// 		while ((*stack_a)->nbr != ft_find_min((*stack_a)))
// 			reverse_rotate_a(stack_a);
// 	}
// 	//?*********************? go_stack_a ?************************************?//
	
	
	
// 	// if (!ft_good_order(*stack_a))
// 	// {
// 	// 	ft_over_five(stack_a, ft_stacksize(*stack_a));
// 	// }
// 	return;
// }
