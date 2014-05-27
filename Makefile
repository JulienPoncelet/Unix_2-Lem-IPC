# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/05/27 17:43:49 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemipc

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = main.c\
	  check_input.c\
	  t_player.c\
	  shm.c\
	  sem.c\
	  msg.c\
	  lock.c\
	  t_board.c\
	  wait_ncurse.c\
	  loop.c\
	  select_dest.c\
	  checks.c\
	  get_dir.c\
	  move.c\
	  check_dead.c\
	  check_end.c

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

LFT = -L ./libft/ -lft

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -O3

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s -C ./ncurse
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(NAME)'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) -s clean -C ./libft
	@$(MAKE) -s clean -C ./ncurse

fclean: clean
	@rm -rf $(NAME) $(NAME)_ncurse
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) -s fclean -C ./libft
	@$(MAKE) -s fclean -C ./ncurse

re : fclean all

.PHONY: all clean fclean re
