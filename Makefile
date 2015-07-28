CC = g++
EXEC = a.out
DEBUG = yes

ifeq ($(DEBUG), yes)
	CXXFLAGS = -std=c++11 -W -Wall -Werror -ansi -pedantic -Wno-ignored-qualifiers -O3 -g
else
	CXXFLAGS = -std=c++11
endif

SDL_OPTIONS = `sdl2-config --cflags --libs`

OBJECT_FILES = event_input.o key_listener.o mouse_button_listener.o window_listener.o game_controller.o log.o log_level.o logger.o console_logger.o


all: $(OBJECT_FILES)
	$(CC) main.cpp $(OBJECT_FILES) $(CXXFLAGS) $(SDL_OPTIONS)

event_input.o: event_input.cpp event_input.hpp
	$(CC) -c event_input.cpp $(CXXFLAGS) $(SDL_OPTIONS)

window_listener.o: window_listener.cpp window_listener.hpp
	$(CC) -c window_listener.cpp $(CXXFLAGS) $(SDL_OPTIONS)

key_listener.o: key_listener.cpp key_listener.hpp
	$(CC) -c key_listener.cpp $(CXXFLAGS) $(SDL_OPTIONS)

mouse_button_listener.o: mouse_button_listener.cpp mouse_button_listener.hpp
	$(CC) -c mouse_button_listener.cpp $(CXXFLAGS) $(SDL_OPTIONS)

game_controller.o: game_controller.cpp game_controller.hpp
	$(CC) -c game_controller.cpp $(CXXFLAGS) $(SDL_OPTIONS)

log.o: log.cpp log.hpp
	$(CC) -c log.cpp $(CXXFLAGS)

log_level.o: log_level.cpp log_level.hpp
	$(CC) -c log_level.cpp $(CXXFLAGS)

logger.o: logger.cpp logger.hpp
	$(CC) -c logger.cpp $(CXXFLAGS)

console_logger.o: console_logger.cpp console_logger.hpp
	$(CC) -c console_logger.cpp $(CXXFLAGS)

help:
	@echo
	@echo "--------------------------------------------------------------------------"
	@echo " Regles disponnibles"
	@echo
	@echo "    * doc            : génération de la documentation"
	@echo "    * clean          : nettoyage des fichiers objets temporaires"
	@echo "    * clean_doc      : nettoyage de toute la documentation"
	@echo "    * purge          : nettoyage complet"
	@echo "    * help           : règles disponnibles"
	@echo "--------------------------------------------------------------------------"
	@echo

clean:
	@rm -f *.o

purge: clean
	@rm -f $(EXEC)

mrproper: clean purge

.PHONY: clean purge 