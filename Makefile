make:
	gcc -Wall main.c -o alarm `pkg-config --cflags --libs sdl3`

clean:
	rm alarm

run:
	./alarm
