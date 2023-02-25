COMPILE_FLAGS = -I include -pedantic -Wall -Wextra
LINK_FLAGS    = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -L lib
C_FILES       = main game game_data tetramino

OBJECT_FILES  = $(patsubst %,obj/%.o,${C_FILES})

NEW_LINE      = @echo ""

.PHONY: build run

build: ${OBJECT_FILES}
	gcc ${OBJECT_FILES} -o bin/main ${LINK_FLAGS}
	${NEW_LINE}
	cp assets/* bin/ -r
	cp "lib/SDL2.dll" bin/
	cp "lib/SDL2_image.dll" bin/

run: build
	${NEW_LINE}
	cd bin && ./main

obj/%.o: src/%.c
	${NEW_LINE}
	gcc -c "$<" -o "$@" ${COMPILE_FLAGS}
