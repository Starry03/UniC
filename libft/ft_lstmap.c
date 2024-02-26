/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:33:11 by astarran          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:12 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*start;
	t_list	*prev;
	char	is_start;

	is_start = 1;
	if (!lst || !f || !del)
		return (NULL);
	prev = NULL;
	while (lst)
	{
		head = (t_list *) malloc(sizeof(struct s_list));
		if (!head)
			return (NULL);
		if (is_start)
			start = head;
		is_start = 0;
		head->content = f(lst->content);
		head->next = NULL;
		if (prev)
			prev->next = head;
		prev = head;
		lst = lst->next;
	}
	return (start);
}
