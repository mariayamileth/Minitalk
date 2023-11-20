# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricont <maricont@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/18 11:02:26 by maricont          #+#    #+#              #
#    Updated: 2023/07/02 20:37:38 by maricont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus

CFLAGS = -Wall -Wextra -Werror

SRCS_C = client.c
SRCS_S = server.c
SRCS_C_BONUS = client_bonus.c
SRCS_S_BONUS = server_bonus.c

OBJS_C = $(SRCS_C:.c=.o)
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)


RM = rm -f
INCLUDE = -I ./

%.o : %.c
	${CC} ${CFLAGS} $(INCLUDE) -c $< -o $@

all: $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJS_C)
	${CC} ${CFLAGS} $(OBJS_C) -o $(NAME_C)

$(NAME_S) : $(OBJS_S)
	${CC} ${CFLAGS} $(OBJS_S) -o $(NAME_S)

bonus: $(NAME_C_BONUS) $(NAME_S_BONUS)
	
$(NAME_C_BONUS) : $(OBJS_C_BONUS)
	${CC} ${CFLAGS} $(OBJS_C_BONUS) -o $(NAME_C_BONUS)

$(NAME_S_BONUS) : $(OBJS_S_BONUS)
	${CC} ${CFLAGS} $(OBJS_S_BONUS) -o $(NAME_S_BONUS)


clean : 
	$(RM) $(OBJS_C)
	$(RM) $(OBJS_S)
	$(RM) $(OBJS_C_BONUS)
	$(RM) $(OBJS_S_BONUS)

fclean : clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)
	$(RM) $(NAME_C_BONUS)
	$(RM) $(NAME_S_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus

