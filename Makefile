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
LOG_SRC = $(wildcard $(LOG_DIR)/*.cpp)

WINDOW_DIR = $(SRC_DIR)/window
WINDOW_SRC = $(wildcard $(WINDOW_DIR)/*.cpp)

SRC = $(LOG_SRC) $(WINDOW_SRC)
OBJ = $(patsubst %.cpp, %.o, $(SRC))


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(SRC_DIR)/main.cpp $(OBJ_DIR)/*.o -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

src/log/%.o:
	$(CC) -c $(LOG_DIR)/$*.cpp -o $(OBJ_DIR)/$*.o $(CXXFLAGS)

src/window/%.o:
	$(CC) -c $(WINDOW_DIR)/$*.cpp -o $(OBJ_DIR)/$*.o $(CXXFLAGS) $(LDFLAGS)



stat:
	@echo -o "nombre de fichier *.o:" && echo $(OBJ) | wc -w



clean:
	@rm -f $(OBJ_DIR)/*.o

purge: clean
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: clean purge