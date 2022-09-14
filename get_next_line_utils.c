/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtortrot <mtortrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:28:37 by mtortrot          #+#    #+#             */
/*   Updated: 2022/09/12 09:59:50 by mtortrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s++))
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = (int) ft_strlen(s1) + 1;
	s2 = malloc(sizeof (char) * len);
	if (s2 == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*str;

	len = 0;
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !str)
		return (NULL);
	while (s1[len])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free ((char *)s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}


size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(src);
	if (size)
		while (++i < (size - 1) && len && src[i])
			dest[i] = src[i];
	dest[i] = '\0';
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;

	n = ft_strlen(s);
	if (start > n)
		return (ft_strdup(""));
	else if (start + len > n)
		len = n - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
