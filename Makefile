DEBUG_FLAGS = -fsanitize=address -g

all:
	g++ akinator.cpp funcakinator.cpp -o aki -Wall -Wextra

debug:
	g++ akinator.cpp funcakinator.cpp -o aki -Wall -Wextra $(DEBUG_FLAGS)
