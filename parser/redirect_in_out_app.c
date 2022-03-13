/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in_out_app.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:13:36 by cluco             #+#    #+#             */
/*   Updated: 2022/03/11 18:28:15 by cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void input(char *s, int *j, t_cmd *c)
{
    char    *tmp;
    int     fd;
    int     k;

    fd = 0;
    k = *j;
    if (s[k + 1] == ' ')
    {
        while (s[++k] == ' ')
            ;
		check_extra_arrows(c, s[k]);
        tmp = get_arg(s, &k);
        fd = open(tmp, O_RDONLY);
        free(tmp);
    }
    else if (s[k + 1] != '>')
    {
        tmp = get_arg(s, &k);
        fd = open(tmp, O_RDONLY);
        free(tmp);
    }
    if (fd >= 0)
        if (dup2(fd, 0) < 0)
            free_all(c, "19840", strerror(errno));
    *j = k;
}

void durakskii_redirect(char *s, int *j, t_cmd *c)
{
    int     k;
    char    *tmp;
    int     fd;

    k = *j + 2;
    while (s[k] == ' ')
        k++;
    check_extra_arrows(c, s[k]);
    tmp = get_arg(s, &k);
    fd = open(tmp, O_TRUNC | O_CREAT | O_RDWR, 0664);
    close(fd);
    free (tmp);
    *j = k;
}

int append(char *s, int *j, t_cmd *c)
{
    int     k;
    int     fd;
    char    *tmp;

    fd = 1000;
    k = *j;
    if (s[++k] == '<')
		check_extra_arrows(c, s[k + 1]);
    else if (s[k] == 0)
        free_all(c, "19840", "zsh: parse error near '\\n'");
    else if (s[k] == '>')
    {
        while (s[++k] == ' ')
            ;
		check_extra_arrows(c, s[k]);
        tmp = get_arg(s, &k);
        fd = open(tmp, O_TRUNC | O_CREAT | O_RDWR | O_APPEND, 0664);
        free (tmp);
    }
    *j = k;
    return (fd);
}

void output(char *s, int *j, t_cmd *c)
{
    int     k;
    int     fd;
    char    *tmp;

    k = *j;
    fd = append(s, &k, c);
    if (fd == 1000)
    {
        while (s[k] == ' ')
            k++;
		check_extra_arrows(c, s[k]);
        tmp = get_arg(s, &k);
        fd = open(tmp, O_TRUNC | O_CREAT | O_RDWR, 0664);
        free (tmp);
    }
    if (fd < 0)
        free_all(c, "19840", strerror(errno));
    if (dup2(fd, 1) < 0)
        free_all(c, "19840", strerror(errno));
    *j = k;
}