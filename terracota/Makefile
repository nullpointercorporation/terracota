#NAME
NAME = terracota.exe

# ENGINE INCLUDES
ENGINE_PATH =  /usr/local/include/ijengine/
ENGINE_INC = -I $(ENGINE_PATH)
ENGINE_LIB = -L /usr/local/lib/ -lijengine

# DIR
INCLUDES=  $(ENGINE_INC) -I include
SRC_DIR  = src
TEST_DIR=test
OBJ_DIR = obj


#FLAGS
CC=clang++
CFLAGS=  -Wall -W -pedantic -std=c++11 -g3
LIBS = $(ENGINE_LIB) `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer

SRC = ${wildcard $(SRC_DIR)/*.cpp}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SRC:.cpp=.o}}}

all:
	@mkdir -p $(OBJ_DIR)
	$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo Building $@
	@$(CC) -c $(CFLAGS) $(INCLUDES)  $< -o $@

clean:
	rm -f terracota.exe obj/*
