# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/05/26 15:42:13 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemipc_ncurse

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = main.c\
	  ncurse.c\
	  loop.c\
	  sem.c\
	  shm.c\
	  t_board.c\
	  lock.c

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

LFT = -L ../libft/ -lft
LNCURSES = -L /usr/lib -lncurses

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -O3

HEAD = -I ./includes -I ../libft/includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@$(MAKE) -C ../libft
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LNCURSES)
	@mv $(NAME) ..
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(NAME)'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ../libft

fclean: clean
	@rm -rf $(NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ../libft

re : fclean all

.PHONY: all clean fclean re
