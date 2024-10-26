.PHONY: all clean

CC := gcc
CFLAGS := -g3 -O0 -std=c99 -Wall 

OBJS = main.o hv.o hdc.o image.o

mchdc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f mchdc *.o
