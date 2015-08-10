CC = g++
EXEC = a.out
DEBUG = yes

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++11 -W -Wall -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS = -std=c++11
endif

LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image

SRC_DIR = src
OBJ_DIR = obj

LOG_DIR = $(SRC_DIR)/log
WINDOW_DIR = $(SRC_DIR)/window

SRC_PATH = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp) 
SRC_FILES = $(notdir $(SRC_PATH) )
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES) )
OBJ_PATH = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_PATH) )



$(EXEC): $(OBJ_PATH)
	$(CC) $(OBJ_PATH) -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

# TODO
prepare:
	# @echo creating directories

obj/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) $(LDFLAGS)

obj/log/%.o: $(LOG_DIR)/%.cpp
	$(CC) -c $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.cpp, $@) -o $@ $(CXXFLAGS) $(LDFLAGS)

obj/window/%.o: $(WINDOW_DIR)/%.cpp
	$(CC) -c $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.cpp, $@) -o $@ $(CXXFLAGS) $(LDFLAGS)



clean:
	@rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*/*.o

purge: clean
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: clean purge