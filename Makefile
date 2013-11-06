
all: galloc.so

galloc.o: galloc.c
	$(CC) -Wall -fPIC -DPIC -c $<

galloc.so: galloc.o
	$(LD) -shared -o $@ $< -ldl

run: galloc.so
	@ls
	@echo '-- '
	@LD_PRELOAD=./galloc.so ls

clean:
	$(RM) core.* core *~ galloc.so galloc.o
