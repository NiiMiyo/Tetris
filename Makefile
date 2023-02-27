COMPILE_FLAGS = -I include -pedantic -Wall -Wextra
LINK_FLAGS    = -lmingw32 -lSDL2main -lSDL2 -L lib
C_FILES       = main game game_data rendering tetramino controls

OBJECT_FILES  = $(patsubst %,obj/%.o,${C_FILES})

NEW_LINE      = @echo ""

.PHONY: build run clean folder.%

build: clean ${OBJECT_FILES}
	${NEW_LINE}
	gcc ${OBJECT_FILES} -o bin/main ${LINK_FLAGS}
	${NEW_LINE}
	cp "lib/SDL2.dll" bin/

run: build
	${NEW_LINE}
	cd bin && ./main

clean:
	${NEW_LINE}
	rm -rf bin/*

obj/%.o: src/%.c
	${NEW_LINE}
	gcc -c "$<" -o "$@" ${COMPILE_FLAGS}
