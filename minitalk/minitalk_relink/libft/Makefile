# Basic script for makefile
#
# target ... : prerequisites(or dependencies) ...
#	(tab)	recipe
# $@: target name
# %.o (%.c) is similar with *.o (*.c)
# $<: first file of dependencies list
# $^: the whole file list of dependencies
# $?: file list that touched latter than TARGERT
# $+: similiart with $^ but includes duplicates file name
# ar command options

# <c> : Create the archive.  The specified archive is always created if it did not exist, when you request an update.  But a warning is issued unless you specify in advance that you expect to create it, by using this modifier.

# <s> : Add an index to the archive, or update it if it already exists.  Note this command is an exception to the rule that there can only be one command letter, as it is possible to use it as either a command or a modifier.  In either case it does the same thing.

# <r> : Insert the files member... into archive (with replacement). This operation differs from q in that any previously existing members are deleted if their names match those being added.

#CC=<compiler>
#CFLAGS=<compiler option>
#LDFLAGS=<link option>
#LDLIBS=<list of link libraries>
#OBJS=<list of objects files>
#NAME=<name of target to build>
# 
#all: $(NAME)
#	 
#clean:
#	    rm -f *.o
#		    rm -f $(NAME)
#			 
#$(NAME): $(OBJS)
#	$(CC) -o $@ $(OBJS)
#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

AR = ar
ARFLAGS = -cr

RM = rm
RMFLAGS = -f

NAME = libft.a

# SRCS (.c files)
# OBJS (.o files)
SRCS_PART1 = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_strdup.c ft_calloc.c
OBJS_PART1 = $(SRCS_PART1:.c=.o)

SRCS_PART2 = \
	ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c
OBJS_PART2 = $(SRCS_PART2:.c=.o)

SRCS_BONUS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# OBJS script
# $@: target name
# %.o (%.c) is similar with *.o (*.c)
# $<: first file of dependencies list
%.o : %.c
	$(CC) $(CFLAGS) $^

ifdef bonus
OBJS = $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS)
else
OBJS = $(OBJS_PART1) $(OBJS_PART2)
endif

# linking
# $@: target name
# %.o (%.c) is similar with *.o (*.c)
# $<: first file of dependencies list
# $^: the whole file list of dependencies
# $?: file list that touched latter than TARGERT
# $+: similiart with $^ but includes duplicates file name

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.Phony : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	make bonus=true all
