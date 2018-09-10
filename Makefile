NAME = lem-in

SRCS = srcs/lemin.c \
		srcs/parsing.c \
		srcs/listops.c \
		srcs/linking.c \
		srcs/neighbours.c \
		srcs/path_finding.c \
		srcs/dijkstra.c \
		srcs/deleting.c \
		srcs/send_ants.c \
		srcs/free_paths.c \
		srcs/error.c 

FLAGS = -Wall -Wextra -Werror -I./includes

OBJS = $(SRCS:.c=.o)

all: makelib $(NAME)

makelib:
	@make -C libft

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) libft/libft.a
	@echo "Lem-in done"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ -I./includes

clean:
	@make clean -C libft
	@rm -rf $(OBJS)
	@echo "Clean done"

fclean: clean
	@make fclean -C libft
	@/bin/rm -rf $(OBJS)
	@/bin/rm -rf $(NAME)
	@echo "Fclean done"

re: fclean all
