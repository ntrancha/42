NAME=test
GCCFLAG=-W -Wall -Werror -Wextra -ansi
FTC= test.c return.c recup.c print.c \
	 param.c list_sort_path.c list_sort.c list_del.c list.c \
	 ft_ls.c extra.c error.c dos.c display.c \
	
FTO= test.o return.o recup.o print.o \
	 param.o list_sort_path.o list_sort.o list_del.o list.o \
	 ft_ls.o extra.o error.o dos.o display.o \
	
FTH= test.h return.h recup.h print.h \
	 param.h list_sort_path.h list_sort.h list_del.h list.h \
	 ft_ls.h extra.h error.h dos.h display.h \
	

all: $(NAME)

$(NAME): gcc

source:
	@gcc -c $(FTC) $(GCCFLAG)

gcc: source
	@gcc $(GCCFLAG) $(FTO) $(FTH) main.c -o $(NAME)
	@rm -rf $(FTO)

clean:
	@rm -fr $(FTO)

fclean: clean
	@rm -rf $(NAME)

proto:
	@cat *.h | grep "ft_" | grep -v "include" | grep -v "define"

list:
	@echo "Executable: $(NAME)"
	@echo "Flags: $(GCCFLAG)"
	@echo "List of .c :"
	@echo "$(FTC)"
	@echo "List of .h :"
	@echo "$(FTH)"

echec:
	@gcc -c $(FTC)
	@gcc $(FTO) $(FTH) main.c -o $(NAME)
	@rm -fr $(FTO)
	@./$(NAME)

norme:list
	@gcc -c $(FTC)
	@gcc $(FTO) $(FTH) main.c -o $(NAME)
	@rm -fr $(FTO)
	@python ~/git/script/norme.py *

debug:
	@gcc -c $(FTC) -g
	@gcc $(FTO) $(FTH) main.c -o $(NAME) -g
	@rm -fr $(FTO)
	@valgrind ./$(NAME)

error:re

test: re
	@echo "Proto"
	@~/git/script/find_ft.sh ft
	@echo "\nCorrection"
	@python ~/git/script/norme.py *
	@echo "\nSTART TEST\n"
	@time ./$(NAME)
	@echo "\nEND TEST\n"

re: fclean gcc

