CC = gcc
FLAG = nasm -f macho64
NAME = libasma.asm
CFILE = ./src/main.c

OFILE = ./src/*.o

SFILE = ./src/ft_strlen.s \
		./src/ft_strcpy.s \
		./src/ft_strcmp.s \
		./src/ft_write.s \
		./src/ft_read.s
		# ./src/ft_strdup.s

all: $(NAME)

$(NAME) :
	ar r $(FLAG) $(SFILE)
	ranlib $(CC) $(CFILE) $(OFILE)

clean:
	rm -rf ./src/*.o

fclean:
	clean
	rm -rf LIBASM

re:
	clean
	all