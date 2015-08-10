CC = g++
EXEC = a.out
DEBUG = yes

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++0x -W -Wall -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS = -std=c++0x
endif

LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image

SRC_DIR = src
OBJ_DIR = obj

SRC_DIRS = $(patsubst %/., %, $(wildcard $(addsuffix /., $(wildcard $(SRC_DIR)/*) ) ) )
OBJ_DIRS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_DIRS) )

SRC_FILES_PATH = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp) 
OBJ_FILES_PATH = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES_PATH) )



$(EXEC): prepare $(OBJ_FILES_PATH)
	$(CC) $(OBJ_FILES_PATH) -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

prepare:
	@mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

$(OBJ_DIR)/log/%.o: src/log/%.cpp
	$(CC) -c $(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp,$@) -o $@ $(CXXFLAGS)

$(OBJ_DIR)/window/%.o: src/window/%.cpp
	$(CC) -c $(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp,$@) -o $@ $(CXXFLAGS) $(LDFLAGS)



clean:
	@rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o

purge: clean
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: clean purge