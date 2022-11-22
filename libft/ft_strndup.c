/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:56:13 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:56:17 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	if (len < n)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n && s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
