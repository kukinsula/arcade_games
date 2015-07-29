CC = g++
EXEC = a.out
DEBUG = yes

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++11 -W -Wall -Werror -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS = -std=c++11
endif

LDFLAGS = `sdl2-config --cflags --libs`

SRC_DIR = src
OBJ_DIR = obj

LOG_DIR = $(SRC_DIR)/log
LOG_SRC = $(wildcard $(LOG_DIR)/*.cpp)

EVENT_DIR = $(SRC_DIR)/event
EVENT_SRC = $(wildcard $(EVENT_DIR)/*.cpp)

SRC = $(LOG_SRC) $(EVENT_SRC)
OBJ = $(patsubst %.cpp, %.o, $(SRC))


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(SRC_DIR)/main.cpp $(OBJ_DIR)/*.o -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)

src/log/%.o:
	$(CC) -c $(LOG_DIR)/$*.cpp -o $(OBJ_DIR)/$*.o $(CXXFLAGS)

src/event/%.o:
	$(CC) -c $(EVENT_DIR)/$*.cpp -o $(OBJ_DIR)/$*.o $(CXXFLAGS) $(LDFLAGS)


clean:
	@rm -f $(OBJ_DIR)/*.o

purge: clean
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: clean purge

test:
	@echo $(OBJ)