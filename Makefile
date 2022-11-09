NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_DIR = srcs/
SRC = command.c command2.c deque_utils.c deque_utils2.c dup_check.c err_check.c \
		operations.c operations_both.c ft_malloc.c set_map.c map_utils.c \
		make_triangles.c make_triangle_4.c make_triangle_5.c merge_triangles.c \
		merge_in_a.c merge_in_b.c sort_small.c push_swap.c
SRC_BONUS_DIR = srcs_bonus/
SRC_BONUS = deque_utils_bonus.c deque_utils2_bonus.c operations_bonus.c operations_both_bonus.c \
			ft_malloc_bonus.c err_check_bonus.c dup_check_bonus.c checker_bonus.c \
			command_bonus.c command2_bonus.c command3_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)
INCLUDE = push_swap.h
LIBFT = libft/libft.a

ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

ifdef BONUS
	OBJS = $(SRCS_BONUS:.c=.o) $(GNL_SRC:.c=.o)
	NAME = $(NAME_BONUS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ -I libft -I get_next_line $<

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft all

clean : 
	@$(MAKE) -C ./libft clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C ./libft fclean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

bonus :
	make BONUS=1 all

sanitize :
	make SANITIZE=1 re

.PHONY: all clean fclean re libft bonus sanitize