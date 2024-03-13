/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:45:51 by yichan            #+#    #+#             */
/*   Updated: 2024/03/13 18:46:23 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	// if (!s)
	// 	return ;
	ft_printf(RED);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_printf(RESET);
	ft_putchar_fd('\n', fd);
}
