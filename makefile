CC =gcc
CFLAGS =-I.
INCLUDE =Estimation.h
OBJECTS = main.o Estimation.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

Mean: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS)

