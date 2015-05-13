#NAME
NAME = terracota.exe

# ENGINE INCLUDES
ENGINE_INC = -I /usr/share/ijengine/include/
ENGINE_LIB = -L /usr/share/ijengine/lib/ -lijengine

# DIR
INCLUDES= -I include $(ENGINE_INC)
SRC_DIR  = src
TEST_DIR=test
OBJ_DIR = obj


#FLAGS
CC=clang++
CFLAGS=  -Wall -W -pedantic -std=c++11
LIBS = $(ENGINE_LIB) `sdl2-config --libs` -lSDL2_image -lSDL2_ttf

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
