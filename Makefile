# main variables
CC = g++
EXEC = a.out
DEBUG = true

# shell code colors
CLOSE_COLOR = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BOLD = \[1m

# C++ compilation options
ifeq ($(DEBUG), true)
	CXXFLAGS = -std=c++11 -W -Wall -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS =
endif

# library compilation options
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image

# directories
SRC_DIR = src
OBJ_DIR = .obj

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_DIRS) )

# C++ source files path
CPP_FILES_PATH = $(sort $(shell find $(SRC_DIR)/ -type f -name '*.cpp') )

# header source files path
HEADER_FILES_PATH = $(sort $(shell find $(SRC_DIR)/ -type f -name '*.hpp') )

# all sources
SRC_FILES_PATH = $(CPP_FILES_PATH) $(HEADER_FILES_PATH)

# obj files
OBJ_FILES_PATH = $(filter-out $(OBJ_DIR)/main.o, $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES_PATH) ) )

# examples
EXAMPLES_CPP_FILES_PATH = $(shell find examples/ -type f -name '*.cpp')
EXAMPLES_EXEC_FILES_PATH = $(patsubst %.cpp, %, $(EXAMPLES_CPP_FILES_PATH) )

# statistic figures
NUMBER_OF_CPP_LINES = $(shell find $(SRC_DIR) -type f -name '*.cpp' -exec cat {} + | wc -l)
NUMBER_OF_HEADER_LINES = $(shell find $(SRC_DIR) -type f -name '*.hpp' -exec cat {} + | wc -l)
TOTAL_NUMBER_OF_LINES = $(shell expr $(NUMBER_OF_CPP_LINES) + $(NUMBER_OF_HEADER_LINES) )

# percent counter
COUNT = 0
TOTAL_PERCENT = 100
NUMBER_COMPILATION_UNITS = $(shell echo $(CPP_FILES_PATH) $(EXEC) | wc -w)
STEP = $(shell echo 'scale=2; $(TOTAL_PERCENT)/$(NUMBER_COMPILATION_UNITS)' | bc)

# returns the first arg + $(STEP)
incr_percent_count = \
	$(shell echo 'scale=2; $(1) + $(STEP)' | bc)


# compiles a .cpp file to an object .o file
	# arg1: .cpp file
	# arg2: .o file
	# arg3: g++ options
compile_obj = \
	@$(CC) -c $(1) -o $(2) $(CXXFLAGS) $(3); \
	$(eval COUNT = $(call incr_percent_count, $(COUNT) ) ) \
	echo "[$(GREEN)$(COUNT)%$(CLOSE_COLOR)] ..... $(YELLOW)$(notdir $(2) )$(CLOSE_COLOR)"; \

compile_example = \
	@$(CC) $(FRAMEWORK) $(1) -o $(2) $(CXXFLAGS) $(LDFLAGS); \
	echo "$(YELLOW)$(notdir $(2) )$(CLOSE_COLOR)" \





all: $(OBJ_FILES_PATH)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp $(SRC_DIR)/%.hpp
	$(call compile_obj, $<, $@, $(LDFLAGS) )


# examples rules
examples: $(OBJ_FILES_PATH) $(EXAMPLES_EXEC_FILES_PATH)

examples/%: examples/%.cpp examples/%.hpp
	@$(CC) $< $(OBJ_FILES_PATH) -o $@ $(CXXFLAGS) $(LDFLAGS)
	@echo "$(YELLOW)$(notdir $@)$(CLOSE_COLOR)"



doc:
	doxygen

valgrind:
	valgrind ./$(EXEC) --leak-check=full --track-origins=yes -v

stat:
	@echo cpp : $(shell echo $(CPP_FILES_PATH) | wc -w) files / $(NUMBER_OF_CPP_LINES) lines
	@echo hpp : $(shell echo $(HEADER_FILES_PATH) | wc -w) files / $(NUMBER_OF_HEADER_LINES) lines
	@echo total: $(shell expr $(shell echo $(HEADER_FILES_PATH) | wc -w) + $(shell echo $(HEADER_FILES_PATH) | wc -w) ) files / $(TOTAL_NUMBER_OF_LINES) lines

wc:
	@wc -l $(SRC_FILES_PATH)

help:
	@echo
	@echo "**************************************************************************"
	@echo "*                                                                        *"
	@echo "*                              ARCADE GAMES                              *"
	@echo "*                                                                        *"
	@echo "**************************************************************************"
	@echo
	@echo " Regles disponnibles"
	@echo
	@echo " * make           : compilation"
	@echo " * examples       : compilation des exemples"
	@echo
	@echo " * prepare        : préparation au build"
	@echo " * doc            : génération de la documentation"
	@echo " * clean          : nettoyage des fichiers objets temporaires"
	@echo " * purge          : nettoyage de $(EXEC)"
	@echo " * mrproper       : nettoyage de tout le build"
	@echo " * clean_doc      : nettoyage de toute la documentation"
	@echo
	@echo " * help           : règles disponnibles"
	@echo "--------------------------------------------------------------------------"
	@echo

prepare:
	@mkdir -p $(OBJ_DIRS)

clean:
	@rm -f $(OBJ_FILES_PATH)

clean_examples:
	@rm -f $(EXAMPLES_EXEC_FILES_PATH)

purge:
	@rm -f $(EXEC)

mrproper: clean clean_examples purge

.PHONY: help clean purge examples doc