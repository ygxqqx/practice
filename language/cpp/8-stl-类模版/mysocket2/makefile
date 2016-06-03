
.PHONY:clean

WORKDIR=.

VPATH = ./src


OBJS= demo01_testplatform.o itcastlog.o socketclient.o

CC = gcc
CFLGS= -Wall -g -I$(WORKDIR)/inc/

mysocket:$(OBJS)
	$(CC)  $^ -o $@
	@rm *.o	
.c.o:
	$(CC) $(CFLGS) -c $< -o $@
clean:
	rm -rf $(BIN) *.o mysocket


