/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:54:42 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 15:54:45 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_words(char **new_arr, size_t nb_of_words)
{
	size_t	i;

	i = 0;
	while (i < nb_of_words)
		free(new_arr[i++]);
	free(new_arr);
	return (0);
}

static size_t	word_count(char const *s, char sep)
{
	size_t	i;
	size_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (s[i])
	{
		if (s[i] == sep)
			nb_of_words++;
		i++;
	}
	if (s[i - 1] != '\n')
		nb_of_words++;
	return (nb_of_words);
}

static int	word_len(char const *s, char sep)
{
	size_t	len;

	len = 0;
	while (*s && *s != sep)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split_with_sep(char const *s, char c)
{
	int		i;
	size_t	size;
	size_t	w_len;
	char	**new_arr;

	if (s == NULL)
		return (NULL);
	size = word_count(s, c);
	new_arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (new_arr == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)size)
	{
		w_len = word_len(s, c);
		new_arr[i] = ft_strndup(s, w_len);
		if (new_arr[i] == NULL)
			return (free_words(new_arr, i), NULL);
		s += w_len + 1;
	}
	new_arr[i] = NULL;
	return (new_arr);
}
