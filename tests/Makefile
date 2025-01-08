NAME = libftgnl
CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_HEADER		= ../get_next_line.h
MANDATORY_FILES			= ../get_next_line.c ../get_next_line_utils.c
MANDATORY_OBJS			= $(MANDATORY_FILES:../%.c=%.o)
MANDATORY_MAIN 			= main.c

BONUS_HEADER			= ../get_next_line_bonus.h
BONUS_FILES				= ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
BONUS_OBJS				= $(BONUS_FILES:../%.c=%.o)
BONUS_MAIN = 			main_bonus.c

.PHONY: all clean fclean re m b

all: m b

m: $(NAME) mandatory_exec

b: $(NAME) bonus_exec

$(NAME): $(MANDATORY_OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

mandatory_exec: $(MANDATORY_OBJS) $(MANDATORY_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

bonus_exec: $(BONUS_OBJS) $(BONUS_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

%.o: ../%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS) mandatory_exec bonus_exec

fclean: clean
	rm -f $(NAME)

re: fclean all