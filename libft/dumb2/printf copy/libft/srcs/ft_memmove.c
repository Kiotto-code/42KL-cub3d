/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:53:41 by yichan            #+#    #+#             */
/*   Updated: 2022/07/07 11:09:25 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	temp = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = temp[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = temp[n];
	}
	return (dest);
}
