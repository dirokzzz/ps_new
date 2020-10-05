#include <stdlib.h>
#include <stdio.h>
#include "ps_src/checker.h"


void ft_clearstr_stack(t_tab *s)
{
	char *ptr;

	ptr = s->message;
	char *str;
    while (*ptr != '\0')
    {
        if (ft_strncmp(ptr, "pa\npb\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "pb\npa\n", 6) == 0)
        {
            ft_strcpy(ptr, (ptr + 6));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "\nrb\nrrb", 7) == 0)
        {
            ft_strcpy(ptr, (ptr + 7));
            ptr = s->message;
        }
        else if (ft_strncmp(ptr, "ra\nrb\n", 4) == 0)
        {
			str = ft_strdup(ptr + 6);
            ft_strcpy(ptr, "rr\n");
			ptr = s->message;
			ptr = ft_strjoin_f(ptr, str, 1);
			s->message = ptr;
        }
        else
            ptr++;
    }
}

int main()
{
	t_tab *a;

	a = malloc(sizeof(t_tab));
	a->message = ft_strdup("!!!!!!!!!!!ra\nrb\n!!!!!!!!!!");
	ft_clearstr_stack(a);
	printf("%s\n", a->message);
	free(a->message);
	free(a);
}