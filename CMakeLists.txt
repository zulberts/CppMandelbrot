cmake_minimum_required(VERSION 3.10)

# Nazwa projektu
project(Fractal)

# Ustawienie standardu C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Znajdowanie pakietu SDL2
find_package(SDL2 REQUIRED)

# Dołączanie katalogu nagłówków SDL2
include_directories(${SDL2_INCLUDE_DIRS})

# Dodanie pliku źródłowego
add_executable(Fractal main.cpp)

# Linkowanie programu z biblioteką SDL2
target_link_libraries(Fractal ${SDL2_LIBRARIES})
