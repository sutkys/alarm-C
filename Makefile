make:
	gcc main.c -o alarm

asm:
	gcc main.c -S # I'm into learning assembly sooo just going to keep this around.

clean:
	rm alarm
	rm main.s

run:
	./alarm
