/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaynes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:22:24 by khaynes           #+#    #+#             */
/*   Updated: 2021/10/25 12:58:37 by khaynes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(src);
	i = ft_strlen(dst);
	if (size > i && size > 0)
	{
		k = i + j;
		size = size - i - 1;
		j = 0;
		while (src[j] && size != 0)
		{
			dst[i++] = src[j++];
			size--;
		}
		dst[i] = '\0';
	}
	else
		k = size + j;
	return (k);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[j] != '\0')
		j++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	if (!str || len <= 0)
		return (NULL);
	if (start < ft_strlen(str))
		num = ft_strlen(str) - (size_t)start;
	if (len < num)
		num = len;
	p = (char *)malloc((num + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (num && start < ft_strlen(str))
	{
		p[i] = ((char *)str)[start + i];
		i++;
		num--;
	}
	p[i] = '\0';
	return (p);
}
