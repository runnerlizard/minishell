NAME		=	minishell

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -O2 -I $(HEADER) 

SRCS		=	main.c \
				utils/error.c \
				utils/utils.c \
				parser/parse_execute.c \
				parser/launcher.c \
				parser/redirects_cut_off.c \
				parser/redirect_in_out_app.c \
				parser/redirect_heredoc_and_utils.c \
				parser/free_all.c \
				parser/run_execve.c \
				parser/run_cmd.c \
				parser/replace_var.c \
				builtins/builtins.c \
				builtins/pwd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/cd.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/unset.c \
				builtins/get_env.c \
				builtins/builtin_utils.c \
				builtins/builtin_futils.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				make clean -C ./libft

fclean		:	clean
				rm $(NAME)
				make fclean -C ./libft

re			:	fclean all
