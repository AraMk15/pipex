NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCSDIR = ./src/
SRCSLIST = pipex.c\
			utils.c
SRCS = $(addprefix $(SRCSDIR), $(SRCSLIST))

OBJSDIR = ./obj/
OBJSLIST = $(SRCS:.c=.o)
OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJSDIR)%.o, $(SRCS))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJSDIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) -r ${OBJSDIR}
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
