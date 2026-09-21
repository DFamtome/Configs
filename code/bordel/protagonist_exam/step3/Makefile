CC = gcc
SRCS = my_price.c compute_price.c compute_quantity.c 
OBJS = $(SRCS:.c=.o)
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
LFLAGS = -lm
TARGET = my_price

all : $(OBJS)
	$(CC) -o $(TARGET) $^ $(CFLAGS) $(LFLAGS)


clean: 
	$(RM) $(OBJS) $(TARGET)

PHONY: clean all

