EXEC 			 = mode
SRC 			 = main.c operation.c
all: clean $(EXEC)
$(EXEC): $(SRC)
	$(CC) -Wall $(CFLAGS) $(LDFLAGS) -lpthread -o $@ $(SRC) $(LDLIBS)
clean:
	-rm -f $(EXEC) *.elf *.gdb *.o