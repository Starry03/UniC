/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astarran <astarran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:34:26 by astarran          #+#    #+#             */
/*   Updated: 2024/02/20 12:21:25 by astarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*addr;
	size_t	i;

	len = ft_strlen(s);
	addr = malloc(sizeof(char) * (len + 1));
	if (!addr)
		return (NULL);
	i = 0;
	ft_strlcpy(addr, s, len + 1);
	return (addr);
}
