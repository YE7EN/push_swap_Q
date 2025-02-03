/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qumiraud <qumiraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:48:04 by qumiraud          #+#    #+#             */
/*   Updated: 2025/01/31 17:14:09 by qumiraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"




/*
void bestmove_in_top_b(t_stack **stack_b, int move)
{
    t_stack *nav;
    int i = 0;

    nav = *stack_b;
    while (nav->bestmove != 1)
    {
        i++;
        nav = nav->next;
    }

    if (i <= ft_stacksize(*stack_b) / 2)
    {
        while (move > 0 && (*stack_b)->bestmove != 1)
        {
            rotate_b(stack_b);
            move--;
        }
    }
    else
    {
        while (move > 0 && (*stack_b)->bestmove != 1)
        {
            reverse_rotate_b(stack_b);
            move--;
        }
    }

    while ((*stack_b)->bestmove != 1)
        rotate_b(stack_b);
}





void bestmove_in_top_a(t_stack **stack_a, int *move)
{
    t_stack *nav;
    int i = 0;

    nav = *stack_a;
    while (nav->bestmove != 1)
    {
        i++;
        nav = nav->next;
    }

    if (i <= ft_stacksize(*stack_a) / 2)
    {
        while ((*move) > 0 && (*stack_a)->bestmove != 1)
        {
            rotate_a(stack_a);
            (*move)--;
        }
    }
    else
    {
        while ((*move) > 0 && (*stack_a)->bestmove != 1)
        {
            reverse_rotate_a(stack_a);
            (*move)--;
        }
    }

    while ((*stack_a)->bestmove != 1)
        rotate_a(stack_a);
}

*/


void bestmove_in_top(t_stack **stack, int move, int is_stack_a)
{
    t_stack *nav;
    int i = 0;

    // Trouver l'élément avec bestmove == 1
    nav = *stack;
    while (nav->bestmove != 1)
    {
        i++;
        nav = nav->next;
    }

    // Déterminer la taille de la pile
    int stack_size = ft_stacksize(*stack);

    // Si le meilleur mouvement est dans la première moitié
    if (i <= stack_size / 2)
    {
        while ((move) > 0 && (*stack)->bestmove != 1)
        {
            if (is_stack_a)
                rotate_a(stack);  // Rotation pour stack_a
            else
                rotate_b(stack);  // Rotation pour stack_b
            (move)--;
        }
    }
    // Si le meilleur mouvement est dans la deuxième moitié
    else
    {
        while ((move) > 0 && (*stack)->bestmove != 1)
        {
            if (is_stack_a)
                reverse_rotate_a(stack);  // Reverse rotation pour stack_a
            else
                reverse_rotate_b(stack);  // Reverse rotation pour stack_b
            (move)--;
        }
    }

    // Finaliser le déplacement du meilleur mouvement vers le sommet de la pile
    while ((*stack)->bestmove != 1)
    {
        if (is_stack_a)
            rotate_a(stack);  // Final rotation pour stack_a
        else
            rotate_b(stack);  // Final rotation pour stack_b
    }
}


/*

void	bestmove_in_top_b(t_stack **stack_b, t_stack **stack_a, int move)
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
	if (i > ft_stacksize(*stack_b)/2 && move >= ft_stacksize(*stack_b)/2)
	{
		while (move > 0 && (*stack_b)->bestmove != 1)
		{
			reverse_rotate_rotate(stack_b, stack_a);
			move--;
		}
		while ((*stack_b)->bestmove != 1)
			reverse_rotate_b(stack_b);
	}
	if (i <= ft_stacksize(*stack_b)/2)
	{
		while ((*stack_b)->bestmove != 1)
			rotate_b(stack_b);
	}
}

*/


/*

void	bestmove_in_top_a(t_stack **stack_a, t_stack **stack_b, int *move)
{
	t_stack	*nav;
	int		i;

	i = 0;
	nav = (*stack_a);
	while (nav->bestmove != 1)
	{
		i++;
		nav = nav->next;
	}
	if (i > ft_stacksize(*stack_a)/2 && (*move) >= ft_stacksize(*stack_b)/2 )
	{
		//move = ft_stacksize(*stack_b) - move;
		while ((*move) >= 0 && (*stack_a)->bestmove != 1)
		{
			reverse_rotate_rotate(stack_a, stack_b);
			(*move)--;
		}
		while ((*stack_a)->bestmove != 1)
			reverse_rotate_a(stack_a);
	}
	if (i <= ft_stacksize(*stack_a)/2)
	{
		while ((*move) > 0 &&  (*stack_a)->bestmove != 1)
		{
			rotate_rotate(stack_a, stack_b);
			(*move)--;
		}
		while ((*stack_a)->bestmove != 1)
			rotate_a(stack_a);
	}
}

*/

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
	near = 2147483647;
	nav = stack;
	nav->proxi = 0;

	while (nav)
	{
		// if (nav->nbr > ref)////////////////////////////////////////////////////////////////
		if (nav->nbr > ref && nav->nbr < near)
		{
			//if (nav->nbr < near)////////////////////////////////////////////////////////////
			//{
			if (reset)
				reset->proxi = 0;
			near = nav->nbr;
			nav->proxi = 1;
			reset = nav;
			//}
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

	t_stack	*nav_a;
	t_stack	*nav_b;
	t_stack	*reset;

	k = 0;
	nav_a = (*stack_a);
	nav_b = stack_b;
	reset = NULL;
	size_b = ft_stacksize(stack_b);
	i = 0;
	j = size_b + ft_stacksize(nav_a);
	while (nav_a && k <= size_b / 4)
	{
		i = 0;
		nav_b = stack_b;
		while (nav_b)
		{
			search_proxi(nav_a->nbr, stack_b);
			if (nav_a->nbr < nav_b->nbr  && nav_a->nbr > ft_find_min(nav_b) && nav_b->proxi == 1)
				break;
			else if (nav_a->nbr > ft_find_max(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
				break;
			else if (nav_a->nbr < ft_find_min(nav_b) && ft_stacklast(nav_b)->nbr == ft_find_max(nav_b))
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




void ft_over_five(t_stack **stack_a, int size_a)
{
    t_stack *stack_b = NULL;
    int size_b;
    int move = 0;

    push_b(stack_a, &stack_b);
    push_b(stack_a, &stack_b);
    size_a -= 2;

    while (size_a >= 3)
    {
        size_b = ft_stacksize(stack_b);
        move = ft_cheapest_move(stack_a, stack_b);
        bestmove_in_top(stack_a, move, 1);

        
        if (move < size_b / 2)
        {
            while (move > 0)
            {
                rotate_b(&stack_b);
                move--;
            }
        }
        else
        {
            move = size_b - move;
            while (move > 0)
            {
                reverse_rotate_b(&stack_b);
                move--;
            }
        }

        push_b(stack_a, &stack_b);
        size_a--;
    }

    ft_for_three(stack_a, ft_stacklast(*stack_a));

    reset_bestmove(&stack_b);

    while (ft_stacksize(stack_b) > 0)
    {
        size_a = ft_stacksize(*stack_a);
        move = ft_cheapest_move(&stack_b, *stack_a);
        bestmove_in_top(&stack_b, move, 0);

        if (move <= size_a / 2)
        {
            while (move > 0)
            {
                rotate_a(stack_a);
                move--;
            }
        }
        else
        {
            move = size_a - move;
            while (move > 0)
            {
                reverse_rotate_a(stack_a);
                move--;
            }
        }

        push_a(stack_a, &stack_b);
    }

    while ((*stack_a)->nbr != ft_find_min(*stack_a))
        rotate_a(stack_a);
}


/*

void	ft_over_five(t_stack **stack_a, int size_a)
{
	t_stack	*stack_b;
	int		size_b;
	int		move;

	move = 0;
	stack_b = NULL;
	
	push_b(stack_a, &stack_b);
	push_b(stack_a, &stack_b);
	size_a = size_a - 2;
	while (--size_a >= 3)
	{
		size_b = ft_stacksize(stack_b);
		move =ft_cheapest_move(stack_a, stack_b);
		if (move < size_b/2)
		{
			bestmove_in_top_a(stack_a, &move);
			while (move > 0 )
			{
					rotate_b(&stack_b);
					move --;
			}
		}
		else
		{
			bestmove_in_top_a(stack_a, &move);
			move = size_b - (move);
			while (move > 0)
			{
				reverse_rotate_b(&stack_b);
				move --;
			}
		}
		push_b(stack_a, &stack_b);
	}
	
	ft_for_three(stack_a, ft_stacklast(*stack_a));
	reset_bestmove(&stack_b);
	

	while (ft_stacksize(stack_b) > 0)
	{
		size_a = ft_stacksize(*stack_a);
		move =ft_cheapest_move(&stack_b, (*stack_a));
		bestmove_in_top_b(&stack_b, move);
		if (move <= size_a/2)
		{
			while (move > 0 )
			{
					rotate_a(stack_a);
					move --;
			}
		}
		else
		{
			move = size_a - (move);
			while (move > 0)
			{
				reverse_rotate_a(stack_a);
				move --;
			}
		}
		push_a(stack_a, &stack_b);
	}
	while ((*stack_a)->nbr != ft_find_min((*stack_a)))
		rotate_a(stack_a);
//	if (ft_good_order(*stack_a) == 0)
//	{
//		ft_over_five(stack_a, size_a);
//	}
	
	return;
}

*/











