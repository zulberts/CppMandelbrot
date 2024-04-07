# Nazwa pliku wykonywalnego
TARGET = fractal

# Kompilator C++
CXX = g++

# Opcje kompilatora, w tym ostrzeżenia i standard C++11
CXXFLAGS = -Wall -Wextra -std=c++11

# Ścieżki do katalogów nagłówkowych SDL
SDL_INCLUDE = -I/usr/include/SDL2

# Flagi linkera dla SDL2
SDL_LIB = -L/usr/lib -lSDL2

# Pliki źródłowe
SRC = main.cpp

# Pliki obiektowe
OBJ = $(SRC:.cpp=.o)

# Reguła domyślna
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(SDL_INCLUDE) -c $< -o $@

# Czyszczenie projektu
clean:
	rm -f $(TARGET) $(OBJ)
