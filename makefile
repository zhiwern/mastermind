CC=gcc
OUT=out

mastermind:
	$(CC) main.c -o out/main.o

run:
	./$(OUT)/main.o

clean:
	rm -r $(OUT)/main.o 