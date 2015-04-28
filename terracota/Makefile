#NAME
NAME = 'terracota.exe'

# DIR
INC_DIR= -I include
SRC_DIR= src/*.cpp
TEST_DIR=test

# ENGINE INCLUDES
ENGINE_INC= -I engine/include/
ENGINE_LIB=engine/lib/ijengine.a

#FLAGS
CC=clang++
CFLAGS=  -Wall -W -pedantic -ansi -std=c++11 
SDL2_FLAGS=`sdl2-config --libs` -lSDL2_image -lSDL2_ttf 

all:
	$(CC) -o $(NAME) $(CFLAGS) $(SRC_DIR) $(ENGINE_INC)  $(INC_DIR)   $(ENGINE_LIB) $(SDL2_FLAGS)

clean:
	rm terracota.exe
