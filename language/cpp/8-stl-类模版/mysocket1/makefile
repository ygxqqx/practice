
.PHONY:clean



OBJS= demo01_testplatform.o itcastlog.o socketclient.o

CC = gcc
CFLGS= -Wall -g 

mysocket:$(OBJS)
	$(CC)  $^ -o $@
	
.c.o:
	$(CC) $(CFLGS) -c $< -o $@


clean:
	rm -rf $(BIN) *.o mysocket


