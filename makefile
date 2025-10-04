explode: main.c lab1.c
	$(CC) -o $@ $^

clean:
	-rm -f *.o explode
	@echo "All clean!"