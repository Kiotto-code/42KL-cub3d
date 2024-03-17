/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:58:30 by yichan            #+#    #+#             */
/*   Updated: 2024/03/14 15:45:29 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	main(void)
// {
// 	char	*str = ft_strdup("USER");
// 	const char	*old = ft_strdup("USER");
// 	const char	*new = ft_strdup("yichan");
// 	char *testing = ft_strdup("TESTING");

// 	ft_replace(&str , old, new, 0);
// 	// // ft_is_all_space((char *)str);
// 	ft_printf("endresult : %s\n", str);
// 	ft_free(testing);
// }

// void	ft_print_arr(char **arr, char *prompt)
// {
// 	size_t	i;

// 	i = 0;
// 	printf(BLUE"CHECKING: %s\n"RESET, prompt);
// 	while (arr[i])
// 	{
// 		// printf("%s\t: ", prompt);
// 		// fflush(stdout);
// 		ft_putendl_fd(arr[i], 1);
// 		i++;
// 	}
// }

int main()
{
	char *str = ft_strdup("k");
	// ft_replace_all(&str, "\t", " ", 0);
	ft_replace_all(&str, "o", "k", 0);
	// char *ret = ft_remove(str, ' ');
	printf("ret : %s\n", str);
	system("leaks -q debugrun");
	return (0);
}

// int main()
// {
// 	char *str1[10];
	
// 	// ft_print_arr(str);
// 	str1[0] = ft_strdup("hello world");
// 	char **str2 = ft_duparr(str1);
// 	ft_print_arr(str2);
// }