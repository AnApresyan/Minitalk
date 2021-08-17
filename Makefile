NAME1 = client
NAME2 = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : client server
		
%.o : %.c
	@${CC} -c ${CFLAGS} $< -o $@

${NAME1} : client.o minitalk.h
	@${CC} $< -o $@
	@echo "Executable file $@ is created."

${NAME2} : server.o minitalk.h
	@${CC} $< -o $@
	@echo "Executable file $@ is created."

clean : 
	@rm -rf *.o

fclean : clean
	@rm -rf ${NAME1} ${NAME2}

re : fclean all

.PHONY : all clean fclean re
