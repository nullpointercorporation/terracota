#NAME
NAME = 'terracota.exe'

# DIR
INC_DIR=include
SRC_DIR= src/*.cpp
TEST_DIR=test

# ENGINE INCLUDES
ENGINE_INC= -I engine/include/
ENGINE_LIB=engine/lib/ijengine.a

#FLAGS
CC=clang++-3.5
CFLAGS=  -Wall -W -pedantic -ansi
SDL2_FLAGS=`sdl2-config --libs`

all:
	$(CC) -o $(NAME) $(SRC_DIR)	 $(ENGINE_INC) $(ENGINE_LIB) $(SDL2_FLAGS)

clean:
	rm terracota.exe
