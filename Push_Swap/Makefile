
NAME = push_swap
BONUS = checker
CFLAGS = -Wall -Wextra -Werror 
SRCMAIN = push_swap.c $(SRCS)
SRCS =	ft_splitarg.c ft_stackinit.c operations.c sorting.c bigsort.c biggi.c biggi2.c\
	
OBJS = $(SRCMAIN:.c=.o) 
DEPS = $(SRCMAIN:.c=.d)

SRCBONUS = 	checker.c $(SRCS)

OBJBONUS = $(SRCBONUS:.c=.o)
DEPBONUS = $(SRCBONUS:.c=.d)

RM = rm -f

LIBS = MyLibft/libft.a
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(LIBS) Makefile
	@$(CC) $(CFLAGS) -MMD -g -I./ -c $< -o $@

all:
	@$(MAKE) -C MyLibft
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)push_swap compiled$(NC)"

$(NAME)::
	@echo -n

bonus:
	@$(MAKE) -C MyLibft
	@$(MAKE) $(BONUS)

$(BONUS):: $(OBJBONUS)
	@$(CC) $(OBJBONUS) $(LIBS) -o $@
	@echo "$(GREEN)checker compiled$(NC)"
	
$(BONUS)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJBONUS) $(DEPBONUS)
	@$(MAKE) clean -C MyLibft
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(BONUS) $(LIBS)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(DEPBONUS)
