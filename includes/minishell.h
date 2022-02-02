/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cluco <cluco@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:22:36 by mjeanett          #+#    #+#             */
/*   Updated: 2022/02/02 13:22:35 by Cluco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define MINISHELL_PROMPT "minishell$ "
# define MINISHELL_ERROR_PREFIX "minishell: "



//error messages
# define ARGS_ERR "too many arguments"
# define NTV_IDENT "not a valid identifier"

# define SUCCESS 0
# define NAMESETTING "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789_"

typedef struct s_kv
{
	char	*name;
	char	*value;
}	t_kv;

typedef struct s_global
{
	char		*env;
	int			exit_status;
}	t_global;

t_global	g_global;

void	init_global(void);
void	free_global(void);

// use it instead of standart malloc
void	*xmalloc(size_t size);

void	execute_command(char *command);

void		ft_echo(char **args, int fd1, int fd2);
void		ft_cd(char **args);
void		ft_env(char **args);
void		ft_export(char **args);
void		ft_unset(char **args);
void		ft_pwd(void);
void		ft_exit();

int			ft_count_char(const char *s, const char *set);

// examples:
//          is_builtin((char *[]){"echo", "-n", "-n", "bla", "bla"})
//          run_builtin((char *[]){"echo", "-n", "-n", "bla", "bla"})
int		is_builtin(char **args); // TODO
void	run_builtin(char **args); // TODO

// examples:
//          get_env("PATH") != NULL
//          get_env("NOT_EXISTED_VARIABLE") == NULL
t_kv	*get_env(const char *name); // TODO
void	set_env(t_kv *kv); // TODO изменение самого листа

t_kv	*create_kv(const char *name, const char *value); //TODO
void	free_kv(t_kv *kv); //TODO

void	print_builtin_error(char *builtin, char *prefix, char *message);
void	print_error(char *prefix, char *message);
void	print_n_exit(char *message);
void	strerror_n_exit(char *prefix);

#endif