#include "../includes/minishell.h"

int rotate_quotes_and_text(char *s, int i)
{
    int j;

    j = 0;
    while (s[i] != '<' && s[i] != '>' && s[i] != ' ' && (s[i]))
    {
        while (s[i] == 34 || s[i] == 39)
        {
            if (s[i] == 34 && ft_strchr(&s[i], 34) != NULL)
                while (s[++i] != 34)
                {}
            if (s[i] == 39 && ft_strchr(&s[i], 39) != NULL)
                while (s[++i] != 39)
                {}
            i++;
            j++;
        }
        if (j == 0)
            i++;
        j = 0;
    }
    return (i);
}

static int count_args(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == ' ')
            i++;
        if (s[i] == '>' || s[i] == '<')
        {
            while (s[i] == '<' || s[i] == '>')
                i++;
            while (s[i] == ' ')
                i++;
            i = rotate_quotes_and_text(s, i);
        }
        else
        {
            i = rotate_quotes_and_text(s, i);
            j++;
        }
    }
    return (j);
}

static void redirect_create_outputs(char *s, int *j, t_cmd *c)
{
    int     k;

    k = *j;
    if (s[k] == '<')
    {
        if (s[k + 1] == '<')
            heredoc(s, &k, c);
        else if (s[k + 1] == '>')
            durakskii_redirect(s, &k, c);
        else 
            input(s, &k, c);
    }
    if (s[k] == '>')
        output(s, &k, c);
    *j = k;
}

char    **redirects_cut_off(char *s, t_cmd *c)
{
    char    **ret;
    int     j;
    int     k;

    ret = xmalloc(sizeof(char *) * (count_args(s) + 1));
    k = 0;
    j = -1;
    c->heredoc = 0;
    while (s[k])
    {
        if (s[k] == '>' || s[k] == '<')
            redirect_create_outputs(s, &k, c);
        else
            ret[++j] = get_arg(s, &k);
    }
    ret[++j] = NULL;
    return (ret);
}
