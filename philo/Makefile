#ANSI codes to add colors
RED			='\033[0;31m'
PURPLE		='\033[0;35m'
YELLOW		='\033[1;33m'
GREEN		='\033[1;32m'
NONE		='\033[0m'

# comp
NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR 			= ar rcs
RM			= rm -f

# directories
INC_PATH	:= includes
SRCS_PATH	:= srcs
BONUS_PATH	:= bonus

SRCS 		= srcs/philosophers.c \
			srcs/error_management.c \
			srcs/utils.c \
			srcs/states.c \
			srcs/stop.c \
			srcs/clear.c \

#SRCS_BONUS				= 

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

%.o: %.c	$(SRCS_PATH)/%.c
			$(CC) $(CFLAGS) -I $(INC_PATH) -o $@ -c $<

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) -lpthread
#			@echo -e ${GREEN}Arguments : [Nb of philosophers] [Time to die] [Time to eat] [Time to sleep] (optionnal)[Nb max of meals]${NONE}

bonus:		$(OBJS_BONUS)
			$(CC) $(OBJS_BONUS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus