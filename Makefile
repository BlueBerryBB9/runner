# E89 Pedagogical & Technical Lab
# project:     rp_sort
# created on:  2023-01-20 - 10:17 +0100
# 1st author:  martin.leroy - martin.leroy
# description: makefile

NAME	=	runner

SRCS	=	$(shell find src/ -name "*.c")

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror -Iinclude/

LDFLAGS	+=	-llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm

RM	=	rm -vf

CC	:=	gcc

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

save:
	git status
	git add Makefile src/*/*.c include/*.h
	git commit -m "$(NAME) Sauvegarde"
	git push
	git status

clean:
	@$(RM) $(OBJS)

clear:
	@$(RM) */*~ include/*~

fclean: clean clear
	@$(RM) $(NAME)

re: fclean all

# Theses rules do not directly map to a specific file
.PHONY: all clear clean fclean re save
