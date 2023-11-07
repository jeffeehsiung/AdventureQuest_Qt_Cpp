CXX = g++
CXXFLAGS = -std=c++17 -Wall

QT_INCLUDE = /usr/local/Cellar/qt/6.6.0/lib/QtWidgets
QT_LIB = /usr/local/Cellar/qt/6.6.0/lib
GRAPHICS_LIB = -lOpenGL  # Include the appropriate flags for your graphics library

all: mario_app

your_app: main.cpp
    $(CXX) $(CXXFLAGS) -I$(QT_INCLUDE) -L$(QT_LIB) -o $@ $< -lQt5Widgets $(GRAPHICS_LIB)

clean:
    rm -f mario_app
