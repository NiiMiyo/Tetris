COMPILE_FLAGS = -I include -pedantic -Wall -Wextra
LINK_FLAGS    = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -L lib

.PHONY: build clean assets compile.src compile.file.% run

build: clean compile.src assets
	gcc obj/main.o obj/game.o obj/game_data.o -o bin/main ${LINK_FLAGS}

run: build
	cd bin && ./main

clean:
	rm -rf obj/*
	rm -rf bin/*

assets:
	cp assets/* bin/ -r
	cp "lib/SDL2.dll" bin/
	cp "lib/SDL2_image.dll" bin/

compile.src: \
	compile.file.main \
	compile.file.game_data \
	compile.file.game ;

compile.file.%:
	@echo ""
	gcc -c "src/$*.c" -o "obj/$*.o" ${COMPILE_FLAGS}
