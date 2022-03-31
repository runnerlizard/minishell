/* ************************************************************************** */
/*###################*/
/*##############:::#  ::::::::   */
/*   redirect_in_out_app.c#######  :+:#  :+:#:+:   */
/*#############+:+ +:+## +:+# */
/*   By: lizard <lizard@student.42.fr>###  +#+  +:+#   +#+##*/
/*############+#+#+#+#+#+   +#+##   */
/*   Created: 2022/03/11 18:13:36 by cluco### #+###+#### */
/*   Updated: 2022/03/28 23:50:10 by lizard##   ###   ########.fr#   */
/*###################*/
/* ************************************************************************** */

#include "../includes/minishell.h"

void	input(char *s, int *j, t_cmd *c)
{
	char	*tmp;
	int		fd;
	int		k;

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

void	durakskii_redirect(char *s, int *j, t_cmd *c)
{
	int		k;
	char	*tmp;
	int		fd;

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

static int	check_digit(char *s, int i)
{
	if (s[i - 1] == '0' && s[i - 2] == ' ')
		return (0);
	if (s[i - 1] == '2' && s[i - 2] == ' ')
		return (2);
	return (1);
}

static int	append(char *s, int *j, t_cmd *c, int *oldfd)
{
	int		k;
	int		fd;
	char	*tmp;

	fd = -1000;
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
		fd = open(tmp, O_CREAT | O_RDWR | O_APPEND, 0664);
		free (tmp);
	}
	*oldfd = check_digit(s, *j);
	*j = k;
	return (fd);
}

void	output(char *s, int *j, t_cmd *c)
{
	int		k;
	int		fd;
	char	*tmp;
	int		oldfd;

	k = *j;
	oldfd = 1;
	fd = append(s, &k, c, &oldfd);
	if (fd == -1000)
	{
		while (s[k] == ' ')
			k++;
		check_extra_arrows(c, s[k]);
		tmp = get_arg(s, &k);
		fd = open(tmp, O_TRUNC | O_CREAT | O_RDWR, 0664);
		free (tmp);
		oldfd = check_digit(s, *j);
	}
	if (fd < 0)
		free_all(c, "19840", strerror(errno));
	if (dup2(fd, oldfd) < 0)
		free_all(c, "19840", strerror(errno));
	*j = k;
}
