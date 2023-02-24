COMPILE_FLAGS = -I include -pedantic -Wall -Wextra
LINK_FLAGS    = -lmingw32 -lSDL2main -lSDL2 -L lib

.PHONY: build clean assets compile.src compile.file.%

build: clean compile.src assets
	gcc obj/main.o obj/sdl_event_handler.o -o bin/main ${LINK_FLAGS}

clean:
	rm -rf obj/*
	rm -rf bin/*

assets:
	cp assets/* bin/ -r
	cp "lib/SDL2.dll" bin/

compile.src: \
	compile.file.main \
	compile.file.sdl_event_handler;

compile.file.%:
	gcc -c "src/$*.c" -o "obj/$*.o" ${COMPILE_FLAGS}
