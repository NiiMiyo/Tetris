COMPILER      = gcc
COMPILE_FLAGS = -I include -pedantic -Wall -Wextra
LINK_FLAGS    = -lmingw32 -lSDL2main -lSDL2 -L lib -mwindows
C_FILES       = main game game_data rendering tetramino controls

OBJECT_FILES  = $(patsubst %,obj/%.o,${C_FILES})

.PHONY: build run clean folder.%

build: clean ${OBJECT_FILES}
	${COMPILER} ${OBJECT_FILES} -o bin/main ${LINK_FLAGS}
	cp "lib/SDL2.dll" bin/

run: build
	cd bin && ./main

clean:
	${NEW_LINE}
	rm -rf bin/*

obj/%.o: src/%.c
	${COMPILER} -c "$<" -o "$@" ${COMPILE_FLAGS}
