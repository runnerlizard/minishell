NAME		=	minishell

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -O2 -I $(HEADER) -lreadline

SRCS		=	minishell.c \
				utils/error.c \
				utils/utils.c \
				utils/kv.c \
				parser/execute_command.c \
				misc/global.c \
				builtins/builtins.c \
				builtins/pwd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/unset.c \
				builtins/builtin_utils.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -L/usr/includes/ -lreadline 

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				make clean -C ./libft

fclean		:	clean
				rm $(NAME)
				make fclean -C ./libft

re			:	fclean all
