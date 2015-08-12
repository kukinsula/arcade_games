CC = g++
EXEC = a.out
DEBUG = true

CLOSE_COLOR = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m

CURRENT_SYSTEM_MS = \
	$(shell date +%s%N | cut -b1-13)

START_TIME = $(call CURRENT_SYSTEM_MS)
END_TIME =

ifeq ($(DEBUG), true)
	CXXFLAGS = -std=c++0x -W -Wall -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS = -std=c++0x
endif

LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_image

SRC_DIR = src
OBJ_DIR = .obj

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_DIRS) )

CPP_FILES_PATH = $(shell find src/ -type f -name '*.cpp' | sort)
CPP_FILES_NAME = $(notdir $(CPP_FILES_PATH) )
HEADER_FILES_PATH = $(shell find src/ -type f -name '*.hpp' | sort)
SRC_FILES_PATH = $(shell echo $(CPP_FILES_PATH) $(HEADER_FILES_PATH) | sort)

OBJ_FILES_PATH = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES_PATH) )
OBJ_FILES_NAME = $(notdir $(OBJ_FILES_PATH) )

COUNT := 0
TOTAL_PERCENT = 100
NUMBER_COMPILATION_UNITS = $(shell echo $(OBJ_FILES_PATH) $(EXEC) | wc -w)
STEP := $(shell echo $$(( $(TOTAL_PERCENT) / $(NUMBER_COMPILATION_UNITS) )) )

# returns the first arg + $(STEP)
incr_counter = \
	$(shell expr $(1) + $(STEP) )

# compiles a .cpp file to an object .o file
	# arg1: .cpp file
	# arg2: .o file
	# arg3: g++ options
compile_unit = \
	@$(CC) -c $(1) -o $(2) $(CXXFLAGS) $(3); \
	$(eval COUNT = $(call incr_counter, $(COUNT) ) ) \
	echo "[$(GREEN)$(COUNT)%$(CLOSE_COLOR)] ..... $(YELLOW)$(notdir $(2) )$(CLOSE_COLOR)"; \



$(EXEC): $(OBJ_FILES_PATH)
	@$(CC) $(OBJ_FILES_PATH) -o $(EXEC) $(CXXFLAGS) $(LDFLAGS)
	@echo "[$(GREEN)$(TOTAL_PERCENT)%$(CLOSE_COLOR)] ..... $(GREEN)$(EXEC)$(CLOSE_COLOR)";

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(call compile_unit, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/tests/%.o: src//tests/%.cpp
	$(call compile_unit, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/framework/log/%.o: src/framework/log/%.cpp
	$(call compile_unit, $<, $@)

$(OBJ_DIR)/framework/event/%.o: src/framework/event/%.cpp
	$(call compile_unit, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/framework/window/%.o: src/framework/window/%.cpp
	$(call compile_unit, $<, $@, $(LDFLAGS) )

$(OBJ_DIR)/framework/view/%.o: src/framework/view/%.cpp
	$(call compile_unit, $<, $@, $(LDFLAGS) )


test:
	@echo $(START_TIME)
	@echo $(CURRENT_SYSTEM_MS)
	@echo $(call calculate_compilation_time, $(CURRENT_SYSTEM_MS) )


prepare:
	@mkdir -p $(OBJ_DIRS)

stat:
	@echo number of C++ files : $(shell echo $(CPP_FILES_PATH) | wc -w)
	@echo number of header files : $(shell echo $(HEADER_FILES_PATH) | wc -w)
	@echo number of C++ lines :
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

clean:
	@rm -f $(OBJ_FILES_PATH)

purge:
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: help prepare clean purge