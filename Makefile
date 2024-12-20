CC = gcc
CFLAGS = -c -g3 -o
OFLAGS = -g3 -o


SRC = ./src/
OBJ = ./obj/
TDIR = ./tests/

TARGET = STREEBOG
vpath %.c $(SRC)
vpath %.o $(OBJ)
vpath test%.o $(TDIR)
vpath test%.c $(TDIR)

all:	print_256.o print_512.o uint8_64.o uint64_8.o  sum_512.o sum_512n.o linear_trans.o byte_swap.o pi_reflection.o X_512.o S_512.o P_512.o L_512.o LPSX.o E_512.o  G_512.o 
		$(CC)  $(OFLAGS) $(TARGET) $(SRC)$(TARGET).c $^

%.o: %.c
	$(CC) $(CFLAGS)  $(OBJ)$@ $<