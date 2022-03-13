/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:24:44 by cluco             #+#    #+#             */
/*   Updated: 2022/03/11 18:37:05 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void get_ret(char *s, char *ret, int *n, int *m)
{
    int i;
    int j;
    
    i = *n;
    j = *m;
    if (s[j] == 34 && ft_strchr(&s[j], 34) != NULL)
    {
        while (s[++j] != 34)
            ret[++i] = s[j];
        *m = ++j;
        *n = i;
        return ;
    }
    if (s[j] == 39 && ft_strchr(&s[j], 39) != NULL)
    {
        while (s[++j] != 39)
            ret[++i] = s[j];
        *m = ++j;
        *n = i;
        return ;
    }
    if (s[j] != ' ' && s[j] != '>' && s[j] != '<')
        ret[++i] = s[j++];
    *n = i;
    *m = j;
}

char *get_arg(char *s, int *k)
{
    int i;
    int j;
    char    *ret;

    j = *k;
    i = rotate_quotes_and_text(s, j);
    ret = xmalloc(sizeof(char) * (i - j + 1));
    i = -1;
    while (s[j] != ' ' && s[j] != '<' && s[j] != '>' && (s[j]))
        get_ret(s, ret, &i, &j);
    while (s[j] == ' ')
        j++;
    ret[++i] = 0;
    *k = j;
    return (ret);
}

void    check_extra_arrows(t_cmd *c, char ch)
{
    if (ch == '<')
        free_all(c, "19840", "bash: parse error near '<'");  
    else if (ch == '>')
        free_all(c, "19840", "bash: parse error near '>'");
}

static void	heredoc_dup2(char *limiter, int fd, t_cmd *c)
{
	char    *line;

	line = NULL;
	while (ft_strcmp(limiter, line) != 0)
    {
        line = readline("> ");
		rl_redisplay();
        ft_putstr_fd(line, fd);
        ft_putstr_fd("\n", fd);
        free(line);
    }
    free(limiter);
    if (dup2(fd, 0) < 0)
    {
        free(limiter);
        free_all(c, "19840", strerror(errno));
    }
    close(fd);
}

void heredoc(char *s, int *i, t_cmd *c)
{
    int     k;
    char    *limiter;
    int     fd;

    k = *i + 2;
    while (s[k] == ' ')
        k++;
    check_extra_arrows(c, s[k]);
    limiter = get_arg(s, &k);
    fd = open("clucoheredoc", O_TRUNC | O_CREAT | O_RDWR | O_APPEND, 0664);
    if (fd < 0)
    {
        free(limiter);
        free_all(c, "19840", strerror(errno));
    }
	heredoc_dup2(limiter, fd, c);
    *i = k;
    c->heredoc = 1;
}