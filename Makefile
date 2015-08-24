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

# framework's lib
FRAMEWORK_LIB = libframework.a

# directories
SRC_DIR = src
OBJ_DIR = .obj
FRAMEWORK_SRC_DIR = $(SRC_DIR)/framework
FRAMEWORK_OBJ_DIR = $(OBJ_DIR)/framework

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_DIRS) )

# C++ source files path
CPP_FILES_PATH = $(sort $(shell find $(SRC_DIR)/ -type f -name '*.cpp') )
FRAMEWORK_CPP_FILES_PATH = $(sort $(shell find $(FRAMEWORK_SRC_DIR)/ -type f -name '*.cpp') )

# header source files path
HEADER_FILES_PATH = $(sort $(shell find $(SRC_DIR)/ -type f -name '*.hpp') )
FRAMEWORK_HEADER_FILES_PATH = $(sort $(shell find $(FRAMEWORK_SRC_DIR)/ -type f -name '*.hpp') )

# all sources
SRC_FILES_PATH = $(CPP_FILES_PATH) $(HEADER_FILES_PATH)

# obj files
OBJ_FILES_PATH = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES_PATH) )
FRAMEWORK_OBJ_FILES_PATH = $(patsubst $(FRAMEWORK_SRC_DIR)/%.cpp, $(FRAMEWORK_OBJ_DIR)/%.o, $(FRAMEWORK_CPP_FILES_PATH) )

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





all: framework examples

# framework rules
framework: $(FRAMEWORK_LIB)

$(FRAMEWORK_LIB): $(FRAMEWORK_OBJ_FILES_PATH)
	@echo "\n[$(GREEN)$(TOTAL_PERCENT)%$(CLOSE_COLOR)] ... \033[1;39;41mcompiling $(FRAMEWORK_LIB)$(CLOSE_COLOR)\n"
	@ar rcs $(FRAMEWORK_LIB) $(FRAMEWORK_OBJ_FILES_PATH)

$(OBJ_DIR)/framework/util/%.o: $(SRC_DIR)/framework/util/%.cpp $(SRC_DIR)/framework/util/%.hpp
	$(call compile_obj, $<, $@)

$(OBJ_DIR)/framework/log/%.o: $(SRC_DIR)/framework/log/%.cpp $(SRC_DIR)/framework/log/%.hpp
	$(call compile_obj, $<, $@)

$(OBJ_DIR)/framework/event/%.o: $(SRC_DIR)/framework/event/%.cpp $(SRC_DIR)/framework/event/%.hpp
	$(call compile_obj, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/framework/window/%.o: $(SRC_DIR)/framework/window/%.cpp $(SRC_DIR)/framework/window/%.hpp
	$(call compile_obj, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/framework/widget/%.o: $(SRC_DIR)/framework/widget/%.cpp $(SRC_DIR)/framework/widget/%.hpp
	$(call compile_obj, $<, $@, $(LDFLAGS) )

# examples rules
examples: $(FRAMEWORK_LIB) $(EXAMPLES_EXEC_FILES_PATH)

examples/%: examples/%.cpp examples/%.hpp
	@$(CC) $< $(FRAMEWORK_LIB) -o $@ $(CXXFLAGS) $(LDFLAGS)
	@echo "$(YELLOW)$(notdir $@)$(CLOSE_COLOR)"



DIRS = \
	src/framework \
	src/framework/event \
	src/framework/log \
	src/framework/util \
	src/framework/widget \
	src/framework/window

CPP = $(sort $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp) ) )
HPP = $(sort $(foreach dir, $(DIRS), $(wildcard $(dir)/*.hpp) ) )
O = $(notdir $(patsubst $(SRC_DIR)/%.cpp, %.o, $(CPP) ) )

test:
	@echo $(DIRS)
	@echo
	@echo $(CPP)
	@echo
	@echo $(HPP)
	@echo
	@echo $(O)


test1: $(O)

test2:





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
	@echo " * prepare        : préparation au build"
	@echo
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
	@rm -f $(OBJ_FILES_PATH) $(FRAMEWORK_LIB)

clean_examples:
	@rm -f $(EXAMPLES_EXEC_FILES_PATH)

purge:
	@rm -f $(EXEC)

mrproper: clean clean_examples purge

.PHONY: help clean purge examples