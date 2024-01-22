CC = gcc

bookpenguin:test.c filehandling.c
	$(CC) &? -o $@.run

clean:
	rm *.run