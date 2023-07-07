# include "libft.h"

int main()
{
    char *str = ft_strdup("hello world asd");
    char *old = ft_strdup("rld");
    char *new = ft_strdup("FOIFDCUIXCUIFCIUGFCGHUIGFCGHUFCGUYFCd");
    ft_replace(&str, old, new);
    ft_printf("endresult : %s\n", str);

    // char *str = ft_strdup("aadasdfgfsfd");
    // int i = 0;
    // while (ft_strlead(&(str[i]), "das"))
    //     i++;

    // printf("%d\n", i);
}