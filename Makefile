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


#_______________________________objects

%.o: %.c
	$(CC) $(CFLAGS)  $(OBJ)$@ $<

#_____________________________tests

test_pi_reflection: pi_reflection.o 
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_byte_swap: byte_swap.o 
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_linear_trans: linear_trans.o uint8_64.o uint64_8.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_X_512: X_512.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_S_512: S_512.o pi_reflection.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_P_512: P_512.o byte_swap.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_sum_512: sum_512.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_L_512: L_512.o linear_trans.o uint8_64.o uint64_8.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_uint8_64: uint8_64.o print_uint64.o 
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_uint64_8: uint64_8.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_LPSX: LPSX.o X_512.o S_512.o P_512.o L_512.o pi_reflection.o byte_swap.o linear_trans.o uint64_8.o uint8_64.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_E_512: E_512.o LPSX.o X_512.o S_512.o P_512.o L_512.o pi_reflection.o byte_swap.o linear_trans.o uint64_8.o uint8_64.o print_512.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

test_G_512: G_512.o E_512.o LPSX.o X_512.o S_512.o P_512.o L_512.o pi_reflection.o byte_swap.o linear_trans.o uint64_8.o uint8_64.o print_512.o
	$(CC) $(OFLAGS)  $(TDIR)$@ $^ $(TDIR)$@.c

