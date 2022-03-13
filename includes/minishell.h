/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluco <cluco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:22:36 by mjeanett          #+#    #+#             */
/*   Updated: 2022/03/11 18:37:50 by cluco            ###   ########.fr       */
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
# include <sys/wait.h>
# include <sys/types.h>

# define MINISHELL_PROMPT "minishell$ "
# define MINISHELL_ERROR_PREFIX "minishell: "
# define NAMESETTING "ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz0123456789_"

int				exit_status;

typedef struct s_cmd
{
	char		**cmd;
	char		*type;
	char		*path;
	int			count;
	char 		**e;
	int			fd1[2];
	int			fd2[2];
	int			fdstd[2];
	int			heredoc;
}	t_cmd;

void		*xmalloc(size_t size);

void		parse_execute(char *command, char **env);
void		launcher(t_cmd *c);
void		*free_all(t_cmd *c, char *s, char *message);
char		**redirects_cut_off(char *s, t_cmd *c);
void		run_execve(t_cmd *c, char **ex);
void		run_cmd(t_cmd *c, int i);
void		run_built(t_cmd *c, char **ex);
void   		check_extra_arrows(t_cmd *c, char ch);
void		heredoc(char *s, int *i, t_cmd *c);
void 		input(char *s, int *j, t_cmd *c);
void 		durakskii_redirect(char *s, int *j, t_cmd *c);
int 		append(char *s, int *j, t_cmd *c);
void 		output(char *s, int *j, t_cmd *c);
char 		*get_arg(char *s, int *k);
int 		rotate_quotes_and_text(char *s, int i);

void		ft_echo(char **args);
void		ft_cd(char **args, char **env);
void		ft_env(char **cmd, char **env);
void		ft_export(char **args, char **env);
void		ft_unset(char **args, char **env);
void		ft_pwd(void);
void		ft_exit(char **cmd, char **env);

// env work
void		ft_addenv(const char *name, const char *value, int equal, char **env);
int			ft_setenv(const char *name, const char *value, int equal, char **env);
char		*ft_getenv(const char *name, char **env);
void		ft_strarr_free(char **arr);
char		**ft_strarr_dup(char **arr, int size_plus);
int			ft_strarr_size(char **arr);
char		*ft_strjoin_triple(const char *s1, const char *s2, const char *s3);
int			ft_strarr_index(char **arr, const char *str, const char *sep);
int			ft_count_char(const char *s, const char *set);
void		reset_env(char **name, int equal, char **env);
void		ft_strarr_sort(char **arr, int size);
char  		*replace_var(char *s, char **env);



int			is_builtin(char **args);
void		run_builtin(char **args, char **env);

void		print_builtin_error(char *builtin, char *prefix, char *message);
void		print_error(char *prefix, char *message);
void		print_n_exit(char *message);
void		strerror_n_exit(char *prefix);

#endif